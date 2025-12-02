__int64 __fastcall FreeCellMove::getMoveScore(__int64 a1, struct Card *a2, int a3, _DWORD *a4)
{
  int v4; // ebp
  __int64 v5; // rbx
  int v6; // edi
  int v7; // r12d
  char v8; // si
  __int64 v9; // r13
  unsigned int *v10; // r15
  FreeCellGame *v11; // rcx
  unsigned int v12; // r9d
  __int64 v13; // rdx
  __int64 v14; // r8
  __int64 v15; // rdx
  __int64 v16; // r8
  unsigned int v17; // r12d
  __int64 v18; // rdx
  unsigned int v19; // r14d
  __int64 v20; // r13
  __int64 v21; // rbp
  int v22; // eax
  unsigned int SuitForType; // ebx
  unsigned int RankForType; // ebx
  unsigned int v25; // eax
  __int64 v26; // rdx
  unsigned int v27; // r14d
  __int64 v28; // r13
  __int64 v29; // rdx
  struct Card *v30; // rbx
  char v31; // r15
  __int64 v32; // r12
  __int64 v33; // rbp
  __int64 v34; // rax
  struct Card *v35; // r14
  bool v36; // zf
  unsigned int v38; // [rsp+30h] [rbp-78h]
  int v39; // [rsp+34h] [rbp-74h] BYREF
  int v40; // [rsp+38h] [rbp-70h]
  int v41; // [rsp+3Ch] [rbp-6Ch]
  int v42; // [rsp+40h] [rbp-68h]
  __int64 v43; // [rsp+48h] [rbp-60h]
  struct Card *v44; // [rsp+50h] [rbp-58h]
  __int64 v45; // [rsp+58h] [rbp-50h]
  struct Card *v47; // [rsp+B8h] [rbp+10h]
  unsigned int v48; // [rsp+C0h] [rbp+18h]

  v47 = a2;
  v4 = a3;
  v5 = a1;
  v6 = 800;
  v42 = a3;
  v7 = 0;
  v41 = 0;
  v8 = 0;
  v9 = a3;
  v45 = a3;
  while ( v4 >= 0 )
  {
    v10 = *(unsigned int **)(*(_QWORD *)(v5 + 320) + 8 * v9);
    if ( !FreeCellMove::DoesCardFollowSequence((struct Card *)v10, a2) )
    {
      v11 = g_pFreeCellGame;
      v12 = 0;
      v38 = 0;
      if ( *((_DWORD *)g_pFreeCellGame + 52) )
      {
        v13 = *((_QWORD *)g_pFreeCellGame + 28);
        v14 = *((unsigned int *)g_pFreeCellGame + 52);
        do
        {
          if ( !*(_DWORD *)(*(_QWORD *)v13 + 304LL) )
            ++v12;
          v13 += 8;
          --v14;
        }
        while ( v14 );
        v38 = v12;
      }
      if ( *((_DWORD *)g_pFreeCellGame + 46) )
      {
        v15 = *((_QWORD *)g_pFreeCellGame + 25);
        v16 = *((unsigned int *)g_pFreeCellGame + 46);
        do
        {
          if ( !*(_DWORD *)(*(_QWORD *)v15 + 304LL) )
            ++v12;
          v15 += 8;
          --v16;
        }
        while ( v16 );
        v38 = v12;
      }
      v6 = 700;
      v17 = 1;
      v18 = v9;
      if ( v4 <= (int)v12 )
        v6 = 500;
      v40 = 1;
      v43 = v9;
      while ( 1 )
      {
        if ( v18 < 0 || v17 > v12 )
        {
LABEL_67:
          v4 = v42;
          v9 = v45;
          v7 = v41;
          v8 = 1;
          goto LABEL_69;
        }
        v19 = 0;
        v10 = *(unsigned int **)(*(_QWORD *)(v5 + 320) + 8 * v18);
        v44 = (struct Card *)v10;
        v20 = 0;
        while ( v19 < 4 )
        {
          v21 = *(_QWORD *)(v20 + *((_QWORD *)v11 + 31));
          if ( !*(_DWORD *)(v21 + 304) )
          {
            if ( Card::GetRankForType(v10[2]) == 13 )
              goto LABEL_35;
            v11 = g_pFreeCellGame;
          }
          v22 = *(_DWORD *)(v21 + 304);
          if ( v22 )
          {
            SuitForType = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 320)
                                                                     + 8LL * (unsigned int)(v22 - 1))
                                                         + 8LL));
            if ( SuitForType == Card::GetSuitForType(v10[2]) )
            {
              RankForType = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + 320)
                                                                       + 8LL
                                                                       * (unsigned int)(*(_DWORD *)(v21 + 304) - 1))
                                                           + 8LL));
              if ( RankForType == 13 )
                RankForType = 0;
              v25 = Card::GetRankForType(v10[2]);
              if ( v25 == 13 )
                v25 = 0;
              if ( RankForType + 1 == v25 )
              {
LABEL_35:
                v8 = 1;
                v6 = v17 != 1 ? 0x190 : 0;
              }
            }
            v11 = g_pFreeCellGame;
          }
          ++v19;
          v20 += 8;
          if ( v8 )
            break;
        }
        v26 = v43;
        v27 = 0;
        v48 = 0;
        if ( !v8 )
          break;
