// InitializeEngine.cpp
// Main engine initialization routine
#include "InitializeEngine.h"
#include "types.h"
#include "DialogHelper.h"
#include "EngineHandler.h"
#include <windows.h>
#include <thread>
#include <atomic>

// Engine state
static std::atomic<bool> g_bRunning{true};

// Forward declarations
void RunEngine();
void CleanupEngine(unsigned int exitCode);
bool CreateGameWindow();
void Engine_LoadingComplete();
void Engine_ResetTimer();

// Message loop implementation
static void RunMessageLoop() {
    MSG msg = {0};
    while (g_bRunning) {
        while (!PeekMessageW(&msg, nullptr, 0, 0, PM_NOREMOVE)) {
            RunEngine();
        }
        
        if (!GetMessageW(&msg, nullptr, 0, 0)) {
            break;
        }
        
        if (!g_Accelerator || !TranslateAcceleratorW(g_hWnd, g_Accelerator, &msg)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
}

// Engine run function - called during idle time
void RunEngine() {
    // Game update logic would go here
    Sleep(10); // Prevent busy-waiting
}

// Cleanup function
void CleanupEngine(unsigned int exitCode) {
    g_bRunning = false;
    if (exitCode != 0) {
        ExitProcess(exitCode);
    }
}

// Create the main game window
bool CreateGameWindow() {
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = DefWindowProcW;
    wc.hInstance = g_hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"FreeCellClass";
    
    if (!RegisterClassExW(&wc)) {
        return false;
    }
    
    g_hWnd = CreateWindowExW(
        0,
        L"FreeCellClass",
        L"FreeCell",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        nullptr, nullptr, g_hInstance, nullptr
    );
    
    if (!g_hWnd) {
        return false;
    }
    
    g_hRenderWindow = g_hWnd;
    ShowWindow(g_hWnd, SW_SHOW);
    UpdateWindow(g_hWnd);
    
    return true;
}

// Called when loading is complete
void Engine_LoadingComplete() {
    // Post-load initialization
}

// Reset timer callback
void Engine_ResetTimer() {
    // Timer reset logic
}

bool InitializeEngine(IEngineInterface* engine, IControllerInterface* controller) {
    if (!engine) {
        return false;
    }
    
    // Initialize dialog helper
    HMODULE hMod = GetModuleHandleW(nullptr);
    DialogHelper::Init((HINSTANCE)hMod, nullptr, g_bMediaCenter, false);
    
    // Get project name
    const wchar_t* projectName = engine->GetProjectName();
    
    // Create singleton mutex to prevent multiple instances
    wchar_t mutexName[256];
    wsprintfW(mutexName, L"Local\\Oberon_%s_Singleton", projectName);
    HANDLE hMutex = CreateMutexW(nullptr, TRUE, mutexName);
    
    if (!hMutex) {
        ExitProcess(0);
    }
    
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        // Another instance is running - bring it to front
        HWND hExisting = FindWindowW(projectName, nullptr);
        if (hExisting) {
            if (IsIconic(hExisting)) {
                ShowWindow(hExisting, SW_RESTORE);
            }
            BringWindowToTop(hExisting);
            SetForegroundWindow(hExisting);
        }
        ExitProcess(0);
    }
    
    // Check command line for MCE mode
    int numArgs = 0;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &numArgs);
    if (argv) {
        for (int i = 1; i < numArgs; i++) {
            if (wcscmp(argv[i], L"-mce") == 0) {
                g_bMediaCenter = true;
                break;
            }
        }
        LocalFree(argv);
    }
    
    // Register for restart
    RegisterApplicationRestart(GetCommandLineW(), 0);
    
    // Initialize COM
    CoInitialize(nullptr);
    
    // Store interface pointer
    g_pInterface = engine;
    
    // Localize project name (simplified)
    g_wszProjectName = projectName;
    
    // Set working directory to executable path
    wchar_t modulePath[MAX_PATH];
    DWORD pathLen = GetModuleFileNameW(nullptr, modulePath, MAX_PATH);
    if (pathLen > 0) {
        // Find last path separator
        wchar_t* lastSep = wcsrchr(modulePath, L'\\');
        if (!lastSep) {
            lastSep = wcsrchr(modulePath, L'/');
        }
        if (lastSep) {
            *lastSep = L'\0';
        }
        SetCurrentDirectoryW(modulePath);
    }
    
    // Create game window
    if (!CreateGameWindow()) {
        CleanupEngine(0);
        return false;
    }
    
    // Initialize MCE dialog if in MCE mode
    if (g_bMediaCenter) {
        DialogHelper::InitMCE(nullptr, nullptr);
    }
    
    // Initialize game code
    g_bInInitializer = true;
    if (!engine->InitializeGameCode()) {
        CleanupEngine(0);
        return false;
    }
    g_bInInitializer = false;
    
    // Signal loading complete
    Engine_LoadingComplete();
    
    // Get accelerator table
    const wchar_t* accel = engine->GetAccelerator();
    if (accel) {
        HMODULE hModule = GetModuleHandleW(nullptr);
        g_Accelerator = LoadAcceleratorsW(hModule, accel);
    }
    
    g_bInitializing = false;
    
    // Run message loop
    RunMessageLoop();
    
    // Shutdown
    engine->ShutdownGameCode();
    CleanupEngine(0);
    
    return true;
}
