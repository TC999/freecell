void __fastcall FreeCellGame::SetSelectedCard(FreeCellGame *this, struct Card *a2, char a3, char a4, bool a5)
{
  struct Card *v6; // r8
  CardStack *CardStackWithCard; // rsi
  CardStack *v8; // rbp
  __int64 v12; // rax
  CardTable *v13; // rcx

  v6 = (struct Card *)*((_QWORD *)this + 38);
  CardStackWithCard = 0;
  v8 = 0;
  if ( a2 != v6 )
    Log(0x10000000u, L"FreeCellGame::SetSelectedCard() - old=%p new=%p", v6, a2);
  v12 = *((_QWORD *)this + 38);
  if ( v12 )
  {
    *(_BYTE *)(*(_QWORD *)(v12 + 96) + 196LL) = 0;
    if ( a5 )
    {
      v13 = (CardTable *)*((_QWORD *)this + 22);
      if ( v13 )
        CardTable::ClearHintAnimations(v13);
      *((_BYTE *)this + 380) = 0;
    }
    CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 22), *((struct Card **)this + 38));
    CardStack::SetHighlight(CardStackWithCard, 0, 0);
  }
  *((_QWORD *)this + 38) = a2;
  if ( a2 )
  {
    *(_BYTE *)(*((_QWORD *)a2 + 12) + 196LL) = 1;
    v8 = CardTable::GetCardStackWithCard(*((CardTable **)this + 22), *((struct Card **)this + 38));
    CardStack::SetHighlight(v8, 1, a2);
    if ( a3 )
      FreeCellGame::PlaySoundW(this, 2u, 0, 0);
  }
  if ( CardStackWithCard && CardStackWithCard != v8 )
    CardStack::Arrange(CardStackWithCard, 1, 0);
  if ( v8 )
    CardStack::Arrange(v8, 1, 0);
  if ( a4 )
    *((_QWORD *)this + 39) = a2;
}
