void __fastcall CardStack::CreateDeck(CardTable **this, unsigned int a2)
{
  unsigned int v2; // edi
  unsigned int v4; // esi
  int v5; // ebx
  struct Card *Card; // rax

  v2 = 0;
  v4 = 13 * a2;
  if ( !a2 )
    goto LABEL_10;
  if ( a2 <= 2 )
  {
    v5 = 26;
    goto LABEL_8;
  }
  if ( a2 == 3 )
  {
    Log(0x10001u, L"CardStack::CreateDeck() - Trying to use 3 suits, are you sure you want to do this?");
    v5 = 13;
    goto LABEL_8;
  }
  if ( a2 != 4 )
  {
LABEL_10:
    Log(0x10001u, L"CardStack::CreateDeck() - Trying to use too many suits.");
    return;
  }
  v5 = 0;
  do
  {
LABEL_8:
    Card = CardTable::CreateCard(this[37], v5 + v2 % v4, v2 / v4);
    CardStack::Push((CardStack *)this, Card);
    ++v2;
  }
  while ( v2 < 0x34 );
  CardStack::Arrange((CardStack *)this, 0, 0);
}
