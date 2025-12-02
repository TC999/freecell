void __fastcall CardTable::ClearHintAnimations(CardTable *this)
{
  unsigned int v2; // esi
  __int64 v3; // r12
  __int64 v4; // rbx
  __int64 v5; // rdx
  NodeBase *v6; // rcx
  __int64 v7; // rcx
  RenderManager *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  unsigned int v12; // r13d
  __int64 v13; // rbp

  *((_QWORD *)this + 22) = 0;
  *((_QWORD *)this + 23) = 0;
  *((_QWORD *)this + 24) = 0;
  v2 = 0;
  if ( *((_DWORD *)this + 54) )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(v3 + *((_QWORD *)this + 29));
      v5 = *(unsigned int *)(v4 + 248);
      if ( (_DWORD)v5 )
      {
        if ( *(_DWORD *)(v4 + 252) && *(_DWORD *)(v4 + 256) )
        {
          NodeBase::StopAnimation(*(NodeBase **)(v4 + 192), v5);
          NodeBase::StopAnimation(*(NodeBase **)(v4 + 200), *(unsigned int *)(v4 + 252));
          NodeBase::StopAnimation(*(NodeBase **)(v4 + 208), *(unsigned int *)(v4 + 256));
          v6 = *(NodeBase **)(v4 + 192);
        }
        else
        {
          NodeBase::StopAnimation(*(NodeBase **)(v4 + 216), v5);
          v6 = *(NodeBase **)(v4 + 216);
        }
        NodeBase::RemoveListener(v6, (struct IEventListener *)(v4 + 8));
        v7 = *(_QWORD *)(v4 + 192);
        v8 = g_pRenderManager;
        if ( *(_BYTE *)(v7 + 41) )
        {
          *(_BYTE *)(v7 + 41) = 0;
          *((_BYTE *)v8 + 20) = 1;
          *((_BYTE *)v8 + 88) = 1;
        }
        v9 = *(_QWORD *)(v4 + 200);
        if ( *(_BYTE *)(v9 + 41) )
        {
          *(_BYTE *)(v9 + 41) = 0;
          *((_BYTE *)v8 + 20) = 1;
          *((_BYTE *)v8 + 88) = 1;
        }
        v10 = *(_QWORD *)(v4 + 208);
        if ( *(_BYTE *)(v10 + 41) )
        {
          *(_BYTE *)(v10 + 41) = 0;
          *((_BYTE *)v8 + 20) = 1;
          *((_BYTE *)v8 + 88) = 1;
        }
        v11 = *(_QWORD *)(v4 + 216);
        if ( *(_BYTE *)(v11 + 41) )
        {
          *(_BYTE *)(v11 + 41) = 0;
          *((_BYTE *)v8 + 20) = 1;
          *((_BYTE *)v8 + 88) = 1;
        }
        *(_DWORD *)(v4 + 248) = 0;
        *(_DWORD *)(v4 + 252) = 0;
        *(_DWORD *)(v4 + 256) = 0;
        v12 = 0;
        if ( *(_DWORD *)(v4 + 304) )
        {
          v13 = 0;
          do
          {
            CardStack::RemoveHintedAccessName(
              (CardStack *)v4,
              *(struct NodeBase **)(*(_QWORD *)(*(_QWORD *)(v4 + 320) + v13) + 96LL));
            ++v12;
            v13 += 8;
          }
          while ( v12 < *(_DWORD *)(v4 + 304) );
        }
        CardStack::RemoveHintedAccessName((CardStack *)v4, *(struct NodeBase **)(v4 + 144));
      }
      ++v2;
      v3 += 8;
    }
    while ( v2 < *((_DWORD *)this + 54) );
  }
  *((_DWORD *)this + 54) = 0;
}
