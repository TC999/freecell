// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::PlayHint(FreeCellGame *this)
{
  void *v2; // rbx
  _DWORD v3[4]; // [rsp+28h] [rbp-50h] BYREF
  void *Block; // [rsp+38h] [rbp-40h]
  _BYTE v5[56]; // [rsp+40h] [rbp-38h] BYREF

  v3[0] = 0;
  v3[1] = 0;
  v3[2] = 16;
  Block = 0;
  FreeCellGame::getHintMovesInPriorityOrder(this, v3);
  v2 = Block;
  if ( *(_DWORD *)(*(_QWORD *)(*((_QWORD *)this + 22) + 88LL) + 40LL) || !v3[0] || *((_BYTE *)this + 360) )
  {
    FreeCellGame::PlaySoundW(this, 5u, 0, 0);
  }
  else
  {
    memcpy(v5, (char *)Block + 56 * (unsigned int)(*((_DWORD *)this + 86) % v3[0]), 0x28u);
    FreeCellMove::PerformMove(v5);
  }
  if ( v2 )
    free(v2);
}
