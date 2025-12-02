void __fastcall FreeCellGame::Cleanup(FreeCellGame *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  NodeBase *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  NodeBase *v7; // rcx
  NodeBase *v8; // rcx
  NodeBase *v9; // rcx
  NodeBase *v10; // rcx
  unsigned int v11; // esi
  __int64 v12; // rbx
  void *v13; // rcx
  unsigned int v14; // esi
  __int64 v15; // rbx
  void *v16; // rcx
  UserInterface *v17; // rbx

  v2 = *((_QWORD *)this + 42);
  if ( v2 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 8LL))(v2, 1);
  v3 = *((_QWORD *)this + 22);
  *((_QWORD *)this + 42) = 0;
  if ( v3 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 8LL))(v3, 1);
  *((_QWORD *)this + 22) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 58) = 0;
  v4 = (NodeBase *)*((_QWORD *)this + 14);
  if ( v4 )
  {
    NodeBase::DeleteSelf(v4);
    *((_QWORD *)this + 14) = 0;
  }
  operator delete(*((void **)this + 10));
  v5 = (void *)*((_QWORD *)this + 11);
  *((_QWORD *)this + 10) = 0;
  operator delete(v5);
  v6 = (void *)*((_QWORD *)this + 12);
  *((_QWORD *)this + 11) = 0;
  operator delete(v6);
  v7 = (NodeBase *)*((_QWORD *)this + 16);
  *((_QWORD *)this + 12) = 0;
  if ( v7 )
  {
    NodeBase::DeleteSelf(v7);
    *((_QWORD *)this + 16) = 0;
  }
  v8 = (NodeBase *)*((_QWORD *)this + 17);
  if ( v8 )
  {
    NodeBase::DeleteSelf(v8);
    *((_QWORD *)this + 17) = 0;
  }
  v9 = (NodeBase *)*((_QWORD *)this + 18);
  if ( v9 )
  {
    NodeBase::DeleteSelf(v9);
    *((_QWORD *)this + 18) = 0;
  }
  v10 = (NodeBase *)*((_QWORD *)this + 19);
  if ( v10 )
  {
    NodeBase::DeleteSelf(v10);
    *((_QWORD *)this + 19) = 0;
  }
  v11 = 0;
  if ( *((_DWORD *)this + 8) )
  {
    v12 = 0;
    do
    {
      operator delete(*(void **)(*((_QWORD *)this + 6) + v12));
      ++v11;
      *(_QWORD *)(v12 + *((_QWORD *)this + 6)) = 0;
      v12 += 8;
    }
    while ( v11 < *((_DWORD *)this + 8) );
  }
  v13 = (void *)*((_QWORD *)this + 6);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  free(v13);
  *((_QWORD *)this + 6) = 0;
  v14 = 0;
  if ( *((_DWORD *)this + 14) )
  {
    v15 = 0;
    do
    {
      operator delete(*(void **)(v15 + *((_QWORD *)this + 9)));
      ++v14;
      *(_QWORD *)(v15 + *((_QWORD *)this + 9)) = 0;
      v15 += 8;
    }
    while ( v14 < *((_DWORD *)this + 14) );
  }
  v16 = (void *)*((_QWORD *)this + 9);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  free(v16);
  v17 = g_pUserInterface;
  *((_QWORD *)this + 9) = 0;
  *((_QWORD *)this + 38) = 0;
  Array<Access_Node *>::FindRemove((char *)v17 + 120, (char *)this + 16);
  Array<Access_Node *>::FindRemove((char *)v17 + 96, (char *)this + 16);
}
