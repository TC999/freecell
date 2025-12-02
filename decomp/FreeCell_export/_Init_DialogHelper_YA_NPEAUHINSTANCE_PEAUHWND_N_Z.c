char __fastcall DialogHelper::Init(DialogHelper *this, HWND a2, HWND a3)
{
  HMODULE LibraryW; // rax
  HRESULT (__stdcall *TaskDialogIndirect)(const TASKDIALOGCONFIG *, int *, int *, BOOL *); // rax
  int (*v6)(struct HWND__ *, struct HINSTANCE__ *, const unsigned __int16 *, const unsigned __int16 *, unsigned int, const unsigned __int16 *, int *); // rax
  int (*v7)(const struct _TASKDIALOGCONFIG_OLD *, int *, int *); // rax
  HGLOBAL v8; // rax
  DWORD pdwDefaultLayout[4]; // [rsp+20h] [rbp-148h] BYREF
  struct _OSVERSIONINFOW VersionInformation; // [rsp+30h] [rbp-138h] BYREF

  if ( !this )
    return 0;
  DialogHelper::m_hInstance = (HINSTANCE)this;
  DialogHelper::m_hWnd = a2;
  DialogHelper::m_bIsMediaCenter = (char)a3;
  if ( !DialogHelper::m_hTaskDialogDll )
  {
    LibraryW = LoadLibraryW(L"comctl32");
    DialogHelper::m_hTaskDialogDll = LibraryW;
    if ( LibraryW )
    {
      DialogHelper::m_TaskDialog = (int (*)(struct HWND__ *, struct HINSTANCE__ *, const unsigned __int16 *, const unsigned __int16 *, const unsigned __int16 *, unsigned int, const unsigned __int16 *, int *))GetProcAddress(LibraryW, "TaskDialog");
      TaskDialogIndirect = (HRESULT (__stdcall *)(const TASKDIALOGCONFIG *, int *, int *, BOOL *))GetProcAddress(
                                                                                                    DialogHelper::m_hTaskDialogDll,
                                                                                                    "TaskDialogIndirect");
      DialogHelper::m_TaskDialogIndirect = TaskDialogIndirect;
      if ( DialogHelper::m_TaskDialog || TaskDialogIndirect )
      {
        VersionInformation.dwOSVersionInfoSize = 276;
        if ( GetVersionExW(&VersionInformation)
          && VersionInformation.dwMajorVersion >= 6
          && !VersionInformation.dwMinorVersion
          && VersionInformation.dwPlatformId == 2
          && VersionInformation.dwBuildNumber < 0x147C )
        {
          v6 = (int (*)(struct HWND__ *, struct HINSTANCE__ *, const unsigned __int16 *, const unsigned __int16 *, unsigned int, const unsigned __int16 *, int *))DialogHelper::m_TaskDialog;
          DialogHelper::m_TaskDialog = 0;
          DialogHelper::m_TaskDialogOld = v6;
          v7 = (int (*)(const struct _TASKDIALOGCONFIG_OLD *, int *, int *))DialogHelper::m_TaskDialogIndirect;
          DialogHelper::m_TaskDialogIndirect = 0;
          DialogHelper::m_TaskDialogIndirectOld = v7;
        }
      }
    }
    pdwDefaultLayout[0] = 0;
    GetProcessDefaultLayout(pdwDefaultLayout);
    DialogHelper::m_DlgTemplateAlloc = 3000;
    DialogHelper::m_bRTL = pdwDefaultLayout[0] & 1;
    v8 = GlobalAlloc(0x40u, 0xBB8u);
    DialogHelper::m_hLastFocus = 0;
    DialogHelper::m_hWritableTemplate = v8;
  }
  return 1;
}
