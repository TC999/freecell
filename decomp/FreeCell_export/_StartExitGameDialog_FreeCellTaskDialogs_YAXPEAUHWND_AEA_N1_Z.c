void __fastcall FreeCellTaskDialogs::StartExitGameDialog(FreeCellTaskDialogs *this, _BYTE *a2, bool *a3, bool *a4)
{
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // ebx
  FreeCellGame *v10; // rcx
  unsigned int v11; // [rsp+28h] [rbp-100h]
  bool *v12; // [rsp+30h] [rbp-F8h]
  __int64 v13; // [rsp+38h] [rbp-F0h]
  _BYTE v14[224]; // [rsp+40h] [rbp-E8h] BYREF

  *(_DWORD *)&v14[64] = 160;
  memset(&v14[68], 0, 0x9Cu);
  *(_DWORD *)&v14[16] = -1;
  v6 = 3;
  *(_DWORD *)&v14[84] = 8;
  *(_QWORD *)&v14[128] = &v14[16];
  *(_QWORD *)&v14[92] = 6001;
  *(_QWORD *)&v14[108] = 6002;
  *(_QWORD *)&v14[20] = 6003;
  *(_DWORD *)&v14[28] = -2;
  *(_DWORD *)&v14[136] = 5005;
  *(_DWORD *)v14 = 5005;
  *(_QWORD *)&v14[32] = 6004;
  *(_DWORD *)&v14[40] = 2;
  *(_QWORD *)&v14[44] = 6005;
  *(_DWORD *)&v14[124] = 3;
  *(_QWORD *)&v14[4] = 0x20000138ELL;
  if ( (_BYTE)g_bMediaCenter )
  {
    v7 = DialogHelper::DialogBoxMCE(
           (LPCWSTR)0x1F9,
           g_hWnd,
           (HWND)SharedDialogs::ExitGame::DialogProc,
           (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
           0,
           139,
           0,
           v13);
  }
  else
  {
    LOWORD(v11) = 501;
    v7 = DialogHelper::ShowDialog((DialogHelper *)&v14[64], (struct _TASKDIALOGCONFIG *)v14, 3u, 0, 0, v11, v12);
  }
  if ( v7 != 2 )
    v6 = (v7 == 5006) + 1;
  v8 = v6 - 1;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 != 1 )
        return;
      *a2 = 0;
    }
    else
    {
      *a2 = 1;
    }
    *a3 = 0;
  }
  else
  {
    v10 = g_pFreeCellGame;
    *a2 = 1;
    *a3 = 1;
    if ( FreeCellGame::GameDataExists(v10) )
      FreeCellGame::RemoveGameData(g_pFreeCellGame);
  }
}
