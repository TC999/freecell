// globals.cpp
// Global variable definitions and stub implementations
#include "types.h"
#include "DialogHelper.h"
#include "EngineHandler.h"
#include <cstring>

// Global variable definitions
HINSTANCE g_hInstance = nullptr;
HWND g_hWnd = nullptr;
HWND g_hRenderWindow = nullptr;
bool g_bMediaCenter = false;
bool g_bDebugEnabled = false;
bool g_bDoubleDPI = false;
bool g_bInitializing = true;
bool g_bInInitializer = false;
bool g_bFocusPause = false;
HACCEL g_Accelerator = nullptr;
const wchar_t* g_SETTINGS_SAVE_FILENAME = L"FreeCellSettings.xml";
const wchar_t* g_wszProjectName = nullptr;
unsigned __int64 g_GdiPlusToken = 0;
unsigned __int16* g_bstrGDFPath = nullptr;
IEngineInterface* g_pInterface = nullptr;
XmlManager* g_pXmlManager = nullptr;
ResourceManager* g_pResourceManager = nullptr;
RenderManager* g_pRenderManager = nullptr;
Audio* g_pAudio = nullptr;
Timer* g_pTimer = nullptr;
FreeCellGame* g_pFreeCellGame = nullptr;
CommonControllerThread* g_pCommonController = nullptr;
void* g_pSecondTimerCallback = nullptr;
DllFileMgr* qword_1000B10B0 = nullptr;

// DialogHelper static members
HINSTANCE DialogHelper::m_hInstance = nullptr;
HWND DialogHelper::m_hWnd = nullptr;
bool DialogHelper::m_bIsMediaCenter = false;
HWND DialogHelper::m_hLastFocus = nullptr;
void* DialogHelper::m_hFont = nullptr;
HWND DialogHelper::m_hHotCtl = nullptr;
bool DialogHelper::m_bMouseOverCtl = false;
unsigned int DialogHelper::m_uiTitle = 0;
bool DialogHelper::m_bRTL = false;
HMODULE DialogHelper::m_hTaskDialogDll = nullptr;
HGLOBAL DialogHelper::m_hWritableTemplate = nullptr;
unsigned int DialogHelper::m_DlgTemplateAlloc = 0;
INT_PTR (*DialogHelper::baseDialogProc)(HWND, UINT, WPARAM, LPARAM) = nullptr;
void (*DialogHelper::m_DialogShutdown)() = nullptr;
int (*DialogHelper::m_TaskDialog)(HWND, HINSTANCE, const unsigned short*, const unsigned short*, 
                                  const unsigned short*, unsigned int, const unsigned short*, int*) = nullptr;
HRESULT (*DialogHelper::m_TaskDialogIndirect)(const TASKDIALOGCONFIG*, int*, int*, BOOL*) = nullptr;
int (*DialogHelper::m_TaskDialogOld)(HWND, HINSTANCE, const unsigned short*, const unsigned short*, 
                                     unsigned int, const unsigned short*, int*) = nullptr;
int (*DialogHelper::m_TaskDialogIndirectOld)(const void*, int*, int*) = nullptr;

// EngineHandler static members
wchar_t EngineHandler::s_wszTitle[512] = {0};
