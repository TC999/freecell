void __fastcall FreeCellGame::SetRightClickCard(FreeCellGame *this, struct Card *a2)
{
  __int64 v2; // r12
  CardStack *CardStackWithCard; // rdi
  CardStack *v4; // rbx

  v2 = *((_QWORD *)this + 44);
  CardStackWithCard = 0;
  v4 = 0;
  if ( v2 )
  {
    Log(0x10000u, L"Card::SetRightClicked()::bRightClicked == %s", L"false");
    *(_BYTE *)(v2 + 19) = 0;
    CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 22), *((struct Card **)this + 44));
  }
  *((_QWORD *)this + 44) = a2;
  if ( a2 )
  {
    Log(0x10000u, L"Card::SetRightClicked()::bRightClicked == %s", L"true");
    *((_BYTE *)a2 + 19) = 1;
    v4 = CardTable::GetCardStackWithCard(*((CardTable **)this + 22), *((struct Card **)this + 44));
  }
  if ( CardStackWithCard && CardStackWithCard != v4 )
    CardStack::Arrange(CardStackWithCard, 1, 0);
  if ( v4 )
    CardStack::Arrange(v4, 1, 0);
}
