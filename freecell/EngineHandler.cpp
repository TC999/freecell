// EngineHandler.cpp
// Implementation of EngineHandler class
#include "EngineHandler.h"
#include "types.h"
#include "DialogHelper.h"
#include <cstring>

EngineHandler::EngineHandler() : m_refCount(1) {
}

EngineHandler::~EngineHandler() {
}

void* EngineHandler::QueryInterface(unsigned int index) {
    return nullptr;
}

unsigned long EngineHandler::AddRef() {
    return ++m_refCount;
}

unsigned long EngineHandler::Release() {
    unsigned long count = --m_refCount;
    if (count == 0) {
        delete this;
    }
    return count;
}

const wchar_t* EngineHandler::GetResourcePath() {
    return L"FreeCell.dll";
}

const wchar_t* EngineHandler::GetProjectName() {
    return L"FreeCell";
}

void EngineHandler::GetDefaultResolution(unsigned int* width, unsigned int* height) {
    if (width) *width = 800;
    if (height) *height = 600;
}

const wchar_t* EngineHandler::GetAccelerator() {
    return MAKEINTRESOURCEW(102); // Resource ID for accelerator table
}

bool EngineHandler::InitializeGameCode() {
    // This would be implemented to initialize the FreeCellGame
    return true;
}

void EngineHandler::ShutdownGameCode() {
    // Cleanup game resources
}

const wchar_t* EngineHandler::GetGDFPath() {
    return L"\\Microsoft Games\\FreeCell\\FreeCell.gdf.xml";
}

// String resource ID for window title
static const UINT WINDOW_TITLE_RESOURCE_ID = 0x65;

const wchar_t* EngineHandler::GetWindowTitle() {
    if (!s_wszTitle[0]) {
        HMODULE hMod = GetModuleHandleW(nullptr);
        if (!LoadStringW(hMod, WINDOW_TITLE_RESOURCE_ID, s_wszTitle, 512)) {
            wcsncpy_s(s_wszTitle, 512, GetProjectName(), _TRUNCATE);
        }
    }
    return s_wszTitle;
}

const wchar_t* EngineHandler::GetHelpGUID() {
    return L"mshelp://windows/?id=70f47084-279a-4ec5-a7b9-364a989ddbf4";
}

int EngineHandler::GetSplashTextFontSize() {
    return 36;
}

void EngineHandler::ReportOutOfMemory() {
    // Display out of memory error
    MessageBoxW(nullptr, L"Out of memory", L"Error", MB_ICONERROR);
}

__int64 EngineHandler::HandleWindowsMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pHandled) {
    if (pHandled) *pHandled = false;
    return 0;
}
