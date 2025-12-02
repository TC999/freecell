struct CardStack *__fastcall CardTable::CreateCardStack(CardTable *this, const unsigned __int16 *a2)
{
  CardStack *v4; // rax
  CardStack *v5; // rbx

  v4 = (CardStack *)operator new(0x150u);
  if ( v4 )
    v5 = CardStack::CardStack(v4);
  else
    v5 = 0;
  if ( CardStack::Init(v5, this, a2, *((struct NodeBase **)this + 12)) )
  {
    Array<IEventListener *>::Add(*((_QWORD *)v5 + 18) + 200LL, *((_QWORD *)this + 14));
    SortedListW<CardStack *>::Add((char *)this + 144, a2, v5);
    return v5;
  }
  else
  {
    Log(0x10001u, L"CardTable::CreateCardStack() - Failed to init the stack.");
    if ( v5 )
      (*(void (__fastcall **)(__int64, __int64))(*((_QWORD *)v5 + 1) + 8LL))((__int64)v5 + 8, 1);
    return 0;
  }
}
