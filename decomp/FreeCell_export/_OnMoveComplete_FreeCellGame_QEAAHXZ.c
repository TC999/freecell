__int64 __fastcall FreeCellGame::OnMoveComplete(__int64 **this)
{
  __int64 v2; // r9
  int v3; // r11d
  __int64 *v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 result; // rax
  int v8; // eax

  FreeCellGame::invalidateHints((FreeCellGame *)this);
  FreeCellGame::UpdateAccessibility((FreeCellGame *)this);
  if ( !*((_BYTE *)this + 360) )
  {
    FreeCellGame::UpdateUI((FreeCellGame *)this, 0);
    v3 = 0;
    if ( *((_DWORD *)this + 58) )
    {
      v4 = this[31];
      v5 = *((unsigned int *)this + 58);
      do
      {
        v6 = *v4++;
        v3 += *(_DWORD *)(v6 + 304);
        --v5;
      }
      while ( v5 );
      if ( v3 == 52 )
        return 3;
    }
    if ( FreeCellGame::IsGameLost((FreeCellGame *)this) )
      return 4;
    v8 = *((_DWORD *)this + 96);
    if ( v8 )
      *((_DWORD *)this + 96) = v8 - 1;
    UserInterface::UpdateMouseOverFocus(g_pUserInterface);
  }
  if ( *((_BYTE *)this + 362) )
    *((_BYTE *)this + 362) = (unsigned int)FreeCellGame::CheckForSuitCompletions(g_pFreeCellGame, 0, 0, v2) != 0;
  else
    FreeCellGame::CheckForSuitCompletions(g_pFreeCellGame, 1, 0, v2);
  FreeCellGame::SetSelectedCard((FreeCellGame *)this, 0, 1, 1, 1);
  FreeCellGame::UpdateUI((FreeCellGame *)this, 0);
  result = *((unsigned int *)this + 2);
  *((_BYTE *)this + 376) = 1;
  return result;
}
