void __fastcall CardTable::SelectStackUp(CardTable *this, struct CardStack *a2)
{
  __int64 v3; // rdx
  unsigned int v4; // r8d
  struct CardStack **v5; // rax
  unsigned int v6; // eax

  v3 = *((_QWORD *)a2 + 8);
  v4 = 0;
  if ( *(_DWORD *)(v3 + 32) )
  {
    v5 = *(struct CardStack ***)(v3 + 48);
    while ( *v5 != a2 )
    {
      ++v4;
      ++v5;
      if ( v4 >= *(_DWORD *)(v3 + 32) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = -1;
  }
  v6 = *(_DWORD *)(v3 + 32) - 1;
  if ( v4 >= v6 )
  {
    if ( v4 == v6 )
      CardTable::SelectGroupUp(this, (struct StackGroup *)v3);
  }
  else
  {
    CardStack::SetFocus(*(CardStack **)(*(_QWORD *)(v3 + 48) + 8LL * (v4 + 1)), -1);
  }
}
