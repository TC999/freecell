char __fastcall FreeCellGame::OnCardDoubleClick(CardTable **this, const unsigned __int16 **a2)
{
  const unsigned __int16 **v2; // r14
  struct CardStack *CardStackWithCard; // rax
  struct CardStack *v5; // r13
  int v6; // ecx
  const wchar_t *v7; // rsi
  const unsigned __int16 **v8; // rdi
  struct Card *v9; // rdx
  struct CardStack *v10; // rax
  unsigned int v11; // esi
  __int64 v12; // rdi
  CardTable *v13; // rcx
  char *v14; // rdx
  int v16; // eax
  __int64 v17; // rsi
  char v18; // r15
  unsigned int RankForType; // eax
  unsigned int v20; // ecx
  unsigned int SuitForType; // eax
  int v22; // r11d
  bool v23; // zf
  bool v24; // sf
  __int64 v25; // rdi
  int v26; // r13d
  CardTable *v27; // rcx
  int v28; // r12d
  __int64 v29; // rbp
  unsigned int v30; // eax
  unsigned int v31; // eax
  int v32; // ebp
  int v33; // edi
  __int64 v34; // rdx
  unsigned int v35; // eax
  unsigned int v36; // eax
  char *v37; // rdi
  unsigned int v38; // r12d
  unsigned int v39; // ebp
  CardTable *v40; // rcx
  CardTable *v41; // r15
  unsigned int i; // ebp
  CardTable *v43; // rcx
  CardTable *v44; // r15
  char v45; // dl
  _BYTE v46[120]; // [rsp+20h] [rbp-78h] BYREF
  unsigned int v47; // [rsp+A0h] [rbp+8h] BYREF
  unsigned int v48; // [rsp+A8h] [rbp+10h]
  __int64 v49; // [rsp+B0h] [rbp+18h]
  struct CardStack *v50; // [rsp+B8h] [rbp+20h]

  v2 = a2;
  CardStackWithCard = CardTable::GetCardStackWithCard(this[22], a2[7]);
  v5 = CardStackWithCard;
  v50 = CardStackWithCard;
  if ( CardStackWithCard )
  {
    v6 = *((_DWORD *)CardStackWithCard + 76);
    if ( v6 )
    {
      v7 = (const wchar_t *)*((_QWORD *)CardStackWithCard + 36);
      v8 = *(const unsigned __int16 ***)(*((_QWORD *)CardStackWithCard + 40) + 8LL * (unsigned int)(v6 - 1));
      if ( v8 == v2 )
        goto LABEL_8;
      v9 = this[38];
      if ( !v9 || (v10 = CardTable::GetCardStackWithCard(this[22], v9)) == 0 || v10 == v5 )
      {
        v2 = v8;
LABEL_8:
        FreeCellGame::CreateHints((FreeCellGame *)this, 1);
        if ( !wcsncmp(v7, L"FreeCell", 7u) )
        {
          v11 = 0;
          if ( *((_DWORD *)this + 70) )
          {
            v12 = 0;
            while ( 1 )
            {
              v13 = this[37];
              if ( *(const unsigned __int16 ***)((char *)v13 + v12 + 8) == v2
                && *(struct CardStack **)((char *)v13 + v12) == v5
                && !(unsigned int)FreeCellMove::StackToMoveDestination(*(_QWORD *)((char *)v13 + v12), 0) )
              {
                break;
              }
              ++v11;
              v12 += 56;
              if ( v11 >= *((_DWORD *)this + 70) )
                goto LABEL_85;
            }
            v14 = (char *)this[37] + 56 * v11;
            goto LABEL_17;
          }
          goto LABEL_85;
        }
        v16 = wcsncmp(v7, L"Stack", 5u);
        v17 = 0;
        if ( v16 )
        {
LABEL_85:
          FreeCellGame::PlaySoundW((FreeCellGame *)this, 7u, 0, 0);
          Log(0x10000000u, L"FreeCellGame::OnCardDoubleClick() - Can't double click this card");
          if ( (unsigned int)FreeCellMove::StackToMoveDestination(v5, 0) == 1 && !this[38] && !*((_BYTE *)this[11] + 14) )
            TipManager::ShowTipIfEnabled(this[42], L"NoOpenFreeCells", 0, v45 + 1);
          return 0;
        }
        v18 = 1;
        RankForType = Card::GetRankForType(*((_DWORD *)v2 + 2));
        if ( RankForType == 13 )
          RankForType = 0;
        if ( !RankForType )
        {
LABEL_64:
          v37 = 0;
          v38 = 4;
          if ( v18 )
          {
            v39 = 0;
            if ( *((_DWORD *)this + 70) )
            {
              do
              {
                v40 = this[37];
                if ( *(const unsigned __int16 ***)((char *)v40 + v17 + 8) == v2
                  && *(struct CardStack **)((char *)v40 + v17) == v5
                  && (unsigned int)FreeCellMove::StackToMoveDestination(*(_QWORD *)((char *)v40 + v17 + 32), 0) == 2 )
                {
                  v41 = this[37];
                  v47 = 4;
                  FreeCellMove::StackToMoveDestination(*(_QWORD *)((char *)v41 + v17 + 32), &v47);
                  if ( !v37 || v38 > v47 )
                  {
                    v38 = v47;
                    v37 = (char *)v41 + 56 * v39;
                  }
                }
                ++v39;
                v17 += 56;
              }
              while ( v39 < *((_DWORD *)this + 70) );
              v17 = 0;
              if ( v37 )
                goto LABEL_74;
            }
          }
          for ( i = 0; i < *((_DWORD *)this + 70); v17 += 56 )
          {
            v43 = this[37];
            if ( *(const unsigned __int16 ***)((char *)v43 + v17 + 8) == v2
              && *(struct CardStack **)((char *)v43 + v17) == v5
              && !(unsigned int)FreeCellMove::StackToMoveDestination(*(_QWORD *)((char *)v43 + v17 + 32), 0) )
            {
              v44 = this[37];
              v47 = 4;
              FreeCellMove::StackToMoveDestination(*(_QWORD *)((char *)v44 + v17 + 32), &v47);
              if ( !v37 || v38 > v47 )
              {
                v38 = v47;
                v37 = (char *)v44 + 56 * i;
              }
            }
            ++i;
          }
          if ( v37 )
          {
LABEL_74:
            v14 = v37;
LABEL_17:
            memcpy(v46, v14, 0x28u);
            FreeCellMove::PerformMove(v46);
            FreeCellGame::invalidateHints((FreeCellGame *)this);
            return 1;
          }
          goto LABEL_85;
        }
        v20 = *((_DWORD *)v2 + 2);
        v48 = RankForType - 1;
        SuitForType = Card::GetSuitForType(v20);
        if ( SuitForType && SuitForType != 2 )
        {
          if ( SuitForType == 1 || SuitForType == 3 )
          {
            v22 = 1;
            goto LABEL_28;
          }
          Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
        }
        v22 = 0;
LABEL_28:
        v23 = *((_DWORD *)this + 46) == 0;
        v24 = *((int *)this + 46) < 0;
        v47 = v22 == 0;
        if ( !v24 && !v23 )
        {
          v25 = 0;
          v26 = 0;
          do
          {
            v27 = this[25];
            v28 = 0;
            if ( *(int *)(*(_QWORD *)((char *)v27 + v25) + 304LL) > 0 )
            {
              v29 = 0;
              while ( 1 )
              {
                v30 = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((char *)v27 + v25) + 320LL)
                                                                 + v29)
                                                     + 8LL));
                if ( v30 && v30 != 2 )
                {
                  if ( v30 == 1 || v30 == 3 )
                    LODWORD(v17) = 1;
                  else
                    Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
                }
                v31 = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)((char *)this[25] + v25)
                                                                             + 320LL)
                                                                 + v29)
                                                     + 8LL));
                if ( v31 == 13 )
                  v31 = 0;
                if ( (_DWORD)v17 == v47 && v31 == v48 )
                  break;
                v27 = this[25];
                ++v28;
                v29 += 8;
                v17 = 0;
                if ( v28 >= *(_DWORD *)(*(_QWORD *)((char *)v27 + v25) + 304LL) )
                  goto LABEL_46;
              }
              v17 = 0;
              v18 = 0;
            }
