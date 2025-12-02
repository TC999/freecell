void __fastcall OptionsDialog::OnCommand(HWND hWnd, int a2, int a3)
{
  int v3; // edx
  HWND v4; // rbx
  int v5; // edx
  int v6; // edx
  BOOL v7; // ebx
  HWND v8; // rcx

  v3 = a2 - 1;
  v4 = hWnd;
  if ( !v3 )
  {
    OptionsDialog::OnOkButton(hWnd);
    hWnd = v4;
    goto LABEL_10;
  }
  v5 = v3 - 1;
  if ( !v5 )
  {
LABEL_10:
    DialogHelper::DismissDialog(hWnd, 0, a3);
    return;
  }
  v6 = v5 - 1007;
  if ( !v6 || v6 == 6 )
  {
    v7 = SendMessageW(qword_1000AE880, 0xF0u, 0, 0) != 1;
    SendMessageW(qword_1000AE880, 0xF1u, 0, 0);
    SendMessageW(qword_1000AE878, 0xF1u, 0, 0);
    if ( v7 )
      v8 = qword_1000AE878;
    else
      v8 = qword_1000AE880;
    SendMessageW(v8, 0xF1u, 1u, 0);
  }
}
