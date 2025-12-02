void __fastcall CardStack::Reverse(CardStack *this)
{
  unsigned int v2; // ecx
  unsigned int v3; // r9d
  __int64 v4; // r10
  __int64 v5; // rdx
  unsigned int v6; // ecx
  __int64 v7; // r8
  __int64 v8; // rcx

  Log(0x10000u, L"CardStack::Reverse()");
  CardTable::PushAction(*((CardTable **)this + 37), 6, *((const unsigned __int16 **)this + 36), &dword_1000028D4);
  v2 = *((_DWORD *)this + 76);
  v3 = 0;
  if ( (v2 & 0xFFFFFFFE) != 0 )
  {
    v4 = 0;
    do
    {
      v5 = *((_QWORD *)this + 40);
      v6 = v2 - v3++;
      v7 = *(_QWORD *)(v4 + v5);
      v8 = (int)(v6 - 1);
      *(_QWORD *)(v4 + v5) = *(_QWORD *)(v5 + 8 * v8);
      v4 += 8;
      *(_QWORD *)(*((_QWORD *)this + 40) + 8 * v8) = v7;
      v2 = *((_DWORD *)this + 76);
    }
    while ( v3 < v2 >> 1 );
  }
}
