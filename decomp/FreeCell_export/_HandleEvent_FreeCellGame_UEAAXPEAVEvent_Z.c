void __fastcall FreeCellGame::HandleEvent(FreeCellGame *this, struct Event *a2)
{
  int v3; // ecx
  const unsigned __int16 *v5; // rdx
  struct Card *v6; // rbp
  struct Card *v7; // rax
  struct Card *v8; // r12
  CardTable *v9; // rbx
  struct CardStack *v10; // rbp
  struct CardStack *v11; // rax
  struct CardStack *v12; // rbx
  unsigned int HighestPlaceableCardIndex; // eax
  FreeCellGame *v14; // rcx
  CardTable *v15; // rcx
  CardAnimationManager *v16; // rcx
  __int64 v17; // r9
  __int64 v18; // r11
  __int64 v19; // rax
  _QWORD *v20; // rax
  struct Card *v21; // r12
  struct Card *v22; // r14
  struct CardStack *v23; // r15
  __int64 v24; // r8
  __int64 v25; // r9
  __int64 v26; // rax
  const unsigned __int16 *v27; // rdx
  struct Card *v28; // rbx
  struct CardStack *v29; // rax
  struct CardStack *v30; // rax
  struct CardStack *v31; // r12
  __int64 v32; // rax
  WPARAM v33; // r8
  __int64 v34; // rax
  const unsigned __int16 *v35; // rbx
  struct Card *v36; // rax
  struct CardStack *CardStack; // rbx
  const unsigned __int16 **v38; // rbx
  struct NodeBase *v39; // rdx
  int v40; // eax
  int v41; // eax
  struct CardStack *v42; // rax
  unsigned int v43; // r8d
  __int64 v44; // rdx
  __int64 v46; // rbx
  struct CardStack *v47; // rax
  int v48; // r8d
  __int64 j; // rdx
  int v51; // ecx
  int v52; // ecx
  int v53; // ecx
  int v54; // ecx
  int v55; // ecx
  __int64 v56; // rax
  __int64 v57; // rbx
  const unsigned __int16 *v58; // rbx
  struct NodeBase *v59; // rax
  struct Card *v60; // rax
  const unsigned __int16 **v61; // rbx
  struct CardStack *v62; // rax
  unsigned int v63; // ecx
  unsigned int v64; // ecx
  unsigned int v65; // ecx
  unsigned int v66; // ecx
  unsigned int v67; // ecx
  struct CardStack *v68; // rdx
  tagPOINT v69; // rcx
  struct Card *v70; // rbx
  int v71; // r14d
  unsigned int v72; // r15d
  int v73; // r13d
  __int64 v74; // r12
  struct CardStack *v75; // rax
  int v76; // edx
  bool v77; // zf
  __int64 v78; // rbx
  __int64 v79; // rax
  __int64 v80; // rcx
  CardAnimationManager *v81; // rcx
  struct CardStack *v82; // rax
  unsigned int v83; // ecx
  unsigned int v84; // ecx
  unsigned int v85; // ecx
  __int64 v86; // rbx
  unsigned int v87; // r12d
  struct CardStack *v88; // rax
  unsigned int v89; // r13d
  __int64 v90; // r14
  __int64 v91; // r15
  int v92; // eax
  unsigned int SuitForType; // ebx
  unsigned int RankForType; // ebx
  unsigned int v95; // eax
  __int64 v96; // rbx
  struct NodeBase *v97; // rbx
  __int64 v98; // rbx
  struct NodeBase *v99; // rbx
  UINT v100; // ebx
  const unsigned __int16 *v101; // rdx
  struct Card *v102; // rax
  CardTable *v103; // rcx
  const unsigned __int16 *v104; // rdx
  struct Card *v105; // rax
  __int64 v106; // rax
  unsigned int v107; // edx
  _DWORD *v108; // rcx
  struct Card *Card; // rbx
  struct CardStack *CardStackWithCard; // rax
  int v111; // ecx
  const unsigned __int16 *v112; // rdx
  struct NodeBase *CurrentFocus; // r13
  char v114; // r12
  char v115; // r8
  unsigned int v116; // ebp
  __int64 i; // rbx
  __int64 v118; // rax
  CardStack *v119; // rcx
  __int64 v120; // rdx
  tagPOINT Point; // [rsp+78h] [rbp+10h] BYREF

  v3 = *((_DWORD *)a2 + 4);
  if ( v3 > 21 )
  {
    v51 = v3 - 22;
    if ( v51 )
    {
      v52 = v51 - 3;
      if ( !v52 )
      {
        if ( !*((_BYTE *)a2 + 24) )
          return;
        if ( *((_BYTE *)this + 356) && *((_DWORD *)this - 2) != 2 )
        {
          *((_BYTE *)a2 + 24) = 0;
          return;
        }
        v106 = *((_QWORD *)a2 + 1);
        if ( !v106 )
          goto LABEL_232;
        v107 = 0;
        if ( !*(_DWORD *)(v106 + 104) )
          goto LABEL_232;
        v108 = *(_DWORD **)(v106 + 120);
        while ( *v108 != 2 )
        {
          ++v107;
          ++v108;
          if ( v107 >= *(_DWORD *)(v106 + 104) )
            goto LABEL_232;
        }
        v112 = *(const unsigned __int16 **)(v106 + 128);
        if ( v112 )
          Card = CardTable::GetCard(*((CardTable **)this + 20), v112);
        else
LABEL_232:
          Card = 0;
        CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), Card);
        if ( !*((_BYTE *)a2 + 25)
          && (*((_QWORD *)this + 36)
           || CardStackWithCard
           && (v111 = *((_DWORD *)CardStackWithCard + 76)) != 0
           && *(struct Card **)(*((_QWORD *)CardStackWithCard + 40) + 8LL * (unsigned int)(v111 - 1)) != Card)
          || !FreeCellGame::OnCanDragCardCheck((CardTable **)this - 2, Card) )
        {
          *((_BYTE *)a2 + 24) = 0;
        }
        return;
      }
      v53 = v52 - 1;
      if ( !v53 )
      {
        v103 = (CardTable *)*((_QWORD *)this + 20);
        *((_BYTE *)this + 356) = 0;
        if ( !*(_DWORD *)(*((_QWORD *)v103 + 11) + 40LL) )
        {
          v104 = *(const unsigned __int16 **)(*((_QWORD *)a2 + 1) + 128LL);
          if ( v104 )
          {
            v105 = CardTable::GetCard(v103, v104);
            if ( v105 )
              FreeCellGame::OnCardDragStarted((CardTable **)this - 2, v105);
          }
        }
        return;
      }
      v54 = v53 - 2;
      if ( !v54 )
      {
        v101 = *(const unsigned __int16 **)(*((_QWORD *)a2 + 1) + 128LL);
        if ( v101 )
        {
          v102 = CardTable::GetCard(*((CardTable **)this + 20), v101);
          if ( v102 )
          {
            FreeCellGame::OnCardDragEnded((CardTable **)this - 2, v102);
            *((_BYTE *)this + 361) = 1;
          }
        }
        return;
      }
      v55 = v54 - 1;
      if ( v55 )
      {
        if ( v55 != 6 || *((_WORD *)a2 + 12) != 65 )
          return;
        goto LABEL_117;
      }
      if ( *((_DWORD *)this - 2) != 2 )
        goto LABEL_160;
      v63 = *((unsigned __int16 *)a2 + 12);
      if ( v63 > 0x35 )
      {
        v83 = v63 - 54;
        if ( v83 )
        {
          v84 = v83 - 1;
          if ( v84 )
          {
            v85 = v84 - 1;
            if ( v85 )
            {
              if ( v85 != 1 )
                goto LABEL_160;
              v86 = *((_QWORD *)this + 36);
              v87 = -1;
              if ( !v86 )
                goto LABEL_175;
              v88 = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), *((struct Card **)this + 36));
              if ( *(_QWORD *)(*((_QWORD *)v88 + 40) + 8LL * (unsigned int)(*((_DWORD *)v88 + 76) - 1)) != v86 )
                goto LABEL_175;
              v89 = 0;
              v90 = 0;
              do
              {
                if ( v89 >= 4 )
                  break;
                v91 = *(_QWORD *)(v90 + *((_QWORD *)this + 29));
                if ( !*(_DWORD *)(v91 + 304) && Card::GetRankForType(*(_DWORD *)(*((_QWORD *)this + 36) + 8LL)) == 13 )
                  goto LABEL_194;
                v92 = *(_DWORD *)(v91 + 304);
                if ( v92 )
                {
                  SuitForType = Card::GetSuitForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v91 + 320)
                                                                           + 8LL * (unsigned int)(v92 - 1))
                                                               + 8LL));
                  if ( SuitForType == Card::GetSuitForType(*(_DWORD *)(*((_QWORD *)this + 36) + 8LL)) )
                  {
                    RankForType = Card::GetRankForType(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v91 + 320)
                                                                             + 8LL
                                                                             * (unsigned int)(*(_DWORD *)(v91 + 304) - 1))
                                                                 + 8LL));
                    if ( RankForType == 13 )
                      RankForType = 0;
                    v95 = Card::GetRankForType(*(_DWORD *)(*((_QWORD *)this + 36) + 8LL));
                    if ( v95 == 13 )
                      v95 = 0;
                    if ( RankForType + 1 == v95 )
