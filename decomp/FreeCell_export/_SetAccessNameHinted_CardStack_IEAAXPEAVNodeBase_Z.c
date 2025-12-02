// Hidden C++ exception states: #wind=3
void __fastcall CardStack::SetAccessNameHinted(CardStack *this, HLOCAL *a2)
{
  const unsigned __int16 *v3; // rax
  unsigned __int16 *v4; // rdi
  const unsigned __int16 *v5; // rax
  _BYTE v6[16]; // [rsp+28h] [rbp-50h] BYREF
  unsigned __int16 *v7; // [rsp+38h] [rbp-40h]
  _BYTE v8[16]; // [rsp+40h] [rbp-38h] BYREF
  void *Block; // [rsp+50h] [rbp-28h]
  _BYTE v10[24]; // [rsp+58h] [rbp-20h] BYREF

  v3 = LocalizeMessage(L"|64932|HintedCardStack| - Hinted// Appended to a card or stack that is being hint highlighted.");
  v4 = (unsigned __int16 *)v3;
  if ( v3 )
  {
    Str::Str((Str *)v8, v3);
    v5 = (const unsigned __int16 *)(*((__int64 (__fastcall **)(HLOCAL *))*a2 + 7))(a2);
    Str::Str((Str *)v10, v5);
    operator+<Str>((Str *)v6);
    operator delete(Block);
    LocalFree(v4);
    NodeBase::SetAccessName(a2, v7);
    operator delete(v7);
  }
}
