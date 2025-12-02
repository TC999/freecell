void __fastcall FreeCellGame::CreateHints(FreeCellGame *this, char a2)
{
  __int64 v3; // rdx

  if ( !*((_BYTE *)this + 373) || a2 )
  {
    FreeCellGame::invalidateHints(this);
    LOBYTE(v3) = *((_BYTE *)this + 374) == 0;
    FreeCellMove::CreateMoves((char *)this + 280, v3);
    Log(0x10000000u, L"Generated %d hints", *((unsigned int *)this + 70));
    *((_BYTE *)this + 373) = 1;
  }
}
