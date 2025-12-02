// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::NewGame(FreeCellGame *this, __int64 a2, unsigned int a3)
{
  *((_BYTE *)this + 376) = 0;
  GameAudio::StopSound((GameAudio *)3, 0, a3);
  TipManager::HideTip(*((TipManager **)this + 42), 0);
  FreeCellGame::invalidateHints(this);
  FreeCellMove::m_aPreviousMoves = 0;
  if ( *(_BYTE *)(*((_QWORD *)this + 11) + 12LL) )
  {
    if ( *((_BYTE *)this + 381) )
      *((_BYTE *)this + 381) = 0;
    else
      FreeCellGame::ChooseNewRandomAppearance(this);
  }
  FreeCellGame::SetSelectedCard(this, 0, 1, 1, 1);
  CardTable::Reset(*((CardTable **)this + 22));
  **(_BYTE **)(*((_QWORD *)this + 22) + 88LL) = *(_BYTE *)(*((_QWORD *)this + 11) + 30LL);
  *(_BYTE *)(*((_QWORD *)this + 42) + 145LL) = *(_BYTE *)(*((_QWORD *)this + 11) + 30LL);
  FreeCellGame::InitialDeal(this);
  CardTable::EmptyStates(*((CardTable **)this + 22));
  (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)this + 16LL))(this, *((unsigned int *)this + 2));
  *((_DWORD *)this + 3) = *((_DWORD *)this + 2);
  *((_DWORD *)this + 2) = 1;
  (*(void (__fastcall **)(FreeCellGame *, __int64))(*(_QWORD *)this + 8LL))(this, 1);
  *((_DWORD *)this + 86) = 0;
  *((_DWORD *)this + 96) = 0;
  *((_BYTE *)this + 362) = 0;
  *((_BYTE *)this + 363) = 0;
}
