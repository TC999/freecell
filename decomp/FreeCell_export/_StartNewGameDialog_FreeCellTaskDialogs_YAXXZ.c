void __fastcall FreeCellTaskDialogs::StartNewGameDialog(FreeCellTaskDialogs *this)
{
  __int64 v1; // rdx
  unsigned int v2; // r8d
  FreeCellGame *v3; // rbx
  bool v4; // zf
  int v5; // ecx
  __int16 v6; // ax
  __int64 v7; // r9
  int v8; // eax
  int v9; // ecx
  __int64 v10; // rcx
  __int64 v11; // rax
  unsigned int v12; // [rsp+28h] [rbp-F0h]
  _BYTE v13[224]; // [rsp+30h] [rbp-E8h] BYREF

  *(_DWORD *)&v13[64] = 160;
  memset(&v13[68], 0, 0x9Cu);
  v3 = g_pFreeCellGame;
  v4 = *((_BYTE *)g_pFreeCellGame + 376) == 0;
  *(_DWORD *)&v13[84] = 24;
  *(_QWORD *)&v13[92] = 58128;
  *(_QWORD *)&v13[108] = 58114;
  v5 = 1057;
  if ( !v4 )
  {
    *(_DWORD *)&v13[136] = 1057;
    *(_DWORD *)v13 = 1057;
    *(_QWORD *)&v13[128] = &v13[16];
    *(_QWORD *)&v13[20] = 58123;
    *(_DWORD *)&v13[28] = -2;
    *(_QWORD *)&v13[32] = 58126;
    *(_DWORD *)&v13[40] = -3;
    *(_QWORD *)&v13[44] = 58127;
    *(_DWORD *)&v13[52] = 2;
    *(_QWORD *)&v13[56] = 58113;
    *(_DWORD *)&v13[124] = 4;
    *(_QWORD *)&v13[4] = 0x42300000420LL;
    *(_QWORD *)&v13[12] = 0xFFFFFFFF00000002uLL;
    if ( (_BYTE)g_bMediaCenter )
    {
      v6 = 131;
      v7 = 1080;
    }
    else
    {
      v6 = 115;
      v7 = 0;
    }
    LOWORD(v12) = v6;
    v8 = DialogHelper::ShowDialog(
           (DialogHelper *)&v13[64],
           (struct _TASKDIALOGCONFIG *)v13,
           4u,
           (unsigned int *const)v7,
           0,
           v12,
           *(bool **)v13);
    v3 = g_pFreeCellGame;
    v5 = v8;
  }
  v9 = v5 - 1056;
  if ( !v9 )
  {
    if ( !*((_BYTE *)v3 + 376) || *((_DWORD *)v3 + 2) == 3 )
      goto LABEL_18;
    FreeCellGame::RecordCurrentGameAsLoss(v3);
LABEL_17:
    v3 = g_pFreeCellGame;
LABEL_18:
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)v3 + 16LL))(v3, *((unsigned int *)v3 + 2));
    v11 = *(_QWORD *)v3;
    *((_DWORD *)v3 + 3) = *((_DWORD *)v3 + 2);
    *((_DWORD *)v3 + 2) = 0;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(v11 + 8))(v3, 0);
    return;
  }
  v10 = (unsigned int)(v9 - 1);
  if ( !(_DWORD)v10 )
  {
    if ( *((_BYTE *)v3 + 376) && *((_DWORD *)v3 + 2) != 3 )
    {
      FreeCellGame::RecordCurrentGameAsLoss(v3);
      v3 = g_pFreeCellGame;
    }
    FreeCellGame::SetRandomGameNumber(v3);
    goto LABEL_17;
  }
  if ( (_DWORD)v10 == 2 )
  {
    SelectGameDialog::RecordAsLossOnNewGame = 1;
    SelectGameDialog::Show(v10, v1, v2);
  }
}
