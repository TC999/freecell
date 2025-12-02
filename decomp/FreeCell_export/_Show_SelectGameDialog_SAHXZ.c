__int64 __fastcall SelectGameDialog::Show(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // ebx
  __int64 v5; // [rsp+38h] [rbp-10h]

  if ( (_BYTE)g_bMediaCenter && g_bMouseHidden )
  {
    g_bMouseHidden = 0;
    ShowCursor(1);
  }
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    GameAudio::StopSound((GameAudio *)3, 0, a3);
  v3 = DialogHelper::DialogBoxMCE(
         (LPCWSTR)((_BYTE)g_bMediaCenter != 0 ? 129LL : 118LL),
         g_hWnd,
         (HWND)SelectGameDialog::DialogProc,
         (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
         0,
         56,
         0,
         v5);
  if ( (_BYTE)g_bMediaCenter && !g_bMouseHidden )
  {
    g_bMouseHidden = 1;
    ShowCursor(0);
  }
  return v3;
}
