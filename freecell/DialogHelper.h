// DialogHelper.h
// Dialog helper class for Windows dialogs
#pragma once

#include <windows.h>
#include <commctrl.h>

// Forward declaration
namespace Gdiplus {
    class Image;
}

class DialogHelper {
public:
    // Static initialization
    static bool Init(HINSTANCE hInstance, HWND hWnd, bool bMediaCenter, bool unused = false);
    static void InitMCE(const wchar_t* unused1 = nullptr, const unsigned short* unused2 = nullptr);
    
    // Dialog functions
    static void CenterDialog(HWND hWnd, HWND unused = nullptr);
    static void DismissDialog(HWND hWnd, int result, int unused = 0);
    static int ShowMessageBox(unsigned int captionId, unsigned int textId, unsigned int flags, 
                              const unsigned short* iconType, const wchar_t* caption = nullptr, 
                              const wchar_t* text = nullptr, const unsigned short* useTaskDialog = nullptr,
                              bool unused = false);
    
    static int ShowDialog(const TASKDIALOGCONFIG* pConfig, unsigned int flags, 
                          unsigned int* pnButton, unsigned int* pnRadio, 
                          unsigned int* pnVerify, bool* pChecked);
    static int ShowEditBalloonTip(HWND hWnd, unsigned int iconId, unsigned int textId, int icon);
    
    static INT_PTR OnCtlColorStaticMCE(HWND hDlg, HDC hdc, unsigned int unused1, unsigned int unused2);
    static int OnEraseBkgndMCE(HWND hWnd, HDC hdc, HDC unused = nullptr);
    static void OnDrawItemMCE(__int64 unused, __int64 unused2);
    
    static BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam);
    static Gdiplus::Image* LoadImageMCE(const wchar_t* path, const wchar_t* unused);
    static int GetMCEFontSize(bool unused);
    static bool SetStaticTextI(HWND hWnd, unsigned int id, const wchar_t* text, int unused1, bool unused2);
    
    static int DialogBoxMCE(const wchar_t* templateName, HWND hParent, 
                            INT_PTR (CALLBACK* dlgProc)(HWND, UINT, WPARAM, LPARAM),
                            int unused1, bool unused2, unsigned int unused3, HWND unused4);
    
    // Static members
    static HINSTANCE m_hInstance;
    static HWND m_hWnd;
    static bool m_bIsMediaCenter;
    static HWND m_hLastFocus;
    static void* m_hFont;
    static HWND m_hHotCtl;
    static bool m_bMouseOverCtl;
    static unsigned int m_uiTitle;
    static bool m_bRTL;
    static HMODULE m_hTaskDialogDll;
    static HGLOBAL m_hWritableTemplate;
    static unsigned int m_DlgTemplateAlloc;
    
    // Function pointers
    static INT_PTR (*baseDialogProc)(HWND, UINT, WPARAM, LPARAM);
    static void (*m_DialogShutdown)();
    static int (*m_TaskDialog)(HWND, HINSTANCE, const unsigned short*, const unsigned short*, 
                               const unsigned short*, unsigned int, const unsigned short*, int*);
    static HRESULT (*m_TaskDialogIndirect)(const TASKDIALOGCONFIG*, int*, int*, BOOL*);
    static int (*m_TaskDialogOld)(HWND, HINSTANCE, const unsigned short*, const unsigned short*, 
                                  unsigned int, const unsigned short*, int*);
    static int (*m_TaskDialogIndirectOld)(const void*, int*, int*);
};

// External dialog procedures
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
