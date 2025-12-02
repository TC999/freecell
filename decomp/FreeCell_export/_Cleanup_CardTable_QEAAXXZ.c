// Hidden C++ exception states: #wind=4
void __fastcall CardTable::Cleanup(void **this)
{
  UserInterface *v2; // rbx
  CardAnimationManager *v3; // rbx
  unsigned int v4; // ebp
  __int64 v5; // rsi
  void *v6; // rcx
  void *v7; // rcx
  unsigned int v8; // esi
  __int64 v9; // rbx
  __int64 v10; // rcx
  unsigned int v11; // ebx
  __int64 v12; // rsi
  unsigned int v13; // ebp
  __int64 v14; // rbx
  void **v15; // rsi
  unsigned int v16; // esi
  __int64 v17; // rbx
  __int64 v18; // rcx
  unsigned int v19; // ebp
  __int64 v20; // rsi
  void **v21; // rbx
  NodeBase *v22; // rcx
  NodeBase *v23; // rcx

  v2 = g_pUserInterface;
  Array<Access_Node *>::FindRemove((__int64)g_pUserInterface + 120, (__int64)this);
  *((_QWORD *)v2 + 21) = 0;
  NodeBase::RemoveListener(*((NodeBase **)g_pRenderManager + 15), (struct IEventListener *)this);
  v3 = (CardAnimationManager *)this[11];
  if ( v3 )
  {
    CardAnimationManager::RemoveAllAnimations(v3, 0);
    v4 = 0;
    if ( *((_DWORD *)v3 + 16) )
    {
      v5 = 0;
      do
      {
        operator delete(*(void **)(v5 + *((_QWORD *)v3 + 10)));
        ++v4;
        v5 += 8;
      }
      while ( v4 < *((_DWORD *)v3 + 16) );
    }
    *((_DWORD *)v3 + 16) = 0;
    *((_QWORD *)v3 + 3) = 0;
    v6 = (void *)*((_QWORD *)v3 + 10);
    if ( v6 )
      free(v6);
    v7 = (void *)*((_QWORD *)v3 + 7);
    if ( v7 )
      free(v7);
    operator delete(v3);
  }
  this[11] = 0;
  v8 = 0;
  if ( *((_DWORD *)this + 92) )
  {
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)((char *)this[45] + v9);
      if ( v10 )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 8LL))(v10, 1);
      ++v8;
      v9 += 8;
    }
    while ( v8 < *((_DWORD *)this + 92) );
  }
  v11 = 0;
  if ( *((_DWORD *)this + 92) )
  {
    v12 = 0;
    do
    {
      free(*(void **)((char *)this[44] + v12));
      ++v11;
      v12 += 8;
    }
    while ( v11 < *((_DWORD *)this + 92) );
  }
  *((_DWORD *)this + 92) = 0;
  v13 = 0;
  if ( *((_DWORD *)this + 60) )
  {
    v14 = 0;
    do
    {
      v15 = *(void ***)((char *)this[32] + v14);
      if ( v15 )
      {
        operator delete(v15[6]);
        operator delete(v15[3]);
        operator delete(v15);
      }
      *(_QWORD *)((char *)this[32] + v14) = 0;
      ++v13;
      v14 += 8;
    }
    while ( v13 < *((_DWORD *)this + 60) );
  }
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  free(this[32]);
  this[32] = 0;
  v16 = 0;
  if ( *((_DWORD *)this + 40) )
  {
    v17 = 0;
    do
    {
      v18 = *(_QWORD *)((char *)this[19] + v17);
      if ( v18 )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v18 + 8) + 8LL))(v18 + 8, 1);
      ++v16;
      v17 += 8;
    }
    while ( v16 < *((_DWORD *)this + 40) );
  }
  SortedListW<unsigned int>::RemoveAll((__int64)(this + 18));
  v19 = 0;
  if ( *((_DWORD *)this + 34) )
  {
    v20 = 0;
    do
    {
      v21 = *(void ***)((char *)this[16] + v20);
      if ( v21 )
      {
        *v21 = &Card::`vftable';
        Card::Cleanup((Card *)v21);
        operator delete(v21[7]);
        operator delete(v21);
      }
      ++v19;
      v20 += 8;
    }
    while ( v19 < *((_DWORD *)this + 34) );
  }
  SortedListW<unsigned int>::RemoveAll((__int64)(this + 15));
  v22 = (NodeBase *)this[13];
  if ( v22 )
  {
    NodeBase::DeleteSelf(v22);
    this[13] = 0;
  }
  v23 = (NodeBase *)this[12];
  if ( v23 )
  {
    NodeBase::DeleteSelf(v23);
    this[12] = 0;
  }
}
