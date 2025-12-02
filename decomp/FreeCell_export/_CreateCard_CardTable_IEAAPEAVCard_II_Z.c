// Hidden C++ exception states: #wind=1
struct Card *__fastcall CardTable::CreateCard(CardTable *this, unsigned int a2, unsigned int a3)
{
  Card *v6; // rax
  Card *v7; // rbx

  v6 = (Card *)operator new(0x70u);
  v7 = v6;
  if ( v6 )
  {
    *(_QWORD *)v6 = &Card::`vftable';
    *((_QWORD *)v6 + 5) = 0;
    *((_QWORD *)v6 + 6) = 0;
    *((_QWORD *)v6 + 7) = 0;
    *((_DWORD *)v6 + 2) = 38;
    *((_BYTE *)v6 + 16) = 1;
    *((_BYTE *)v6 + 17) = 0;
    *((_BYTE *)v6 + 18) = 0;
    *((_BYTE *)v6 + 19) = 0;
    *((_QWORD *)v6 + 3) = 0;
    *((_QWORD *)v6 + 8) = 0;
    *((_QWORD *)v6 + 9) = 0;
    *((_QWORD *)v6 + 10) = 0;
    *((_DWORD *)v6 + 23) = 0;
    *((_DWORD *)v6 + 22) = 0;
    *((_QWORD *)v6 + 12) = 0;
    *((_QWORD *)v6 + 13) = 0;
    *((_DWORD *)v6 + 3) = 0;
    *((_DWORD *)v6 + 8) = 0;
  }
  else
  {
    v7 = 0;
  }
  if ( Card::Init(v7, this, a2, *((const unsigned __int16 **)this + 41), *((struct NodeBase **)this + 12), a3) )
  {
    Array<IEventListener *>::Add(*((_QWORD *)v7 + 12) + 200LL, (__int64)this);
    Array<IEventListener *>::Add(*((_QWORD *)v7 + 12) + 200LL, *((_QWORD *)this + 14));
    SortedListW<CardStack *>::Add((char *)this + 120, *((_QWORD *)v7 + 7), v7);
    return v7;
  }
  else
  {
    Log(0x10001u, L"CardTable::CreateCard() - Failed to init the card.");
    if ( v7 )
    {
      *(_QWORD *)v7 = &Card::`vftable';
      Card::Cleanup(v7);
      operator delete(*((void **)v7 + 7));
      operator delete(v7);
    }
    return 0;
  }
}
