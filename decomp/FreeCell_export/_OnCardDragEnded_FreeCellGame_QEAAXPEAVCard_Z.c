// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::OnCardDragEnded(CardTable **this, struct Card *a2)
{
  const unsigned __int16 *v4; // rdx
  struct CardStack *CardStackWithCard; // rax
  CardStack *v6; // rsi
  __int64 v7; // r9
  unsigned __int16 *v8; // rax
  int v9; // r10d
  int v10; // ecx
  struct CardStack *v11; // rbp
  char CardStackIntersect; // al
  void *v13; // rbx
  __int64 v14; // rax
  CardStack **v15; // rcx
  _DWORD v16[4]; // [rsp+38h] [rbp-20h] BYREF
  void *Block; // [rsp+48h] [rbp-10h]

  v4 = (const unsigned __int16 *)*((_QWORD *)a2 + 7);
  if ( v4 )
  {
    CardStackWithCard = CardTable::GetCardStackWithCard(this[22], v4);
    v6 = CardStackWithCard;
    if ( CardStackWithCard )
    {
      v7 = *((_QWORD *)CardStackWithCard + 36);
      if ( v7 )
      {
        v8 = (unsigned __int16 *)*((_QWORD *)CardStackWithCard + 36);
        do
        {
          v9 = *(unsigned __int16 *)((char *)L"DragStack" + (_QWORD)v8 - v7);
          v10 = *v8 - v9;
          if ( v10 )
            break;
          ++v8;
        }
        while ( v9 );
        if ( v10 )
        {
          Log(
            0x10000001u,
            L"FreeCellGame::OnCardDragStarted() - Card should belong to stack named %s, not %s",
            L"DragStack");
        }
        else
        {
          v11 = 0;
          v16[0] = 0;
          v16[1] = 0;
          v16[2] = 16;
          Block = 0;
          CardStackIntersect = CardTable::GetCardStackIntersect(this[22], v16, a2, 20, 10);
          v13 = Block;
          if ( CardStackIntersect )
          {
            v14 = 0;
            v15 = (CardStack **)Block;
            while ( (unsigned int)v14 < v16[0] )
            {
              if ( *v15 != v6 )
              {
                v11 = (struct CardStack *)*((_QWORD *)Block + v14);
                break;
              }
              v14 = (unsigned int)(v14 + 1);
              ++v15;
            }
          }
          CardStack::SetShadow(v6, 0, 0, 0);
          if ( v11 == this[41] )
          {
            FreeCellMove::CancelCurrentMove();
            FreeCellGame::SetSelectedCard((FreeCellGame *)this, a2, 1, 1, 1);
          }
          else if ( v11 && FreeCellMove::CanFinishMove(v6, v11) && FreeCellMove::CanMoveCard(a2, this[41], 1, 0, 0) )
          {
            FreeCellMove::FinishMove(v6, v11, this[41]);
          }
          else
          {
            FreeCellMove::CancelCurrentMove();
            FreeCellGame::SetSelectedCard((FreeCellGame *)this, 0, 1, 1, 1);
          }
          if ( v13 )
            free(v13);
        }
      }
      else
      {
        Log(0x10000001u, L"FreeCellGame::OnCardDragStarted() - Stack is missing a name");
      }
    }
    else
    {
      Log(0x10000001u, L"FreeCellGame::OnCardDragStarted() - Card is not associated with a stack");
    }
  }
  else
  {
    Log(0x10000001u, L"FreeCellGame::OnCardDragStarted() - Card is missing a name");
  }
}
