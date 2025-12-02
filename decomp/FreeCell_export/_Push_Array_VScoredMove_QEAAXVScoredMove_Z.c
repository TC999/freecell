void __fastcall Array<ScoredMove>::Push(__int64 a1, const void *a2)
{
  unsigned int v3; // ecx
  __int64 v4; // rdx
  void *v5; // rax
  _BYTE Src[56]; // [rsp+20h] [rbp-48h] BYREF

  memcpy(Src, a2, sizeof(Src));
  v3 = *(_DWORD *)(a1 + 4);
  if ( ++*(_DWORD *)a1 > v3 )
  {
    v4 = *(_DWORD *)(a1 + 8) + v3;
    *(_DWORD *)(a1 + 4) = v4;
    v5 = realloc(*(void **)(a1 + 16), 56 * v4);
    if ( !v5 )
    {
      CheckAllocation(0);
      return;
    }
    *(_QWORD *)(a1 + 16) = v5;
  }
  memcpy((void *)(*(_QWORD *)(a1 + 16) + 56LL * (unsigned int)(*(_DWORD *)a1 - 1)), Src, 0x38u);
}
