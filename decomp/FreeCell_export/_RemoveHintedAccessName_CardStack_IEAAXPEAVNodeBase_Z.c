// Hidden C++ exception states: #wind=3
void __fastcall CardStack::RemoveHintedAccessName(CardStack *this, HLOCAL *a2)
{
  char v3; // si
  const unsigned __int16 *v4; // rax
  const unsigned __int16 *v5; // rax
  unsigned __int16 *v6; // rbx
  int v7; // ebp
  Str *v8; // rax
  bool v10; // bl
  Str *v11; // rax
  int v12[4]; // [rsp+28h] [rbp-50h] BYREF
  void *v13; // [rsp+38h] [rbp-40h]
  int v14[4]; // [rsp+40h] [rbp-38h] BYREF
  unsigned __int16 *v15; // [rsp+50h] [rbp-28h]
  _BYTE v16[16]; // [rsp+58h] [rbp-20h] BYREF
  void *Block; // [rsp+68h] [rbp-10h]

  v3 = 0;
  v4 = (const unsigned __int16 *)(*((__int64 (__fastcall **)(HLOCAL *))*a2 + 7))(a2);
  Str::Str((Str *)v14, v4);
  v5 = LocalizeMessage(L"|64932|HintedCardStack| - Hinted// Appended to a card or stack that is being hint highlighted.");
  v6 = (unsigned __int16 *)v5;
  if ( v5 )
  {
    Str::Str((Str *)v12, v5);
    LocalFree(v6);
    v7 = v14[0];
    v10 = 0;
    if ( v14[0] >= v12[0] )
    {
      v8 = Str::SubString((__int64)v14, (Str *)v16, v14[0] - v12[0], v12[0]);
      v3 = 1;
      if ( *((_QWORD *)v8 + 2) && Str::Equals(v8, (const struct Str *)v12) )
        v10 = 1;
    }
    if ( (v3 & 1) != 0 )
      operator delete(Block);
    if ( v10 )
    {
      v11 = Str::SubString((__int64)v14, (Str *)v16, 0, v7 - v12[0]);
      Str::operator=((__int64)v14, (__int64)v11);
      operator delete(Block);
      NodeBase::SetAccessName(a2, v15);
    }
    operator delete(v13);
  }
  operator delete(v15);
}
