void __fastcall StatisticsDialog::Show(StatisticsDialog *this, __int64 a2, unsigned int a3)
{
  __int64 v3; // [rsp+38h] [rbp-10h]

  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    GameAudio::StopSound((GameAudio *)3, 0, a3);
  if ( (_BYTE)g_bMediaCenter && g_bMouseHidden )
  {
    g_bMouseHidden = 0;
    ShowCursor(1);
  }
  DialogHelper::DialogBoxMCE(
    (LPCWSTR)0x69,
    g_hWnd,
    (HWND)StatisticsDialog::DialogProc,
    (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
    0,
    0,
    0,
    v3);
  if ( (_BYTE)g_bMediaCenter && !g_bMouseHidden )
  {
    g_bMouseHidden = 1;
    ShowCursor(0);
  }
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
}
