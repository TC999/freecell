char __fastcall FreeCellGame::OnGameClose(FreeCellGame *this)
{
  FreeCellGame *v1; // rbx
  int v3; // eax
  char unused; // di
  bool *v5; // r9
  __int64 v6; // rcx
  __int64 v7; // rax
  struct HWND__ v8; // [rsp+38h] [rbp+10h] BYREF
  bool v9; // [rsp+40h] [rbp+18h] BYREF

  v1 = g_pFreeCellGame;
  if ( !g_pFreeCellGame )
    return 1;
  v3 = *((_DWORD *)g_pFreeCellGame + 2);
  unused = 1;
  if ( v3 == 1
    || v3 == 3
    || v3 == 4
    || v3 == 5
    || !*((_BYTE *)g_pFreeCellGame + 376)
    || !*(_DWORD *)(*((_QWORD *)g_pFreeCellGame + 22) + 240LL) )
  {
    goto LABEL_24;
  }
  LOBYTE(v8.unused) = 0;
  v9 = 0;
  if ( FreeCellGame::IsGameLost(g_pFreeCellGame) )
    goto LABEL_23;
  if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 15LL) == 1 )
  {
LABEL_13:
    v6 = *((_QWORD *)v1 + 40);
    if ( v6 && g_pUserInterface && *(_QWORD *)(v6 + 96) == *((_QWORD *)g_pUserInterface + 8)
      || (v7 = *((_QWORD *)v1 + 22)) != 0 && *(_DWORD *)(*(_QWORD *)(v7 + 88) + 40LL) )
    {
      FreeCellGame::Undo((CardTable **)v1);
      CardAnimationManager::FinishAllAnimations(*(CardAnimationManager **)(*((_QWORD *)v1 + 22) + 88LL));
    }
    if ( !*((_BYTE *)v1 + 363) )
    {
      if ( *((_BYTE *)v1 + 364) )
        FreeCellGame::RecordCurrentGameAsLoss(v1);
    }
    FreeCellGame::SaveGameData(v1);
    goto LABEL_24;
  }
  FreeCellTaskDialogs::StartExitGameDialog((FreeCellTaskDialogs *)g_hWnd, &v8, &v9, v5);
  unused = v8.unused;
  if ( LOBYTE(v8.unused) )
  {
    if ( v9 )
      goto LABEL_13;
LABEL_23:
    FreeCellGame::RecordCurrentGameAsLoss(v1);
    FreeCellGame::RemoveGameData(v1);
LABEL_24:
    FreeCellGame::SaveGeneralData(v1);
  }
  return unused;
}
