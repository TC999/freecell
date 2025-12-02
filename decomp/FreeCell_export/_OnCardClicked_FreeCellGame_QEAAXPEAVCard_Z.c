void __fastcall FreeCellGame::OnCardClicked(CardTable **this, struct Card *a2)
{
  const unsigned __int16 *v4; // rdx
  struct CardStack *CardStackWithCard; // rax
  struct CardStack *v6; // rsi
  struct Card *v7; // rdx
  struct Card *v8; // rdx

  if ( *((_DWORD *)this + 2) == 2 )
  {
    v4 = (const unsigned __int16 *)*((_QWORD *)a2 + 7);
    if ( v4 )
    {
      CardStackWithCard = CardTable::GetCardStackWithCard(this[22], v4);
      v6 = CardStackWithCard;
      if ( !CardStackWithCard )
      {
        Log(0x10000001u, L"FreeCellGame::OnCardClicked() - Card doesn't belong to any stack.");
        return;
      }
      if ( !*((_QWORD *)CardStackWithCard + 36) )
      {
        Log(0x10000001u, L"FreeCellGame::OnCardClicked() - Stack missing a name.");
        return;
      }
      v7 = this[38];
      if ( v7 )
      {
        if ( v7 == a2 || CardStackWithCard == CardTable::GetCardStackWithCard(this[22], v7) )
        {
          FreeCellGame::SetSelectedCard((FreeCellGame *)this, 0, 1, 1, 1);
          return;
        }
        FreeCellGame::OnCardStackClicked((FreeCellGame *)this, v6);
      }
      else
      {
        if ( FreeCellMove::IsPartOfValidSequence(a2) )
          v8 = a2;
        else
          v8 = *(struct Card **)(*((_QWORD *)v6 + 40) + 8LL * (unsigned int)(*((_DWORD *)v6 + 76) - 1));
        FreeCellGame::SetSelectedCard((FreeCellGame *)this, v8, 1, 1, 1);
      }
      CardTable::ClearHintAnimations(this[22]);
    }
    else
    {
      Log(0x10000001u, L"FreeCellGame::OnCardClicked() - Card missing a name.");
    }
  }
}
