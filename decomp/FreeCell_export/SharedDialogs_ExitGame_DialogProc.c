__int64 __fastcall SharedDialogs::ExitGame::DialogProc(HWND a1, int a2, unsigned __int16 a3)
{
  HWND v3; // rdx

  v3 = (HWND)(unsigned int)(a2 - 272);
  if ( (_DWORD)v3 )
  {
    if ( (_DWORD)v3 != 1 )
      return 0;
    if ( a3 == 2 || a3 > 0x138Cu && a3 <= 0x138Eu )
      DialogHelper::DismissDialog(a1, (HWND)a3, a3);
  }
  else
  {
    DialogHelper::CenterDialog(a1, v3);
  }
  return 1;
}
