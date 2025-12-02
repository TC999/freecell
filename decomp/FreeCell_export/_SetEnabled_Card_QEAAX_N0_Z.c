void __fastcall Card::SetEnabled(Card *this, char a2)
{
  const unsigned __int16 *v4; // rsi
  __int64 v5; // rax

  v4 = L"false";
  if ( a2 )
    v4 = L"true";
  Log(0x10000u, L"Card::SetEnabled()::bEnabled == %s", v4);
  v5 = *((_QWORD *)this + 12);
  if ( *(_BYTE *)(v5 + 72) != a2 )
  {
    *(_BYTE *)(v5 + 72) = a2;
    NodeBase::SetAccessible(*((NodeBase **)this + 12), a2, *(_DWORD *)(*((_QWORD *)this + 12) + 192LL));
    CardTable::PushAction(*((CardTable **)this + 3), 1, *((const unsigned __int16 **)this + 7), v4);
    Card::RefreshAccessibility(this);
  }
}
