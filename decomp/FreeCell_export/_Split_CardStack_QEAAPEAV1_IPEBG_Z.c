struct CardStack *__fastcall CardStack::Split(CardStack *this, unsigned int a2, const unsigned __int16 *a3)
{
  __int64 v4; // rsi
  struct CardStack *CardStack; // rax
  CardStack *v7; // rbx
  NodeBase *v9; // rcx
  __int64 v10; // rdx
  struct Card *v11; // rax

  v4 = a2;
  Log(0x10000u, L"CardStack::Split()::uiCard == %u", a2);
  Log(0x10000u, L"CardStack::Split()::wszStackName == %s", a3);
  CardTable::PushAction(*((CardTable **)this + 37), 7, *((const unsigned __int16 **)this + 36), a3);
  CardStack = CardTable::CreateCardStack(*((CardTable **)this + 37), a3);
  v7 = CardStack;
  if ( CardStack )
  {
    v9 = (NodeBase *)*((_QWORD *)CardStack + 18);
    v10 = *(_QWORD *)(*((_QWORD *)this + 40) + 8 * v4);
    *((_DWORD *)CardStack + 8) = *((_DWORD *)this + 8);
    *((_DWORD *)CardStack + 9) = *((_DWORD *)this + 9);
    *((_DWORD *)CardStack + 5) = *((_DWORD *)this + 5);
    *((_DWORD *)CardStack + 6) = *((_DWORD *)this + 6);
    *((_DWORD *)CardStack + 7) = *((_DWORD *)this + 7);
    *((_DWORD *)CardStack + 10) = *((_DWORD *)this + 10);
    *((_DWORD *)CardStack + 11) = *((_DWORD *)this + 11);
    NodeBase::SetPosition(v9, *(_DWORD *)(*(_QWORD *)(v10 + 64) + 8LL), *(_DWORD *)(*(_QWORD *)(v10 + 64) + 12LL));
    while ( *((_DWORD *)this + 76) > (unsigned int)v4 )
    {
      v11 = CardStack::Pop(this);
      CardStack::Push(v7, v11);
    }
    CardStack::Reverse(v7);
    if ( *((_BYTE *)this + 56) )
      CardStack::UpdateAccessibility(this);
    if ( *((_BYTE *)this + 57) )
      CardStack::ResizeAccessAreas(this);
    return v7;
  }
  else
  {
    Log(0x10001u, L"CardTable::SplitStack() - Failed to create a new stack.");
    return 0;
  }
}
