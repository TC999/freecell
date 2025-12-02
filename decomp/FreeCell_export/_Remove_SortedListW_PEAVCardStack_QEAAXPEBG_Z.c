void __fastcall SortedListW<CardStack *>::Remove(__int64 a1, const wchar_t *a2)
{
  __int64 v3; // rdi
  __int64 v4; // rdx

  v3 = (int)SortedListW<Card *>::BinSearch((_QWORD *)a1, a2, 0, *(_DWORD *)(a1 + 16));
  free(*(void **)(*(_QWORD *)a1 + 8 * v3));
  if ( (unsigned int)v3 < *(_DWORD *)(a1 + 16) - 1 )
  {
    v4 = 8 * v3;
    do
    {
      LODWORD(v3) = v3 + 1;
      *(_QWORD *)(v4 + *(_QWORD *)a1) = *(_QWORD *)(v4 + *(_QWORD *)a1 + 8);
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + v4) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + v4 + 8);
      v4 += 8;
    }
    while ( (unsigned int)v3 < *(_DWORD *)(a1 + 16) - 1 );
  }
  --*(_DWORD *)(a1 + 16);
}
