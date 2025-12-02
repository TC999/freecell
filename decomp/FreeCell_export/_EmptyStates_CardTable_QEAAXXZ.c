// Hidden C++ exception states: #wind=1
void __fastcall CardTable::EmptyStates(CardTable *this)
{
  unsigned int v2; // esi
  __int64 v3; // rdi
  void **v4; // rbp

  v2 = 0;
  if ( *((_DWORD *)this + 60) )
  {
    v3 = 0;
    do
    {
      v4 = *(void ***)(v3 + *((_QWORD *)this + 32));
      if ( v4 )
      {
        operator delete(v4[6]);
        operator delete(v4[3]);
        operator delete(v4);
      }
      *(_QWORD *)(v3 + *((_QWORD *)this + 32)) = 0;
      ++v2;
      v3 += 8;
    }
    while ( v2 < *((_DWORD *)this + 60) );
  }
  *((_DWORD *)this + 60) = 0;
}
