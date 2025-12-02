void __fastcall FreeCellGame::SetCurrentBackground(FreeCellGame *this, unsigned int a2)
{
  if ( a2 != -1 && (int)a2 < (__int64)*((unsigned int *)this + 14) )
  {
    *(_DWORD *)(*((_QWORD *)this + 11) + 24LL) = a2;
    CardTable::SetBackground(*((CardTable **)this + 22), *(const unsigned __int16 **)(*((_QWORD *)this + 9) + 8LL * a2));
  }
}
