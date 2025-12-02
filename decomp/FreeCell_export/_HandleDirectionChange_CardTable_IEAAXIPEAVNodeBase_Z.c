void __fastcall CardTable::HandleDirectionChange(CardTable *this, int a2, const unsigned __int16 **a3)
{
  int v5; // edx
  int v6; // edx
  int v7; // ecx
  struct CardStack *v8; // rsi
  bool IsGroupSelectable; // al
  CardTable *v10; // rcx
  struct CardStack *v11; // rdx
  struct Card *Card; // rax
  CardTable *v13; // rcx
  int v14; // ecx
  struct CardStack *v15; // rsi
  bool v16; // al
  CardTable *v17; // rcx
  struct CardStack *v18; // rdx
  struct Card *v19; // rax
  CardTable *v20; // rcx
  int v21; // ecx
  struct CardStack *v22; // rax
  struct CardStack *v23; // rax
  int v24; // ecx
  struct CardStack *CardStackWithCard; // rax
  struct CardStack *CardStack; // rax

  if ( !a2 )
  {
    v24 = *((_DWORD *)this + 96);
    if ( !v24 )
    {
      Card = CardTable::GetCard(this, a3[16]);
      v13 = this;
      if ( !Card )
      {
        CardStack = CardTable::GetCardStack(this, a3[16]);
        if ( CardStack )
          CardTable::MoveRowDown(this, CardStack);
        return;
      }
      goto LABEL_38;
    }
    if ( v24 != 1 )
      return;
    CardStackWithCard = CardTable::GetCardStack(this, a3[16]);
    v17 = this;
    if ( !CardStackWithCard )
    {
      CardStackWithCard = CardTable::GetCardStackWithCard(this, a3[16]);
      v17 = this;
    }
    v18 = CardStackWithCard;
LABEL_36:
    CardTable::SelectStackDown(v17, v18);
    return;
  }
  v5 = a2 - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 != 1 )
        return;
      *((_QWORD *)this + 26) = 0;
      *((_QWORD *)this + 25) = 0;
      v7 = *((_DWORD *)this + 97);
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          v8 = CardTable::GetCardStack(this, a3[16]);
          if ( v8 || (v8 = CardTable::GetCardStackWithCard(this, a3[16])) != 0 )
          {
            IsGroupSelectable = CardTable::IsGroupSelectable(this, *((struct StackGroup **)v8 + 8));
            v10 = this;
            if ( IsGroupSelectable )
            {
              v11 = v8;
LABEL_11:
              CardTable::SelectStackUp(v10, v11);
              return;
            }
            CardTable::SelectGroupUp(this, *((struct StackGroup **)v8 + 8));
          }
        }
        return;
      }
      Card = CardTable::GetCard(this, a3[16]);
      v13 = this;
LABEL_38:
      CardTable::SelectCardDown(v13, Card);
      return;
    }
    *((_QWORD *)this + 26) = 0;
    *((_QWORD *)this + 25) = 0;
    v14 = *((_DWORD *)this + 97);
    if ( v14 )
    {
      if ( v14 != 1 )
        return;
      v15 = CardTable::GetCardStack(this, a3[16]);
      if ( !v15 )
      {
        v15 = CardTable::GetCardStackWithCard(this, a3[16]);
        if ( !v15 )
          return;
      }
      v16 = CardTable::IsGroupSelectable(this, *((struct StackGroup **)v15 + 8));
      v17 = this;
      if ( !v16 )
      {
        CardTable::SelectGroupDown(this, *((struct StackGroup **)v15 + 8));
        return;
      }
      v18 = v15;
      goto LABEL_36;
    }
    v19 = CardTable::GetCard(this, a3[16]);
    v20 = this;
LABEL_22:
    CardTable::SelectCardUp(v20, v19);
    return;
  }
  v21 = *((_DWORD *)this + 96);
  if ( !v21 )
  {
    v19 = CardTable::GetCard(this, a3[16]);
    v20 = this;
    if ( !v19 )
    {
      v23 = CardTable::GetCardStack(this, a3[16]);
      if ( v23 )
        CardTable::MoveRowUp(this, v23);
      return;
    }
    goto LABEL_22;
  }
  if ( v21 == 1 )
  {
    v22 = CardTable::GetCardStack(this, a3[16]);
    v10 = this;
    if ( !v22 )
    {
      v22 = CardTable::GetCardStackWithCard(this, a3[16]);
      v10 = this;
    }
    v11 = v22;
    goto LABEL_11;
  }
}
