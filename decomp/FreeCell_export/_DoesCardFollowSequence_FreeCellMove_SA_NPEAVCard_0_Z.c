char __fastcall FreeCellMove::DoesCardFollowSequence(struct Card *a1, struct Card *a2)
{
  unsigned int RankForType; // eax
  unsigned int v5; // eax
  unsigned int SuitForType; // eax
  char v7; // di
  int v8; // ebx
  unsigned int v9; // eax
  int v10; // r11d
  unsigned int v11; // ebx
  unsigned int v12; // eax

  RankForType = Card::GetRankForType(*((_DWORD *)a2 + 2));
  if ( RankForType == 13 )
    RankForType = 0;
  if ( RankForType == 12 )
    return 0;
  v5 = Card::GetRankForType(*((_DWORD *)a1 + 2));
  if ( v5 == 13 )
    v5 = 0;
  if ( !v5 )
    return 0;
  SuitForType = Card::GetSuitForType(*((_DWORD *)a2 + 2));
  v7 = 1;
  if ( SuitForType && SuitForType != 2 )
  {
    if ( SuitForType == 1 || SuitForType == 3 )
    {
      v8 = 1;
      goto LABEL_13;
    }
    Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
  }
  v8 = 0;
LABEL_13:
  v9 = Card::GetSuitForType(*((_DWORD *)a1 + 2));
  if ( v9 && v9 != 2 )
  {
    if ( v9 == 1 || v9 == 3 )
    {
      v10 = 1;
      goto LABEL_19;
    }
    Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
  }
  v10 = 0;
LABEL_19:
  if ( v8 == v10 )
    return 0;
  v11 = Card::GetRankForType(*((_DWORD *)a2 + 2));
  if ( v11 == 13 )
    v11 = 0;
  v12 = Card::GetRankForType(*((_DWORD *)a1 + 2));
  if ( v12 == 13 )
    v12 = 0;
  if ( v11 != v12 - 1 )
    return 0;
  return v7;
}
