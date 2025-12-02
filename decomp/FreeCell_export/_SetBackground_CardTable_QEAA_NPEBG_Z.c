// Hidden C++ exception states: #wind=2
char __fastcall CardTable::SetBackground(CardTable *this, const unsigned __int16 *a2)
{
  char v4; // di
  unsigned int v5; // ebx
  __int64 i; // rbp
  __int64 v7; // rax
  XmlNode *v8; // r12
  const unsigned __int16 *v9; // rax
  int v10; // r8d
  int v11; // edx
  NodeBase *v13; // r13
  __int64 v14; // rax
  unsigned int v15; // ebx
  __int64 v16; // rbp
  __int64 v17; // rcx
  __int64 v18; // rdx
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  _DWORD *v21; // rax
  NodeSprite *v22; // rcx
  NodeBase *v23; // rcx
  wchar_t *v24; // rbp
  wchar_t *v25; // rbx
  unsigned int v26; // r14d
  unsigned __int16 *v27; // r12
  unsigned __int16 *v28; // rbp
  __int64 v29; // r13
  __int64 v30; // r15
  int v31; // eax
  bool v32; // bl
  struct NodeBase *v33; // rbx
  const wchar_t **Xml; // rax
  struct NodeBase *v35; // rax
  int *v36; // rbx
  bool v37; // bl
  struct NodeBase *v38; // rbx
  const wchar_t **v39; // rax
  void *Block; // [rsp+20h] [rbp-1A8h] BYREF
  _BYTE v41[16]; // [rsp+28h] [rbp-1A0h] BYREF
  void *v42; // [rsp+38h] [rbp-190h]
  _BYTE v43[16]; // [rsp+40h] [rbp-188h] BYREF
  unsigned __int16 *v44; // [rsp+50h] [rbp-178h]
  _BYTE v45[16]; // [rsp+58h] [rbp-170h] BYREF
  unsigned __int16 *v46; // [rsp+68h] [rbp-160h]
  __int64 v47; // [rsp+70h] [rbp-158h]
  unsigned __int16 v48[128]; // [rsp+80h] [rbp-148h] BYREF

  v47 = -2;
  v4 = 0;
  v5 = 0;
  if ( !*(_DWORD *)(*((_QWORD *)this + 42) + 24LL) )
    return 0;
  for ( i = 0; ; i += 8 )
  {
    v7 = *((_QWORD *)this + 42);
    if ( v5 < *(_DWORD *)(v7 + 24) )
      v8 = *(XmlNode **)(*(_QWORD *)(v7 + 40) + i);
    else
      v8 = 0;
    if ( !XmlNode::MatchName(v8, L"Background") )
      goto LABEL_14;
    Block = XmlNode::XPathAttributeSearchSingle(v8, L"/@Name");
    if ( !Block )
      goto LABEL_14;
    LocalizeDeckOrBackgroundName((const unsigned __int16 **)&Block, 0);
    if ( !Block )
      goto LABEL_14;
    v9 = a2;
    do
    {
      v10 = *(const unsigned __int16 *)((char *)v9 + (_BYTE *)Block - (_BYTE *)a2);
      v11 = *v9 - v10;
      if ( v11 )
        break;
      ++v9;
    }
    while ( v10 );
    if ( !v11 )
      break;
    operator delete(Block);
LABEL_14:
    if ( ++v5 >= *(_DWORD *)(*((_QWORD *)this + 42) + 24LL) )
      return 0;
  }
  operator delete(Block);
  if ( !XmlNode::GetNodeValue(v8, v48, 0x80u) )
  {
    Log(0x10001u, L"CardTable::SetBackground() - Unable to get the filename.");
    return 0;
  }
  v13 = NodeBase::CreateFromType(L"Base", *((struct NodeBase **)this + 12), 1);
  if ( !v13 )
  {
    Log(0x10001u, L"CardTable::SetBackground() - Unable to load the background sprite.");
    return 0;
  }
  v14 = *((_QWORD *)this + 13);
  if ( v14 )
  {
    v15 = 0;
    if ( *(_DWORD *)(v14 + 80) )
    {
      v16 = 0;
      do
      {
        v17 = *((_QWORD *)this + 13);
        if ( v15 >= *(_DWORD *)(v17 + 80) )
          v18 = 0;
        else
          v18 = *(_QWORD *)(*(_QWORD *)(v17 + 96) + v16);
        v19 = 0;
        v20 = *(_DWORD *)(v18 + 104);
        if ( v20 )
        {
          v21 = *(_DWORD **)(v18 + 120);
          while ( *v21 != 1 )
          {
            ++v19;
            ++v21;
            if ( v19 >= v20 )
              goto LABEL_35;
          }
          if ( v15 >= *(_DWORD *)(v17 + 80) )
            v22 = 0;
          else
            v22 = *(NodeSprite **)(*(_QWORD *)(v17 + 96) + v16);
          NodeSprite::Unpin(v22);
        }
LABEL_35:
        ++v15;
        v16 += 8;
      }
      while ( v15 < *(_DWORD *)(*((_QWORD *)this + 13) + 80LL) );
    }
    v23 = (NodeBase *)*((_QWORD *)this + 13);
    if ( v23 )
    {
      NodeBase::DeleteSelf(v23);
      *((_QWORD *)this + 13) = 0;
    }
  }
  *((_QWORD *)this + 13) = v13;
  NodeBase::SetSize(v13, 800, 496);
  Str::operator=((__int64)this + 264, a2);
  *(_BYTE *)(*((_QWORD *)this + 13) + 72LL) = 1;
  if ( g_CurrentBackStyle == 1 )
  {
    RenderManager::SetBack(g_pRenderManager, v48);
  }
  else
  {
    g_CurrentBackStyle = 1;
    RenderManager::SetBack(g_pRenderManager, v48);
    CenterRenderWindow();
    SetDPIFromWindowSize();
  }
  v24 = XmlNode::XPathAttributeSearchSingle(v8, L"/@OpenPlacement");
  v25 = XmlNode::XPathAttributeSearchSingle(v8, L"/@ClosedPlacement");
  Str::Str((Str *)v43, &dword_1000028D4);
  Str::Str((Str *)v45, &dword_1000028D4);
  if ( v24 )
  {
    Str::operator=((__int64)v43, v24);
    operator delete(v24);
  }
  if ( v25 )
  {
    Str::operator=((__int64)v45, v25);
    operator delete(v25);
  }
  NodeBase::MoveToBack(*((NodeBase **)this + 13));
  Array<IEventListener *>::Add(*((_QWORD *)this + 13) + 200LL, *((_QWORD *)this + 14));
  v26 = 0;
  v27 = v44;
  v28 = v46;
  if ( *((_DWORD *)this + 40) )
  {
    v29 = 0;
    do
    {
      v30 = *(_QWORD *)(v29 + *((_QWORD *)this + 19));
      v31 = *(_DWORD *)(v30 + 260);
      if ( v31 == 1 )
      {
        Str::Str((Str *)v41, &dword_1000028D4);
        if ( v27 )
          v32 = Str::Equals((Str *)v43, (const struct Str *)v41);
        else
          v32 = 0;
        operator delete(v42);
        if ( !v32 )
        {
          v33 = (struct NodeBase *)*((_QWORD *)this + 13);
          Xml = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v27);
          v35 = NodeBase::CreateFromXmlNode(Xml, v33);
          v36 = (int *)v35;
          if ( !v35 )
          {
            operator delete(v28);
            operator delete(v27);
            return 0;
          }
LABEL_62:
          NodeSprite::Pin(v35);
          NodeBase::SetPosition((NodeBase *)v36, *(_DWORD *)(*(_QWORD *)(v30 + 144) + 8LL), v36[3]);
          NodeBase::SetPosition((NodeBase *)v36, v36[2], *(_DWORD *)(*(_QWORD *)(v30 + 144) + 12LL));
          goto LABEL_63;
        }
        Log(0x10001u, L"CardTable::SetBackground() - No open placement cardstack image defined.");
      }
      else if ( v31 == 2 )
      {
        Str::Str((Str *)v41, &dword_1000028D4);
        if ( v28 )
          v37 = Str::Equals((Str *)v45, (const struct Str *)v41);
        else
          v37 = 0;
        operator delete(v42);
        if ( !v37 )
        {
          v38 = (struct NodeBase *)*((_QWORD *)this + 13);
          v39 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v28);
          v35 = NodeBase::CreateFromXmlNode(v39, v38);
          v36 = (int *)v35;
          if ( !v35 )
          {
            operator delete(v28);
            goto LABEL_68;
          }
          goto LABEL_62;
        }
        Log(0x10001u, L"CardTable::SetBackground() - No closed placement cardstack image defined.");
      }
LABEL_63:
      ++v26;
      v29 += 8;
    }
    while ( v26 < *((_DWORD *)this + 40) );
  }
  operator delete(v28);
  v4 = 1;
LABEL_68:
  operator delete(v27);
  return v4;
}
