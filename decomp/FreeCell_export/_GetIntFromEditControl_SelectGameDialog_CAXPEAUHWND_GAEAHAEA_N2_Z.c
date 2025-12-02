void __fastcall SelectGameDialog::GetIntFromEditControl(HWND hDlg, __int64 a2, int *a3, bool *a4, bool *a5)
{
  wchar_t v8; // ax
  wchar_t v9; // bp
  int v10; // eax
  int v11; // edx
  __int64 v12; // rcx
  wchar_t v13; // ax
  wchar_t lParam[16]; // [rsp+30h] [rbp-58h] BYREF

  *a4 = 0;
  *a5 = 0;
  v8 = SendDlgItemMessageW(hDlg, 1016, 0xC1u, 0, 0);
  v9 = v8;
  if ( !v8
    || (lParam[0] = v8, SendDlgItemMessageW(hDlg, 1016, 0xC4u, 0, (LPARAM)lParam), lParam[v9] = 0, v9 == 1)
    && lParam[0] == 45 )
  {
    *a5 = 1;
  }
  else
  {
    v10 = wcstol(lParam, 0, 10);
    *a3 = v10;
    if ( v10 && v10 >= -4 )
    {
      v11 = 0;
      v12 = 0;
      if ( !*a4 )
      {
        while ( 1 )
        {
          if ( v11 >= v9 )
            return;
          v13 = lParam[v12];
          if ( v13 != 45 )
            break;
          if ( v12 )
            goto LABEL_13;
LABEL_14:
          ++v11;
          ++v12;
          if ( *a4 )
            return;
        }
        if ( v13 >= 0x30u && v13 <= 0x39u )
          goto LABEL_14;
LABEL_13:
        *a4 = 1;
        goto LABEL_14;
      }
    }
    else
    {
      *a4 = 1;
    }
  }
}
