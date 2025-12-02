__int64 __fastcall SharedDialogs::LoadGame::DialogProc(HWND a1, int a2, unsigned __int16 a3, HWND a4)
{
  HWND v4; // rdx

  v4 = (HWND)(unsigned int)(a2 - 272);
  if ( (_DWORD)v4 )
  {
    if ( (_DWORD)v4 != 1 )
      return 0;
    if ( a3 )
    {
      if ( a3 <= 2u )
      {
        DialogHelper::DismissDialog(a1, (HWND)a3, a3);
      }
      else if ( a3 == 5008 )
      {
        byte_1000B111E = (unsigned int)SendMessageW(a4, 0xF0u, 0, 0) == 1;
      }
    }
  }
  else
  {
    DialogHelper::CenterDialog(a1, v4);
  }
  return 1;
}
