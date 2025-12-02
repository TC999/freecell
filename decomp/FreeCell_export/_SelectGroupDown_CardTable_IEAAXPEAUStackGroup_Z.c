void __fastcall CardTable::SelectGroupDown(CardTable *this, struct StackGroup *a2)
{
  int v4; // ebp
  __int64 v5; // r12
  __int64 v6; // rbx
  unsigned int v7; // r8d
  int v8; // ecx
  __int64 i; // rdx
  struct NodeBase *v10; // rdx
  __int64 v11; // r8
  int v12; // eax
  Card *v13; // rcx

  while ( 1 )
  {
    a2 = (struct StackGroup *)*((_QWORD *)a2 + 2);
    v4 = 0;
    if ( *((_DWORD *)this + 6) )
      break;
LABEL_5:
    if ( !a2 )
    {
      if ( !*((_DWORD *)this + 6) )
        return;
      v10 = (struct NodeBase *)**((_QWORD **)this + 5);
      goto LABEL_20;
    }
    if ( CardTable::IsGroupSelectable(this, a2) )
    {
      v7 = *((_DWORD *)this + 40);
      v8 = 0;
      if ( v7 )
      {
        for ( i = *((_QWORD *)this + 19); *(struct StackGroup **)(*(_QWORD *)i + 64LL) != a2; i += 8 )
        {
          if ( ++v8 >= v7 )
            return;
        }
        v11 = *(_QWORD *)(*((_QWORD *)a2 + 6) + 8LL * (unsigned int)(*((_DWORD *)a2 + 8) - 1));
        v12 = *(_DWORD *)(v11 + 304);
        if ( v12 && (v13 = *(Card **)(*(_QWORD *)(v11 + 320) + 8LL * (unsigned int)(v12 - 1)), *((_BYTE *)v13 + 17)) )
          Card::SetFocus(v13);
        else
          CardStack::SetFocus((CardStack *)v11, -1);
      }
      return;
    }
  }
  v5 = 0;
  while ( 1 )
  {
    v6 = *((_QWORD *)this + 5);
    if ( UserInterface::GetCurrentFocus(g_pUserInterface) == *(struct NodeBase **)(v5 + v6) )
      break;
    ++v4;
    v5 += 8;
    if ( (unsigned int)v4 >= *((_DWORD *)this + 6) )
      goto LABEL_5;
  }
  if ( v4 < *((_DWORD *)this + 6) - 1 )
  {
    v10 = *(struct NodeBase **)(*((_QWORD *)this + 5) + 8LL * (unsigned int)(v4 + 1));
LABEL_20:
    UserInterface::SetFocus(g_pUserInterface, v10);
  }
}
