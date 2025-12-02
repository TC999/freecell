void __fastcall CardTable::SelectCardDown(CardTable *this, struct Card *a2)
{
  CardStack *CardStackWithCard; // rax
  CardStack *v5; // rsi
  unsigned int CardLocation; // eax
  Card *v7; // rbx
  __int64 v8; // rcx
  __int64 v9; // rax
  Card *v10; // rcx
  int v11; // eax
  char v12; // dl
  int v13; // r8d
  Card **v14; // rcx

  if ( a2 )
  {
    CardStackWithCard = CardTable::GetCardStackWithCard(this, a2);
    v5 = CardStackWithCard;
    if ( CardStackWithCard )
    {
      CardLocation = CardStack::GetCardLocation(CardStackWithCard, a2);
      v7 = 0;
      if ( !*((_BYTE *)v5 + 16)
        && CardLocation < *((_DWORD *)v5 + 76) - 1
        && (v8 = CardLocation + 1, v9 = *((_QWORD *)v5 + 40), (v7 = *(Card **)(v9 + 8 * v8)) != 0)
        && *((_BYTE *)v7 + 17) )
      {
        v10 = *(Card **)(v9 + 8 * v8);
      }
      else
      {
        if ( CardTable::MoveRowDown(this, v5) )
          return;
        v11 = *((_DWORD *)v5 + 76);
        if ( !v11 )
          goto LABEL_19;
        v12 = 0;
        v13 = 0;
        if ( v11 > 0 )
        {
          v14 = (Card **)*((_QWORD *)v5 + 40);
          while ( 1 )
          {
            v7 = *v14;
            if ( *v14 )
            {
              if ( *((_BYTE *)v7 + 17) )
                break;
            }
            ++v13;
            ++v14;
            if ( v13 >= v11 )
              goto LABEL_17;
          }
          v12 = 1;
        }
LABEL_17:
        if ( !v7 || (v10 = v7, !v12) )
LABEL_19:
          v10 = a2;
      }
      Card::SetFocus(v10);
    }
  }
}
