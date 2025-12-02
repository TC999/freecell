// DialogHelper.cpp
// Implementation of DialogHelper class
#include "DialogHelper.h"
#include "types.h"
#include <cstring>

bool DialogHelper::Init(HINSTANCE hInstance, HWND hWnd, bool bMediaCenter, bool unused) {
    if (!hInstance) {
        return false;
    }
    
    m_hInstance = hInstance;
    m_hWnd = hWnd;
    m_bIsMediaCenter = bMediaCenter;
    
    if (!m_hTaskDialogDll) {
        HMODULE hLib = LoadLibraryW(L"comctl32");
        m_hTaskDialogDll = hLib;
        
        if (hLib) {
            m_TaskDialog = (int (*)(HWND, HINSTANCE, const unsigned short*, const unsigned short*, 
                                    const unsigned short*, unsigned int, const unsigned short*, int*))
                           GetProcAddress(hLib, "TaskDialog");
            m_TaskDialogIndirect = (HRESULT (*)(const TASKDIALOGCONFIG*, int*, int*, BOOL*))
                                   GetProcAddress(hLib, "TaskDialogIndirect");
        }
        
        DWORD defaultLayout = 0;
        GetProcessDefaultLayout(&defaultLayout);
        m_DlgTemplateAlloc = 3000;
        m_bRTL = (defaultLayout & 1) != 0;
        m_hWritableTemplate = GlobalAlloc(GMEM_FIXED | GMEM_ZEROINIT, 0xBB8);
        m_hLastFocus = nullptr;
    }
    
    return true;
}

void DialogHelper::InitMCE(const wchar_t* unused1, const unsigned short* unused2) {
    // MCE specific initialization - placeholder
}

