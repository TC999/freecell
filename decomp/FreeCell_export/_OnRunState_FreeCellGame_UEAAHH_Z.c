__int64 __fastcall FreeCellGame::OnRunState(FreeCellGame *this, unsigned int a2)
{
  int v3; // eax
  unsigned int v4; // eax

  *((_BYTE *)this + 377) = 0;
  switch ( a2 )
  {
    case 1u:
      v4 = 1;
      if ( !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 22) + 88LL) + 40LL) )
        return 2;
      return v4;
    case 2u:
      if ( *((_BYTE *)this + 360) == 1 && !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 22) + 88LL) + 40LL) )
      {
        *((_BYTE *)this + 360) = 0;
        return (unsigned int)FreeCellGame::OnMoveComplete((__int64 **)this);
      }
      break;
    case 3u:
      if ( !*(_BYTE *)(*((_QWORD *)this + 11) + 30LL) || !*(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 22) + 88LL) + 40LL) )
        return (unsigned int)FreeCellGame::OnGameWon(this);
      break;
    case 4u:
      if ( !*((_BYTE *)this + 375) && !FreeCellTaskDialogs::StartNoMoreMovesDialog((FreeCellTaskDialogs *)(a2 - 3)) )
      {
        v3 = *((_DWORD *)this + 96);
        a2 = 2;
        if ( v3 )
          *((_DWORD *)this + 96) = v3 - 1;
        else
          *((_DWORD *)this + 96) = 2;
        return a2;
      }
      return (unsigned int)FreeCellGame::OnGameLost(this);
    default:
      return a2;
  }
  return a2;
}
