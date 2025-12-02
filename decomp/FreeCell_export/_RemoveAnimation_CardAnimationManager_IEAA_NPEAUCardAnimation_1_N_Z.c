// Hidden C++ exception states: #wind=1
char __fastcall CardAnimationManager::RemoveAnimation(
        CardTable **this,
        struct CardAnimationManager::CardAnimation *a2,
        char a3)
{
  Card *v6; // rcx
  NodeBase *v7; // rcx
  int v8; // eax
  void *v9; // rcx
  unsigned int v10; // ebp
  __int64 v11; // rsi
  __int64 v12; // rdx
  bool v13; // si
  _DWORD v15[4]; // [rsp+28h] [rbp-30h] BYREF
  void *Block; // [rsp+38h] [rbp-20h]

  if ( Array<Access_Node *>::FindRemove((__int64)(this + 5), (__int64)a2) == 1 )
  {
    v6 = (Card *)*((_QWORD *)a2 + 1);
    if ( v6 )
      Card::SetShadow(v6, 0, 0, 0);
    v7 = (NodeBase *)*((_QWORD *)a2 + 2);
    if ( v7 )
      NodeBase::DeleteSelf(v7);
    if ( a3 && !*((_DWORD *)this + 10) )
      CardTable::SetObjectsReceiveMouseEvents(this[4], 1);
    if ( *((_BYTE *)this + 1) )
    {
      v8 = 0;
      v15[0] = 0;
      v15[1] = 0;
      v15[2] = 16;
      v9 = 0;
      Block = 0;
      v10 = 0;
      if ( *((_DWORD *)this + 10) )
      {
        v11 = 0;
        do
        {
          v12 = *(_QWORD *)((char *)this[7] + v11);
          if ( *(_BYTE *)(v12 + 70) )
            Array<IEventListener *>::Add((__int64)v15, v12);
          ++v10;
          v11 += 8;
        }
        while ( v10 < *((_DWORD *)this + 10) );
        v9 = Block;
        v8 = v15[0];
      }
      v13 = v8 != 0;
      if ( v9 )
        free(v9);
      if ( !v13 && *((_BYTE *)a2 + 70) && !*((_BYTE *)g_pUserInterface + 300) )
      {
        if ( !a3 )
        {
LABEL_26:
          Array<Access_Node *>::FindRemove((__int64)(this + 8), (__int64)a2);
          operator delete(a2);
          return 1;
        }
        UserInterface::UpdateMouseOverFocus(g_pUserInterface);
      }
    }
    if ( a3 )
    {
      if ( this[3] )
        (**(void (__fastcall ***)(CardTable *, struct CardAnimationManager::CardAnimation *))this[3])(this[3], a2);
    }
    goto LABEL_26;
  }
  return 0;
}
