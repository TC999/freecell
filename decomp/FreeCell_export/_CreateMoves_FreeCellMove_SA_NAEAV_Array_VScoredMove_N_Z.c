// Hidden C++ exception states: #wind=2
char __fastcall FreeCellMove::CreateMoves(__int64 a1, char a2)
{
  char v2; // r10
  int v3; // edi
  char *v4; // rsi
  unsigned int v5; // ebx
  char *v6; // rbp
  __int64 v7; // rdx
  unsigned int v8; // esi
  __int64 v9; // rdi
  __int64 v10; // r9
  int v11; // ecx
  __int64 v12; // rdx
  __int64 v13; // rax
  __int64 v14; // r8
  int v15; // edx
  struct Card *v16; // rax
  int v17; // edx
  int MoveScore; // eax
  char *v19; // rax
  __int64 v20; // rdi
  unsigned int v21; // esi
  __int64 v22; // rcx
  __int64 v23; // rdx
  char *v24; // rax
  __int64 v25; // rdx
  __int64 v26; // r8
  __int64 v27; // rdi
  unsigned __int64 v28; // rsi
  int v29; // eax
  int v30; // ebx
  unsigned __int64 v31; // rsi
  struct Card *v32; // rbx
  int v33; // eax
  int v34; // eax
  int v35; // edx
  bool hasMoveBeenPlayed; // al
  bool v37; // si
  char v38; // bl
  char *v39; // rdx
  __int64 v40; // r8
  unsigned int *v41; // rbp
  __int64 v42; // rdi
  int v43; // eax
  unsigned int SuitForType; // ebx
  unsigned int RankForType; // ebx
  unsigned int v46; // eax
  char v47; // al
  const void *v48; // rsi
  bool v49; // di
  char v50; // si
  __int64 v51; // rbp
  __int64 v52; // rbx
  int v53; // ebx
  char v54; // al
  int v55; // ebp
  char *v56; // rbx
  char *v57; // rcx
  __int64 v58; // rbp
  char *v59; // rbx
  unsigned int *v60; // rdi
  int v61; // eax
  __int64 v62; // rdx
  __int64 v63; // rsi
  __int64 v64; // rcx
  int v65; // r11d
  __int64 v66; // r10
  __int64 v67; // rbx
  __int64 v68; // r8
  __int64 v69; // r9
  int v70; // eax
  __int64 v71; // rdi
  char Moves; // bl
  __int64 v74; // [rsp+30h] [rbp-158h]
  __int64 v75; // [rsp+30h] [rbp-158h]
  __int64 v76; // [rsp+30h] [rbp-158h]
  __int64 v77; // [rsp+30h] [rbp-158h]
  __int64 v78; // [rsp+30h] [rbp-158h]
  __int64 v79; // [rsp+38h] [rbp-150h]
  __int64 v80; // [rsp+38h] [rbp-150h]
  __int64 v81; // [rsp+38h] [rbp-150h]
  CardStack *Src[4]; // [rsp+40h] [rbp-148h] BYREF
  int v83; // [rsp+60h] [rbp-128h]
  __int64 v84; // [rsp+68h] [rbp-120h]
  char *v85; // [rsp+70h] [rbp-118h]
  _QWORD v86[7]; // [rsp+78h] [rbp-110h] BYREF
  int v87; // [rsp+B0h] [rbp-D8h]
  unsigned int v88; // [rsp+B4h] [rbp-D4h]
  int v89; // [rsp+B8h] [rbp-D0h]
  char *v90; // [rsp+C0h] [rbp-C8h]
  int v91; // [rsp+C8h] [rbp-C0h] BYREF
  unsigned int v92; // [rsp+CCh] [rbp-BCh]
  int v93; // [rsp+D0h] [rbp-B8h]
  _DWORD v94[4]; // [rsp+D8h] [rbp-B0h] BYREF
  char *v95; // [rsp+E8h] [rbp-A0h]
  __int64 v96; // [rsp+F0h] [rbp-98h]
  CardStack *v97; // [rsp+F8h] [rbp-90h]
  __int64 v98; // [rsp+100h] [rbp-88h]
  _BYTE v99[64]; // [rsp+110h] [rbp-78h] BYREF
  __int64 v100; // [rsp+150h] [rbp-38h]
  __int64 v103; // [rsp+1A0h] [rbp+18h] BYREF
  unsigned __int64 v104; // [rsp+1A8h] [rbp+20h]

  v100 = -2;
  v2 = a2;
  v3 = 0;
  LODWORD(v85) = 0;
  v94[0] = 0;
  v94[1] = 0;
  v94[2] = 16;
  v4 = 0;
  v95 = 0;
  v5 = 0;
  v87 = 0;
  v88 = 0;
  v89 = 16;
  v6 = 0;
  v90 = 0;
  v92 = 0;
  if ( *((_DWORD *)g_pFreeCellGame + 46) )
  {
    v7 = 0;
    v74 = 0;
    v8 = 0;
    while ( 1 )
    {
      v9 = *(_QWORD *)(v7 + *((_QWORD *)g_pFreeCellGame + 25));
      v10 = *(int *)(v9 + 304);
      LOBYTE(v104) = 0;
      v11 = 1;
      v83 = 1;
      v12 = v10;
      v84 = v10;
      v13 = 1;
      v98 = 1;
      v14 = 8 * v10 - 8;
      v96 = v14;
      while ( v13 <= v12 )
      {
        v15 = v10 - v11;
        v93 = v10 - v11;
        v16 = *(struct Card **)(v14 + *(_QWORD *)(v9 + 320));
        v97 = v16;
        LOBYTE(v103) = 0;
        if ( v11 != 1 )
        {
          if ( !FreeCellMove::CanMoveCard(v16, (struct CardStack *)v9, 0, 0, (bool *)&v103) )
          {
            LOBYTE(v104) = 1;
            goto LABEL_17;
          }
          v15 = v93;
          v16 = v97;
          v2 = a2;
        }
        v91 = 0;
        if ( v84 == 1 )
        {
          v17 = 0;
          MoveScore = v2 != 0 ? 300 : 1000;
        }
        else
        {
          MoveScore = FreeCellMove::getMoveScore(v9, v16, v15 - 1, &v91);
          v17 = v91;
        }
        Src[0] = (CardStack *)v9;
        Src[1] = v97;
        LODWORD(Src[2]) = v93;
        HIDWORD(Src[2]) = v17 + MoveScore;
        LODWORD(Src[3]) = v83;
        BYTE4(Src[3]) = v103;
        v87 = ++v5;
        if ( v5 <= v8 )
          goto LABEL_16;
        v8 += 16;
        v88 = v8;
        v19 = (char *)realloc(v6, 32LL * v8);
        if ( v19 )
        {
          v6 = v19;
          v90 = v19;
LABEL_16:
          memcpy(&v6[32 * v5 - 32], Src, 0x20u);
          goto LABEL_17;
        }
        CheckAllocation(0);
LABEL_17:
        v11 = ++v83;
        v13 = ++v98;
        v14 = v96 - 8;
        v96 -= 8;
        v12 = v84;
        LODWORD(v10) = v84;
        v2 = a2;
        if ( (_BYTE)v104 )
          break;
      }
      ++v92;
      v7 = v74 + 8;
      v74 += 8;
      if ( v92 >= *((_DWORD *)g_pFreeCellGame + 46) )
      {
        v4 = v95;
        v3 = (int)v85;
        break;
      }
    }
  }
  LODWORD(v103) = 0;
  if ( !*((_DWORD *)g_pFreeCellGame + 52) )
    goto LABEL_33;
  v20 = 0;
  v21 = v88;
  do
  {
    v22 = *((_QWORD *)g_pFreeCellGame + 28);
    v23 = *(_QWORD *)(v20 + v22);
    if ( *(_DWORD *)(v23 + 304) != 1 )
      goto LABEL_31;
    Src[0] = *(CardStack **)(v20 + v22);
    Src[1] = **(CardStack ***)(v23 + 320);
    LODWORD(Src[2]) = 0;
    if ( Card::GetRankForType(*((_DWORD *)Src[1] + 2)) == 12 )
      HIDWORD(Src[2]) = 100;
    else
      HIDWORD(Src[2]) = a2 != 0 ? 300 : 1000;
    LODWORD(Src[3]) = 1;
    v87 = ++v5;
    if ( v5 > v21 )
    {
      v21 += 16;
      v88 = v21;
      v24 = (char *)realloc(v6, 32LL * v21);
      if ( !v24 )
      {
        CheckAllocation(0);
        goto LABEL_31;
      }
      v6 = v24;
      v90 = v24;
    }
    memcpy(&v6[32 * v5 - 32], Src, 0x20u);
LABEL_31:
    LODWORD(v103) = v103 + 1;
    v20 += 8;
  }
  while ( (unsigned int)v103 < *((_DWORD *)g_pFreeCellGame + 52) );
  v4 = v95;
  v3 = (int)v85;
LABEL_33:
  if ( v5 )
  {
    v25 = 0;
    v75 = 0;
    v26 = 8;
    v84 = 8;
    while ( 2 )
    {
      v27 = *(_QWORD *)(v25 + *((_QWORD *)g_pFreeCellGame + 25));
      if ( !v5 )
        goto LABEL_59;
      v28 = v5;
      v104 = v5;
      while ( 2 )
      {
        memcpy(Src, v6, sizeof(Src));
        if ( Src[0] != (CardStack *)v27 && (BYTE4(Src[3]) || LODWORD(Src[3]) == 1 || *(_DWORD *)(v27 + 304)) )
        {
          LODWORD(v103) = 0;
          v29 = *(_DWORD *)(v27 + 304);
          if ( !v29 )
          {
            v30 = a2 != 0 ? 300 : 1000;
            v31 = (unsigned __int64)Src[2] >> 32;
            goto LABEL_45;
          }
          v32 = Src[1];
          if ( FreeCellMove::DoesCardFollowSequence(
                 *(struct Card **)(*(_QWORD *)(v27 + 320) + 8LL * (unsigned int)(v29 - 1)),
                 Src[1]) )
          {
            v33 = FreeCellMove::getMoveScore(v27, v32, *(_DWORD *)(v27 + 304) - 1, &v103);
            v30 = v103 + v33;
            LODWORD(v31) = HIDWORD(Src[2]);
LABEL_45:
            v86[0] = Src[0];
            v86[1] = Src[1];
            LODWORD(v86[2]) = CardStack::GetCardLocation(Src[0], Src[1]);
            v86[4] = v27;
            HIDWORD(v86[2]) = *(_DWORD *)(v27 + 304);
            LODWORD(v86[3]) = Src[3];
            LODWORD(v86[5]) = v30 - v31;
            HIDWORD(v86[5]) = v30;
            if ( v30 - (int)v31 <= 0
              && ((v34 = FreeCellMove::StackToMoveDestination((__int64)Src[0], 0), v34 != v35)
               && LODWORD(Src[3]) != *((_DWORD *)Src[0] + 76)
               || *(_DWORD *)(v27 + 304) == v35)
              || (hasMoveBeenPlayed = FreeCellMove::hasMoveBeenPlayed((struct Move *)v86),
                  LOBYTE(v35) = 0,
                  hasMoveBeenPlayed) )
            {
              LOBYTE(v86[6]) = v35;
            }
            else
            {
              LOBYTE(v86[6]) = 1;
            }
            if ( v30 == (_DWORD)v31 && (unsigned int)(v30 - 800) <= 0x63 )
              BYTE1(v86[6]) = 1;
            else
              BYTE1(v86[6]) = v35;
            WORD1(v86[6]) = FreeCellMove::hasMoveBeenPlayed((struct Move *)v86);
            memcpy(v99, v86, 0x38u);
            Array<ScoredMove>::Push((__int64)v94, v99);
            v28 = v104;
          }
        }
        v6 += 32;
        v104 = --v28;
        if ( v28 )
          continue;
        break;
      }
      v6 = v90;
      v5 = v87;
      v25 = v75;
      v26 = v84;
LABEL_59:
      v25 += 8;
      v75 = v25;
      v84 = --v26;
      if ( v26 )
        continue;
      break;
    }
    if ( v5 )
    {
      v85 = v6;
      v76 = v5;
      while ( 1 )
      {
        memcpy(Src, v6, sizeof(Src));
        v37 = 0;
        v38 = 0;
        LOBYTE(v103) = 0;
        v39 = 0;
        v104 = 0;
        v40 = 4;
        v79 = 4;
        v41 = (unsigned int *)Src[1];
        do
        {
          v42 = *(_QWORD *)&v39[*((_QWORD *)g_pFreeCellGame + 31)];
          if ( LODWORD(Src[3]) != 1 )
            goto LABEL_87;
          if ( !*(_DWORD *)(v42 + 304) )
          {
            if ( Card::GetRankForType(v41[2]) == 13 )
              goto LABEL_75;
            v39 = (char *)v104;
            v40 = v79;
          }
          v43 = *(_DWORD *)(v42 + 304);
          if ( !v43 )
            goto LABEL_87;
          SuitForType = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v42 + 320)
                                                                   + 8LL * (unsigned int)(v43 - 1))
                                                       + 8LL));
          if ( SuitForType != Card::GetSuitForType(v41[2]) )
          {
            v39 = (char *)v104;
            v38 = v103;
            v40 = v79;
            goto LABEL_87;
          }
          RankForType = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v42 + 320)
                                                                   + 8LL * (unsigned int)(*(_DWORD *)(v42 + 304) - 1))
                                                       + 8LL));
          if ( RankForType == 13 )
            RankForType = 0;
          v46 = Card::GetRankForType(v41[2]);
          if ( v46 == 13 )
            v46 = 0;
          if ( RankForType + 1 != v46 )
          {
            v39 = (char *)v104;
            v38 = v103;
            v40 = v79;
            goto LABEL_87;
          }
          v38 = v103;
