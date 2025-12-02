char __fastcall FreeCellMove::CanMoveCard(struct Card *a1, struct CardStack *a2, char a3, int *a4, bool *a5)
{
  FreeCellGame *v9; // rbx
  struct CardStack *CardStackWithCard; // rdi
  unsigned int v12; // edx
  unsigned int v13; // ecx
  struct CardStack **v14; // rax
  unsigned int CardLocation; // eax
  int v16; // ecx
  int v17; // edi
  unsigned int v18; // ecx
  int v19; // ebx
  TipManager *v20; // rcx

  if ( a5 )
    *a5 = 0;
  if ( a4 )
    *a4 = 0;
  v9 = g_pFreeCellGame;
  CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)g_pFreeCellGame + 22), a1);
  if ( !CardStackWithCard )
    return 0;
  v12 = *((_DWORD *)v9 + 58);
  v13 = 0;
  if ( v12 )
  {
    v14 = (struct CardStack **)*((_QWORD *)v9 + 31);
    while ( *v14 != CardStackWithCard )
    {
      ++v13;
      ++v14;
      if ( v13 >= v12 )
        goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  CardLocation = CardStack::GetCardLocation(CardStackWithCard, a1);
  v16 = *((_DWORD *)CardStackWithCard + 76);
  v17 = 1;
  v18 = v16 - CardLocation;
  if ( v18 > 1 )
    v17 = v18;
  v19 = FreeCellMove::MaxMove(0, *((_DWORD *)a2 + 76) == 0);
  if ( !FreeCellMove::IsPartOfValidSequence(a1) )
    return 0;
  if ( v19 < v17 )
  {
    if ( a3 && !*(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) )
    {
      v20 = (TipManager *)*((_QWORD *)g_pFreeCellGame + 42);
      if ( v19 == 1 )
        TipManager::ShowTipIfEnabled(v20, L"MoveTooLargeSingular", 0, 1, v17);
      else
        TipManager::ShowTipIfEnabled(v20, L"MoveTooLarge", 0, 1, v17, v19);
    }
    return 0;
  }
  if ( (int)FreeCellMove::MaxMove(1, 0) >= v17 && a5 )
    *a5 = 1;
  if ( a4 )
    *a4 = v19 - v17;
  return 1;
}