void DialogHelper::CenterDialog(HWND hWnd, HWND unused) {
    HWND hParent = GetWindow(hWnd, GW_OWNER);
    bool useMonitor = false;
    
    if (hParent) {
        LONG style = GetWindowLongW(hParent, GWL_STYLE);
        if ((style & WS_VISIBLE) == 0 || (style & WS_MINIMIZE) != 0) {
            useMonitor = true;
        }
    }
    
    RECT rcDlg;
    GetWindowRect(hWnd, &rcDlg);
    
    RECT rcArea = {0, 0, 0, 0};
    bool centeredToMonitor = false;
    
    if (useMonitor || !hParent) {
        HMONITOR hMon = MonitorFromWindow(hParent, MONITOR_DEFAULTTONEAREST);
        MONITORINFO mi = { sizeof(mi) };
        GetMonitorInfoW(hMon, &mi);
        
        if (m_bIsMediaCenter) {
            rcArea = mi.rcMonitor;
        } else {
            rcArea = mi.rcWork;
        }
        centeredToMonitor = true;
    } else {
        GetWindowRect(hParent, &rcArea);
    }
    
    int width = rcDlg.right - rcDlg.left;
    int height = rcDlg.bottom - rcDlg.top;
    int left = (rcArea.right + rcArea.left) / 2 - width / 2;
    int top = (rcArea.top + rcArea.bottom) / 2 - height / 2;
    
    if (centeredToMonitor) {
        if (left < rcArea.left) {
            left = rcArea.left;
        } else if (left + width > rcArea.right) {
            left = rcArea.right - width;
        }
        
        if (top < rcArea.top) {
            top = rcArea.top;
        } else if (top + height > rcArea.bottom) {
            top = rcArea.bottom - height;
        }
    }
    
    SetWindowPos(hWnd, nullptr, left, top, -1, -1, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void DialogHelper::DismissDialog(HWND hWnd, int result, int unused) {
    EndDialog(hWnd, result);
}

int DialogHelper::ShowMessageBox(unsigned int captionId, unsigned int textId, unsigned int flags, 
                                  const unsigned short* iconType, const wchar_t* caption, 
                                  const wchar_t* text, const unsigned short* useTaskDialog, bool unused) {
    int result = 0;
    wchar_t captionBuf[256] = {0};
    wchar_t textBuf[512] = {0};
    
    if (m_TaskDialog && useTaskDialog && (char)(reinterpret_cast<uintptr_t>(useTaskDialog) & 0xFF)) {
        const unsigned short* pText = text ? (const unsigned short*)text : reinterpret_cast<const unsigned short*>(static_cast<uintptr_t>(textId));
        unsigned short* pCaption = caption ? (unsigned short*)(const_cast<wchar_t*>(caption)) : reinterpret_cast<unsigned short*>(static_cast<uintptr_t>(captionId));
        m_TaskDialog(m_hWnd, m_hInstance, pCaption, pText, nullptr, 1, iconType, &result);
    } else {
        if (!caption && !LoadStringW(m_hInstance, (UINT)captionId, captionBuf, 256)) {
            return 0;
        }
        if (!text && !LoadStringW(m_hInstance, textId, textBuf, 512)) {
            return 0;
        }
        
        UINT mbType = 0;
        if (iconType == (const unsigned short*)0xFFFE) {
            mbType = MB_ICONERROR;
        } else if (iconType == (const unsigned short*)0xFFFF) {
            mbType = MB_ICONWARNING;
        }
        
        const wchar_t* finalCaption = caption ? caption : captionBuf;
        const wchar_t* finalText = text ? text : textBuf;
        result = MessageBoxW(m_hWnd, finalText, finalCaption, mbType);
    }
    
    if (m_DialogShutdown) {
        m_DialogShutdown();
    }
    
    return result;
}

int DialogHelper::ShowDialog(const TASKDIALOGCONFIG* pConfig, unsigned int flags, 
                              unsigned int* pnButton, unsigned int* pnRadio, 
                              unsigned int* pnVerify, bool* pChecked) {
    // Stub implementation
    return 0;
}

int DialogHelper::ShowEditBalloonTip(HWND hWnd, unsigned int iconId, unsigned int textId, int icon) {
    // Stub implementation
    return 0;
}

INT_PTR DialogHelper::OnCtlColorStaticMCE(HWND hDlg, HDC hdc, unsigned int unused1, unsigned int unused2) {
    return (INT_PTR)GetStockObject(NULL_BRUSH);
}

int DialogHelper::OnEraseBkgndMCE(HWND hWnd, HDC hdc, HDC unused) {
    return 1;
}

void DialogHelper::OnDrawItemMCE(__int64 unused, __int64 unused2) {
    // MCE draw item handler - placeholder
}

BOOL CALLBACK DialogHelper::EnumChildProc(HWND hWnd, LPARAM lParam) {
    return TRUE;
}

Gdiplus::Image* DialogHelper::LoadImageMCE(const wchar_t* path, const wchar_t* unused) {
    return nullptr;
}

int DialogHelper::GetMCEFontSize(bool unused) {
    return 12;
}

bool DialogHelper::SetStaticTextI(HWND hWnd, unsigned int id, const wchar_t* text, int unused1, bool unused2) {
    return SetDlgItemTextW(hWnd, id, text) != 0;
}

int DialogHelper::DialogBoxMCE(const wchar_t* templateName, HWND hParent, 
                               INT_PTR (CALLBACK* dlgProc)(HWND, UINT, WPARAM, LPARAM),
                               int unused1, bool unused2, unsigned int unused3, HWND unused4) {
    return (int)DialogBoxW(m_hInstance, templateName, hParent, dlgProc);
}

// DialogProc implementation
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_ERASEBKGND:
            if (DialogHelper::m_bIsMediaCenter) {
                return DialogHelper::OnEraseBkgndMCE(hDlg, (HDC)wParam);
            }
            break;
            
        case WM_ACTIVATEAPP:
            if (wParam) {
                ShowWindow(DialogHelper::m_hWnd, SW_RESTORE);
                if (DialogHelper::m_bIsMediaCenter) {
                    int ctrlId = GetDlgCtrlID(DialogHelper::m_hLastFocus);
                    HWND hFocus = ctrlId ? DialogHelper::m_hLastFocus : hDlg;
                    SetFocus(hFocus);
                }
            } else if (DialogHelper::m_bIsMediaCenter) {
                DialogHelper::m_hLastFocus = GetFocus();
            }
            break;
            
        case WM_DRAWITEM:
            if (DialogHelper::m_bIsMediaCenter) {
                DialogHelper::OnDrawItemMCE(lParam, uMsg);
                return TRUE;
            }
            break;
            
        case WM_NCCALCSIZE:
            if (DialogHelper::m_bIsMediaCenter) {
                DialogHelper::CenterDialog(hDlg);
            }
            break;
            
        case WM_INITDIALOG:
            if (DialogHelper::baseDialogProc) {
                DialogHelper::baseDialogProc(hDlg, WM_INITDIALOG, wParam, lParam);
            } else {
                DialogHelper::CenterDialog(hDlg);
            }
            if (DialogHelper::m_bIsMediaCenter) {
                RECT rc;
                GetWindowRect(hDlg, &rc);
                HRGN hRgn = CreateRoundRectRgn(1, 1, rc.right - rc.left, rc.bottom - rc.top, 10, 10);
                SetWindowRgn(hDlg, hRgn, FALSE);
                EnumChildWindows(hDlg, DialogHelper::EnumChildProc, 0);
                DialogHelper::m_hFont = (void*)SendMessageW(hDlg, WM_GETFONT, 0, 0);
                DialogHelper::m_hHotCtl = nullptr;
                DialogHelper::m_bMouseOverCtl = false;
            }
            return TRUE;
            
        case WM_COMMAND:
            if (DialogHelper::baseDialogProc) {
                DialogHelper::baseDialogProc(hDlg, WM_COMMAND, wParam, lParam);
            } else {
                DialogHelper::DismissDialog(hDlg, LOWORD(wParam), 0);
            }
            return TRUE;
            
        case WM_CTLCOLORDLG:
            if (DialogHelper::m_bIsMediaCenter) {
                return (INT_PTR)GetStockObject(NULL_BRUSH);
            }
            break;
            
        case WM_CTLCOLORSTATIC:
            if (DialogHelper::m_bIsMediaCenter) {
                return DialogHelper::OnCtlColorStaticMCE((HWND)lParam, (HDC)wParam, 
                                                         DialogHelper::m_uiTitle, (unsigned int)lParam);
            }
            break;
            
        case WM_MOUSEMOVE:
            if (DialogHelper::m_bIsMediaCenter && DialogHelper::m_bMouseOverCtl) {
                DialogHelper::m_bMouseOverCtl = false;
                InvalidateRect(DialogHelper::m_hHotCtl, nullptr, FALSE);
                DialogHelper::m_hHotCtl = nullptr;
            }
            break;
    }
    
    if (DialogHelper::baseDialogProc) {
        return DialogHelper::baseDialogProc(hDlg, uMsg, wParam, lParam);
    }
    return FALSE;
}
