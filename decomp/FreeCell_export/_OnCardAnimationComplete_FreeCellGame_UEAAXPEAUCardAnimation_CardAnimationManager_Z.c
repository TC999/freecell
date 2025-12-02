void __fastcall FreeCellGame::OnCardAnimationComplete(CardTable **this, struct Card **a2)
{
  struct CardStack *CardStackWithCard; // rax
  struct CardStack *v4; // rdi
  int v5; // eax
  __int64 v6; // rcx
  struct CardStack *v7; // rcx

  if ( *((_DWORD *)this - 4) != 3 && !*((_DWORD *)*a2 + 10) && *((_BYTE *)g_pUserInterface + 300) && !this[36] )
  {
    CardStackWithCard = CardTable::GetCardStackWithCard(this[19], a2[1]);
    v4 = CardStackWithCard;
    if ( !CardStackWithCard || (unsigned int)FreeCellMove::StackToMoveDestination(CardStackWithCard, 0) == 2 )
    {
      v7 = *(struct CardStack **)this[22];
      v5 = *((_DWORD *)v7 + 76);
      if ( v5 )
      {
        v6 = *((_QWORD *)v7 + 40);
        goto LABEL_14;
      }
    }
    else
    {
      v5 = *((_DWORD *)v4 + 76);
      if ( v5 )
      {
        v6 = *((_QWORD *)v4 + 40);
LABEL_14:
        Card::SetFocus(*(Card **)(v6 + 8LL * (unsigned int)(v5 - 1)));
        return;
      }
      v7 = v4;
    }
    CardStack::SetFocus(v7, -1);
  }
}
