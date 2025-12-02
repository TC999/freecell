void __fastcall CardStack::AssignCards(CardTable **this, unsigned int *a2)
{
  unsigned int v4; // esi
  __int64 v5; // rbp
  struct Card *Card; // rax

  Log(0x10000u, L"CardStack::AssignCards()::aCardIDs.GetSize() == %u", *a2);
  if ( *((_DWORD *)this + 76) )
  {
    Log(0x10001u, L"CardStack::AssignCards() - Deck already has cards in it!");
  }
  else
  {
    v4 = 0;
    if ( *a2 )
    {
      v5 = 0;
      while ( 1 )
      {
        Card = CardTable::CreateCard(this[37], *(_DWORD *)(*((_QWORD *)a2 + 2) + v5), 0);
        if ( !Card )
          break;
        CardStack::Push((CardStack *)this, Card);
        ++v4;
        v5 += 4;
        if ( v4 >= *a2 )
          goto LABEL_8;
      }
      Log(0x10001u, L"CardStack::AssignCards() - Failed to create a card.");
    }
    else
    {
LABEL_8:
      CardStack::Arrange((CardStack *)this, 0, 0);
    }
  }
}
