void __fastcall FreeCellGame::invalidateHints(FreeCellGame *this)
{
  CardTable *v2; // rcx

  v2 = (CardTable *)*((_QWORD *)this + 22);
  if ( v2 )
    CardTable::ClearHintAnimations(v2);
  *((_DWORD *)this + 86) = 0;
  *((_BYTE *)this + 380) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_BYTE *)this + 373) = 0;
}
