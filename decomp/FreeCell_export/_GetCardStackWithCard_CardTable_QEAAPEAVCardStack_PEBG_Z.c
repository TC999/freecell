struct CardStack *__fastcall CardTable::GetCardStackWithCard(CardTable *this, const unsigned __int16 *a2)
{
  struct Card *Card; // rax

  Card = CardTable::GetCard(this, a2);
  if ( Card )
    return CardTable::GetCardStackWithCard(this, Card);
  Log(0x10001u, L"CardTable::GetCardStackWithCard() - Failed to find the card.");
  return 0;
}
