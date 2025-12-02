__int64 __fastcall FreeCellGame::checkForSuitCompletionsInStacks(__int64 a1, __int64 a2, char a3, char a4)
{
  unsigned int v8; // ebp
  unsigned int v9; // esi
  __int64 v10; // rdi
  __int64 v11; // rdx
  unsigned int RankForType; // ebx
  unsigned int SuitForType; // eax
  __int64 v14; // rdx
  int v15; // esi
  __int64 i; // rbx
  __int64 v17; // rdx
  unsigned int v18; // eax
  __int64 v19; // r9
  unsigned int v20; // edx
  __int64 v21; // r8
  __int64 v22; // rcx
  __int64 v23; // rax
  _BYTE *v24; // rcx
  __int64 v25; // rdi
  unsigned int v26; // eax
  bool v27; // cl
  __int64 v28; // rax
  __int64 v30; // [rsp+20h] [rbp-E8h]
  __int64 v31; // [rsp+28h] [rbp-E0h]
  _QWORD v32[2]; // [rsp+30h] [rbp-D8h]
  _QWORD Src[5]; // [rsp+40h] [rbp-C8h] BYREF
  _BYTE v34[48]; // [rsp+80h] [rbp-88h] BYREF
  _BYTE v35[48]; // [rsp+B0h] [rbp-58h] BYREF

  v32[0] = -1;
  v32[1] = -1;
  v8 = 0;
  v30 = 0;
  v31 = 0;
  v9 = 0;
  v10 = 0;
  do
  {
    v11 = *(_QWORD *)(v10 + *(_QWORD *)(a1 + 248));
    if ( *(_DWORD *)(v11 + 304) )
    {
      RankForType = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 320)
                                                               + 8LL * (unsigned int)(*(_DWORD *)(v11 + 304) - 1))
                                                   + 8LL));
      if ( RankForType == 13 )
        RankForType = 0;
      SuitForType = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v10 + *(_QWORD *)(a1 + 248))
                                                                           + 320LL)
                                                               + 8LL
                                                               * (unsigned int)(*(_DWORD *)(*(_QWORD *)(v10 + *(_QWORD *)(a1 + 248))
                                                                                          + 304LL)
                                                                              - 1))
                                                   + 8LL));
      v14 = *(_QWORD *)(v10 + *(_QWORD *)(a1 + 248));
      *((_DWORD *)&v30 + SuitForType) = RankForType + 1;
      *((_DWORD *)v32
      + Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 320)
                                                   + 8LL * (unsigned int)(*(_DWORD *)(v14 + 304) - 1))
                                       + 8LL))) = v9;
    }
    ++v9;
    v10 += 8;
  }
  while ( v9 < 4 );
  v15 = 0;
  if ( *(int *)a2 > 0 )
  {
    for ( i = 0; ; i += 8 )
    {
      v17 = *(_QWORD *)(i + *(_QWORD *)(a2 + 16));
      if ( *(_DWORD *)(v17 + 304) )
        break;
LABEL_37:
      if ( ++v15 >= *(_DWORD *)a2 )
        return v8;
    }
    v18 = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v17 + 320)
                                                     + 8LL * (unsigned int)(*(_DWORD *)(v17 + 304) - 1))
                                         + 8LL));
    if ( v18 == 13 )
      v18 = 0;
    if ( !v18 )
    {
      v19 = *(_QWORD *)(a1 + 248);
      v20 = 0;
      v21 = 0;
      v22 = v19;
      while ( *(_DWORD *)(*(_QWORD *)v22 + 304LL) )
      {
        ++v20;
        ++v21;
        v22 += 8;
        if ( v20 >= 4 )
          goto LABEL_37;
      }
      if ( a4 )
        goto LABEL_36;
      Src[0] = *(_QWORD *)(i + *(_QWORD *)(a2 + 16));
      v23 = *(_QWORD *)(v19 + 8 * v21);
      Src[1] = *(_QWORD *)(*(_QWORD *)(Src[0] + 320LL) + 8LL * (unsigned int)(*(_DWORD *)(Src[0] + 304LL) - 1));
      Src[4] = v23;
      memcpy(v34, Src, 0x28u);
      v24 = v34;
LABEL_35:
      FreeCellMove::PerformMove(v24);
LABEL_36:
      ++v8;
      goto LABEL_37;
    }
    v25 = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(i + *(_QWORD *)(a2 + 16)) + 320LL)
                                                     + 8LL
                                                     * (unsigned int)(*(_DWORD *)(*(_QWORD *)(i + *(_QWORD *)(a2 + 16))
                                                                                + 304LL)
                                                                    - 1))
                                         + 8LL));
    v26 = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(i + *(_QWORD *)(a2 + 16)) + 320LL)
                                                     + 8LL
                                                     * (unsigned int)(*(_DWORD *)(*(_QWORD *)(i + *(_QWORD *)(a2 + 16))
                                                                                + 304LL)
                                                                    - 1))
                                         + 8LL));
    if ( v26 == 13 )
      v26 = 0;
    if ( *((_DWORD *)&v30 + v25) != v26 )
      goto LABEL_37;
    v27 = a3 == 0;
    if ( v26 == 1 )
      goto LABEL_27;
    if ( !(_DWORD)v25 || (_DWORD)v25 == 2 )
    {
      if ( HIDWORD(v30) >= v26 && HIDWORD(v31) >= v26 )
        v27 = 1;
      goto LABEL_31;
    }
    if ( (unsigned int)v30 >= v26 && (unsigned int)v31 >= v26 )
LABEL_27:
      v27 = 1;
LABEL_31:
    if ( !v27 || *((_DWORD *)v32 + v25) == -1 )
      goto LABEL_37;
    if ( a4 )
      goto LABEL_36;
    Src[0] = *(_QWORD *)(i + *(_QWORD *)(a2 + 16));
    v28 = *(_QWORD *)(a1 + 248);
    Src[1] = *(_QWORD *)(*(_QWORD *)(Src[0] + 320LL) + 8LL * (unsigned int)(*(_DWORD *)(Src[0] + 304LL) - 1));
    Src[4] = *(_QWORD *)(v28 + 8LL * *((unsigned int *)v32 + v25));
    memcpy(v35, Src, 0x28u);
    v24 = v35;
    goto LABEL_35;
  }
  return v8;
}
