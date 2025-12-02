// Hidden C++ exception states: #wind=1
char __fastcall CardTable::GetCardStackIntersect(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // r14
  char v6; // r12
  unsigned int v7; // r13d
  int *v8; // rdi
  __int64 v9; // r15
  __int64 v10; // r14
  int v11; // eax
  __int64 v12; // rbx
  int v13; // ebp
  unsigned int v14; // ebx
  __int64 v15; // r12
  unsigned int v16; // eax
  int *v17; // rax
  unsigned int v18; // eax
  int *v19; // rdx
  __int64 v20; // r8
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  void *v23; // rax
  int v24; // eax
  __int64 v25; // r8
  __int64 v26; // r9
  RECT rcSrc2; // [rsp+28h] [rbp-80h] BYREF
  RECT rcSrc1; // [rsp+38h] [rbp-70h] BYREF
  struct tagRECT rcDst; // [rsp+48h] [rbp-60h] BYREF
  unsigned int v31; // [rsp+58h] [rbp-50h]
  unsigned int v32; // [rsp+5Ch] [rbp-4Ch]
  int v33; // [rsp+60h] [rbp-48h]
  int *v34; // [rsp+68h] [rbp-40h]
  unsigned int v36; // [rsp+C0h] [rbp+18h]

  v5 = a1;
  v6 = 0;
  v7 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 16;
  v8 = 0;
  v34 = 0;
  NodeBase::GetLayoutLocation(*(NodeBase **)(a3 + 104), &rcSrc1.top, &rcSrc1.left);
  NodeBase::GetLayoutSize(*(NodeBase **)(a3 + 104), (unsigned int *)&rcSrc1.bottom, (unsigned int *)&rcSrc1.right);
  rcSrc1.bottom += rcSrc1.top;
  rcSrc1.right += rcSrc1.left;
  v36 = 0;
  if ( *(_DWORD *)(v5 + 160) )
  {
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)(v9 + *(_QWORD *)(v5 + 152));
      v11 = *(_DWORD *)(v10 + 304);
      if ( v11 )
      {
        v12 = *(_QWORD *)(*(_QWORD *)(v10 + 320) + 8LL * (unsigned int)(v11 - 1));
        NodeBase::GetLayoutLocation(*(NodeBase **)(v12 + 104), &rcSrc2.top, &rcSrc2.left);
        NodeBase::GetLayoutSize(
          *(NodeBase **)(v12 + 104),
          (unsigned int *)&rcSrc2.bottom,
          (unsigned int *)&rcSrc2.right);
      }
      else
      {
        NodeBase::GetLayoutLocation(*(NodeBase **)(v10 + 144), &rcSrc2.top, &rcSrc2.left);
        NodeBase::GetLayoutSize(
          *(NodeBase **)(v10 + 144),
          (unsigned int *)&rcSrc2.bottom,
          (unsigned int *)&rcSrc2.right);
      }
      rcSrc2.bottom += rcSrc2.top;
      rcSrc2.right += rcSrc2.left;
      if ( !IntersectRect(&rcDst, &rcSrc1, &rcSrc2) )
        goto LABEL_30;
      v13 = (rcDst.right - rcDst.left) * (rcDst.bottom - rcDst.top);
      if ( (unsigned int)(rcDst.right - rcDst.left) < 0xA || (unsigned int)(rcDst.bottom - rcDst.top) < 0x14 )
        goto LABEL_30;
      v14 = 0;
      v15 = 0;
      if ( v7 && v13 < *v8 )
      {
        do
        {
          ++v14;
          ++v15;
        }
        while ( v14 < v7 && v13 < v8[v15] );
      }
      v31 = ++v7;
      v16 = v32;
      if ( v7 > v32 )
      {
        v32 += 16;
        v17 = (int *)realloc(v8, 4LL * (v16 + 16));
        if ( !v17 )
        {
          CheckAllocation(0);
          goto LABEL_21;
        }
        v8 = v17;
        v34 = v17;
      }
      v18 = v7 - 1;
      if ( v7 - 1 > v14 )
      {
        v19 = &v8[v18];
        v20 = v18 - v14;
        do
        {
          *v19 = *(v19 - 1);
          --v19;
          --v20;
        }
        while ( v20 );
      }
      v8[v15] = v13;
LABEL_21:
      ++*(_DWORD *)a2;
      v21 = *(_DWORD *)(a2 + 4);
      if ( *(_DWORD *)a2 <= v21 )
        goto LABEL_25;
      v22 = *(_DWORD *)(a2 + 8) + v21;
      *(_DWORD *)(a2 + 4) = v22;
      v23 = realloc(*(void **)(a2 + 16), 8LL * v22);
      if ( v23 )
      {
        *(_QWORD *)(a2 + 16) = v23;
LABEL_25:
        v24 = *(_DWORD *)a2 - 1;
        if ( v24 > v14 )
        {
          v25 = 8LL * v24;
          v26 = v24 - v14;
          do
          {
            *(_QWORD *)(v25 + *(_QWORD *)(a2 + 16)) = *(_QWORD *)(v25 + *(_QWORD *)(a2 + 16) - 8);
            v25 -= 8;
            --v26;
          }
          while ( v26 );
        }
        *(_QWORD *)(*(_QWORD *)(a2 + 16) + 8 * v15) = v10;
        goto LABEL_29;
      }
      CheckAllocation(0);
LABEL_29:
      v6 = 1;
LABEL_30:
      ++v36;
      v9 += 8;
      v5 = a1;
    }
    while ( v36 < *(_DWORD *)(a1 + 160) );
  }
  if ( v8 )
    free(v8);
  return v6;
}
