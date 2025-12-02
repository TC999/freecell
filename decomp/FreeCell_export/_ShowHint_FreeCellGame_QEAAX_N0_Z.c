// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::ShowHint(CardTable **this, char a2, char a3)
{
  char *v6; // rdi
  __int64 v7; // r8
  _DWORD v8[4]; // [rsp+28h] [rbp-20h] BYREF
  void *Block; // [rsp+38h] [rbp-10h]

  if ( !*(_DWORD *)(*((_QWORD *)this[22] + 11) + 40LL) && (!*((_BYTE *)this + 380) || a3) )
  {
    v8[0] = 0;
    v8[1] = 0;
    v8[2] = 16;
    Block = 0;
    FreeCellGame::getHintMovesInPriorityOrder(this, v8);
    if ( v8[0] )
    {
      v6 = (char *)Block + 56 * (unsigned int)(*((_DWORD *)this + 86) % v8[0]);
      v7 = *((_QWORD *)v6 + 4);
      if ( *(_DWORD *)(v7 + 304) )
        CardTable::AddTargetedHintAnimation(
          this[22],
          *((struct Card **)v6 + 1),
          *(struct Card **)(*(_QWORD *)(v7 + 320) + 8LL * (unsigned int)(*(_DWORD *)(v7 + 304) - 1)));
      else
        CardTable::AddTargetedHintAnimation(this[22], *((struct Card **)v6 + 1), (struct CardStack *)v7);
      if ( a3 )
      {
        Card::SetFocus(*((Card **)v6 + 1));
        *((_BYTE *)this + 380) = 1;
      }
      if ( a2 )
        FreeCellGame::PlaySoundW((FreeCellGame *)this, 6u, 0, 0);
    }
    else
    {
      if ( a3
        && *((_DWORD *)this + 2) == 2
        && *((_DWORD *)this[22] + 60)
        && !*((_QWORD *)g_pUserInterface + 8)
        && !*((_BYTE *)this[11] + 14) )
      {
        TipManager::ShowTipIfEnabled(this[42], L"InvalidHintRequested", 0, 1, -2);
      }
      if ( a2 )
        FreeCellGame::PlaySoundW((FreeCellGame *)this, 5u, 0, 0);
    }
    ++*((_DWORD *)this + 86);
    if ( Block )
      free(Block);
  }
}
