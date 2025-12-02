bool __fastcall CardTable::IsGroupSelectable(CardTable *this, struct StackGroup *a2)
{
  int v2; // r8d
  char v4; // r9
  char v5; // r11
  unsigned int v6; // ebx
  __int64 v7; // rdi
  __int64 v8; // rcx
  unsigned int v10; // r11d
  unsigned int v11; // r9d
  __int64 v12; // rcx
  unsigned int v13; // r9d
  unsigned int v14; // edx
  __int64 v15; // rcx
  unsigned int v16; // r9d
  int v17; // ecx
  __int64 i; // rdx

  v2 = *((_DWORD *)a2 + 6);
  if ( (v2 & 2) != 0 )
  {
    v4 = 1;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    while ( (!v5 || v4) && v6 < *((_DWORD *)a2 + 8) )
    {
      v8 = *(_QWORD *)(v7 + *((_QWORD *)a2 + 6));
      if ( *(_DWORD *)(v8 + 304) )
        v4 = 0;
      if ( *(_QWORD *)(v8 + 224) )
        v5 = 1;
      ++v6;
      v7 += 8;
    }
    if ( v5 )
      return 1;
    if ( v4 == 1 )
      return 0;
  }
  if ( (v2 & 1) != 0 )
  {
    v10 = *((_DWORD *)a2 + 8);
    v11 = 0;
    if ( v10 )
    {
      v12 = *((_QWORD *)a2 + 6);
      while ( !*(_QWORD *)(*(_QWORD *)v12 + 224LL) )
      {
        ++v11;
        v12 += 8;
        if ( v11 >= v10 )
          goto LABEL_20;
      }
      return 1;
    }
LABEL_20:
    v13 = *((_DWORD *)this + 40);
    v14 = 0;
    if ( v13 )
    {
      v15 = *((_QWORD *)this + 19);
      while ( !*(_QWORD *)(*(_QWORD *)v15 + 224LL) )
      {
        ++v14;
        v15 += 8;
        if ( v14 >= v13 )
          goto LABEL_24;
      }
      return 0;
    }
  }
LABEL_24:
  if ( (v2 & 4) != 0 )
  {
    v16 = *((_DWORD *)this + 40);
    v17 = 0;
    if ( !v16 )
      return 0;
    for ( i = *((_QWORD *)this + 19); !*(_QWORD *)(*(_QWORD *)i + 224LL); i += 8 )
    {
      if ( ++v17 >= v16 )
        return 0;
    }
  }
  return (v2 & 8) == 0;
}