LABEL_194:
                      v87 = v89;
                  }
                }
                ++v89;
                v90 += 8;
              }
              while ( v87 == -1 );
              if ( v87 == -1 )
                goto LABEL_175;
              v68 = *(struct CardStack **)(*((_QWORD *)this + 29) + 8LL * v87);
            }
            else
            {
              v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 56LL);
            }
          }
          else
          {
            v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 48LL);
          }
        }
        else
        {
          v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 40LL);
        }
        goto LABEL_174;
      }
      if ( v63 == 53 )
      {
        v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 32LL);
        goto LABEL_174;
      }
      v64 = v63 - 48;
      if ( v64 )
      {
        v65 = v64 - 1;
        if ( v65 )
        {
          v66 = v65 - 1;
          if ( v66 )
          {
            v67 = v66 - 1;
            if ( v67 )
            {
              if ( v67 != 1 )
                goto LABEL_160;
              v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 24LL);
            }
            else
            {
              v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 16LL);
            }
          }
          else
          {
            v68 = *(struct CardStack **)(*((_QWORD *)this + 23) + 8LL);
          }
        }
        else
        {
          v68 = (struct CardStack *)**((_QWORD **)this + 23);
        }
        goto LABEL_174;
      }
      v69 = (tagPOINT)*((_QWORD *)this + 26);
      v70 = (struct Card *)*((_QWORD *)this + 36);
      v71 = -1;
      v72 = -1;
      v73 = 0;
      Point = v69;
      v74 = 0xFFFFFFFFLL;
      while ( 1 )
      {
        if ( v70
          && (v75 = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), v70),
              v69 = Point,
              v75 == **(struct CardStack ***)&Point) )
        {
          v71 = v73;
        }
        else
        {
          v76 = *(_DWORD *)(**(_QWORD **)&v69 + 304LL);
          v77 = v76 == 0;
          if ( !v76 )
            goto LABEL_147;
          if ( v72 != -1 )
          {
            v77 = v76 == 0;
LABEL_147:
            if ( v77 && (_DWORD)v74 == -1 )
              v74 = (unsigned int)v73;
            goto LABEL_150;
          }
          v72 = v73;
        }
