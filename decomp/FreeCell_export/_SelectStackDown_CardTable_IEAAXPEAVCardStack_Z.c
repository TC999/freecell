void __fastcall CardTable::SelectStackDown(CardTable *this, struct CardStack *a2)
{
  __int64 v4; // r8
  unsigned int v5; // eax
  __int64 v6; // rdx
  struct CardStack **v7; // rcx

  while ( 1 )
  {
    v4 = *((_QWORD *)a2 + 8);
    v5 = 0;
    v6 = 0;
    if ( *(_DWORD *)(v4 + 32) )
    {
      v7 = *(struct CardStack ***)(v4 + 48);
      while ( *v7 != a2 )
      {
        ++v5;
        ++v6;
        ++v7;
        if ( v5 >= *(_DWORD *)(v4 + 32) )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      v5 = -1;
      v6 = -1;
    }
    if ( !v5 )
      break;
    a2 = *(struct CardStack **)(*(_QWORD *)(v4 + 48) + 8 * v6 - 8);
    if ( CardTable::IsGroupSelectable(this, *((struct StackGroup **)a2 + 8)) )
    {
      CardStack::SetFocus(a2, -1);
      return;
    }
  }
  CardTable::SelectGroupDown(this, *((struct StackGroup **)a2 + 8));
}
