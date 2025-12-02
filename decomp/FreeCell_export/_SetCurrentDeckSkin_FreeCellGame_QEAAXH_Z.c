void __fastcall FreeCellGame::SetCurrentDeckSkin(FreeCellGame *this, unsigned int a2)
{
  if ( a2 != -1 && (int)a2 < (__int64)*((unsigned int *)this + 8) )
  {
    *(_DWORD *)(*((_QWORD *)this + 11) + 20LL) = a2;
    CardTable::SetCardDeck(*((CardTable **)this + 22), *(const unsigned __int16 **)(*((_QWORD *)this + 6) + 8LL * a2));
  }
}
