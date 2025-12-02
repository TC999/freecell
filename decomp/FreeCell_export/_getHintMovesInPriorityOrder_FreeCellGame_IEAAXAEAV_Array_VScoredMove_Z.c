// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::getHintMovesInPriorityOrder(__int64 a1, __int64 a2)
{
  __int64 v4; // rdx
  unsigned int v5; // ebx
  unsigned int v6; // r13d
  char *v7; // rdi
  int v8; // r12d
  __int64 v9; // rbp
  char *v10; // rax
  int v11; // esi
  __int64 v12; // rbx
  _BYTE *v13; // rdx
  int v14; // esi
  __int64 v15; // rbx
  _BYTE *v16; // rdx
  int v17; // esi
  __int64 v18; // rbx
  _BYTE *v19; // rdx
  int v20; // esi
  __int64 v21; // rbx
  _BYTE *v22; // rdx
  int v23; // eax
  __int64 v24; // rbx
  _BYTE *v25; // rdx
  int v26; // [rsp+28h] [rbp-80h] BYREF
  unsigned int v27; // [rsp+2Ch] [rbp-7Ch]
  int v28; // [rsp+30h] [rbp-78h]
  char *v29; // [rsp+38h] [rbp-70h]
  _BYTE v30[64]; // [rsp+40h] [rbp-68h] BYREF

  if ( !*(_BYTE *)(a1 + 373) )
  {
    FreeCellGame::invalidateHints((FreeCellGame *)a1);
    LOBYTE(v4) = *(_BYTE *)(a1 + 374) == 0;
    FreeCellMove::CreateMoves(a1 + 280, v4);
    Log(0x10000000u, L"Generated %d hints", *(unsigned int *)(a1 + 280));
    *(_BYTE *)(a1 + 373) = 1;
  }
  v5 = 0;
  v26 = 0;
  v6 = 0;
  v27 = 0;
  v28 = 16;
  v7 = 0;
  v29 = 0;
  v8 = *(_DWORD *)(a1 + 280) - 1;
  if ( v8 >= 0 )
  {
    while ( 1 )
    {
      v9 = *(_QWORD *)(a1 + 296) + 56LL * (unsigned int)v8;
      v26 = ++v5;
      if ( v5 <= v6 )
        goto LABEL_8;
      v6 += 16;
      v27 = v6;
      v10 = (char *)realloc(v7, 8LL * v6);
      if ( v10 )
        break;
      CheckAllocation(0);
LABEL_9:
      if ( --v8 < 0 )
        goto LABEL_10;
    }
    v7 = v10;
    v29 = v10;
LABEL_8:
    *(_QWORD *)&v7[8 * v5 - 8] = v9;
    goto LABEL_9;
  }
LABEL_10:
  v11 = v5 - 1;
  if ( (int)(v5 - 1) >= 0 )
  {
    v12 = 8LL * v11;
    do
    {
      v13 = *(_BYTE **)&v7[v12];
      if ( v13[48] && !v13[49] && !v13[50] && !v13[51] )
      {
        memcpy(v30, v13, 0x38u);
        Array<ScoredMove>::Push(a2, v30);
        Array<ScoredMove *>::Remove(&v26, (unsigned int)v11);
        v7 = v29;
      }
      --v11;
      v12 -= 8;
    }
    while ( v11 >= 0 );
    v5 = v26;
  }
  v14 = v5 - 1;
  if ( (int)(v5 - 1) >= 0 )
  {
    v15 = 8LL * v14;
    do
    {
      v16 = *(_BYTE **)&v7[v15];
      if ( v16[48] && v16[49] && !v16[50] && !v16[51] )
      {
        memcpy(v30, v16, 0x38u);
        Array<ScoredMove>::Push(a2, v30);
        Array<ScoredMove *>::Remove(&v26, (unsigned int)v14);
        v7 = v29;
      }
      --v14;
      v15 -= 8;
    }
    while ( v14 >= 0 );
    v5 = v26;
  }
  v17 = v5 - 1;
  if ( (int)(v5 - 1) >= 0 )
  {
    v18 = 8LL * v17;
    do
    {
      v19 = *(_BYTE **)&v7[v18];
      if ( !v19[49] && !v19[50] && !v19[51] )
      {
        memcpy(v30, v19, 0x38u);
        Array<ScoredMove>::Push(a2, v30);
        Array<ScoredMove *>::Remove(&v26, (unsigned int)v17);
        v7 = v29;
      }
      --v17;
      v18 -= 8;
    }
    while ( v17 >= 0 );
    v5 = v26;
  }
  v20 = v5 - 1;
  if ( (int)(v5 - 1) >= 0 )
  {
    v21 = 8LL * v20;
    do
    {
      v22 = *(_BYTE **)&v7[v21];
      if ( v22[49] && !v22[50] && !v22[51] )
      {
        memcpy(v30, v22, 0x38u);
        Array<ScoredMove>::Push(a2, v30);
        Array<ScoredMove *>::Remove(&v26, (unsigned int)v20);
        v7 = v29;
      }
      --v20;
      v21 -= 8;
    }
    while ( v20 >= 0 );
    v5 = v26;
  }
  v23 = v5 - 1;
  v24 = (int)(v5 - 1);
  if ( v23 >= 0 )
  {
    do
    {
      v25 = *(_BYTE **)&v7[8 * v24];
      if ( v25[50] && !v25[51] )
      {
        memcpy(v30, v25, 0x38u);
        Array<ScoredMove>::Push(a2, v30);
      }
      --v24;
    }
    while ( v24 >= 0 );
  }
  if ( v7 )
    free(v7);
}
