void __fastcall FreeCellGame::OnCardDragStarted(CardTable **this, struct Card *a2)
{
  const unsigned __int16 *v3; // rdx
  struct CardStack *CardStackWithCard; // rax
  CardStack *v6; // rdi
  unsigned int CardLocation; // ebx
  CardStack *v8; // rbx

  v3 = (const unsigned __int16 *)*((_QWORD *)a2 + 7);
  if ( v3 )
  {
    CardStackWithCard = CardTable::GetCardStackWithCard(this[22], v3);
    v6 = CardStackWithCard;
    if ( CardStackWithCard )
    {
      if ( *((_QWORD *)CardStackWithCard + 36) )
      {
        CardTable::ClearHintAnimations(this[22]);
        this[41] = v6;
        this[40] = a2;
        CardLocation = CardStack::GetCardLocation(v6, a2);
        FreeCellGame::SetSelectedCard((FreeCellGame *)this, 0, 1, 1, 1);
        v8 = CardStack::Split(v6, CardLocation, L"DragStack");
        CardStack::Arrange(v8, 0, 0);
        CardStack::SetShadow(v8, 1, -1, -1);
        Card::SetFocus(a2);
        FreeCellGame::PlaySoundW((FreeCellGame *)this, 8u, 0, 0);
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
