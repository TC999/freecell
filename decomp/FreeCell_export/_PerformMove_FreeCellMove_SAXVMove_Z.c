void __fastcall FreeCellMove::PerformMove(CardStack **a1)
{
  FreeCellGame *v2; // rcx
  FreeCellGame *v3; // rbx
  unsigned int CardLocation; // ebx
  CardStack *v5; // rcx
  struct CardStack *v6; // rax
  int v7; // eax
  CardTable *v8; // rbx
  int v9; // edx

  v2 = g_pFreeCellGame;
  v3 = g_pFreeCellGame;
  if ( *((_QWORD *)g_pFreeCellGame + 22) )
  {
    CardTable::ClearHintAnimations(*((CardTable **)g_pFreeCellGame + 22));
    v2 = g_pFreeCellGame;
  }
  *((_BYTE *)v3 + 380) = 0;
  *((_DWORD *)v2 + 26) = 0;
  FreeCellGame::SetSelectedCard(v2, 0, 1, 1, 1);
  CardLocation = CardStack::GetCardLocation(*a1, a1[1]);
  if ( CardLocation != -1 )
  {
    TipManager::HideTip(*((TipManager **)g_pFreeCellGame + 42), 0);
    v5 = *a1;
    *((_DWORD *)g_pFreeCellGame + 26) = 0;
    v6 = CardStack::Split(v5, CardLocation, L"MoveStack");
    if ( v6 )
    {
      CardStack::Join(a1[4], v6);
      CardStack::Arrange(*a1, 0, 0);
      v7 = FreeCellMove::StackToMoveDestination((__int64)a1[4], 0);
      CardStack::Arrange(a1[4], 1, v7 == 2);
      CardStack::SetHighlight(a1[4], 0, 0);
      if ( !wcsncmp(*((const wchar_t **)a1[4] + 36), L"SuitStack", 9u) )
      {
        Card::SetEnabled(*(Card **)(*((_QWORD *)a1[4] + 40) + 8LL * (unsigned int)(*((_DWORD *)a1[4] + 76) - 1)), 1, 0);
        FreeCellGame::PlaySoundW(g_pFreeCellGame, 0xAu, 0, 0);
      }
      v8 = (CardTable *)*((_QWORD *)g_pFreeCellGame + 22);
      Log(0x10000u, L"CardTable::PushState()");
      CardTable::PushAction(v8, 0, &dword_1000028D4, &dword_1000028D4);
      FreeCellGame::PlaySoundW(g_pFreeCellGame, 9u, 0, 0);
      if ( *((_BYTE *)g_pFreeCellGame + 360) != 1 )
        *((_BYTE *)g_pFreeCellGame + 360) = 1;
      if ( (unsigned int)FreeCellMove::StackToMoveDestination((__int64)a1[4], 0) == 2 )
        FreeCellMove::m_aPreviousMoves &= v9;
      else
        FreeCellMove::addPreviousMove((struct Move *)a1);
    }
  }
}
