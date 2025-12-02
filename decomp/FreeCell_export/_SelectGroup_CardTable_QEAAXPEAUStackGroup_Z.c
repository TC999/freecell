void __fastcall CardTable::SelectGroup(CardTable *this, struct StackGroup *a2)
{
  struct StackGroup *v2; // rdi
  bool IsGroupSelectable; // al
  int v5; // ebx
  unsigned int v6; // edx
  __int64 i; // rcx

  v2 = a2;
  IsGroupSelectable = CardTable::IsGroupSelectable(this, a2);
  v5 = 0;
  while ( !IsGroupSelectable )
  {
    v2 = (struct StackGroup *)*((_QWORD *)v2 + 2);
    IsGroupSelectable = CardTable::IsGroupSelectable(this, v2);
  }
  v6 = *((_DWORD *)this + 40);
  if ( v6 )
  {
    for ( i = *((_QWORD *)this + 19); *(struct StackGroup **)(*(_QWORD *)i + 64LL) != v2; i += 8 )
    {
      if ( ++v5 >= v6 )
        return;
    }
    CardStack::SetFocus(**((CardStack ***)v2 + 6), -1);
  }
}
