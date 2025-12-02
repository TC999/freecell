INT_PTR __fastcall DialogHelper::DialogBoxMCE(
        LPCWSTR lpTemplateName,
        HWND hWnd,
        __int64 (*lpDialogFunc)(struct HWND__ *, unsigned int, unsigned __int64, __int64),
        __int64 (*nIDDlgItem)(HWND, unsigned int, unsigned __int64, __int64),
        char a5,
        int a6)
{
  unsigned int v6; // edi
  INT_PTR (__stdcall *v7)(HWND, UINT, WPARAM, LPARAM); // rsi
  HWND v8; // rbp
  INT_PTR v10; // rdi
  INT_PTR result; // rax
  HRSRC ResourceW; // rax
  HWND DialogIndirectParamW; // rbx
  HGLOBAL Resource; // rax
  void *v15; // r13
  const struct DLGTEMPLATE *v16; // rax
  const struct DLGTEMPLATE *v17; // r12
  signed int TemplateSize; // eax
  int v19; // ecx
  size_t v20; // rbp
  struct DLGTEMPLATE *v21; // rax
  struct DLGTEMPLATE *v22; // rdi
  DWORD style; // eax
  unsigned __int8 *FontSizeField; // rax
  int v25; // ecx
  __int16 v26; // r9
  DialogHelper *v27; // rcx
  bool v28; // dl
  unsigned __int16 MCEFontSize; // bx
  HDC DC; // rdi
  double v31; // xmm6_8
  HWND DlgItem; // rax
  UINT v33; // r12d
  int MessageW; // eax
  WPARAM wParam; // rax
  HWND v36; // rcx
  LONG_PTR v37; // rax
  HWND NextDlgGroupItem; // rdi
  LONG_PTR v39; // rax
  HWND v40; // rax
  HWND v41; // rdi
  HWND v42; // rsi
  HWND NextDlgTabItem; // rax
  HWND v44; // rdi
  HWND v45; // rdi
  HWND Focus; // rdi
  HWND v47; // rax
  HWND v48; // rbp
  int ClassNameW; // eax
  bool v50; // zf
  WCHAR *v51; // rsi
  const wchar_t *v52; // rdi
  __int64 v53; // rcx
  __int16 v54; // dx
  HWND v55; // rcx
  _DWORD *v56; // rax
  _DWORD *v57; // rdi
  UINT RawInputData; // eax
  unsigned int pcbSize; // [rsp+30h] [rbp-378h] BYREF
  HWND hWndParent; // [rsp+38h] [rbp-370h]
  struct tagMSG Msg; // [rsp+40h] [rbp-368h] BYREF
  RAWINPUTDEVICE pRawInputDevices; // [rsp+70h] [rbp-338h] BYREF
  struct tagRECT v63; // [rsp+80h] [rbp-328h] BYREF
  struct tagRECT v64; // [rsp+90h] [rbp-318h] BYREF
  struct tagRECT v65; // [rsp+A0h] [rbp-308h] BYREF
  struct tagRECT v66; // [rsp+B0h] [rbp-2F8h] BYREF
  struct tagRECT v67; // [rsp+C0h] [rbp-2E8h] BYREF
  struct tagRECT Rect; // [rsp+D0h] [rbp-2D8h] BYREF
  struct tagRECT v69; // [rsp+E0h] [rbp-2C8h] BYREF
  struct tagRECT v70; // [rsp+F0h] [rbp-2B8h] BYREF
  wchar_t Destination[32]; // [rsp+100h] [rbp-2A8h] BYREF
  WCHAR ClassName[256]; // [rsp+140h] [rbp-268h] BYREF

  v6 = (unsigned int)nIDDlgItem;
  pcbSize = (unsigned int)nIDDlgItem;
  v7 = lpDialogFunc;
  v8 = hWnd;
  hWndParent = hWnd;
  if ( !DialogHelper::m_bIsMediaCenter )
  {
    ShowCursor(1);
    v10 = DialogBoxParamW(DialogHelper::m_hInstance, lpTemplateName, v8, v7, 0);
    ShowCursor(0);
    return v10;
  }
  LODWORD(DialogHelper::m_uiTitle) = a6;
  if ( (char *)lpDialogFunc == (char *)DialogProc )
  {
    DialogHelper::baseDialogProc = 0;
  }
  else
  {
    DialogHelper::baseDialogProc = lpDialogFunc;
    v7 = (INT_PTR (__stdcall *)(HWND, UINT, WPARAM, LPARAM))DialogProc;
  }
  ResourceW = FindResourceW(DialogHelper::m_hInstance, lpTemplateName, (LPCWSTR)5);
  DialogIndirectParamW = 0;
  if ( !ResourceW )
    goto LABEL_28;
  Resource = LoadResource(DialogHelper::m_hInstance, ResourceW);
  v15 = Resource;
  if ( !Resource )
    goto LABEL_28;
  v16 = (const struct DLGTEMPLATE *)LockResource(Resource);
  v17 = v16;
  if ( v16 )
  {
    TemplateSize = GetTemplateSize(v16);
    v19 = DialogHelper::m_DlgTemplateAlloc;
    v20 = TemplateSize;
    if ( TemplateSize < DialogHelper::m_DlgTemplateAlloc )
    {
      v22 = (struct DLGTEMPLATE *)DialogHelper::m_hWritableTemplate;
    }
    else
    {
      if ( DialogHelper::m_hWritableTemplate )
        GlobalFree(DialogHelper::m_hWritableTemplate);
      DialogHelper::m_DlgTemplateAlloc = v20 + 1000;
      v21 = (struct DLGTEMPLATE *)GlobalAlloc(0x40u, (int)v20 + 1000);
      v19 = DialogHelper::m_DlgTemplateAlloc;
      v22 = v21;
      DialogHelper::m_hWritableTemplate = v21;
    }
    if ( v22 && (int)v20 < v19 )
    {
      memcpy(v22, v17, v20);
      memset(Destination, 0, sizeof(Destination));
      if ( HIWORD(v22->style) == 0xFFFF )
        style = *(_DWORD *)&v22->y;
      else
        style = v22->style;
      if ( (style & 0x40) != 0 )
      {
        FontSizeField = GetFontSizeField(v22);
        v25 = 1;
        if ( HIWORD(v22->style) == v26 )
          v25 = 3;
        wcsncpy_s(Destination, 0x20u, (const wchar_t *)&FontSizeField[2 * v25], 0xFFFFFFFFFFFFFFFFuLL);
        LOBYTE(v27) = 1;
        MCEFontSize = DialogHelper::GetMCEFontSize(v27, v28);
        DC = GetDC(DialogHelper::m_hWnd);
        v31 = 96.0 / (double)GetDeviceCaps(DC, 88);
        ReleaseDC(DialogHelper::m_hWnd, DC);
        v22 = (struct DLGTEMPLATE *)DialogHelper::m_hWritableTemplate;
        if ( DialogHelper::m_hWritableTemplate )
        {
          SetFontSize(
            (struct DLGTEMPLATE *)DialogHelper::m_hWritableTemplate,
            Destination,
            (int)((double)MCEFontSize * v31));
          v22 = (struct DLGTEMPLATE *)DialogHelper::m_hWritableTemplate;
        }
      }
      v8 = hWndParent;
      DialogIndirectParamW = CreateDialogIndirectParamW(DialogHelper::m_hInstance, v22, hWndParent, v7, 0);
    }
    else
    {
      v8 = hWndParent;
    }
    v6 = pcbSize;
  }
  FreeResource(v15);
  if ( !DialogIndirectParamW )
LABEL_28:
    DialogIndirectParamW = CreateDialogParamW(DialogHelper::m_hInstance, lpTemplateName, v8, v7, 0);
  pRawInputDevices.usUsage = 1;
  pRawInputDevices.dwFlags = 0;
  pRawInputDevices.usUsagePage = 12;
  pRawInputDevices.hwndTarget = DialogIndirectParamW;
  RegisterRawInputDevices(&pRawInputDevices, 1u, 0x10u);
  EnableWindow(v8, 0);
  ShowWindow(DialogIndirectParamW, 5);
  if ( a5 )
  {
    DlgItem = GetDlgItem(DialogIndirectParamW, v6);
    SetFocus(DlgItem);
  }
  v33 = RegisterWindowMessageW(L"MCEDialogDismiss");
  MessageW = GetMessageW(&Msg, 0, 0, 0);
  if ( MessageW )
  {
    while ( 1 )
    {
      if ( MessageW == -1 || Msg.message == v33 )
      {
LABEL_105:
        v8 = hWndParent;
        break;
      }
      if ( Msg.message != 256 )
      {
        if ( Msg.message == 255 )
        {
          if ( LOBYTE(Msg.wParam) )
            goto LABEL_105;
          pcbSize = 0;
          GetRawInputData((HRAWINPUT)Msg.lParam, 0x10000003u, 0, &pcbSize, 0x18u);
          v56 = operator new(pcbSize);
          v57 = v56;
          if ( !v56 )
            goto LABEL_105;
          RawInputData = GetRawInputData((HRAWINPUT)Msg.lParam, 0x10000003u, v56, &pcbSize, 0x18u);
          if ( RawInputData != pcbSize || *v57 != 2 )
          {
            operator delete(v57);
            goto LABEL_105;
          }
          if ( v57[6] == 3 && *((_BYTE *)v57 + 32) == 2 && *((_BYTE *)v57 + 33) == 9 && *((_BYTE *)v57 + 34) == 2 )
          {
            byte_1000B1CDA = 1;
            FakeKeyPress(DialogIndirectParamW, 13, 0, 0, 0, 0);
          }
          operator delete(v57);
        }
        goto LABEL_100;
      }
      wParam = Msg.wParam;
      switch ( Msg.wParam )
      {
        case '(':
          if ( !GetDlgCtrlID(Msg.hwnd) )
            goto LABEL_37;
          v37 = GetWindowLongPtrW(Msg.hwnd, -16) & 0xF;
          if ( v37 == 9 || v37 == 4 )
          {
            NextDlgGroupItem = GetNextDlgGroupItem(DialogIndirectParamW, Msg.hwnd, 0);
            GetWindowRect(Msg.hwnd, &Rect);
            GetWindowRect(NextDlgGroupItem, &v69);
            if ( Rect.top < v69.top )
            {
              v36 = NextDlgGroupItem;
              goto LABEL_58;
            }
          }
          break;
        case '&':
          if ( !GetDlgCtrlID(Msg.hwnd) )
            goto LABEL_37;
          v39 = GetWindowLongPtrW(Msg.hwnd, -16) & 0xF;
          if ( v39 == 9 || v39 == 4 )
          {
            v40 = GetNextDlgGroupItem(DialogIndirectParamW, Msg.hwnd, 1);
            v41 = Msg.hwnd;
            v42 = v40;
            GetWindowRect(v40, &v63);
            GetWindowRect(v41, &v65);
            if ( v63.top < v65.top )
              goto LABEL_57;
          }
          break;
        case '%':
        case '\'':
          if ( GetDlgCtrlID(Msg.hwnd) )
          {
            if ( !(unsigned __int8)DialogHelper::DialogBoxMCE_::_2_::LocalScope::IsPushButton(Msg.hwnd) )
              goto LABEL_59;
            NextDlgTabItem = GetNextDlgTabItem(DialogIndirectParamW, Msg.hwnd, !DialogHelper::m_bRTL);
            v42 = NextDlgTabItem;
            if ( Msg.wParam != 37
              || (v44 = Msg.hwnd, GetWindowRect(NextDlgTabItem, &v70), GetWindowRect(v44, &v67), v70.left >= v67.left) )
            {
              v42 = GetNextDlgTabItem(DialogIndirectParamW, Msg.hwnd, DialogHelper::m_bRTL);
              wParam = Msg.wParam;
              if ( Msg.wParam != 39 )
                goto LABEL_60;
              v45 = Msg.hwnd;
              GetWindowRect(v42, &v66);
              GetWindowRect(v45, &v64);
              if ( v66.left <= v64.left )
              {
LABEL_59:
                wParam = Msg.wParam;
LABEL_60:
                if ( wParam == 37 || wParam == 39 )
                {
                  Focus = GetFocus();
                  if ( !(unsigned __int8)DialogHelper::DialogBoxMCE_::_2_::LocalScope::IsRadioButton(Focus)
                    && !(unsigned __int8)DialogHelper::DialogBoxMCE_::_2_::LocalScope::IsCheckBox(Focus) )
                  {
                    wParam = Msg.wParam;
                    goto LABEL_65;
                  }
                  v55 = DialogIndirectParamW;
                  if ( Msg.wParam == 37 )
                    v54 = 38;
                  else
                    v54 = 40;
                }
                else
                {
LABEL_65:
                  if ( wParam == 37 || wParam == 39 )
                  {
                    v47 = GetFocus();
                    v48 = v47;
                    if ( !v47 )
                      goto LABEL_102;
                    ClassNameW = GetClassNameW(v47, ClassName, 256);
                    v50 = ClassNameW == 0;
                    if ( ClassNameW <= 0 )
                      goto LABEL_102;
                    v51 = ClassName;
                    v52 = L"msctls_trackbar32";
                    v53 = 18;
                    do
                    {
                      if ( !v53 )
                        break;
                      v50 = *v51++ == *v52++;
                      --v53;
                    }
                    while ( v50 );
                    if ( !v50 )
                      goto LABEL_102;
                    if ( DialogHelper::m_bRTL )
                      InvalidateRect(v48, 0, 0);
                    wParam = Msg.wParam;
                  }
                  if ( wParam == 166 )
                  {
                    if ( !GetDlgCtrlID(Msg.hwnd) )
                      SetFocus(DialogIndirectParamW);
                    v54 = 27;
                  }
                  else
                  {
                    if ( wParam != 13 )
                      goto LABEL_100;
                    if ( byte_1000B1CDA )
                    {
                      byte_1000B1CDA = 0;
LABEL_100:
                      if ( !IsDialogMessageW(DialogIndirectParamW, &Msg) )
                      {
                        TranslateMessage(&Msg);
                        DispatchMessageW(&Msg);
                      }
                      goto LABEL_102;
                    }
                    v54 = 32;
                  }
                  v55 = DialogIndirectParamW;
                }
                FakeKeyPress(v55, v54, 0, 0, 0, 0);
                goto LABEL_102;
              }
            }
LABEL_57:
            v36 = v42;
          }
          else
          {
LABEL_37:
            v36 = DialogIndirectParamW;
          }
LABEL_58:
          SetFocus(v36);
          goto LABEL_102;
        default:
          goto LABEL_60;
      }
      DialogHelper::DialogBoxMCE_::_2_::LocalScope::FakeTab(DialogIndirectParamW);
LABEL_102:
      MessageW = GetMessageW(&Msg, 0, 0, 0);
      if ( !MessageW )
        goto LABEL_105;
    }
  }
  EnableWindow(v8, 1);
  DestroyWindow(DialogIndirectParamW);
  pRawInputDevices.hwndTarget = v8;
  RegisterRawInputDevices(&pRawInputDevices, 1u, 0x10u);
  if ( DialogHelper::m_Background )
    (**(void (__fastcall ***)(struct Image *, __int64))DialogHelper::m_Background)(DialogHelper::m_Background, 1);
  result = LOWORD(Msg.wParam);
  DialogHelper::m_Background = 0;
  return result;
}
