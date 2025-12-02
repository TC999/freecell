void __fastcall FreeCellGame::FinishGame(FreeCellGame *this)
{
  FreeCellGame *v1; // rdi
  __int64 v2; // rbp
  CardStack *v3; // rbx
  __int64 v4; // r13
  unsigned int v5; // r8d
  char v6; // si
  char v7; // r12
  Card *v8; // rbx

  v1 = g_pFreeCellGame;
  CardTable::Reset(*((CardTable **)g_pFreeCellGame + 22));
  v2 = 4;
  v3 = (CardStack *)**((_QWORD **)v1 + 28);
  Log(0x10000u, L"CardStack::CreateDeck()::uiNumSuits == %u", 4);
  v4 = 52;
  Log(0x10000u, L"CardStack::CreateDeck()::uiNumCards == %u", 52);
  CardStack::CreateDeck(v3, 4u, v5);
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = CardStack::Pop(**((CardStack ***)v1 + 28));
    Card::SetFaceUp(v8, 1, 0);
    CardStack::Push(*(CardStack **)(*((_QWORD *)v1 + 31) + 8LL * (v7++ & 3)), v8);
    --v4;
  }
  while ( v4 );
  CardStack::Arrange(**((CardStack ***)v1 + 28), 0, 0);
  do
  {
    CardStack::Arrange(*(CardStack **)(*((_QWORD *)v1 + 31) + 8LL * (v6++ & 3)), 0, 0);
    --v2;
  }
  while ( v2 );
  FreeCellGame::UpdateUI(v1, 0);
}
