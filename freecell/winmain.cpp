// winmain.cpp
// Windows entry point for FreeCell game
#include <windows.h>
#include "types.h"
#include "DialogHelper.h"
#include "EngineHandler.h"
#include "InitializeEngine.h"

// Entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    g_hInstance = hInstance;
    
    // Enable heap corruption termination
    HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

    // Check for tablet mode (GetSystemMetrics(67) is SM_CONVERTIBLESLATEMODE)
    if (GetSystemMetrics(67))
    {
        // Device is in tablet mode, show error dialog
        unsigned short flag = 1;
        DialogHelper::ShowMessageBox(0x385, 0x374, 1, (const unsigned short*)0xFFFE, 
                                     nullptr, nullptr, &flag, false);
        return 1;
    }
    else
    {
        // Create engine handler
        IEngineInterface* engine = new EngineHandler();
        BOOL failed = TRUE;
        if (engine)
        {
            // Initialize engine
            failed = !InitializeEngine(engine, nullptr);
            // Release engine object
            delete engine;
        }
        return failed;
    }
}