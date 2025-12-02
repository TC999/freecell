void __fastcall CardAnimationManager::QueueOrSetAnimation(
        CardTable **this,
        struct CardAnimationManager::CardAnimation *a2,
        struct Card *a3,
        char a4,
        bool a5)
{
  bool v9; // bl
  unsigned int v10; // edx
  CardTable *v11; // rcx
  __int64 v12; // rax
  unsigned int v13; // ecx
  CardTable *v14; // rax
  __int64 v15; // rdx

  CardTable::SetObjectsReceiveMouseEvents(this[4], 0);
  v9 = 0;
  if ( *((_BYTE *)this + 1) )
    v9 = *((_DWORD *)this + 10) == 0;
  v10 = 0;
  if ( *((_DWORD *)this + 10) )
  {
    v11 = this[7];
    while ( 1 )
    {
      v12 = *(_QWORD *)v11;
      if ( a3 == *(struct Card **)(*(_QWORD *)v11 + 8LL) )
        break;
      ++v10;
      v11 = (CardTable *)((char *)v11 + 8);
      if ( v10 >= *((_DWORD *)this + 10) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v12 = 0;
  }
  if ( a5 && v12 )
  {
    while ( *(_QWORD *)(v12 + 24) )
      v12 = *(_QWORD *)(v12 + 24);
    *(_QWORD *)(v12 + 24) = a2;
  }
  else
  {
    if ( a4 )
      NodeBase::MoveToFront(*((NodeBase **)a3 + 8));
    v13 = 0;
    if ( *((_DWORD *)this + 10) )
    {
      v14 = this[7];
      while ( 1 )
      {
        v15 = *(_QWORD *)v14;
        if ( a3 == *(struct Card **)(*(_QWORD *)v14 + 8LL) && !*(_DWORD *)(v15 + 76) )
          break;
        ++v13;
        v14 = (CardTable *)((char *)v14 + 8);
        if ( v13 >= *((_DWORD *)this + 10) )
          goto LABEL_22;
      }
      CardAnimationManager::RemoveAnimation(
        (CardAnimationManager *)this,
        (struct CardAnimationManager::CardAnimation *)v15,
        1);
    }
LABEL_22:
    Array<IEventListener *>::Add((__int64)(this + 5), (__int64)a2);
  }
  if ( v9 )
    UserInterface::ClearFocus(g_pUserInterface);
}