LABEL_75:
          v86[0] = Src[0];
          v86[1] = v41;
          v86[4] = v42;
          HIDWORD(v86[2]) = *(_DWORD *)(v42 + 304);
          LODWORD(v86[3]) = 1;
          LODWORD(v86[2]) = CardStack::GetCardLocation(Src[0], (struct Card *)v41);
          LODWORD(v86[5]) = 900 - HIDWORD(Src[2]);
          HIDWORD(v86[5]) = 900;
          if ( v37 || 900 - HIDWORD(Src[2]) <= 0 || FreeCellMove::hasMoveBeenPlayed((struct Move *)v86) )
          {
            v47 = 0;
            LOBYTE(v86[6]) = 0;
          }
          else
          {
            v47 = 1;
            LOBYTE(v86[6]) = 1;
          }
          *(_WORD *)((char *)&v86[6] + 1) = 0;
          BYTE3(v86[6]) = v38;
          v37 = v37 || v47;
          v38 = 1;
          LOBYTE(v103) = 1;
          memcpy(v99, v86, 0x38u);
          Array<ScoredMove>::Push((__int64)v94, v99);
          v39 = (char *)v104;
          v40 = v79;
LABEL_87:
          v39 += 8;
          v104 = (unsigned __int64)v39;
          v79 = --v40;
        }
        while ( v40 );
        v6 = v85 + 32;
        v85 += 32;
        if ( !--v76 )
        {
          v6 = v90;
          v5 = v87;
          break;
        }
      }
    }
    if ( v5 )
    {
      v48 = v6;
      v104 = (unsigned __int64)v6;
      v77 = v5;
      do
      {
        memcpy(Src, v48, sizeof(Src));
        v49 = 0;
        v50 = 0;
        v51 = 0;
        v103 = 4;
        do
        {
          v52 = *(_QWORD *)(*((_QWORD *)g_pFreeCellGame + 28) + v51);
          v84 = v52;
          if ( (unsigned int)FreeCellMove::StackToMoveDestination((__int64)Src[0], 0)
            && !*(_DWORD *)(v52 + 304)
            && LODWORD(Src[3]) == 1
            && Card::GetRankForType(*((_DWORD *)Src[1] + 2)) != 13 )
          {
            v53 = a2 != 0 ? 300 : 1000;
            if ( Card::GetRankForType(*((_DWORD *)Src[1] + 2)) == 12 )
              v53 = 100;
            v86[0] = Src[0];
            v86[1] = Src[1];
            v86[4] = v84;
            HIDWORD(v86[2]) = *(_DWORD *)(v84 + 304);
            LODWORD(v86[3]) = 1;
            LODWORD(v86[2]) = CardStack::GetCardLocation(Src[0], Src[1]);
            LODWORD(v86[5]) = v53 - HIDWORD(Src[2]);
            HIDWORD(v86[5]) = v53;
            if ( v49 || v53 - HIDWORD(Src[2]) <= 0 || FreeCellMove::hasMoveBeenPlayed((struct Move *)v86) )
            {
              v54 = 0;
              LOBYTE(v86[6]) = 0;
            }
            else
            {
              v54 = 1;
              LOBYTE(v86[6]) = 1;
            }
            BYTE1(v86[6]) = 0;
            BYTE3(v86[6]) = v50;
            v49 = v49 || v54;
            v50 = 1;
            BYTE2(v86[6]) = FreeCellMove::hasMoveBeenPlayed((struct Move *)v86);
            memcpy(v99, v86, 0x38u);
            Array<ScoredMove>::Push((__int64)v94, v99);
          }
          v51 += 8;
          --v103;
        }
        while ( v103 );
        v48 = (const void *)(v104 + 32);
        v104 += 32LL;
        --v77;
      }
      while ( v77 );
      v4 = v95;
      v3 = v94[0];
      v6 = v90;
    }
    else
    {
      v4 = v95;
      v3 = v94[0];
    }
  }
  *(_DWORD *)a1 = 0;
  LODWORD(v103) = 0;
  if ( v3 )
  {
    v55 = 0;
    do
    {
      LODWORD(v104) = rand() % v3;
      v56 = &v4[56 * (unsigned int)v104];
      memcpy(v99, v56, 0x38u);
      Array<ScoredMove>::Push(a1, v99);
      if ( v56[48] )
        LODWORD(v103) = ++v55;
      if ( (unsigned int)v104 < --v3 )
      {
        v57 = &v4[56 * (int)v104];
        v58 = (unsigned int)(v3 - v104);
        do
        {
          v59 = v57 + 56;
          memcpy(v57, v57 + 56, 0x38u);
          v57 = v59;
          --v58;
        }
        while ( v58 );
        v55 = v103;
      }
      v94[0] = v3;
    }
    while ( v3 );
    v6 = v90;
  }
  v60 = (unsigned int *)a1;
  v61 = *(_DWORD *)a1 - 1;
  v62 = v61;
  if ( v61 >= 0 )
  {
    v63 = 56LL * v61;
    do
    {
      v64 = v62;
      LODWORD(v104) = v61 - 1;
      v65 = v61 - 1;
      v66 = v62 - 1;
      v78 = v62 - 1;
      if ( v61 >= 1 )
      {
        v67 = v63;
        v68 = v63 - 56;
        do
        {
          if ( v64 == -1
            || (v69 = *((_QWORD *)v60 + 2), v70 = *(_DWORD *)(v67 + v69 + 40), *(_DWORD *)(v68 + v69 + 40) < v70)
            || *(_DWORD *)(v68 + v69 + 40) == v70 && *(_DWORD *)(v68 + v69 + 44) < *(_DWORD *)(v67 + v69 + 44) )
          {
            v64 = v66;
            v67 = v68;
          }
          --v65;
          --v66;
          v68 -= 56;
        }
        while ( v65 >= 0 );
        v80 = v64;
        if ( v64 != v62 )
        {
          v71 = *((_QWORD *)v60 + 2);
          memcpy(v99, (const void *)(v63 + v71), 0x38u);
          v81 = 56 * v80;
          memcpy((void *)(v63 + v71), (const void *)(v81 + v71), 0x38u);
          v60 = (unsigned int *)a1;
          memcpy((void *)(*(_QWORD *)(a1 + 16) + v81), v99, 0x38u);
        }
      }
      v61 = v104;
      v62 = v78;
      v63 -= 56;
    }
    while ( (v104 & 0x80000000) == 0LL );
    v4 = v95;
  }
  if ( (_DWORD)v103 || !a2 )
  {
    Log(0x10000000u, L"CreateHints(): Hints generated: %d (%d advancing), cards observed: %d", *v60);
    if ( a2 )
    {
      if ( v6 )
        free(v6);
      if ( v4 )
        free(v4);
      return 1;
    }
    else
    {
      if ( v6 )
        free(v6);
      if ( v4 )
        free(v4);
      return 0;
    }
  }
  else
  {
    *v60 = 0;
    Log(0x10000000u, L"CreateHints(): No hints found, recalculating with empty stacks low");
    Moves = FreeCellMove::CreateMoves(v60, 0);
    if ( v6 )
      free(v6);
    if ( v4 )
      free(v4);
    return Moves;
  }
}
