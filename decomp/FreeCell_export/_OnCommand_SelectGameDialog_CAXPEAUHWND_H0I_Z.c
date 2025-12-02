void __fastcall SelectGameDialog::OnCommand(HWND hWnd, int a2, HWND a3, int a4)
{
  int v4; // edx
  int v6; // edx
  HWND v7; // rax
  HWND v8; // rax
  HWND DlgItem; // rax
  int v10; // ebp
  FreeCellGame *v11; // rcx
  FreeCellGame *v12; // rbx
  __int64 v13; // rax
  int v14; // [rsp+20h] [rbp-28h]
  bool v15[4]; // [rsp+30h] [rbp-18h] BYREF
  int v16[5]; // [rsp+34h] [rbp-14h] BYREF
  bool v17; // [rsp+58h] [rbp+10h] BYREF

  v4 = a2 - 1;
  if ( !v4 )
  {
    DlgItem = GetDlgItem(hWnd, 1016);
    if ( !DialogHelper::m_bIsMediaCenter )
      SendMessageW(DlgItem, 0x1504u, 0, 0);
    v16[0] = 0;
    v17 = 0;
    v15[0] = 0;
    SelectGameDialog::GetIntFromEditControl(hWnd, 1016, v16, &v17, v15);
    if ( v17 )
      goto LABEL_8;
    if ( v15[0] )
      goto LABEL_8;
    v10 = v16[0];
    if ( v16[0] > 1000000 )
      goto LABEL_8;
    v11 = g_pFreeCellGame;
    if ( SelectGameDialog::RecordAsLossOnNewGame
      && *((_BYTE *)g_pFreeCellGame + 376)
      && *((_DWORD *)g_pFreeCellGame + 2) != 3 )
    {
      FreeCellGame::RecordCurrentGameAsLoss(g_pFreeCellGame);
      v11 = g_pFreeCellGame;
    }
    *(_DWORD *)(*((_QWORD *)v11 + 12) + 12LL) = v10;
    FreeCellGame::UpdateUI(v11, 1);
    v12 = g_pFreeCellGame;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
      g_pFreeCellGame,
      *((unsigned int *)g_pFreeCellGame + 2));
    v13 = *(_QWORD *)v12;
    *((_DWORD *)v12 + 3) = *((_DWORD *)v12 + 2);
    *((_DWORD *)v12 + 2) = 0;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(v13 + 8))(v12, 0);
LABEL_22:
    DialogHelper::DismissDialog(hWnd, 0, (int)a3);
    return;
  }
  v6 = v4 - 1;
  if ( !v6 )
  {
    if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
      FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
    goto LABEL_22;
  }
  if ( v6 == 1014 && a4 == 768 )
  {
    v7 = GetDlgItem(hWnd, 1016);
    if ( !DialogHelper::m_bIsMediaCenter )
      SendMessageW(v7, 0x1504u, 0, 0);
    v16[0] = 0;
    v17 = 0;
    v15[0] = 0;
    SelectGameDialog::GetIntFromEditControl(hWnd, 1016, v16, &v17, v15);
    if ( v17 )
    {
LABEL_8:
      v8 = GetDlgItem(hWnd, 1016);
      DialogHelper::ShowEditBalloonTip(v8, (HWND)0xE313, 0xE312u, 3u, v14);
    }
  }
}
