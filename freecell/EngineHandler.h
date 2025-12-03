// EngineHandler.h
// EngineHandler class implementation of IEngineInterface
#pragma once

#include "IEngineInterface.h"

class EngineHandler : public IEngineInterface {
public:
    EngineHandler();
    virtual ~EngineHandler();
    
    // IEngineInterface implementations
    virtual void* QueryInterface(unsigned int index) override;
    virtual unsigned long AddRef() override;
    virtual unsigned long Release() override;
    virtual const wchar_t* GetResourcePath() override;
    virtual const wchar_t* GetProjectName() override;
    virtual void GetDefaultResolution(unsigned int* width, unsigned int* height) override;
    virtual const wchar_t* GetAccelerator() override;
    virtual bool InitializeGameCode() override;
    virtual void ShutdownGameCode() override;
    virtual const wchar_t* GetGDFPath() override;
    
    // Additional methods from decompilation
    const wchar_t* GetWindowTitle();
    const wchar_t* GetHelpGUID();
    int GetSplashTextFontSize();
    void ReportOutOfMemory();
    __int64 HandleWindowsMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pHandled);
    
private:
    unsigned long m_refCount;
    static wchar_t s_wszTitle[512];
};
