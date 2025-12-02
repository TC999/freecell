__int64 __fastcall SelectGameDialog::DialogProc(HWND hWnd, int a2, int a3, HWND a4)
{
  HWND v4; // rdx
  UINT v7; // ebx
  __int64 v8; // rax

  v4 = (HWND)(unsigned int)(a2 - 272);
  if ( (_DWORD)v4 )
  {
    if ( (_DWORD)v4 != 1 )
      return 0;
    SelectGameDialog::OnCommand(hWnd, (unsigned __int16)a3, a4, HIWORD(a3));
  }
  else
  {
    DialogHelper::CenterDialog(hWnd, v4);
    TipManager::HideTip(*((TipManager **)g_pFreeCellGame + 42), 0);
    v7 = 0;
    SendDlgItemMessageW(hWnd, 1016, 0xC5u, 7u, 0);
    v8 = *((_QWORD *)g_pFreeCellGame + 12);
    if ( v8 )
      v7 = *(_DWORD *)(v8 + 12);
    SetDlgItemInt(hWnd, 1016, v7, 1);
  }
  return 1;
}
