void __fastcall FreeCellGame::PlayHint(CardTable **this, struct Card *a2, struct Card *a3, struct CardStack *a4)
{
  CardStack *CardStackWithCard; // rax
  int v9; // eax
  _BYTE v10[48]; // [rsp+20h] [rbp-78h] BYREF
  _QWORD Src[5]; // [rsp+50h] [rbp-48h] BYREF

  CardStackWithCard = CardTable::GetCardStackWithCard(this[22], a2);
  Src[1] = a2;
  Src[0] = CardStackWithCard;
  LODWORD(Src[2]) = CardStack::GetCardLocation(CardStackWithCard, a2);
  if ( a4 )
  {
    v9 = *((_DWORD *)a4 + 76);
    Src[4] = a4;
  }
  else
  {
    Src[4] = CardTable::GetCardStackWithCard(this[22], a3);
    v9 = *(_DWORD *)(Src[4] + 304LL);
  }
  HIDWORD(Src[2]) = v9;
  memcpy(v10, Src, 0x28u);
  FreeCellMove::PerformMove(v10);
}
