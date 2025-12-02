void __fastcall CardTable::SetObjectsReceiveMouseEvents(CardTable *this, char a2)
{
  unsigned int v2; // r8d
  unsigned int v5; // r11d
  __int64 v6; // r10
  __int64 v7; // rcx
  unsigned int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // r10
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx

  v2 = 0;
  v5 = 0;
  if ( *((_DWORD *)this + 34) )
  {
    v6 = 0;
    do
    {
      ++v5;
      *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v6 + *((_QWORD *)this + 16)) + 96LL) + 64LL) = a2;
      v7 = *(_QWORD *)(v6 + *((_QWORD *)this + 16));
      v6 += 8;
      *(_BYTE *)(*(_QWORD *)(v7 + 64) + 64LL) = a2;
    }
    while ( v5 < *((_DWORD *)this + 34) );
  }
  v8 = 0;
  if ( *((_DWORD *)this + 92) )
  {
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)(v9 + *((_QWORD *)this + 45));
      v11 = *(_QWORD *)(v10 + 64);
      if ( v11 && !*(_BYTE *)(v10 + 73) )
        *(_BYTE *)(v11 + 64) = a2;
      ++v8;
      v9 += 8;
    }
    while ( v8 < *((_DWORD *)this + 92) );
  }
  if ( *((_DWORD *)this + 40) )
  {
    v12 = 0;
    do
    {
      ++v2;
      v13 = *(_QWORD *)(*((_QWORD *)this + 19) + v12);
      v12 += 8;
      *(_BYTE *)(*(_QWORD *)(v13 + 144) + 64LL) = a2;
    }
    while ( v2 < *((_DWORD *)this + 40) );
  }
}
