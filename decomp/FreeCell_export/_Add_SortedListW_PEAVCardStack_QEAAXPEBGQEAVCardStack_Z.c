void __fastcall SortedListW<CardStack *>::Add(__int64 a1, const wchar_t *a2, __int64 a3)
{
  int v6; // esi
  int v7; // esi
  wchar_t *v8; // rdi
  void *v9; // rax
  void *v10; // rbp
  int v11; // eax
  unsigned int v12; // edx
  __int64 v13; // rdi
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rcx
  const wchar_t *v17; // rdi
  bool v18; // zf
  __int64 v19; // rcx
  __int64 v20; // rbp
  wchar_t *v21; // rcx

  v6 = SortedListW<Card *>::BinSearch((_QWORD *)a1, a2, 0, *(_DWORD *)(a1 + 16));
  if ( v6 < 0 )
  {
    v7 = ~v6;
    if ( (unsigned int)(*(_DWORD *)(a1 + 16) + 1) >= *(_DWORD *)(a1 + 20) )
    {
      if ( !*(_DWORD *)(a1 + 20) )
        *(_DWORD *)(a1 + 20) = 2;
      v8 = (wchar_t *)malloc(16LL * *(unsigned int *)(a1 + 20));
      v9 = malloc(16LL * *(unsigned int *)(a1 + 20));
      v10 = v9;
      if ( !v9 || !v8 )
      {
        CheckAllocation(v9);
        v21 = v8;
        goto LABEL_19;
      }
      memcpy(v8, *(const void **)a1, 8LL * *(unsigned int *)(a1 + 16));
      memcpy(v10, *(const void **)(a1 + 8), 8LL * *(unsigned int *)(a1 + 16));
      free(*(void **)a1);
      free(*(void **)(a1 + 8));
      v11 = *(_DWORD *)(a1 + 20);
      *(_QWORD *)a1 = v8;
      *(_QWORD *)(a1 + 8) = v10;
      *(_DWORD *)(a1 + 20) = 2 * v11;
    }
    v12 = *(_DWORD *)(a1 + 16) - 1;
    if ( v12 >= v7 )
    {
      v13 = 8LL * (int)v12;
      do
      {
        if ( v12 >= *(_DWORD *)(a1 + 16) )
          break;
        --v12;
        *(_QWORD *)(v13 + *(_QWORD *)a1 + 8) = *(_QWORD *)(v13 + *(_QWORD *)a1);
        v14 = *(_QWORD *)(a1 + 8);
        v15 = *(_QWORD *)(v14 + v13);
        v13 -= 8;
        *(_QWORD *)(v14 + v13 + 16) = v15;
      }
      while ( v12 >= v7 );
    }
    ++*(_DWORD *)(a1 + 16);
    v16 = -1;
    v17 = a2;
    do
    {
      if ( !v16 )
        break;
      v18 = *v17++ == 0;
      --v16;
    }
    while ( !v18 );
    v19 = ~v16;
    v20 = v19 - 1;
    *(_QWORD *)(*(_QWORD *)a1 + 8LL * v7) = malloc(8 * v19);
    v21 = *(wchar_t **)(*(_QWORD *)a1 + 8LL * v7);
    if ( v21 )
    {
      wcscpy_s(v21, v20 + 1, a2);
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL * v7) = a3;
      return;
    }
LABEL_19:
    CheckAllocation(v21);
  }
}
