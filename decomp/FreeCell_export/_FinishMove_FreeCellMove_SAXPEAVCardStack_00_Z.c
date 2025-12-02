void __fastcall FreeCellMove::FinishMove(struct CardStack *a1, struct CardStack *this, struct CardStack *a3)
{
  int v5; // eax
  FreeCellGame *v6; // rcx
  CardTable *v7; // rbx
  _QWORD v8[2]; // [rsp+30h] [rbp-38h] BYREF
  int v9; // [rsp+40h] [rbp-28h]
  int v10; // [rsp+44h] [rbp-24h]
  int v11; // [rsp+48h] [rbp-20h]
  struct CardStack *v12; // [rsp+50h] [rbp-18h]

  v8[0] = a3;
  *((_DWORD *)g_pFreeCellGame + 26) = 0;
  v5 = *((_DWORD *)a3 + 76) - 1;
  v8[1] = **((_QWORD **)a1 + 40);
  v9 = v5;
  v10 = *((_DWORD *)this + 76);
  v11 = *((_DWORD *)a1 + 76);
  v12 = this;
  FreeCellMove::addPreviousMove((struct Move *)v8);
  TipManager::HideTip(*((TipManager **)g_pFreeCellGame + 42), 0);
  v6 = g_pFreeCellGame;
  *((_DWORD *)g_pFreeCellGame + 26) = 0;
  FreeCellGame::PlaySoundW(v6, 9u, 0, 0);
  FreeCellGame::SetSelectedCard(g_pFreeCellGame, 0, 1, 1, 1);
  CardStack::Join(this, a1);
  CardStack::Arrange(this, 1, 0);
  CardStack::SetHighlight(this, 0, 0);
  if ( *((_QWORD *)g_pFreeCellGame + 41) )
    *((_QWORD *)g_pFreeCellGame + 41) = 0;
  if ( !wcsncmp(*((const wchar_t **)this + 36), L"SuitStack", 9u) )
  {
    Card::SetEnabled(*(Card **)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1)), 1, 0);
    FreeCellGame::PlaySoundW(g_pFreeCellGame, 0xAu, 0, 0);
  }
  v7 = (CardTable *)*((_QWORD *)g_pFreeCellGame + 22);
  Log(0x10000u, L"CardTable::PushState()");
  CardTable::PushAction(v7, 0, &dword_1000028D4, &dword_1000028D4);
  if ( *((_BYTE *)g_pFreeCellGame + 360) != 1 )
    *((_BYTE *)g_pFreeCellGame + 360) = 1;
}