LABEL_150:
        *(_QWORD *)&v69 += 8LL;
        ++v73;
        Point = v69;
        if ( v73 >= 4 )
        {
          if ( v71 != -1 )
          {
            v78 = 0xFFFFFFFFLL;
            v79 = (unsigned int)((v71 + 1) % 4);
            do
            {
              if ( (_DWORD)v79 == v71 )
                break;
              if ( *(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 26) + 8 * v79) + 304LL) )
                v78 = (unsigned int)v79;
              v79 = (unsigned int)(((int)v79 + 1) % 4);
            }
            while ( (_DWORD)v78 == -1 );
            if ( (_DWORD)v78 != -1 )
            {
              UserInterface::ClearFocus(g_pUserInterface);
              v80 = *(_QWORD *)(*((_QWORD *)this + 26) + 8 * v78);
              goto LABEL_159;
            }
            goto LABEL_160;
          }
          if ( !v70 )
          {
            if ( v72 != -1 )
            {
              UserInterface::ClearFocus(g_pUserInterface);
              v80 = *(_QWORD *)(*((_QWORD *)this + 26) + 8LL * v72);
LABEL_159:
              FreeCellGame::SetSelectedCard(
                (FreeCellGame *)((char *)this - 16),
                *(struct Card **)(*(_QWORD *)(v80 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v80 + 304) - 1)),
                1,
                1,
                1);
LABEL_160:
              if ( *((_WORD *)a2 + 12) == 27 || *((_WORD *)a2 + 12) == 32 )
              {
                if ( *((_DWORD *)this - 2) == 2 )
                {
                  v81 = *(CardAnimationManager **)(*((_QWORD *)this + 20) + 88LL);
                  if ( *((_DWORD *)v81 + 10) )
                    CardAnimationManager::FinishAllAnimations(v81);
                  if ( *((_WORD *)a2 + 12) == 27 )
                    FreeCellGame::SetSelectedCard((FreeCellGame *)((char *)this - 16), 0, 1, 1, 1);
                }
                else
                {
                  FreeCellGame::RequestSkipAnimation((FreeCellGame *)((char *)this - 16));
                }
                if ( *((_WORD *)a2 + 12) == 32 )
                  goto LABEL_204;
              }
              if ( *((_WORD *)a2 + 12) == 13 )
              {
LABEL_204:
                v96 = *(_QWORD *)(*((_QWORD *)this + 20) + 192LL);
                if ( v96
                  && (v97 = *(struct NodeBase **)(v96 + 144), v97 == UserInterface::GetCurrentFocus(g_pUserInterface))
                  || (v98 = *(_QWORD *)(*((_QWORD *)this + 20) + 176LL)) != 0
                  && (v99 = *(struct NodeBase **)(v98 + 96), v99 == UserInterface::GetCurrentFocus(g_pUserInterface)) )
                {
                  FreeCellGame::PlayHint(
                    (CardTable **)this - 2,
                    *(struct Card **)(*((_QWORD *)this + 20) + 176LL),
                    *(struct Card **)(*((_QWORD *)this + 20) + 184LL),
                    *(struct CardStack **)(*((_QWORD *)this + 20) + 192LL));
                }
                else if ( *((_WORD *)a2 + 12) == 13 && (_BYTE)g_bMediaCenter )
                {
                  if ( *((_DWORD *)this + 23)
                    && (v100 = timeGetTime() - *((_DWORD *)this + 23), v100 < GetDoubleClickTime()) )
                  {
                    FakeControllerDoubleTap(g_hWnd, 0x41u);
                  }
                  else
                  {
                    *((_DWORD *)this + 23) = timeGetTime();
                  }
                  FreeCellGame::RequestSkipAnimation((FreeCellGame *)((char *)this - 16));
                }
              }
              return;
            }
