// IEngineInterface.h
// Interface definition for the engine
#pragma once

#include <windows.h>

// IEngineInterface - Pure virtual interface for engine operations
struct IEngineInterface {
    virtual void* QueryInterface(unsigned int index) = 0;                   // vftable[0]
    virtual unsigned long AddRef() = 0;                                     // vftable[1]  
    virtual unsigned long Release() = 0;                                    // vftable[2]
    virtual const wchar_t* GetResourcePath() = 0;                           // vftable[3] - offset 0
    virtual const wchar_t* GetProjectName() = 0;                            // vftable[4] - offset 32
    virtual void GetDefaultResolution(unsigned int* width, unsigned int* height) = 0; // vftable[5] - offset 24
    virtual const wchar_t* GetAccelerator() = 0;                            // vftable[10] - offset 80
    virtual bool InitializeGameCode() = 0;                                  // vftable[12] - offset 96
    virtual void ShutdownGameCode() = 0;                                    // vftable[18] - offset 144
    virtual const wchar_t* GetGDFPath() = 0;                                // vftable[21] - offset 168
    
    virtual ~IEngineInterface() = default;
};

// IControllerInterface - Interface for controller/input handling
struct IControllerInterface {
    virtual void* QueryInterface(unsigned int index) = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
    virtual bool HandleInput(int inputType, int param1, int param2) = 0;
    
    virtual ~IControllerInterface() = default;
};
