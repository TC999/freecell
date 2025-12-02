struct Card *__fastcall CardTable::GetCard(CardTable *this, const unsigned __int16 *a2)
{
  char *v4; // rdi

  if ( !a2 )
    return 0;
  v4 = (char *)this + 120;
  if ( (int)SortedListW<Card *>::BinSearch((_QWORD *)this + 15, a2, 0, *((_DWORD *)this + 34)) < 0 )
  {
    Log(0x10001u, L"CardTable::GetCard() - Failed to find the card.");
    return 0;
  }
  return *(struct Card **)(*((_QWORD *)v4 + 1)
                         + 8LL * (int)SortedListW<Card *>::BinSearch(v4, a2, 0, *((_DWORD *)v4 + 4)));
}