LABEL_175:
            FreeCellGame::PlaySoundW((FreeCellGame *)((char *)this - 16), 7u, 0, 0);
            goto LABEL_160;
          }
          if ( (_DWORD)v74 == -1 )
            goto LABEL_175;
          v82 = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), v70);
          if ( *(struct Card **)(*((_QWORD *)v82 + 40) + 8LL * (unsigned int)(*((_DWORD *)v82 + 76) - 1)) != v70 )
            goto LABEL_175;
          v68 = *(struct CardStack **)(*((_QWORD *)this + 26) + 8 * v74);
LABEL_174:
          FreeCellGame::doFakeClick((FreeCellGame *)((char *)this - 16), v68);
          goto LABEL_160;
        }
      }
    }
    if ( *((_QWORD *)g_pUserInterface + 8) )
      return;
    CurrentFocus = UserInterface::GetCurrentFocus(g_pUserInterface);
    if ( !*((_QWORD *)this + 36) )
      return;
    v114 = 0;
    v115 = 0;
    v116 = 0;
    for ( i = 0; ; ++i )
    {
      if ( v116 >= *((_DWORD *)this + 48) )
        return;
      v118 = *((_QWORD *)this + 26);
      if ( !v114 )
        break;
      v119 = *(CardStack **)(v118 + 8 * i);
      if ( !*((_DWORD *)v119 + 76) )
      {
        CardStack::SetFocus(v119, -1);
LABEL_254:
        v115 = 1;
      }
LABEL_256:
      ++v116;
      if ( v115 )
        return;
    }
    v120 = *(_QWORD *)(v118 + 8 * i);
    if ( CurrentFocus != *(struct NodeBase **)(v120 + 144)
      && (!*(_DWORD *)(v120 + 304)
       || *(struct NodeBase **)(*(_QWORD *)(*(_QWORD *)(v120 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v120 + 304) - 1))
                              + 96LL) != CurrentFocus) )
    {
      goto LABEL_256;
    }
    v114 = 1;
    if ( *(_DWORD *)(v120 + 304) )
    {
      v116 = -1;
      i = -1;
      goto LABEL_256;
    }
    goto LABEL_254;
  }
  switch ( v3 )
  {
    case 21:
      v38 = (const unsigned __int16 **)*((_QWORD *)a2 + 1);
      v39 = (struct NodeBase *)*((_QWORD *)this + 14);
      if ( v38 == (const unsigned __int16 **)v39 )
      {
        v40 = *((_DWORD *)a2 + 6);
        if ( !v40 )
        {
          CardStack::SetFocus(**((CardStack ***)this + 26), -1);
          return;
        }
        if ( (unsigned int)(v40 - 2) > 1 )
          return;
        v39 = (struct NodeBase *)*((_QWORD *)this + 15);
      }
      else if ( v38 == *((const unsigned __int16 ***)this + 15) )
      {
        v41 = *((_DWORD *)a2 + 6);
        if ( !v41 )
        {
          CardTable::SelectGroup(*((CardTable **)this + 20), *(struct StackGroup **)(**((_QWORD **)this + 29) + 64LL));
          return;
        }
        if ( (unsigned int)(v41 - 2) > 1 )
          return;
      }
      else
      {
        v42 = CardTable::GetCardStackWithCard(*((CardTable **)g_pFreeCellGame + 22), v38[16]);
        v43 = 0;
        v44 = 0;
        while ( !(v42
                ? v42 == *(struct CardStack **)(v44 + *((_QWORD *)g_pFreeCellGame + 28))
                : v38 == *(const unsigned __int16 ***)(*(_QWORD *)(*((_QWORD *)g_pFreeCellGame + 28) + v44) + 144LL)) )
        {
          ++v43;
          v44 += 8;
          if ( v43 >= 4 )
            goto LABEL_100;
        }
        if ( *((_DWORD *)a2 + 6) == 1 )
        {
          v39 = (struct NodeBase *)*((_QWORD *)this + 14);
          if ( v39 )
            goto LABEL_109;
        }
LABEL_100:
        v46 = *((_QWORD *)a2 + 1);
        v47 = CardTable::GetCardStackWithCard(
                *((CardTable **)g_pFreeCellGame + 22),
                *(const unsigned __int16 **)(v46 + 128));
        v48 = 0;
        for ( j = 0;
              !(v47
              ? v47 == *(struct CardStack **)(j + *((_QWORD *)g_pFreeCellGame + 31))
              : v46 == *(_QWORD *)(*(_QWORD *)(*((_QWORD *)g_pFreeCellGame + 31) + j) + 144LL));
              j += 8 )
        {
          if ( (unsigned int)++v48 >= 4 )
            return;
        }
        if ( *((_DWORD *)a2 + 6) != 1 )
          return;
        v39 = (struct NodeBase *)*((_QWORD *)this + 15);
        if ( !v39 )
          return;
      }
LABEL_109:
      UserInterface::SetFocus(g_pUserInterface, v39);
      return;
    case 1:
      *((_BYTE *)this + 356) = 0;
      v32 = *((_QWORD *)a2 + 1);
      if ( v32 == *((_QWORD *)this + 14) )
      {
        v33 = 40001;
      }
      else
      {
        if ( v32 != *((_QWORD *)this + 15) )
        {
          if ( !*((_BYTE *)this + 361) )
          {
            v34 = *((_QWORD *)a2 + 3);
            v35 = *(const unsigned __int16 **)(v34 + 128);
            if ( v35 )
            {
              v36 = CardTable::GetCard(*((CardTable **)this + 20), *(const unsigned __int16 **)(v34 + 128));
              if ( v36 )
              {
                FreeCellGame::OnCardClicked((CardTable **)this - 2, v36);
              }
              else
              {
                CardStack = CardTable::GetCardStack(*((CardTable **)this + 20), v35);
                if ( ((unsigned int)FreeCellMove::StackToMoveDestination(CardStack, 0) != 2 || *((_QWORD *)this + 36))
                  && CardStack )
                {
                  FreeCellGame::OnCardStackClicked((FreeCellGame *)((char *)this - 16), CardStack);
                }
              }
            }
          }
          return;
        }
        v33 = 40005;
      }
      SendMessageW(g_hWnd, 0x111u, v33, 0);
      return;
    case 4:
      v20 = (_QWORD *)*((_QWORD *)this + 20);
      v21 = (struct Card *)v20[22];
      v22 = (struct Card *)v20[23];
      v23 = (struct CardStack *)v20[24];
      FreeCellGame::RequestSkipAnimation((FreeCellGame *)((char *)this - 16));
      if ( *((_DWORD *)a2 + 12) != 1 )
        goto LABEL_51;
      if ( (_BYTE)g_bMediaCenter )
      {
        if ( *((_DWORD *)this - 2) != 2
          || (LOBYTE(v24) = 1, !(unsigned int)FreeCellGame::CheckForSuitCompletions(g_pFreeCellGame, 0, v24, v25)) )
        {
          GetCursorPos(&Point);
          TrackPopupMenu(g_hContextMenu, 0x1402u, Point.x, Point.y, 0, g_hWnd, 0);
          *((_BYTE *)a2 + 52) = 1;
          goto LABEL_66;
        }
      }
      if ( *((_DWORD *)a2 + 12) != 1 )
      {
LABEL_51:
        if ( *((_DWORD *)a2 + 12) || *((_BYTE *)a2 + 40) != 1 )
        {
LABEL_66:
          if ( *((_QWORD *)a2 + 1) )
            CardTable::ClearHintAnimations(*((CardTable **)this + 20));
          return;
        }
      }
      v26 = *((_QWORD *)a2 + 1);
      if ( v26 )
      {
        v27 = *(const unsigned __int16 **)(v26 + 128);
        if ( v27 )
        {
          v28 = CardTable::GetCard(*((CardTable **)this + 20), v27);
          v29 = CardTable::GetCardStack(
                  *((CardTable **)this + 20),
                  *(const unsigned __int16 **)(*((_QWORD *)a2 + 1) + 128LL));
          if ( v28 && (v21 == v28 || v22 == v28) || v29 && v29 == v23 )
          {
            FreeCellGame::SetSelectedCard((FreeCellGame *)((char *)this - 16), 0, 1, 1, 1);
            FreeCellGame::PlayHint((CardTable **)this - 2, v21, v22, v23);
          }
          else if ( v28 )
          {
            v30 = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), v28);
            v31 = v30;
            if ( !v30
              || (unsigned int)FreeCellMove::StackToMoveDestination(v30, 0) == 2
              || *(struct Card **)(*((_QWORD *)v31 + 40) + 8LL * (unsigned int)(*((_DWORD *)v31 + 76) - 1)) != v28
              || !FreeCellGame::OnCardDoubleClick((CardTable **)this - 2, (const unsigned __int16 **)v28) )
            {
              FreeCellGame::SetRightClickCard((FreeCellGame *)((char *)this - 16), v28);
            }
          }
        }
      }
      goto LABEL_66;
    case 5:
LABEL_117:
      v56 = *((_QWORD *)this + 20);
      *((_BYTE *)this + 356) = 1;
      if ( !*(_DWORD *)(*(_QWORD *)(v56 + 88) + 40LL) )
      {
        v57 = *((_QWORD *)a2 + 1);
        if ( v57 )
        {
          v58 = *(const unsigned __int16 **)(v57 + 128);
          if ( !v58 || g_bMouseHidden )
          {
            v59 = UserInterface::GetCurrentFocus(g_pUserInterface);
            if ( v59 )
              v58 = (const unsigned __int16 *)*((_QWORD *)v59 + 16);
          }
          v60 = CardTable::GetCard(*((CardTable **)this + 20), v58);
          v61 = (const unsigned __int16 **)v60;
          if ( v60 )
          {
            v62 = CardTable::GetCardStackWithCard(*((CardTable **)this + 20), v60);
            if ( v62 )
            {
              if ( (unsigned int)FreeCellMove::StackToMoveDestination(v62, 0) != 2 )
                FreeCellGame::OnCardDoubleClick((CardTable **)this - 2, v61);
            }
          }
        }
      }
      return;
  }
  if ( v3 <= 5 )
    return;
  if ( v3 <= 7 || v3 == 10 )
  {
    *((_BYTE *)this + 362) = 0;
    if ( *((_DWORD *)a2 + 12) || *((_BYTE *)a2 + 40) )
    {
      if ( *((_DWORD *)a2 + 12) == 1 || !*((_DWORD *)a2 + 12) && *((_BYTE *)a2 + 40) == 1 )
      {
        FreeCellGame::SetRightClickCard((FreeCellGame *)((char *)this - 16), 0);
        v18 = *((_QWORD *)this + 20);
        if ( *(_DWORD *)(*(_QWORD *)(v18 + 88) + 40LL) )
          return;
        v19 = *((_QWORD *)a2 + 1);
        if ( (!v19 || v19 == *(_QWORD *)(v18 + 104)) && *((_DWORD *)this - 2) == 2 )
          *((_BYTE *)this + 346) = (unsigned int)FreeCellGame::CheckForSuitCompletions(g_pFreeCellGame, 0, 0, v17) != 0;
      }
    }
    else
    {
      v14 = (FreeCellGame *)((char *)this - 16);
      if ( *((_DWORD *)this - 2) == 2 )
      {
        FreeCellGame::SetRightClickCard(v14, 0);
        v15 = (CardTable *)*((_QWORD *)this + 20);
        if ( v15 )
          CardTable::ClearHintAnimations(v15);
        *((_BYTE *)this + 364) = 0;
        v16 = *(CardAnimationManager **)(*((_QWORD *)this + 20) + 88LL);
        if ( *((_DWORD *)v16 + 10) && *((_BYTE *)this + 344) && !*((_BYTE *)this + 356) )
          CardAnimationManager::FinishAllAnimations(v16);
        if ( *((_QWORD *)a2 + 1) == *(_QWORD *)(*((_QWORD *)this + 20) + 104LL) )
        {
          FreeCellGame::SetSelectedCard((FreeCellGame *)((char *)this - 16), 0, 1, 1, 1);
          TipManager::HideTip(*((TipManager **)this + 40), 0);
        }
      }
      else
      {
        FreeCellGame::RequestSkipAnimation(v14);
      }
    }
    *((_BYTE *)this + 356) = 0;
    FreeCellGame::UpdateMenuState((FreeCellGame *)((char *)this - 16));
  }
  else if ( v3 == 17 )
  {
    v5 = *(const unsigned __int16 **)(*((_QWORD *)a2 + 1) + 128LL);
    if ( v5 )
    {
      v6 = (struct Card *)*((_QWORD *)this + 36);
      v7 = CardTable::GetCard(*((CardTable **)this + 20), v5);
      v8 = v7;
      if ( v6 )
      {
        if ( v7 )
        {
          v9 = (CardTable *)*((_QWORD *)this + 20);
          v10 = CardTable::GetCardStackWithCard(v9, v6);
          v11 = CardTable::GetCardStackWithCard(v9, v8);
          v12 = v11;
          if ( v10 )
          {
            if ( v11 )
            {
              if ( v10 != v11 )
              {
                if ( *((_DWORD *)v11 + 76) )
                {
                  if ( (unsigned int)FreeCellMove::StackToMoveDestination(v11, 0) == 1 )
                  {
                    HighestPlaceableCardIndex = FreeCellMove::GetHighestPlaceableCardIndex(
                                                  v10,
                                                  *(struct Card **)(*((_QWORD *)v12 + 40)
                                                                  + 8LL * (unsigned int)(*((_DWORD *)v12 + 76) - 1)));
                    if ( HighestPlaceableCardIndex != -1 )
                      FreeCellGame::SetSelectedCard(
                        (FreeCellGame *)((char *)this - 16),
                        *(struct Card **)(*((_QWORD *)v10 + 40) + 8LL * HighestPlaceableCardIndex),
                        0,
                        0,
                        1);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if ( v3 == 18 && !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 20) + 88LL) + 40LL) )
  {
    FreeCellGame::SetSelectedCard((FreeCellGame *)((char *)this - 16), *((struct Card **)this + 37), 0, 0, 0);
  }
}