LABEL_46:
            ++v26;
            v25 += 8;
          }
          while ( ((v26 < *((_DWORD *)this + 46)) & (unsigned __int8)v18) != 0 );
          v5 = v50;
        }
        v32 = 0;
        if ( ((*((_DWORD *)this + 52) > 0) & (unsigned __int8)v18) != 0 )
        {
          v33 = 0;
          while ( 1 )
          {
            v34 = *(_QWORD *)((char *)this[28] + v17);
            if ( *(_DWORD *)(v34 + 304) )
            {
              v49 = *(_QWORD *)(*(_QWORD *)(v34 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v34 + 304) - 1));
              v35 = Card::GetSuitForType(*(_DWORD *)(v49 + 8));
              if ( v35 && v35 != 2 )
              {
                if ( v35 == 1 || v35 == 3 )
                  v33 = 1;
                else
                  Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
              }
              v36 = Card::GetRankForType(*(_DWORD *)(v49 + 8));
              if ( v36 == 13 )
                v36 = 0;
              if ( v33 == v47 && v36 == v48 )
              {
                v17 = 0;
                v18 = 0;
                goto LABEL_64;
              }
              v33 = 0;
            }
            ++v32;
            v17 += 8;
            if ( ((v32 < *((_DWORD *)this + 52)) & (unsigned __int8)v18) == 0 )
            {
              v17 = 0;
              goto LABEL_64;
            }
          }
        }
        goto LABEL_64;
      }
    }
  }
  return 0;
}
