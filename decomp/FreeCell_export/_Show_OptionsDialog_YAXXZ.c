void __fastcall OptionsDialog::Show(OptionsDialog *this, __int64 a2, unsigned int a3)
{
  __int64 v3; // [rsp+38h] [rbp-10h]

  qword_1000AE8C0 = 0;
  qword_1000AE8B8 = 0;
  qword_1000AE8B0 = 0;
  qword_1000AE8A8 = 0;
  hWnd = 0;
  qword_1000AE898 = 0;
  qword_1000AE880 = 0;
  qword_1000AE878 = 0;
  qword_1000AE890 = 0;
  qword_1000AE888 = 0;
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    GameAudio::StopSound((GameAudio *)3, 0, a3);
  DialogHelper::DialogBoxMCE(
    (LPCWSTR)((_BYTE)g_bMediaCenter != 0 ? 126LL : 104LL),
    g_hWnd,
    (HWND)OptionsDialog::DialogProc,
    (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))0x3FE,
    1,
    56,
    0,
    v3);
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
}
