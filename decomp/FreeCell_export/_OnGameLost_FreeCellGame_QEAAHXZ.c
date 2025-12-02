__int64 __fastcall FreeCellGame::OnGameLost(FreeCellGame *this)
{
  unsigned int v1; // ebx
  int v3; // edi
  char v4; // al
  int v5; // edi
  __int64 v7; // [rsp+38h] [rbp-10h]

  v1 = 0;
  if ( *((_BYTE *)this + 376) && *((_DWORD *)this + 2) != 3 )
    FreeCellGame::RecordCurrentGameAsLoss(this);
  FreeCellGame::RemoveGameData(this);
  FreeCellGame::SaveGeneralData(g_pFreeCellGame);
  if ( *((_BYTE *)this + 375) )
  {
    v3 = 1041;
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
           (LPCWSTR)(v4 != 0 ? 127LL : 108LL),
           g_hWnd,
           (HWND)LoseDialog::DialogProc,
           (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
           0,
           56,
           0,
           v7);
    if ( (_BYTE)g_bMediaCenter && !g_bMouseHidden )
    {
      g_bMouseHidden = 1;
      ShowCursor(0);
    }
  }
  v5 = v3 - 1031;
  if ( v5 )
  {
    if ( v5 == 5 )
    {
      PostMessageW(g_hWnd, 0x10u, 0, 0);
      return 5;
    }
    else
    {
      FreeCellGame::SetRandomGameNumber(g_pFreeCellGame);
    }
  }
  return v1;
}
