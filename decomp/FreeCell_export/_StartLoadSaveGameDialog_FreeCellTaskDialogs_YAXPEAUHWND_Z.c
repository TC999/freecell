void __fastcall FreeCellTaskDialogs::StartLoadSaveGameDialog(FreeCellTaskDialogs *this, HWND a2)
{
  int v2; // eax
  char v3; // cl
  bool v4; // bl
  FreeCellGame *v5; // rcx
  FreeCellGame *v6; // rbx
  int v7; // r11d
  __int64 v8; // rdx
  __int64 v9; // rax
  unsigned int v10; // [rsp+28h] [rbp-E0h]
  bool *v11; // [rsp+30h] [rbp-D8h]
  unsigned __int16 *v12; // [rsp+30h] [rbp-D8h]
  __int64 v13; // [rsp+38h] [rbp-D0h]
  int v14; // [rsp+40h] [rbp-C8h] BYREF
  __int64 v15; // [rsp+44h] [rbp-C4h]
  int v16; // [rsp+4Ch] [rbp-BCh]
  __int64 v17; // [rsp+50h] [rbp-B8h]
  _QWORD v18[21]; // [rsp+60h] [rbp-A8h] BYREF
  WCHAR Caption; // [rsp+118h] [rbp+10h] BYREF
  int v20; // [rsp+120h] [rbp+18h] BYREF
  int v21; // [rsp+124h] [rbp+1Ch]

  LOBYTE(Caption) = 0;
  LODWORD(v18[0]) = 160;
  memset((char *)v18 + 4, 0, 0x9Cu);
  HIDWORD(v18[2]) = 8;
  *(_QWORD *)((char *)&v18[3] + 4) = 6006;
  *(_QWORD *)((char *)&v18[5] + 4) = 6007;
  v18[8] = &v14;
  *(_QWORD *)((char *)&v18[11] + 4) = 6023;
  v14 = 1;
  v15 = 6008;
  v16 = 2;
  v17 = 6009;
  HIDWORD(v18[7]) = 2;
  LODWORD(v18[9]) = 1;
  v20 = 1;
  v21 = 2;
  if ( (_BYTE)g_bMediaCenter )
  {
    v2 = DialogHelper::DialogBoxMCE(
           (LPCWSTR)0x1FA,
           g_hWnd,
           (HWND)&SharedDialogs::LoadGame::DialogProc,
           (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
           0,
           139,
           0,
           v13);
    v3 = byte_1000B111E;
  }
  else
  {
    LOWORD(v10) = 502;
    v2 = DialogHelper::ShowDialog(
           (DialogHelper *)v18,
           (struct _TASKDIALOGCONFIG *)&v20,
           2u,
           0,
           (unsigned int)&Caption,
           v10,
           v11);
    v3 = Caption;
  }
  v4 = v2 == 1;
  if ( v3 )
  {
    v5 = g_pFreeCellGame;
    *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 13LL) = 1;
    FreeCellGame::SaveGeneralData(v5);
  }
  if ( !v4 )
  {
    FreeCellGame::RemoveGameData(g_pFreeCellGame);
    FreeCellGame::SaveGeneralData(g_pFreeCellGame);
    FreeCellGame::RecordCurrentGameAsLoss(g_pFreeCellGame);
    goto LABEL_11;
  }
  if ( !FreeCellGame::LoadGameData(g_pFreeCellGame) )
  {
    LOBYTE(v12) = 1;
    DialogHelper::ShowMessageBox(0x1784u, 0x1785u, 1, (const unsigned __int16 *)0xFFFF, 0, 0, v12);
    FreeCellGame::RemoveGameData(g_pFreeCellGame);
LABEL_11:
    FreeCellGame::SetRandomGameNumber(g_pFreeCellGame);
    v6 = g_pFreeCellGame;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
      g_pFreeCellGame,
      *((unsigned int *)g_pFreeCellGame + 2));
    v7 = *((_DWORD *)v6 + 2);
    *((_DWORD *)v6 + 2) = 0;
    v8 = 0;
    goto LABEL_12;
  }
  v6 = g_pFreeCellGame;
  (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
    g_pFreeCellGame,
    *((unsigned int *)g_pFreeCellGame + 2));
  v7 = *((_DWORD *)v6 + 2);
  *((_DWORD *)v6 + 2) = 2;
  v8 = 2;
LABEL_12:
  v9 = *(_QWORD *)v6;
  *((_DWORD *)v6 + 3) = v7;
  (*(void (__fastcall **)(FreeCellGame *, __int64))(v9 + 8))(v6, v8);
}
