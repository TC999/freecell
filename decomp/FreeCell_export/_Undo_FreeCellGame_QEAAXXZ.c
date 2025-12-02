void __fastcall FreeCellGame::Undo(CardTable **this)
{
  CardTable *v2; // rcx

  if ( *((_DWORD *)this + 2) == 2 && *((_DWORD *)this[22] + 60) && !*((_QWORD *)g_pUserInterface + 8) )
  {
    FreeCellGame::PlaySoundW((FreeCellGame *)this, 0x1Au, 0, 0);
    v2 = this[22];
    if ( v2 )
      CardTable::ClearHintAnimations(v2);
    *((_BYTE *)this + 380) = 0;
    FreeCellGame::invalidateHints((FreeCellGame *)this);
    FreeCellGame::SetSelectedCard(g_pFreeCellGame, 0, 1, 1, 1);
    CardTable::PopState(this[22]);
    FreeCellMove::m_aPreviousMoves = 0;
    *((_DWORD *)this + 26) = 0;
    FreeCellGame::UpdateAccessibility((FreeCellGame *)this);
    FreeCellGame::UpdateUI((FreeCellGame *)this, 0);
  }
  else
  {
    FreeCellGame::PlaySoundW((FreeCellGame *)this, 5u, 0, 0);
  }
}
