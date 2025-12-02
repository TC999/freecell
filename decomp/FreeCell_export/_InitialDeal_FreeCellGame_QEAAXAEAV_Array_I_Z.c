void __fastcall FreeCellGame::InitialDeal(FreeCellGame *this, _DWORD *a2)
{
  HMENU Menu; // rax
  CardStack *v5; // rbx
  unsigned int v6; // r8d
  __int64 v7; // rax
  int v8; // edx
  __int64 v9; // rbx
  __int64 v10; // rdi
  int v11; // r12d
  char v12; // r13
  __int64 v13; // rdi
  NodeBase **v14; // rbp
  CardAnimationManager *v15; // r14
  struct CardAnimationManager::CardAnimation *v16; // rax
  struct CardAnimationManager::CardAnimation *v17; // rbx
  float v18; // xmm0_4
  int v19; // edx

  *((_QWORD *)this + 40) = 0;
  Menu = GetMenu(g_hWnd);
  if ( Menu )
    EnableMenuItem(Menu, 0x9C4Cu, 1u);
  if ( *a2 >= 0x34u )
  {
    CardStack::AssignCards(**((CardStack ***)this + 28));
  }
  else
  {
    v5 = (CardStack *)**((_QWORD **)this + 28);
    Log(0x10000u, L"CardStack::CreateDeck()::uiNumSuits == %u", 4);
    Log(0x10000u, L"CardStack::CreateDeck()::uiNumCards == %u", 52);
    CardStack::CreateDeck(v5, 4u, v6);
    CardStack::Shuffle(**((CardStack ***)this + 28), 0);
  }
  v7 = *((_QWORD *)this + 12);
  v8 = 0;
  if ( v7 )
    v8 = *(_DWORD *)(v7 + 12);
  FreeCellGame::SpecialDealCards(this, v8);
  v9 = 0;
  v10 = 8;
  do
  {
    CardStack::Arrange(*(CardStack **)(v9 + *((_QWORD *)this + 25)), 0, 0);
    v9 += 8;
    --v10;
  }
  while ( v10 );
  v11 = 0;
  v12 = 1;
  if ( *(_BYTE *)(*((_QWORD *)this + 11) + 30LL) )
  {
    v13 = 0;
    do
    {
      v14 = *(NodeBase ***)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 25) + 8 * v13) + 320LL)
                          + 8LL * (unsigned int)(v11 / 8));
      NodeBase::MoveToFront(v14[8]);
      Card::SetFaceUp((Card *)v14, 1, 0);
      v15 = *(CardAnimationManager **)(*((_QWORD *)this + 22) + 88LL);
      if ( *(_BYTE *)v15 )
      {
        Card::SetFaceUp((Card *)v14, 0, 1);
        v16 = (struct CardAnimationManager::CardAnimation *)operator new(0x50u);
        v17 = v16;
        if ( v16 )
        {
          *(_QWORD *)v16 = v15;
          *((_QWORD *)v16 + 1) = v14;
          *((_BYTE *)v16 + 69) = 1;
          *((_BYTE *)v16 + 71) = 1;
          *((_BYTE *)v16 + 72) = 0;
          *((_DWORD *)v16 + 19) = 3;
          *((_DWORD *)v16 + 11) = 0;
          *((_DWORD *)v16 + 12) = 0;
          v18 = (float)((float)v11 * FreeCellGame::ANIM_DEAL_DELAY_CONST) + CardAnimationManager::BASE_FLIP_TIME;
          *((_DWORD *)v16 + 15) = 0;
          *((_DWORD *)v16 + 16) = 0;
          *((float *)v16 + 8) = v18;
          *((_DWORD *)v16 + 13) = 0;
          *((_DWORD *)v16 + 14) = 0;
          *((_DWORD *)v16 + 10) = 0;
          *((_QWORD *)v16 + 3) = 0;
          *((_QWORD *)v16 + 2) = 0;
          *((_DWORD *)v16 + 9) = 1047904911;
          *((_BYTE *)v16 + 70) = 0;
          *((_BYTE *)v16 + 68) = 0;
        }
        else
        {
          v17 = 0;
        }
        Array<IEventListener *>::Add((char *)v15 + 64, v17);
        CardAnimationManager::QueueOrSetAnimation(v15, v17, (struct Card *)v14, 0, 0);
      }
      else
      {
        Card::SetFaceUp((Card *)v14, 1, 1);
      }
      CardTable::AddMovementAnimation(
        *((CardTable **)this + 22),
        (struct Card *)v14,
        (float)v11 * FreeCellGame::ANIM_DEAL_DELAY_CONST,
        364,
        390,
        *((_DWORD *)v14[8] + 2),
        *((_DWORD *)v14[8] + 3),
        1,
        0,
        0);
      NodeBase::SetPosition(v14[8], 364, *((_DWORD *)v14[8] + 3));
      NodeBase::SetPosition(v14[8], *((_DWORD *)v14[8] + 2), v19 + 26);
      ++v11;
      if ( v12 )
        ++v13;
      else
        --v13;
      if ( v13 == 8 )
      {
        v13 = 7;
        v12 = 0;
      }
      else if ( v13 < 0 )
      {
        ++v13;
        v12 = 1;
      }
    }
    while ( (unsigned int)v11 < 0x34 );
  }
}
