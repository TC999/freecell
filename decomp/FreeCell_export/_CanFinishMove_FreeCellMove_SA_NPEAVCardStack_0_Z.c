char __fastcall FreeCellMove::CanFinishMove(struct CardStack *a1, struct CardStack *a2)
{
  FreeCellGame *v4; // rbx
  __int16 v5; // bx
  __int16 v6; // di
  int v8; // eax
  int v9; // edx
  int v10; // edi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  TipManager **v14; // rcx
  unsigned __int16 *v15; // rdx
  unsigned int SuitForType; // ebx
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int RankForType; // ebx
  unsigned int v21; // eax
  int v22; // eax
  unsigned int v23; // eax
  int v24; // ebx
  unsigned int v25; // eax
  int v26; // r11d
  unsigned int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // eax
  bool v30; // zf

  if ( !a1 || !a2 )
  {
    Log(0x10000001u, L"FreeCellMove::CanPlaceSelectedCardOnStack() - Invalid card stack parameters.");
    return 0;
  }
  v4 = g_pFreeCellGame;
  if ( a2 != *((struct CardStack **)g_pFreeCellGame + 41) )
  {
    if ( g_bDebugEnabled )
    {
      v5 = (unsigned __int16)GetKeyState(18) >> 15;
      v6 = v5 & ((unsigned __int16)GetKeyState(17) >> 15);
      if ( ((GetKeyState(16) < 0) & (unsigned __int8)v6) != 0 )
        return 1;
      v4 = g_pFreeCellGame;
    }
    v8 = FreeCellMove::StackToMoveDestination((__int64)a2, 0);
    v10 = v9 + 1;
    if ( !v8 )
    {
      if ( !*((_DWORD *)a2 + 76) )
        return *((_DWORD *)a1 + 76) == v10;
      v30 = *((_DWORD *)a1 + 76) == v10;
      if ( *((_DWORD *)a1 + 76) == v10 )
      {
        if ( !*(_BYTE *)(*((_QWORD *)v4 + 11) + 14LL) )
        {
          TipManager::ShowTipIfEnabled(*((TipManager **)v4 + 42), L"FreeCellOccupied", 0, v10);
          v4 = g_pFreeCellGame;
        }
        v14 = (TipManager **)v4;
        goto LABEL_19;
      }
      return v30;
    }
    v11 = v8 - v10;
    if ( v11 )
    {
      if ( v11 != v10 || *((_DWORD *)a1 + 76) != v10 )
        return 0;
      v12 = *(_DWORD *)(**((_QWORD **)a1 + 40) + 8LL);
      if ( *((_DWORD *)a2 + 76) )
      {
        SuitForType = Card::GetSuitForType(v12);
        if ( SuitForType != Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                                       + 8LL
                                                                       * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                                           + 8LL)) )
        {
          v17 = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                           + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                               + 8LL));
          v14 = (TipManager **)g_pFreeCellGame;
          if ( v17 )
          {
            v18 = v17 - v10;
            if ( v18 )
            {
              v19 = v18 - v10;
              if ( v19 )
              {
                if ( v19 != v10 || *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
                  goto LABEL_19;
                v15 = L"SuitWrongInHomeHearts";
              }
              else
              {
                if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
                  goto LABEL_19;
                v15 = L"SuitWrongInHomeSpades";
              }
            }
            else
            {
              if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
                goto LABEL_19;
              v15 = L"SuitWrongInHomeDiamonds";
            }
          }
          else
          {
            if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
              goto LABEL_19;
            v15 = L"SuitWrongInHomeClubs";
          }
          goto LABEL_18;
        }
        RankForType = Card::GetRankForType(*(_DWORD *)(**((_QWORD **)a1 + 40) + 8LL));
        if ( RankForType == 13 )
          RankForType = 0;
        v21 = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                         + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                             + 8LL));
        if ( v21 == 13 )
          v21 = 0;
        if ( RankForType != v21 + 1 )
        {
          v14 = (TipManager **)g_pFreeCellGame;
          if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
            goto LABEL_19;
          v15 = L"RankWrongInHome";
          goto LABEL_18;
        }
      }
      else
      {
        v13 = Card::GetRankForType(v12);
        if ( v13 == 13 )
          v13 = 0;
        if ( v13 )
        {
          v14 = (TipManager **)g_pFreeCellGame;
          if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
          {
LABEL_19:
            FreeCellGame::PlaySoundW((FreeCellGame *)v14, 7u, 0, 0);
            return 0;
          }
          v15 = L"NonAceInEmptyHome";
LABEL_18:
          TipManager::ShowTipIfEnabled(v14[42], v15, 0, v10);
          v14 = (TipManager **)g_pFreeCellGame;
          goto LABEL_19;
        }
      }
      return v10;
    }
    if ( !*((_DWORD *)a2 + 76) )
    {
      v22 = FreeCellMove::MaxMove((unsigned __int8)v9 + 1, v9);
      if ( *((_DWORD *)a1 + 76) > v22 )
      {
        if ( !*(_BYTE *)(*((_QWORD *)v4 + 11) + 14LL) )
        {
          if ( v22 == v10 )
            TipManager::ShowTipIfEnabled(
              *((TipManager **)v4 + 42),
              L"MoveTooLargeSingular",
              0,
              v10,
              *((_DWORD *)a1 + 76));
          else
            TipManager::ShowTipIfEnabled(*((TipManager **)v4 + 42), L"MoveTooLarge", 0, v10, *((_DWORD *)a1 + 76), v22);
        }
        return 0;
      }
      return v10;
    }
    v23 = Card::GetSuitForType(*(_DWORD *)(**((_QWORD **)a1 + 40) + 8LL));
    if ( v23 && v23 != 2 )
    {
      if ( v23 == v10 || v23 == 3 )
      {
        v24 = v10;
        goto LABEL_53;
      }
      Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
    }
    v24 = 0;
LABEL_53:
    v25 = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                     + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                         + 8LL));
    if ( v25 && v25 != 2 )
    {
      if ( v25 == v10 || v25 == 3 )
      {
        v26 = v10;
LABEL_59:
        if ( v24 == v26 )
        {
          v27 = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                           + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                               + 8LL));
          if ( v27 && v27 != 2 )
          {
            if ( v27 == v10 || v27 == 3 )
            {
              v14 = (TipManager **)g_pFreeCellGame;
              if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
                goto LABEL_19;
              v15 = L"CardColorWrongRed";
              goto LABEL_18;
            }
            Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
          }
          v14 = (TipManager **)g_pFreeCellGame;
          if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
            goto LABEL_19;
          v15 = L"CardColorWrongBlack";
          goto LABEL_18;
        }
        v28 = Card::GetRankForType(*(_DWORD *)(**((_QWORD **)a1 + 40) + 8LL));
        if ( v28 == 13 )
          v28 = 0;
        v29 = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40)
                                                         + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - v10))
                                             + 8LL));
        if ( v29 == 13 )
          v29 = 0;
        if ( v28 + 1 != v29 )
        {
          v14 = (TipManager **)g_pFreeCellGame;
          if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
            goto LABEL_19;
          v15 = L"CardRankWrong";
          goto LABEL_18;
        }
        return v10;
      }
      Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
    }
    v26 = 0;
    goto LABEL_59;
  }
  return 0;
}
