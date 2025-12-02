char __fastcall CardTable::MoveRowDown(CardStack **this, const unsigned __int16 **a2)
{
  char v4; // bl
  struct CardStack *CardStack; // rax
  struct CardStack *v6; // rsi
  unsigned int v7; // edx
  int v8; // ecx
  __int64 v9; // r9
  __int64 v10; // rax
  CardStack *v11; // rcx

  v4 = 0;
  CardStack = CardTable::GetCardStack((CardTable *)this, a2[14]);
  v6 = CardStack;
  if ( CardStack )
  {
    if ( CardTable::IsGroupSelectable((CardTable *)this, *((struct StackGroup **)CardStack + 8)) )
    {
      this[25] = (CardStack *)a2;
      v7 = *((_DWORD *)v6 + 76);
      v8 = 0;
      if ( v7 )
      {
        v9 = *((_QWORD *)v6 + 40);
        while ( 1 )
        {
          v10 = v7 - v8 - 1;
          if ( *(_BYTE *)(*(_QWORD *)(v9 + 8 * v10) + 17LL) )
          {
            if ( !*((_BYTE *)v6 + 16) )
              break;
          }
          if ( ++v8 >= v7 )
            goto LABEL_8;
        }
        Card::SetFocus(*(Card **)(v9 + 8 * v10));
        return 1;
      }
LABEL_8:
      v11 = v6;
LABEL_12:
      CardStack::SetFocus(v11, -1);
      return 1;
    }
  }
  else
  {
    v11 = this[25];
    if ( v11 )
      goto LABEL_12;
    v11 = this[26];
    if ( v11 )
      goto LABEL_12;
  }
  return v4;
}
