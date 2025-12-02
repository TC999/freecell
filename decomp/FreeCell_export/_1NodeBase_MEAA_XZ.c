// Hidden C++ exception states: #wind=8
void __fastcall NodeBase::~NodeBase(NodeBase *this)
{
  __int64 v2; // rcx
  unsigned int v3; // esi
  __int64 v4; // rdi
  __int64 v5; // rcx
  unsigned int v6; // ebp
  __int64 v7; // rsi
  _QWORD *v8; // rdi
  unsigned int v9; // r13d
  __int64 v10; // r12
  __int64 v11; // rcx
  void *v12; // rcx
  RenderManager *v13; // rdi
  unsigned int *v14; // rcx
  unsigned int v15; // edx
  NodeBase **v16; // rax
  UserInterface *v17; // rcx
  void *v18; // rcx
  void *v19; // rcx
  void *v20; // rcx
  void *v21; // rcx
  void *v22; // rcx
  void *v23; // rcx

  *(_QWORD *)this = &NodeBase::`vftable';
  *((_DWORD *)this + 50) = 0;
  v2 = *((_QWORD *)this + 29);
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 - 8) )
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 8LL))(v2, 3);
    else
      operator delete((void *)(v2 - 8));
  }
  v3 = 0;
  if ( *((_DWORD *)this + 20) )
  {
    v4 = 0;
    do
    {
      v5 = *(_QWORD *)(v4 + *((_QWORD *)this + 12));
      if ( v5 )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v5 + 104LL))(v5, 1);
      ++v3;
      v4 += 8;
    }
    while ( v3 < *((_DWORD *)this + 20) );
  }
  v6 = 0;
  if ( *((_DWORD *)this + 64) )
  {
    v7 = 0;
    do
    {
      v8 = *(_QWORD **)(v7 + *((_QWORD *)this + 31));
      if ( v8 )
      {
        v9 = 0;
        if ( *(_DWORD *)v8 )
        {
          v10 = 0;
          do
          {
            v11 = *(_QWORD *)(v10 + v8[2]);
            if ( v11 )
              (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 8LL))(v11, 1);
            ++v9;
            v10 += 16;
          }
          while ( v9 < *(_DWORD *)v8 );
        }
        v12 = (void *)v8[2];
        if ( v12 )
          free(v12);
        operator delete(v8);
      }
      ++v6;
      v7 += 8;
    }
    while ( v6 < *((_DWORD *)this + 64) );
  }
  *((_DWORD *)this + 64) = 0;
  v13 = g_pRenderManager;
  if ( *((_BYTE *)this + 40) )
  {
    v14 = (unsigned int *)((char *)g_pRenderManager + 128);
    v15 = 0;
    if ( *((_DWORD *)g_pRenderManager + 32) )
    {
      v16 = (NodeBase **)*((_QWORD *)g_pRenderManager + 18);
      while ( *v16 != this )
      {
        ++v15;
        ++v16;
        if ( v15 >= *v14 )
          goto LABEL_27;
      }
    }
    else
    {
LABEL_27:
      v15 = -1;
    }
    if ( v15 != -1 )
      Array<ScoredMove *>::Remove((__int64)v14, v15);
  }
  v17 = g_pUserInterface;
  if ( *((NodeBase **)g_pUserInterface + 8) == this )
    *((_QWORD *)g_pUserInterface + 8) = 0;
  if ( *((NodeBase **)v17 + 27) == this )
    *((_QWORD *)v17 + 27) = 0;
  if ( *((NodeBase **)v17 + 22) == this )
  {
    *((_QWORD *)v17 + 22) = 0;
    *((_QWORD *)v17 + 23) = 0;
    *((_QWORD *)v17 + 24) = 0;
    *((_QWORD *)v17 + 25) = 0;
  }
  if ( *((NodeBase **)v17 + 23) == this )
    *((_QWORD *)v17 + 23) = 0;
  if ( *((NodeBase **)v17 + 24) == this )
    *((_QWORD *)v17 + 24) = 0;
  if ( *((NodeBase **)v17 + 25) == this )
    *((_QWORD *)v17 + 25) = 0;
  if ( *((NodeBase **)v17 + 38) == this )
    *((_QWORD *)v17 + 38) = 0;
  if ( *((_BYTE *)this + 144) && *((NodeBase **)v13 + 15) != this )
    UserInterface::Access_ClipNode(v17, this);
  operator delete(*((void **)this + 16));
  LocalFree(*((HLOCAL *)this + 20));
  LocalFree(*((HLOCAL *)this + 19));
  LocalFree(*((HLOCAL *)this + 21));
  LocalFree(*((HLOCAL *)this + 22));
  LocalFree(*((HLOCAL *)this + 23));
  --NodeBase::m_RenderLayerNodeCount[*((unsigned int *)this + 15)];
  v18 = (void *)*((_QWORD *)this + 44);
  if ( v18 )
    free(v18);
  v19 = (void *)*((_QWORD *)this + 41);
  if ( v19 )
    free(v19);
  v20 = (void *)*((_QWORD *)this + 38);
  if ( v20 )
    free(v20);
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  free(*((void **)this + 30));
  free(*((void **)this + 31));
  *((_QWORD *)this + 30) = 0;
  *((_QWORD *)this + 31) = 0;
  v21 = (void *)*((_QWORD *)this + 27);
  if ( v21 )
    free(v21);
  v22 = (void *)*((_QWORD *)this + 15);
  if ( v22 )
    free(v22);
  v23 = (void *)*((_QWORD *)this + 12);
  if ( v23 )
    free(v23);
}
