// Hidden C++ exception states: #wind=2
Str *__fastcall RequestGetUsername(Str *a1, ULONG a2)
{
  WCHAR *v3; // rax
  WCHAR *v4; // rbx
  _BYTE v6[16]; // [rsp+28h] [rbp-30h] BYREF
  void *Block; // [rsp+38h] [rbp-20h]
  ULONG nSize; // [rsp+68h] [rbp+10h] BYREF
  int v9; // [rsp+70h] [rbp+18h]

  nSize = a2;
  v9 = 0;
  Str::Str((Str *)v6, &dword_1000028D4);
  nSize = 256;
  v3 = (WCHAR *)operator new(saturated_mul(0x100u, 2u));
  v4 = v3;
  if ( v3 )
  {
    if ( GetUserNameExW(NameDisplay, v3, &nSize) || (nSize = 256, GetUserNameW(v4, &nSize)) )
      Str::operator=(v6, v4);
    operator delete(v4);
    Str::Str(a1, (const struct Str *)v6);
    v9 = 1;
    operator delete(Block);
    return a1;
  }
  else
  {
    Str::Str(a1, (const struct Str *)v6);
    v9 = 1;
    operator delete(Block);
    return a1;
  }
}
