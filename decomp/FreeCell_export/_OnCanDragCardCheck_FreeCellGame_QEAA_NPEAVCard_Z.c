char __fastcall FreeCellGame::OnCanDragCardCheck(CardTable **this, struct Card *a2)
{
  const unsigned __int16 *v3; // rdx
  const wchar_t *v5; // r9
  struct CardStack *CardStackWithCard; // rax

  v3 = (const unsigned __int16 *)*((_QWORD *)a2 + 7);
  if ( !v3 )
  {
    v5 = L"Card is missing a name";
LABEL_3:
    Log(0x10000001u, L"%s() - %s", L"FreeCellGame::OnCanDragCardCheck", v5);
    return 0;
  }
  CardStackWithCard = CardTable::GetCardStackWithCard(this[22], v3);
  if ( !CardStackWithCard )
  {
    v5 = L"Card is not associated with a stack";
    goto LABEL_3;
  }
  if ( !*((_QWORD *)CardStackWithCard + 36) )
  {
    v5 = L"Stack is missing a name";
    goto LABEL_3;
  }
  if ( (unsigned int)FreeCellMove::StackToMoveDestination(CardStackWithCard, 0) == 2 )
    return 0;
  if ( !FreeCellMove::IsPartOfValidSequence(a2) )
  {
    if ( !*((_BYTE *)this + 378) )
    {
      if ( !*((_BYTE *)this[11] + 14) )
        TipManager::ShowTipIfEnabled(this[42], L"InvalidSequence", 0, 1);
      FreeCellGame::PlaySoundW((FreeCellGame *)this, 7u, 0, 0);
      *((_BYTE *)this + 378) = 1;
    }
    return 0;
  }
  return 1;
}
