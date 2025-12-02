void __fastcall CardStack::SetShadow(CardStack *this, char a2, int a3, int a4)
{
  unsigned int v7; // ebx
  const wchar_t *v8; // r8
  __int64 v10; // rdi

  v7 = 0;
  v8 = L"false";
  if ( a2 )
    v8 = L"true";
  Log(0x10000u, L"CardStack::SetShadow()::bShadow == %s", v8);
  if ( *((_DWORD *)this + 76) )
  {
    v10 = 0;
    do
    {
      Card::SetShadow(*(Card **)(*((_QWORD *)this + 40) + v10), a2, a3, a4);
      ++v7;
      v10 += 8;
    }
    while ( v7 < *((_DWORD *)this + 76) );
  }
}
