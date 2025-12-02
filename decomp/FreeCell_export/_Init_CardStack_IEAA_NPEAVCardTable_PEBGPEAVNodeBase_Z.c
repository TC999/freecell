char __fastcall CardStack::Init(CardStack *this, struct CardTable *a2, const unsigned __int16 *a3, struct NodeBase *a4)
{
  const unsigned __int16 *v7; // rdx
  const wchar_t **Xml; // rax
  struct NodeBase *v9; // rax
  __int64 v11; // rax
  RenderManager *v12; // rax
  const unsigned __int16 *v13; // rdx
  const wchar_t **v14; // rax
  struct NodeBase *v15; // rax
  __int64 v16; // rax
  RenderManager *v17; // rax
  const unsigned __int16 *v18; // rdx
  const wchar_t **v19; // rax
  struct NodeBase *v20; // rax
  __int64 v21; // rax
  RenderManager *v22; // rax
  const unsigned __int16 *v23; // rdx
  const wchar_t **v24; // rax
  struct NodeBase *v25; // rax
  __int64 v26; // rax
  RenderManager *v27; // rax
  const wchar_t **v28; // rax
  struct NodeBase *v29; // rax
  __int64 v30; // rax
  RenderManager *v31; // rax
  const wchar_t **v32; // rax
  struct NodeBase *v33; // rax
  __int64 v34; // rax
  RenderManager *v35; // rax
  const wchar_t **v36; // rax
  struct NodeBase *v37; // rax
  __int64 v38; // rax
  RenderManager *v39; // rax
  const wchar_t **v40; // rax
  struct NodeBase *v41; // rax
  __int64 v42; // rax
  RenderManager *v43; // rax
  struct NodeBase *v44; // rax
  RenderManager *v45; // rcx
  __int64 v46; // rax
  __int64 v47; // rax
  struct NodeBase *v48; // rax
  RenderManager *v49; // rcx
  __int64 v50; // rax
  __int64 v51; // rdx
  UserInterface *v52; // rcx

  *((_QWORD *)this + 37) = a2;
  v7 = L"CardButtonStack_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v7 = L"CardButtonStack.xml";
  Xml = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v7);
  v9 = NodeBase::CreateFromXmlNode(Xml, a4);
  *((_QWORD *)this + 18) = v9;
  if ( !v9 )
  {
    Log(0x10001u, L"CardStack::Init() - Failed to create the container button.");
    CardStack::Cleanup(this);
    return 0;
  }
  *((_DWORD *)v9 + 90) = 1;
  v11 = *((_QWORD *)this + 18);
  *(_BYTE *)(v11 + 501) = 1;
  if ( *(_DWORD *)(v11 + 428) )
  {
    if ( *(_DWORD *)(v11 + 396) != 255 )
    {
      *(_DWORD *)(v11 + 396) = 255;
      goto LABEL_10;
    }
  }
  else if ( *(_DWORD *)(v11 + 396) )
  {
    *(_DWORD *)(v11 + 396) = 0;
LABEL_10:
    v12 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 88) = 1;
    *((_BYTE *)v12 + 20) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 18) + 75LL) = 1;
  *(_BYTE *)(*((_QWORD *)this + 18) + 73LL) = 1;
  *(_BYTE *)(*((_QWORD *)this + 18) + 74LL) = 1;
  NodeBase::SetAccessDefaultAction(*((HLOCAL **)this + 18), L"|42287|DefaultStackAction|Click");
  Array<IEventListener *>::Add(*((_QWORD *)this + 18) + 200LL, (__int64)this + 8);
  v13 = L"StackHighlightTopSprite_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v13 = L"StackHighlightTopSprite.xml";
  v14 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v13);
  v15 = NodeBase::CreateFromXmlNode(v14, a4);
  *((_QWORD *)this + 21) = v15;
  *((_DWORD *)v15 + 90) = 1;
  v16 = *((_QWORD *)this + 21);
  if ( *(_BYTE *)(v16 + 41) )
  {
    *(_BYTE *)(v16 + 41) = 0;
    v17 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v17 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 21) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 21));
  v18 = L"StackHighlightMiddleSprite_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v18 = L"StackHighlightMiddleSprite.xml";
  v19 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v18);
  v20 = NodeBase::CreateFromXmlNode(v19, a4);
  *((_QWORD *)this + 22) = v20;
  *((_DWORD *)v20 + 90) = 1;
  v21 = *((_QWORD *)this + 22);
  if ( *(_BYTE *)(v21 + 41) )
  {
    *(_BYTE *)(v21 + 41) = 0;
    v22 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v22 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 22) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 22));
  v23 = L"StackHighlightBottomSprite_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v23 = L"StackHighlightBottomSprite.xml";
  v24 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v23);
  v25 = NodeBase::CreateFromXmlNode(v24, a4);
  *((_QWORD *)this + 23) = v25;
  *((_DWORD *)v25 + 90) = 1;
  v26 = *((_QWORD *)this + 23);
  if ( *(_BYTE *)(v26 + 41) )
  {
    *(_BYTE *)(v26 + 41) = 0;
    v27 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v27 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 23) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 23));
  v28 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"StackHintTopSprite.xml");
  v29 = NodeBase::CreateFromXmlNode(v28, a4);
  *((_QWORD *)this + 24) = v29;
  *((_DWORD *)v29 + 90) = 1;
  v30 = *((_QWORD *)this + 24);
  if ( *(_BYTE *)(v30 + 41) )
  {
    *(_BYTE *)(v30 + 41) = 0;
    v31 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v31 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 24) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 24));
  v32 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"StackHintMiddleSprite.xml");
  v33 = NodeBase::CreateFromXmlNode(v32, a4);
  *((_QWORD *)this + 25) = v33;
  *((_DWORD *)v33 + 90) = 1;
  v34 = *((_QWORD *)this + 25);
  if ( *(_BYTE *)(v34 + 41) )
  {
    *(_BYTE *)(v34 + 41) = 0;
    v35 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v35 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 25) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 25));
  v36 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"StackHintBottomSprite.xml");
  v37 = NodeBase::CreateFromXmlNode(v36, a4);
  *((_QWORD *)this + 26) = v37;
  *((_DWORD *)v37 + 90) = 1;
  v38 = *((_QWORD *)this + 26);
  if ( *(_BYTE *)(v38 + 41) )
  {
    *(_BYTE *)(v38 + 41) = 0;
    v39 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v39 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 26) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 26));
  v40 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"CardHintStackSprite.xml");
  v41 = NodeBase::CreateFromXmlNode(v40, a4);
  *((_QWORD *)this + 27) = v41;
  *((_DWORD *)v41 + 90) = 1;
  v42 = *((_QWORD *)this + 27);
  if ( *(_BYTE *)(v42 + 41) )
  {
    *(_BYTE *)(v42 + 41) = 0;
    v43 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v43 + 88) = 1;
  }
  *(_BYTE *)(*((_QWORD *)this + 27) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 27));
  v44 = NodeBase::CreateFromType(L"Label", a4, 1);
  v45 = g_pRenderManager;
  *((_QWORD *)this + 20) = v44;
  if ( *((_BYTE *)v44 + 41) )
  {
    *((_BYTE *)v44 + 41) = 0;
    *((_BYTE *)v45 + 20) = 1;
    *((_BYTE *)v45 + 88) = 1;
  }
  v46 = *((_QWORD *)this + 20);
  if ( *(_DWORD *)(v46 + 404) != -16777216 )
  {
    *(_DWORD *)(v46 + 404) = -16777216;
    *((_BYTE *)v45 + 20) = 1;
    *((_BYTE *)v45 + 88) = 1;
  }
  v47 = *((_QWORD *)this + 20);
  if ( *(_DWORD *)(v47 + 396) != 64 )
  {
    *(_DWORD *)(v47 + 396) = 64;
    *((_BYTE *)v45 + 20) = 1;
    *((_BYTE *)v45 + 88) = 1;
  }
  NodeBase::SetSize(*((NodeBase **)this + 20), 200, *(_DWORD *)(*((_QWORD *)this + 20) + 20LL));
  NodeBase::SetSize(*((NodeBase **)this + 20), *(_DWORD *)(*((_QWORD *)this + 20) + 16LL), 200);
  *(_BYTE *)(*((_QWORD *)this + 20) + 72LL) = 0;
  v48 = NodeBase::CreateFromType(L"Label", a4, 1);
  v49 = g_pRenderManager;
  *((_QWORD *)this + 19) = v48;
  if ( *((_BYTE *)v48 + 41) )
  {
    *((_BYTE *)v48 + 41) = 0;
    *((_BYTE *)v49 + 20) = 1;
    *((_BYTE *)v49 + 88) = 1;
  }
  v50 = *((_QWORD *)this + 19);
  if ( *(_DWORD *)(v50 + 404) != -1 )
  {
    *(_DWORD *)(v50 + 404) = -1;
    *((_BYTE *)v49 + 20) = 1;
    *((_BYTE *)v49 + 88) = 1;
  }
  NodeBase::SetSize(*((NodeBase **)this + 19), 200, *(_DWORD *)(*((_QWORD *)this + 19) + 20LL));
  NodeBase::SetSize(*((NodeBase **)this + 19), *(_DWORD *)(*((_QWORD *)this + 19) + 16LL), 200);
  *(_BYTE *)(*((_QWORD *)this + 19) + 72LL) = 0;
  v51 = *((_QWORD *)this + 19);
  if ( *(_BYTE *)(v51 + 144) )
  {
    v52 = g_pUserInterface;
    *(_BYTE *)(v51 + 144) = 0;
    *(_DWORD *)(v51 + 192) = 41;
    UserInterface::Access_ClipNode(v52, (struct NodeBase *)v51);
  }
  Log(0x10000u, L"CardStack::SetName()::wszName == %s", a3);
  Str::operator=((__int64)this + 272, a3);
  NodeBase::SetName(*((void ***)this + 18), a3);
  return 1;
}
