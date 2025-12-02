char __fastcall Card::Init(
        Card *this,
        struct CardTable *a2,
        unsigned int a3,
        const unsigned __int16 *a4,
        struct NodeBase *a5,
        unsigned int a6)
{
  __int64 v6; // rbp
  struct NodeBase *v9; // rbx
  const unsigned __int16 *v11; // rdx
  const wchar_t **Xml; // rax
  struct NodeBase *v13; // rax
  __int64 v14; // rax
  RenderManager *v15; // rax
  struct NodeBase *v16; // rbx
  const wchar_t **v17; // rax
  struct NodeBase *v18; // rax
  __int64 v19; // rax
  RenderManager *v20; // rax
  __int64 v21; // r11
  struct NodeBase *v22; // rbx
  const unsigned __int16 *v23; // rdx
  const wchar_t **v24; // rax
  struct NodeBase *v25; // rax
  __int64 v26; // rcx
  bool v27; // zf
  int v28; // edx
  RenderManager *v29; // rax
  __int64 v30; // rax
  RenderManager *v31; // rax
  RenderManager *v32; // rcx

  v6 = a3;
  *((_QWORD *)this + 3) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = a6;
  v9 = NodeBase::CreateFromType(L"Base", a5, 1);
  *((_QWORD *)this + 8) = v9;
  if ( !v9 )
  {
    Log(0x10001u, L"Card::Init() - Failed to create the container.");
LABEL_3:
    Card::Cleanup(this);
    return 0;
  }
  v11 = L"CardHighlight_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v11 = L"CardHighlight.xml";
  Xml = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v11);
  v13 = NodeBase::CreateFromXmlNode(Xml, v9);
  *((_QWORD *)this + 9) = v13;
  if ( !v13 )
  {
    Log(0x10001u, L"Card::Init() - Failed to create the card highlight.");
    goto LABEL_3;
  }
  *((_DWORD *)v13 + 90) = 1;
  *(_BYTE *)(*((_QWORD *)this + 9) + 72LL) = 0;
  v14 = *((_QWORD *)this + 9);
  if ( *(_BYTE *)(v14 + 41) )
  {
    *(_BYTE *)(v14 + 41) = 0;
    v15 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v15 + 88) = 1;
  }
  NodeSprite::Pin(*((NodeSprite **)this + 9));
  v16 = (struct NodeBase *)*((_QWORD *)this + 8);
  v17 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"CardShadow.xml");
  v18 = NodeBase::CreateFromXmlNode(v17, v16);
  *((_QWORD *)this + 10) = v18;
  if ( !v18 )
  {
    Log(0x10001u, L"Card::Init() - Failed to create the card shadow.");
    goto LABEL_3;
  }
  *((_DWORD *)v18 + 90) = 1;
  *(_BYTE *)(*((_QWORD *)this + 10) + 72LL) = 0;
  v19 = *((_QWORD *)this + 10);
  if ( *(_BYTE *)(v19 + 41) )
  {
    *(_BYTE *)(v19 + 41) = 0;
    v20 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v20 + 88) = 1;
  }
  NodeSprite::Pin(*((NodeSprite **)this + 10));
  v21 = *((_QWORD *)this + 10);
  *((_DWORD *)this + 22) = *(_DWORD *)(v21 + 388);
  *((_DWORD *)this + 23) = *(_DWORD *)(v21 + 392);
  if ( a6 )
    swprintf_s(word_1000B2430, 0x80u, L"%s%u", (&Card::CARD_NAME)[v6], a6);
  else
    swprintf_s(word_1000B2430, 0x80u, (const wchar_t *const)(&Card::CARD_NAME)[v6]);
  if ( !Card::SetCardSprite(this, a4) )
  {
    Log(0x10001u, L"Card::Init() - Failed to create the card sprite.");
    goto LABEL_3;
  }
  Card::UpdateCardFace(this);
  *(_BYTE *)(*((_QWORD *)this + 13) + 72LL) = 0;
  NodeSprite::Pin(*((NodeSprite **)this + 13));
  v22 = (struct NodeBase *)*((_QWORD *)this + 8);
  v23 = L"CardButton_MCE.xml";
  if ( !(_BYTE)g_bMediaCenter )
    v23 = L"CardButton.xml";
  v24 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v23);
  v25 = NodeBase::CreateFromXmlNode(v24, v22);
  *((_QWORD *)this + 12) = v25;
  if ( !v25 )
  {
    Log(0x10001u, L"Card::Init() - Failed to create the card button.");
    goto LABEL_3;
  }
  *((_BYTE *)v25 + 75) = 1;
  *(_BYTE *)(*((_QWORD *)this + 12) + 74LL) = 1;
  *(_BYTE *)(*((_QWORD *)this + 12) + 73LL) = 1;
  v26 = *((_QWORD *)this + 12);
  if ( *(_BYTE *)(v26 + 499) )
  {
    v27 = *(_DWORD *)(v26 + 428) == 1;
    *(_BYTE *)(v26 + 499) = 0;
    if ( v27 )
    {
      v28 = *(_DWORD *)(*(_QWORD *)(v26 + 416) + 44LL) - 1;
      if ( v28 != *(_DWORD *)(v26 + 384) )
      {
        v29 = g_pRenderManager;
        *(_DWORD *)(v26 + 384) = v28;
        *((_BYTE *)v29 + 20) = 1;
        *((_BYTE *)v29 + 88) = 1;
      }
      NodeBase::CompleteAnimation((NodeBase *)v26, *(unsigned int *)(v26 + 488));
    }
  }
  *(_DWORD *)(*((_QWORD *)this + 12) + 360LL) = 1;
  v30 = *((_QWORD *)this + 12);
  *(_BYTE *)(v30 + 501) = 1;
  if ( *(_DWORD *)(v30 + 428) )
  {
    if ( *(_DWORD *)(v30 + 396) != 255 )
    {
      *(_DWORD *)(v30 + 396) = 255;
      v32 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v32 + 88) = 1;
    }
  }
  else if ( *(_DWORD *)(v30 + 396) )
  {
    *(_DWORD *)(v30 + 396) = 0;
    v31 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v31 + 88) = 1;
  }
  Card::RefreshAccessibility(this);
  Card::SetName(this, word_1000B2430);
  return 1;
}