LABEL_66:
        v12 = v38;
        v5 = a1;
        ++v17;
        v18 = v26 - 1;
        v40 = v17;
        v43 = v18;
        if ( v8 )
          goto LABEL_67;
      }
      v28 = 0;
      while ( 2 )
      {
        if ( v27 >= *((_DWORD *)v11 + 46) )
        {
LABEL_65:
          v26 = v43;
          goto LABEL_66;
        }
        v29 = *(_QWORD *)(v28 + *((_QWORD *)v11 + 25));
        if ( *(_DWORD *)(v29 + 304) )
        {
          if ( !FreeCellMove::DoesCardFollowSequence(
                  *(struct Card **)(*(_QWORD *)(v29 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v29 + 304) - 1)),
                  (struct Card *)v10) )
          {
            v30 = 0;
            v31 = 0;
            v32 = *(_QWORD *)(v28 + *((_QWORD *)g_pFreeCellGame + 25));
            v33 = *(_DWORD *)(v32 + 304) - 1;
            do
            {
              if ( v33 < 0 )
                break;
              v34 = *(_QWORD *)(v32 + 320);
              v35 = *(struct Card **)(v34 + 8 * v33);
              if ( !v30 || FreeCellMove::DoesCardFollowSequence(*(struct Card **)(v34 + 8 * v33), v30) )
                v30 = v35;
              else
                v31 = 1;
              --v33;
            }
            while ( !v31 );
            v17 = v40;
            v10 = (unsigned int *)v44;
            v39 = 0;
            if ( !v30
              || !FreeCellMove::DoesCardFollowSequence(v44, v30)
              || !FreeCellMove::CanMoveCard(
                    v30,
                    *(struct CardStack **)(v28 + *((_QWORD *)g_pFreeCellGame + 25)),
                    0,
                    &v39,
                    0)
              || (int)(v39 - v17) < 0 )
            {
              v27 = v48;
              goto LABEL_63;
            }
            v27 = v48;
          }
          if ( v17 == 1 && v6 > 500 )
          {
            v6 = 500;
          }
          else if ( v6 > 600 )
          {
            v6 = 600;
          }
          v8 = 1;
LABEL_63:
          v11 = g_pFreeCellGame;
        }
        ++v27;
        v28 += 8;
        v48 = v27;
        if ( v8 )
          goto LABEL_65;
        continue;
      }
    }
    v41 = ++v7;
LABEL_69:
    --v4;
    --v9;
    a2 = (struct Card *)v10;
    v42 = v4;
    v45 = v9;
    if ( v8 )
      break;
  }
  *a4 = v7;
  if ( !v8 )
  {
    v36 = *(_DWORD *)(v5 + 304) == 0;
    if ( *(_DWORD *)(v5 + 304) )
    {
      if ( Card::GetRankForType(*(_DWORD *)(**(_QWORD **)(v5 + 320) + 8LL)) == 12 )
        return (unsigned int)v6;
      v36 = *(_DWORD *)(v5 + 304) == 0;
    }
    if ( v36 )
      Card::GetRankForType(*((_DWORD *)v47 + 2));
  }
  return (unsigned int)v6;
}
