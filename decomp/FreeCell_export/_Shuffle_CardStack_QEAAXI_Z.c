// Hidden C++ exception states: #wind=1
void __fastcall CardStack::Shuffle(CardStack *this)
{
  _QWORD *v2; // rbx
  __int64 v3; // rbx
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  __int64 v7; // r12
  _QWORD *v8; // r8
  __int64 v9; // rdx
  _DWORD v10[4]; // [rsp+28h] [rbp-20h] BYREF
  _QWORD *v11; // [rsp+38h] [rbp-10h]

  Log(0x10000u, L"CardStack::Shuffle()");
  v10[0] = 0;
  v10[1] = 0;
  v10[2] = 16;
  v2 = 0;
  v11 = 0;
  if ( *((_DWORD *)this + 76) )
  {
    v3 = *((unsigned int *)this + 76);
    do
    {
      Array<IEventListener *>::Add(
        (__int64)v10,
        *(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1)));
      v4 = *((_DWORD *)this + 76);
      if ( v4 )
        *((_DWORD *)this + 76) = v4 - 1;
      --v3;
    }
    while ( v3 );
    v5 = v10[0];
    if ( v10[0] )
    {
      v2 = v11;
      do
      {
        v6 = rand();
        v7 = (int)(v6 % v5);
        Array<IEventListener *>::Add((__int64)this + 304, v2[v6 % v5--]);
        if ( (unsigned int)v7 < v5 )
        {
          v8 = &v2[v7];
          v9 = v5 - (unsigned int)v7;
          do
          {
            *v8 = v8[1];
            ++v8;
            --v9;
          }
          while ( v9 );
        }
        v10[0] = v5;
      }
      while ( v5 );
    }
    else
    {
      v2 = v11;
    }
  }
  CardStack::Arrange(this, 0, 0);
  if ( v2 )
    free(v2);
}
