void __fastcall Card::SetShadow(Card *this, char a2, int a3, int a4)
{
  const wchar_t *v7; // r8
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rcx
  int v13; // edx
  int v14; // r8d
  RenderManager *v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rcx
  __int64 v18; // rax
  RenderManager *v19; // rax

  v7 = L"false";
  if ( a2 )
    v7 = L"true";
  Log(0x10000u, L"Card::SetShadow()::bShadow == %s", v7);
  v9 = *((_QWORD *)this + 12);
  --NodeBase::m_RenderLayerNodeCount[*(unsigned int *)(v9 + 60)];
  if ( a2 )
  {
    *(_DWORD *)(v9 + 60) = 5;
    ++dword_1000AE8E4;
    v10 = *((_QWORD *)this + 13);
    --NodeBase::m_RenderLayerNodeCount[*(unsigned int *)(v10 + 60)];
    *(_DWORD *)(v10 + 60) = 5;
    ++dword_1000AE8E4;
    v11 = *((_QWORD *)this + 10);
    --NodeBase::m_RenderLayerNodeCount[*(unsigned int *)(v11 + 60)];
    *(_DWORD *)(v11 + 60) = 4;
    ++dword_1000AE8E0;
    v12 = *((_QWORD *)this + 10);
    v13 = a4 + *((_DWORD *)this + 23);
    v14 = a3 + *((_DWORD *)this + 22);
    v15 = g_pRenderManager;
    if ( v14 != *(_DWORD *)(v12 + 388) || v13 != *(_DWORD *)(v12 + 392) )
    {
      *(_DWORD *)(v12 + 388) = v14;
      *(_DWORD *)(v12 + 392) = v13;
      *((_BYTE *)v15 + 20) = 1;
      *((_BYTE *)v15 + 88) = 1;
    }
    v16 = *((_QWORD *)this + 10);
    if ( *(_BYTE *)(v16 + 41) != 1 )
    {
      *(_BYTE *)(v16 + 41) = 1;
      *((_BYTE *)v15 + 20) = 1;
      *((_BYTE *)v15 + 88) = 1;
    }
    NodeBase::MoveToBack(*((NodeBase **)this + 10));
  }
  else
  {
    *(_DWORD *)(v9 + 60) = 3;
    ++dword_1000AE8DC;
    v17 = *((_QWORD *)this + 13);
    --NodeBase::m_RenderLayerNodeCount[*(unsigned int *)(v17 + 60)];
    *(_DWORD *)(v17 + 60) = 3;
    ++dword_1000AE8DC;
    v18 = *((_QWORD *)this + 10);
    if ( *(_BYTE *)(v18 + 41) )
    {
      *(_BYTE *)(v18 + 41) = 0;
      v19 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v19 + 88) = 1;
    }
  }
}
