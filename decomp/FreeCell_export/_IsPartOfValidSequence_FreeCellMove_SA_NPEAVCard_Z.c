bool __fastcall FreeCellMove::IsPartOfValidSequence(CardTable **a1)
{
  struct Card *v1; // rsi
  bool DoesCardFollowSequence; // bp
  CardStack *CardStackWithCard; // rax
  CardStack *v4; // rdi
  signed int CardLocation; // eax
  unsigned int v6; // r12d
  __int64 v7; // r13
  struct Card *v8; // rbx

  v1 = (struct Card *)a1;
  DoesCardFollowSequence = 1;
  CardStackWithCard = CardTable::GetCardStackWithCard(a1[3], (struct Card *)a1);
  v4 = CardStackWithCard;
  if ( !CardStackWithCard )
    SharedDialogs::FatalDialog::Show(0);
  CardLocation = CardStack::GetCardLocation(CardStackWithCard, v1);
  if ( CardLocation != -1 )
  {
    v6 = CardLocation + 1;
    v7 = 8LL * CardLocation + 8;
    do
    {
      if ( v6 >= *((_DWORD *)v4 + 76) )
        break;
      v8 = *(struct Card **)(v7 + *((_QWORD *)v4 + 40));
      ++v6;
      v7 += 8;
      DoesCardFollowSequence = FreeCellMove::DoesCardFollowSequence(v1, v8);
      v1 = v8;
    }
    while ( DoesCardFollowSequence );
  }
  return DoesCardFollowSequence;
}
