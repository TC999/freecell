// Hidden C++ exception states: #wind=1
struct Card *__fastcall CardTable::CreateBlankCard(CardTable *this)
{
  Card *v2; // rax
  Card *v3; // rbx

  v2 = (Card *)operator new(0x70u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Card::`vftable';
    *((_QWORD *)v2 + 5) = 0;
    *((_QWORD *)v2 + 6) = 0;
    *((_QWORD *)v2 + 7) = 0;
    *((_DWORD *)v2 + 2) = 38;
    *((_BYTE *)v2 + 16) = 1;
    *((_BYTE *)v2 + 17) = 0;
    *((_BYTE *)v2 + 18) = 0;
    *((_BYTE *)v2 + 19) = 0;
    *((_QWORD *)v2 + 3) = 0;
    *((_QWORD *)v2 + 8) = 0;
    *((_QWORD *)v2 + 9) = 0;
    *((_QWORD *)v2 + 10) = 0;
    *((_DWORD *)v2 + 23) = 0;
    *((_DWORD *)v2 + 22) = 0;
    *((_QWORD *)v2 + 12) = 0;
    *((_QWORD *)v2 + 13) = 0;
    *((_DWORD *)v2 + 3) = 0;
    *((_DWORD *)v2 + 8) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( Card::Init(v3, this, 0x26u, *((const unsigned __int16 **)this + 41), *((struct NodeBase **)this + 12), 0) )
  {
    Array<IEventListener *>::Add(*((_QWORD *)v3 + 12) + 200LL, (__int64)this);
    Array<IEventListener *>::Add(*((_QWORD *)v3 + 12) + 200LL, *((_QWORD *)this + 14));
    return v3;
  }
  else
  {
    Log(0x10001u, L"CardTable::CreateBlankCard() - Failed to init the blank card.");
    if ( v3 )
    {
      *(_QWORD *)v3 = &Card::`vftable';
      Card::Cleanup(v3);
      operator delete(*((void **)v3 + 7));
      operator delete(v3);
    }
    return 0;
  }
}
