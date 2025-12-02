char __fastcall SortedListW<StackGroup *>::TryGet(__int64 a1, const wchar_t *a2, _QWORD *a3)
{
  int v5; // eax
  char result; // al
  __int64 v7; // rcx

  v5 = SortedListW<Card *>::BinSearch((_QWORD *)a1, a2, 0, *(_DWORD *)(a1 + 16));
  if ( v5 < 0 )
    return 0;
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL * v5);
  result = 1;
  *a3 = v7;
  return result;
}
