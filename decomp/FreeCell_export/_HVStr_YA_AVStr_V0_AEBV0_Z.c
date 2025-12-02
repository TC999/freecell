// Hidden C++ exception states: #wind=3
Str *__fastcall operator+<Str>(Str *this, __int64 a2, __int64 *a3)
{
  const wchar_t **v6; // rax
  _BYTE v8[16]; // [rsp+28h] [rbp-30h] BYREF
  void *Block; // [rsp+38h] [rbp-20h]

  Str::Str((Str *)v8, (const wchar_t **)a2);
  v6 = (const wchar_t **)Str::operator+=((__int64)v8, a3);
  Str::Str(this, v6);
  operator delete(Block);
  operator delete(*(void **)(a2 + 16));
  return this;
}
