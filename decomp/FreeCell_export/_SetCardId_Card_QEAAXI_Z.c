void __fastcall Card::SetCardId(Card *this, int a2)
{
  int v2; // eax
  __int64 v4; // rdi
  __int64 v5; // rsi
  __int64 v6; // rdx
  int v7; // [rsp+20h] [rbp-18h]

  v2 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 2) = a2;
  if ( v2 )
  {
    v7 = v2;
    swprintf_s(word_1000B1E30, 0x80u, L"%s%u", (&Card::CARD_NAME)[a2], v7);
  }
  else
  {
    swprintf_s(word_1000B1E30, 0x80u, (const wchar_t *const)(&Card::CARD_NAME)[a2]);
  }
  Card::UpdateCardFace(this);
  NodeBase::SetAccessName(
    *((HLOCAL **)this + 12),
    (const unsigned __int16 *)(&Card::CARD_HUMAN_NAME)[*((unsigned int *)this + 2)]);
  Card::SetName(this, word_1000B1E30);
  v4 = *((_QWORD *)this + 3);
  if ( v4 )
  {
    v5 = (int)SortedListW<Card *>::BinSearch(
                (_QWORD *)(v4 + 120),
                *((const wchar_t **)this + 7),
                0,
                *(_DWORD *)(v4 + 136));
    free(*(void **)(*(_QWORD *)(v4 + 120) + 8 * v5));
    if ( (unsigned int)v5 < *(_DWORD *)(v4 + 136) - 1 )
    {
      v6 = 8 * v5;
      do
      {
        LODWORD(v5) = v5 + 1;
        *(_QWORD *)(*(_QWORD *)(v4 + 120) + v6) = *(_QWORD *)(*(_QWORD *)(v4 + 120) + v6 + 8);
        *(_QWORD *)(v6 + *(_QWORD *)(v4 + 128)) = *(_QWORD *)(v6 + *(_QWORD *)(v4 + 128) + 8);
        v6 += 8;
      }
      while ( (unsigned int)v5 < *(_DWORD *)(v4 + 136) - 1 );
    }
    --*(_DWORD *)(v4 + 136);
    SortedListW<CardStack *>::Add(*((_QWORD *)this + 3) + 120LL, *((const wchar_t **)this + 7), (__int64)this);
  }
}
