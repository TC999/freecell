void __fastcall FreeCellMove::addPreviousMove(struct Move *Src)
{
  int v1; // ebx
  unsigned int v3; // esi
  __int64 v4; // rcx
  __int64 v5; // rbx
  unsigned int v6; // ebx
  char *v7; // rax
  char *v8; // r11
  _BYTE Srca[40]; // [rsp+20h] [rbp-38h] BYREF

  v1 = FreeCellMove::m_aPreviousMoves;
  if ( (unsigned int)FreeCellMove::m_aPreviousMoves > 0x3E8 )
  {
    v3 = 0;
    if ( FreeCellMove::m_aPreviousMoves != 1 )
    {
      v4 = 0;
      do
      {
        v5 = v4 + 40;
        memcpy((char *)Block + v4, (char *)Block + v4 + 40, 0x28u);
        v4 = v5;
        v1 = FreeCellMove::m_aPreviousMoves;
        ++v3;
      }
      while ( v3 < FreeCellMove::m_aPreviousMoves - 1 );
    }
    FreeCellMove::m_aPreviousMoves = --v1;
  }
  memcpy(Srca, Src, sizeof(Srca));
  v6 = v1 + 1;
  FreeCellMove::m_aPreviousMoves = v6;
  if ( v6 <= dword_1000ACE24 )
  {
    v8 = (char *)Block;
  }
  else
  {
    dword_1000ACE24 += dword_1000ACE28;
    v7 = (char *)realloc(Block, 40LL * (unsigned int)dword_1000ACE24);
    v8 = v7;
    if ( !v7 )
    {
      CheckAllocation(0);
      return;
    }
    v6 = FreeCellMove::m_aPreviousMoves;
    Block = v7;
  }
  memcpy(&v8[40 * v6 - 40], Srca, 0x28u);
}
