// Hidden C++ exception states: #wind=1
char __fastcall FreeCellGame::Update(FreeCellGame *this, float a2)
{
  FreeCellGame *v2; // rbx
  __int64 v3; // rdi
  CardAnimationManager *v4; // rcx
  unsigned int v5; // ebp
  __int64 v6; // rsi
  CardStack *v7; // rcx
  float v8; // xmm6_4
  void *v9; // rdi
  __int64 v10; // rdx
  __int64 v11; // rcx
  unsigned int v12; // edi
  _DWORD v14[4]; // [rsp+28h] [rbp-30h] BYREF
  void *Block; // [rsp+38h] [rbp-20h]

  v2 = g_pFreeCellGame;
  if ( *((_BYTE *)g_pFreeCellGame + 379) )
  {
    v3 = *((_QWORD *)g_pFreeCellGame + 22);
    v4 = *(CardAnimationManager **)(v3 + 88);
    if ( v4 )
      CardAnimationManager::Update(v4, a2);
    v5 = 0;
    if ( *(_DWORD *)(v3 + 160) )
    {
      v6 = 0;
      do
      {
        v7 = *(CardStack **)(v6 + *(_QWORD *)(v3 + 152));
        if ( *((_QWORD *)v7 + 28) )
          CardStack::ArrangeHighlight(v7);
        ++v5;
        v6 += 8;
      }
      while ( v5 < *(_DWORD *)(v3 + 160) );
    }
  }
  else
  {
    FreeCellGame::OnGameStart(g_pFreeCellGame);
    *((_BYTE *)v2 + 379) = 1;
  }
  if ( *(_BYTE *)(*((_QWORD *)v2 + 11) + 14LL) || *((_QWORD *)g_pUserInterface + 8) )
  {
    *((_DWORD *)v2 + 26) = 0;
  }
  else
  {
    v8 = a2 + *((float *)v2 + 26);
    *((float *)v2 + 26) = v8;
    if ( v8 >= 30.0 )
    {
      if ( !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2 + 22) + 88LL) + 40LL) && !*((_BYTE *)v2 + 380) )
      {
        v14[0] = 0;
        v14[1] = 0;
        v14[2] = 16;
        Block = 0;
        FreeCellGame::getHintMovesInPriorityOrder((__int64)v2, (__int64)v14);
        v9 = Block;
        if ( v14[0] )
        {
          v10 = 56LL * (unsigned int)(*((_DWORD *)v2 + 86) % v14[0]);
          v11 = *(_QWORD *)((char *)Block + v10 + 32);
          if ( *(_DWORD *)(v11 + 304) )
            CardTable::AddTargetedHintAnimation(
              *((CardTable **)v2 + 22),
              *(struct Card **)((char *)Block + v10 + 8),
              *(struct Card **)(*(_QWORD *)(v11 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v11 + 304) - 1)));
          else
            CardTable::AddTargetedHintAnimation(
              *((CardTable **)v2 + 22),
              *(struct Card **)((char *)Block + v10 + 8),
              *(struct CardStack **)((char *)Block + v10 + 32));
        }
        ++*((_DWORD *)v2 + 86);
        if ( v9 )
          free(v9);
      }
      *((_DWORD *)v2 + 26) = 0;
    }
  }
  v12 = (*(__int64 (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)v2 + 24LL))(v2, *((unsigned int *)v2 + 2));
  if ( v12 != *((_DWORD *)v2 + 2) )
  {
    (*(void (__fastcall **)(FreeCellGame *))(*(_QWORD *)v2 + 16LL))(v2);
    *((_DWORD *)v2 + 3) = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = v12;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)v2 + 8LL))(v2, v12);
  }
  if ( *((_BYTE *)v2 + 375) && *((_DWORD *)v2 + 2) == 2 && !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2 + 22) + 88LL) + 40LL) )
    FreeCellGame::PlayHint(v2);
  return 1;
}
