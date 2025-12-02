void __fastcall FreeCellGame::OnCardStackClicked(FreeCellGame *this, struct CardStack *a2)
{
  const unsigned __int16 **v2; // rbx
  struct CardStack *v3; // rbp
  FreeCellGame *v4; // r13
  struct CardStack *CardStackWithCard; // rdi
  bool v6; // zf
  bool v7; // dl
  unsigned int v8; // r12d
  const unsigned __int16 **v9; // rsi
  int v10; // eax
  unsigned int v11; // r15d
  bool v12; // cc
  signed int v13; // r13d
  struct Card *v14; // rsi
  __int64 v15; // r12
  char v16; // bp
  __int64 v17; // rax
  struct Card *v18; // r14
  int v19; // r12d
  int v20; // r12d
  unsigned int CardLocation; // ebx
  CardStack *v22; // rbx
  unsigned int HighestPlaceableCardIndex; // eax
  unsigned int v24; // [rsp+28h] [rbp-120h]
  _BYTE v25[224]; // [rsp+30h] [rbp-118h] BYREF

  v2 = (const unsigned __int16 **)*((_QWORD *)this + 38);
  v3 = a2;
  v4 = this;
  if ( !v2 )
    return;
  CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 22), v2[7]);
  if ( !CardStackWithCard )
    return;
  v6 = *((_DWORD *)v3 + 76) == 0;
  if ( !*((_DWORD *)v3 + 76) )
  {
    if ( (unsigned int)FreeCellMove::StackToMoveDestination(v3, 0) == 1 )
    {
      v8 = *((_DWORD *)CardStackWithCard + 76);
      v9 = *(const unsigned __int16 ***)(*((_QWORD *)CardStackWithCard + 40) + 8LL * (v8 - 1));
      if ( v9 == v2 )
      {
        v10 = FreeCellMove::MaxMove(1, v7);
        if ( v10 <= 1 || v8 <= 1 )
        {
          v2 = v9;
        }
        else
        {
          v11 = v8;
          v12 = (int)v8 <= v10;
          v13 = v8 - 1;
          v14 = 0;
          v15 = (int)(v8 - 1);
          if ( !v12 )
            v11 = v10;
          v16 = 0;
          do
          {
            if ( v13 < (int)(*((_DWORD *)CardStackWithCard + 76) - v11) || v15 < 0 )
              break;
            v17 = *((_QWORD *)CardStackWithCard + 40);
            v18 = *(struct Card **)(v17 + 8 * v15);
            if ( !v14 || FreeCellMove::DoesCardFollowSequence(*(struct Card **)(v17 + 8 * v15), v14) )
              v14 = v18;
            else
              v16 = 1;
            --v13;
            --v15;
          }
          while ( !v16 );
          v3 = a2;
          if ( v14 )
          {
            if ( v14 != (struct Card *)v2 )
            {
              *(_DWORD *)&v25[64] = 160;
              memset(&v25[68], 0, 0x9Cu);
              *(_DWORD *)&v25[16] = -1;
              *(_QWORD *)&v25[128] = &v25[16];
              *(_DWORD *)&v25[84] = 24;
              *(_DWORD *)&v25[136] = 1078;
              *(_DWORD *)v25 = 1078;
              *(_QWORD *)&v25[92] = 58132;
              *(_QWORD *)&v25[108] = 58133;
              *(_QWORD *)&v25[20] = 58134;
              *(_DWORD *)&v25[28] = -2;
              *(_QWORD *)&v25[32] = 58135;
              *(_DWORD *)&v25[40] = 2;
              *(_QWORD *)&v25[44] = 58136;
              *(_DWORD *)&v25[124] = 3;
              *(_QWORD *)&v25[4] = 0x200000435LL;
              LOWORD(v24) = (_BYTE)g_bMediaCenter != 0 ? 132 : 125;
              v19 = DialogHelper::ShowDialog(
                      (DialogHelper *)&v25[64],
                      (struct _TASKDIALOGCONFIG *)v25,
                      3u,
                      (unsigned int *const)0x438,
                      0,
                      v24,
                      *(bool **)v25);
              Engine_ResetTimer();
              v20 = v19 - 1077;
              if ( v20 )
              {
                if ( v20 != 1 )
                  return;
                v2 = (const unsigned __int16 **)v14;
              }
            }
          }
          v4 = this;
        }
        goto LABEL_24;
      }
    }
    v6 = *((_DWORD *)v3 + 76) == 0;
  }
  if ( !v6 && (unsigned int)FreeCellMove::StackToMoveDestination(v3, 0) != 2 )
  {
    HighestPlaceableCardIndex = FreeCellMove::GetHighestPlaceableCardIndex(
                                  CardStackWithCard,
                                  *(struct Card **)(*((_QWORD *)v3 + 40) + 8LL
                                                                         * (unsigned int)(*((_DWORD *)v3 + 76) - 1)));
    if ( HighestPlaceableCardIndex != -1 )
      v2 = *(const unsigned __int16 ***)(*((_QWORD *)CardStackWithCard + 40) + 8LL * HighestPlaceableCardIndex);
  }
LABEL_24:
  if ( FreeCellMove::CanMoveCard((struct Card *)v2, CardStackWithCard, 1, 0, 0) )
  {
    CardTable::ClearHintAnimations(*((CardTable **)v4 + 22));
    CardLocation = CardStack::GetCardLocation(CardStackWithCard, (struct Card *)v2);
    FreeCellGame::SetSelectedCard(g_pFreeCellGame, 0, 1, 1, 1);
    v22 = CardStack::Split(CardStackWithCard, CardLocation, L"MoveStack");
    CardStack::Arrange(CardStackWithCard, 0, 0);
    CardStack::Arrange(v22, 0, 0);
    if ( FreeCellMove::CanFinishMove(v22, v3) )
      FreeCellMove::FinishMove(v22, v3, CardStackWithCard);
    else
      FreeCellMove::CancelCurrentMove();
  }
}
