struct CardStack *__fastcall CardTable::GetCardStack(CardTable *this, const unsigned __int16 *a2)
{
  char *v2; // rbx

  v2 = (char *)this + 144;
  if ( (int)SortedListW<Card *>::BinSearch((_QWORD *)this + 18, a2, 0, *((_DWORD *)this + 40)) >= 0 )
    return *(struct CardStack **)(*((_QWORD *)v2 + 1)
                                + 8LL * (int)SortedListW<Card *>::BinSearch(v2, a2, 0, *((_DWORD *)v2 + 4)));
  Log(0x10001u, L"CardTable::GetCardStack() - Failed to find the card stack.");
  return 0;
}
