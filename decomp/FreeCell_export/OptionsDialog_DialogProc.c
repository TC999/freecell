__int64 __fastcall OptionsDialog::DialogProc(HWND hWnd, int a2)
{
  HWND v2; // rdx

  v2 = (HWND)(unsigned int)(a2 - 272);
  if ( (_DWORD)v2 )
  {
    if ( (_DWORD)v2 != 1 )
      return 0;
    OptionsDialog::OnCommand(hWnd);
  }
  else
  {
    OptionsDialog::OnDialogInit(hWnd, v2);
  }
  return 1;
}
