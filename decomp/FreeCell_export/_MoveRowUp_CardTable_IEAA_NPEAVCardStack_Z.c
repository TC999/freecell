char __fastcall CardTable::MoveRowUp(CardStack **this, const unsigned __int16 **a2)
{
  char v4; // bl
  struct CardStack *CardStack; // rax
  CardStack *v6; // rsi
  CardStack *v7; // rcx

  v4 = 0;
  CardStack = CardTable::GetCardStack((CardTable *)this, a2[17]);
  v6 = CardStack;
  if ( CardStack )
  {
    if ( CardTable::IsGroupSelectable((CardTable *)this, *((struct StackGroup **)CardStack + 8)) )
    {
      CardStack::SetFocus(v6, -1);
      this[26] = (CardStack *)a2;
      return 1;
    }
  }
  else
  {
    v7 = this[26];
    if ( v7 || (v7 = this[25]) != 0 )
    {
      CardStack::SetFocus(v7, -1);
      return 1;
    }
  }
  return v4;
}
