void __fastcall CardStack::StartHintAnimation(CardStack *this, unsigned int a2, HLOCAL **a3)
{
  __int64 v6; // rcx
  RenderManager *v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  RenderManager *v12; // rax
  __int64 v13; // rcx
  __int64 v14; // rcx
  int v15; // eax
  NodeBase *v16; // rcx
  int v17; // eax
  NodeBase *v18; // rcx
  int v19; // eax
  __int64 v20; // rdx
  NodeBase *v21; // rcx
  HLOCAL *v22; // rdx
  __int64 v23; // rcx
  unsigned int v24; // eax
  NodeBase *v25; // rcx

  Log(0x10000u, L"CardStack::StartHintAnimation()");
  if ( *((_QWORD *)this + 29) )
    *((_QWORD *)this + 29) = 0;
  v6 = *((_QWORD *)this + 24);
  v7 = g_pRenderManager;
  if ( *(_BYTE *)(v6 + 41) )
  {
    *(_BYTE *)(v6 + 41) = 0;
    *((_BYTE *)v7 + 20) = 1;
    *((_BYTE *)v7 + 88) = 1;
  }
  v8 = *((_QWORD *)this + 25);
  if ( *(_BYTE *)(v8 + 41) )
  {
    *(_BYTE *)(v8 + 41) = 0;
    *((_BYTE *)v7 + 20) = 1;
    *((_BYTE *)v7 + 88) = 1;
  }
  v9 = *((_QWORD *)this + 26);
  if ( *(_BYTE *)(v9 + 41) )
  {
    *(_BYTE *)(v9 + 41) = 0;
    *((_BYTE *)v7 + 20) = 1;
    *((_BYTE *)v7 + 88) = 1;
  }
  v10 = *((_QWORD *)this + 27);
  if ( *(_BYTE *)(v10 + 41) )
  {
    *(_BYTE *)(v10 + 41) = 0;
    *((_BYTE *)v7 + 20) = 1;
    *((_BYTE *)v7 + 88) = 1;
  }
  if ( *((_DWORD *)this + 76) )
  {
    if ( !a3 )
      a3 = (HLOCAL **)**((_QWORD **)this + 40);
    if ( (unsigned int)CardStack::GetCardLocation(this, (struct Card *)a3) != -1 )
    {
      v11 = *((_QWORD *)this + 24);
      v12 = g_pRenderManager;
      *((_QWORD *)this + 29) = a3;
      if ( *(_BYTE *)(v11 + 41) != 1 )
      {
        *(_BYTE *)(v11 + 41) = 1;
        *((_BYTE *)v12 + 20) = 1;
        *((_BYTE *)v12 + 88) = 1;
      }
      v13 = *((_QWORD *)this + 25);
      if ( *(_BYTE *)(v13 + 41) != 1 )
      {
        *(_BYTE *)(v13 + 41) = 1;
        *((_BYTE *)v12 + 20) = 1;
        *((_BYTE *)v12 + 88) = 1;
      }
      v14 = *((_QWORD *)this + 26);
      if ( *(_BYTE *)(v14 + 41) != 1 )
      {
        *(_BYTE *)(v14 + 41) = 1;
        *((_BYTE *)v12 + 20) = 1;
        *((_BYTE *)v12 + 88) = 1;
      }
      CardStack::ArrangeHint((NodeBase **)this);
    }
    v15 = NodeBase::AddAnimation(*((NodeBase **)this + 24), a2);
    v16 = (NodeBase *)*((_QWORD *)this + 25);
    *((_DWORD *)this + 62) = v15;
    v17 = NodeBase::AddAnimation(v16, a2);
    v18 = (NodeBase *)*((_QWORD *)this + 26);
    *((_DWORD *)this + 63) = v17;
    v19 = NodeBase::AddAnimation(v18, a2);
    v20 = *((unsigned int *)this + 62);
    v21 = (NodeBase *)*((_QWORD *)this + 24);
    *((_DWORD *)this + 64) = v19;
    NodeBase::ResumeAnimation(v21, v20);
    NodeBase::ResumeAnimation(*((NodeBase **)this + 25), *((unsigned int *)this + 63));
    NodeBase::ResumeAnimation(*((NodeBase **)this + 26), *((unsigned int *)this + 64));
    Array<IEventListener *>::Add(*((_QWORD *)this + 24) + 200LL, (__int64)this + 8);
    v22 = a3[12];
  }
  else
  {
    v23 = *((_QWORD *)this + 27);
    *((_QWORD *)this + 29) = 0;
    if ( *(_BYTE *)(v23 + 41) != 1 )
    {
      *(_BYTE *)(v23 + 41) = 1;
      *((_BYTE *)v7 + 20) = 1;
      *((_BYTE *)v7 + 88) = 1;
    }
    CardStack::ArrangeHint((NodeBase **)this);
    v24 = NodeBase::AddAnimation(*((NodeBase **)this + 27), a2);
    v25 = (NodeBase *)*((_QWORD *)this + 27);
    *((_DWORD *)this + 62) = v24;
    NodeBase::ResumeAnimation(v25, v24);
    v22 = (HLOCAL *)*((_QWORD *)this + 18);
  }
  CardStack::SetAccessNameHinted(this, v22);
}
