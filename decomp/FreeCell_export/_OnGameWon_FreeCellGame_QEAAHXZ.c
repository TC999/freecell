__int64 __fastcall FreeCellGame::OnGameWon(FreeCellGame *this)
{
  unsigned int v1; // ebx
  int v3; // esi
  char v4; // al
  __int64 v6; // [rsp+38h] [rbp-10h]

  v1 = 0;
  if ( *((_BYTE *)this + 375) )
  {
    v3 = 1047;
  }
  else
  {
    v4 = (char)g_bMediaCenter;
    if ( (_BYTE)g_bMediaCenter && g_bMouseHidden )
    {
      g_bMouseHidden = 0;
      ShowCursor(1);
      v4 = (char)g_bMediaCenter;
    }
    v3 = DialogHelper::DialogBoxMCE(
           (LPCWSTR)(v4 != 0 ? 128LL : 109LL),
           g_hWnd,
           (HWND)WonDialog::DialogProc,
           (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
           0,
           56,
           0,
           v6);
    if ( (_BYTE)g_bMediaCenter && !g_bMouseHidden )
    {
      g_bMouseHidden = 1;
      ShowCursor(0);
    }
  }
  FreeCellGame::RemoveGameData(this);
  FreeCellGame::SaveGeneralData(g_pFreeCellGame);
  if ( v3 == 1045 )
  {
    PostMessageW(g_hWnd, 0x10u, 0, 0);
    return 5;
  }
  else
  {
    FreeCellGame::SetRandomGameNumber(g_pFreeCellGame);
  }
  return v1;
}
