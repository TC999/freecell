void __fastcall CardTable::SelectCardUp(CardTable *this, struct Card *a2)
{
  CardStack *CardStackWithCard; // rax
  CardStack *v5; // rdi
  unsigned int CardLocation; // eax
  struct Card *v7; // rcx
  int v8; // eax

  if ( a2 )
  {
    CardStackWithCard = CardTable::GetCardStackWithCard(this, a2);
    v5 = CardStackWithCard;
    if ( CardStackWithCard )
    {
      CardLocation = CardStack::GetCardLocation(CardStackWithCard, a2);
      if ( *((_BYTE *)v5 + 16)
        || !CardLocation
        || (v7 = *(struct Card **)(*((_QWORD *)v5 + 40) + 8LL * (CardLocation - 1))) == 0
        || !*((_BYTE *)v7 + 17) )
      {
        if ( CardTable::MoveRowUp(this, v5) )
          return;
        v8 = *((_DWORD *)v5 + 76);
        if ( !v8
          || (v7 = *(struct Card **)(*((_QWORD *)v5 + 40) + 8LL * (unsigned int)(v8 - 1))) == 0
          || !*((_BYTE *)v7 + 17) )
        {
          v7 = a2;
        }
      }
      Card::SetFocus(v7);
    }
  }
}
