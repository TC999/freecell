// Hidden C++ exception states: #wind=6
bool __fastcall CardTable::Init(CardTable *this, struct IEventListener *a2, const wchar_t **a3, struct NodeBase *a4)
{
  struct NodeBase *v8; // rax
  unsigned int v9; // ebx
  _DWORD *v11; // rax
  struct XmlNode *Xml; // rax
  struct XmlNode *v13; // rax
  const unsigned __int16 *v14; // r9
  wchar_t *v15; // r15
  UserInterface *v16; // rax
  const struct XmlNode **v17; // rax
  XmlNode **v18; // rsi
  unsigned int v19; // r12d
  XmlNode **v20; // rdi
  unsigned __int16 *v21; // rsi
  _DWORD *v22; // r13
  const struct XmlNode **v23; // rax
  void *v24; // rdi
  XmlNode *v25; // rdi
  const unsigned __int16 *v26; // rax
  unsigned __int16 *v27; // rsi
  struct CardStack *CardStack; // r12
  int XmlInt; // eax
  int v30; // eax
  Str *v31; // rax
  bool v32; // di
  bool v33; // zf
  bool v34; // di
  unsigned __int16 *v35; // rsi
  const wchar_t *v36; // rdi
  __int64 v37; // rcx
  unsigned __int16 *v38; // rsi
  const wchar_t *v39; // rdi
  __int64 v40; // rcx
  unsigned __int16 *v41; // rsi
  const wchar_t *v42; // rdi
  __int64 v43; // rcx
  unsigned __int16 *v44; // rsi
  const wchar_t *v45; // rdi
  __int64 v46; // rcx
  unsigned __int16 *v47; // rsi
  const wchar_t *v48; // rdi
  __int64 v49; // rcx
  XmlNode *v50; // rdi
  XmlNode *v51; // rax
  XmlNode *v52; // rsi
  int v53; // edi
  int v54; // edx
  int v55; // edx
  int v56; // r8d
  int v57; // r8d
  int v58; // eax
  __int64 v59; // rdx
  RenderManager *v60; // rcx
  __int64 v61; // rdx
  unsigned int v62; // edi
  unsigned __int16 *v63; // rsi
  int v64; // edx
  __int64 v65; // rcx
  RenderManager *v66; // rax
  __int64 v67; // rcx
  Str *v68; // rax
  _QWORD *XmlStr; // rax
  int v70; // eax
  Str *v71; // rax
  _QWORD *v72; // rax
  Str *v73; // rax
  _QWORD *v74; // rax
  char *v75; // r13
  XmlNode **v76; // r12
  wchar_t *v77; // rdi
  __int64 v78; // rsi
  XmlNode *v79; // rax
  unsigned __int16 *NodeValue; // rdi
  const wchar_t *v81; // rax
  XmlNode *v82; // rax
  unsigned __int16 *v83; // rdi
  const wchar_t *v84; // rax
  XmlNode *v85; // rax
  unsigned __int16 *v86; // rdi
  const wchar_t *v87; // rax
  XmlNode *v88; // rax
  unsigned __int16 *v89; // rdi
  const wchar_t *v90; // rax
  const struct XmlNode **v91; // rax
  XmlNode **v92; // r15
  unsigned int i; // r13d
  wchar_t *v94; // rdi
  struct NodeBase *v95; // rax
  XmlNode *v96; // rax
  unsigned __int16 *v97; // rdi
  XmlNode *v98; // rax
  unsigned __int16 *v99; // rdi
  __int64 v100; // rdx
  unsigned int v101; // eax
  XmlNode *v102; // rax
  unsigned __int16 *v103; // rdi
  RenderManager *v104; // rcx
  __int64 v105; // rdi
  int v106; // [rsp+20h] [rbp-548h]
  int v107; // [rsp+28h] [rbp-540h]
  int v108; // [rsp+30h] [rbp-538h]
  const struct XmlNode **v109; // [rsp+40h] [rbp-528h] BYREF
  unsigned int v110; // [rsp+48h] [rbp-520h] BYREF
  void *v111; // [rsp+50h] [rbp-518h] BYREF
  unsigned int v112; // [rsp+58h] [rbp-510h] BYREF
  unsigned int v113; // [rsp+5Ch] [rbp-50Ch]
  unsigned int v114; // [rsp+60h] [rbp-508h]
  void *v115; // [rsp+68h] [rbp-500h]
  int v116; // [rsp+70h] [rbp-4F8h] BYREF
  void *v117[2]; // [rsp+78h] [rbp-4F0h] BYREF
  void *Block; // [rsp+88h] [rbp-4E0h]
  int v119[4]; // [rsp+90h] [rbp-4D8h] BYREF
  wchar_t *Source; // [rsp+A0h] [rbp-4C8h]
  const struct XmlNode **v121; // [rsp+A8h] [rbp-4C0h]
  XmlNode *v122; // [rsp+B0h] [rbp-4B8h]
  void *v123[2]; // [rsp+B8h] [rbp-4B0h] BYREF
  void *v124; // [rsp+C8h] [rbp-4A0h]
  int v125[4]; // [rsp+D0h] [rbp-498h] BYREF
  wchar_t *v126; // [rsp+E0h] [rbp-488h]
  __int64 v127; // [rsp+E8h] [rbp-480h]
  _BYTE v128[24]; // [rsp+F0h] [rbp-478h] BYREF
  char v129[24]; // [rsp+108h] [rbp-460h] BYREF
  unsigned __int16 v130[128]; // [rsp+120h] [rbp-448h] BYREF
  unsigned __int16 v131[128]; // [rsp+220h] [rbp-348h] BYREF
  unsigned __int16 v132[128]; // [rsp+320h] [rbp-248h] BYREF
  unsigned __int16 v133[128]; // [rsp+420h] [rbp-148h] BYREF

  v127 = -2;
  Array<IEventListener *>::Add((__int64)g_pUserInterface + 120, (__int64)this);
  *((_QWORD *)this + 14) = a2;
  v8 = NodeBase::CreateFromType(L"Base", a4, 1);
  *((_QWORD *)this + 12) = v8;
  v9 = 0;
  if ( v8 )
  {
    v11 = operator new(0x58u);
    if ( v11 )
    {
      v11[10] = 0;
      v11[11] = 0;
      v11[12] = 16;
      *((_QWORD *)v11 + 7) = 0;
      v11[16] = 0;
      v11[17] = 0;
      v11[18] = 16;
      *((_QWORD *)v11 + 10) = 0;
      *(_BYTE *)v11 = 1;
      *((_BYTE *)v11 + 1) = 1;
      *((_QWORD *)v11 + 3) = 0;
      *((_QWORD *)v11 + 4) = this;
    }
    else
    {
      v11 = 0;
    }
    *((_QWORD *)this + 11) = v11;
    memcpy(v132, L"Backgrounds\\BackgroundList.xml", 0x3Eu);
    memset(&v132[31], 0, 0xC2u);
    if ( !XmlNode::GetXmlString((XmlNode *)a3, v132, 0x80u, L"/BackgroundList") )
      Log(0x10000u, L"CardTable::Init() - No background list specified, defaulting to Backgrounds\\BackgroundList.xml");
    Xml = XmlManager::GetXml(g_pXmlManager, v132);
    *((_QWORD *)this + 42) = Xml;
    if ( Xml )
    {
      v13 = XmlManager::GetXml(g_pXmlManager, L"Decks\\DeckList.xml");
      *((_QWORD *)this + 43) = v13;
      if ( v13 )
      {
        if ( a3 )
        {
          v14 = L"/DefaultDeck";
          if ( (_BYTE)g_bMediaCenter )
            v14 = L"/DefaultDeckMCE";
          if ( XmlNode::GetXmlString((XmlNode *)a3, v131, 0x80u, v14) )
          {
            v111 = v131;
            LocalizeDeckOrBackgroundName((const unsigned __int16 **)&v111, 0x80u);
            if ( CardTable::SetCardDeck(this, v131) )
            {
              Str::Str((Str *)v119, L"Animations\\PulseAlphaAnimation.xml");
              *((_DWORD *)this + 42) = ResourceAnimation::Create(Source, (unsigned int)(v119[0] + 1));
              Str::Str((Str *)v125, L"Animations\\DelayedPulseAlphaAnimation.xml");
              v15 = v126;
              *((_DWORD *)this + 43) = ResourceAnimation::Create(v126, (unsigned int)(v125[0] + 1));
              *((_DWORD *)this + 13) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultSelectedVerticalOffset", 30);
              *((_DWORD *)this + 14) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultVerticalSpacingFaceUp", 14);
              *((_DWORD *)this + 15) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultVerticalSpacingFaceDown", 7);
              *((_DWORD *)this + 16) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultHorizontalSpacingFaceUp", 12);
              *((_DWORD *)this + 17) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultHorizontalSpacingFaceDown", 6);
              *((_DWORD *)this + 18) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultUpSpacing", 2);
              *((_DWORD *)this + 19) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultSpacingCount", 1);
              *((_DWORD *)this + 20) = XmlNode::GetXmlInt((XmlNode *)a3, L"/DefaultEndSpacing", 15);
              v16 = g_pUserInterface;
              *((_DWORD *)g_pUserInterface + 22) = 16;
              *((_DWORD *)v16 + 23) = 16;
              v112 = 0;
              v17 = XmlNode::XPathElementSearch((XmlNode *)a3, L"/StackGroup", &v112);
              v18 = v17;
              v115 = v17;
              v19 = 0;
              v114 = 0;
              if ( v112 )
              {
                v20 = v17;
                v109 = v17;
                while ( 1 )
                {
                  v21 = XmlNode::XPathAttributeSearchSingle(*v20, L"/@Name");
                  if ( !v21 )
                  {
                    operator delete(v115);
                    CardTable::Cleanup(this);
                    operator delete(v15);
                    operator delete(Source);
                    return 0;
                  }
                  v22 = operator new(0x60u);
                  if ( v22 )
                  {
                    *(_QWORD *)v22 = &StackGroup::`vftable';
                    v22[8] = 0;
                    v22[9] = 0;
                    v22[10] = 16;
                    *((_QWORD *)v22 + 6) = 0;
                  }
                  else
                  {
                    v22 = 0;
                  }
                  *((_QWORD *)v22 + 1) = 0;
                  SortedListW<CardStack *>::Add((char *)this + 352, v21, v22);
                  operator delete(v21);
                  v22[19] = XmlNode::GetXmlUInt(*v20, L"/GroupWidth", -1);
                  v22[20] = XmlNode::GetXmlUInt(*v20, L"/GroupHeight", -1);
                  v22[21] = XmlNode::GetXmlInt(*v20, L"/GroupX", -1);
                  v22[22] = XmlNode::GetXmlInt(*v20, L"/GroupY", -1);
                  v110 = 0;
                  v23 = XmlNode::XPathElementSearch(*v20, L"/CardStack", &v110);
                  v24 = v23;
                  v111 = v23;
                  v113 = 0;
                  if ( v110 )
                    break;
LABEL_89:
                  operator delete(v24);
                  v114 = ++v19;
                  v20 = ++v109;
                  if ( v19 >= v112 )
                  {
                    v18 = (XmlNode **)v115;
                    goto LABEL_99;
                  }
                }
                v121 = v23;
                while ( 1 )
                {
                  v25 = *v23;
                  v122 = v25;
                  v26 = XmlNode::XPathAttributeSearchSingle(v25, L"/@Name");
                  v27 = (unsigned __int16 *)v26;
                  if ( !v26 )
                    break;
                  CardStack = CardTable::CreateCardStack(this, v26);
                  if ( !CardStack )
                  {
                    Log(0x10001u, L"CardTable::Init() - Failed to create the stack.");
                    operator delete(v27);
                    CardTable::Cleanup(this);
                    operator delete(v115);
                    operator delete(v111);
                    operator delete(v15);
                    operator delete(Source);
                    return 0;
                  }
                  operator delete(v27);
                  *((_QWORD *)CardStack + 8) = v22;
                  Array<IEventListener *>::Add((__int64)(v22 + 8), (__int64)CardStack);
                  XmlInt = XmlNode::GetXmlInt(v25, L"/X", -954380);
                  CardStack::SetX(CardStack, XmlInt);
                  if ( *(_DWORD *)(*((_QWORD *)CardStack + 18) + 8LL) == -954380 )
                  {
                    Log(0x10001u, L"CardTable::Init() - Failed to get the stack x pos.");
                    CardTable::Cleanup(this);
                    operator delete(v115);
                    operator delete(v111);
                    operator delete(v15);
                    operator delete(Source);
                    return 0;
                  }
                  v30 = XmlNode::GetXmlInt(v25, L"/Y", -954380);
                  CardStack::SetY(CardStack, v30);
                  if ( *(_DWORD *)(*((_QWORD *)CardStack + 18) + 12LL) == -954380 )
                  {
                    Log(0x10001u, L"CardTable::Init() - Failed to get the stack y pos.");
                    CardTable::Cleanup(this);
                    operator delete(v115);
                    operator delete(v111);
                    operator delete(v15);
                    operator delete(Source);
                    return 0;
                  }
                  memset(v130, 0, sizeof(v130));
                  XmlNode::GetXmlString(v25, v130, 0x80u, L"/Direction");
                  if ( !v130[0] )
                  {
                    Log(0x10001u, L"CardTable::Init() - Failed to get the stack direction.");
                    CardTable::Cleanup(this);
                    operator delete(v115);
                    operator delete(v111);
                    operator delete(v15);
                    operator delete(Source);
                    return 0;
                  }
                  v31 = Str::Str((Str *)v129, &dword_1000028D4);
                  XmlNode::GetXmlStr(v25, v123, L"/CardPlacement", (__int64)v31);
                  Str::Str((Str *)v117, L"Open");
                  if ( v124 )
                    v32 = Str::Equals((Str *)v123, (const struct Str *)v117);
                  else
                    v32 = 0;
                  operator delete(Block);
                  v33 = !v32;
                  if ( v32 )
                  {
                    *((_DWORD *)CardStack + 65) = 1;
                  }
                  else
                  {
                    Str::Str((Str *)v117, L"Closed");
                    if ( v124 )
                      v34 = Str::Equals((Str *)v123, (const struct Str *)v117);
                    else
                      v34 = 0;
                    operator delete(Block);
                    v33 = !v34;
                    if ( v34 )
                      *((_DWORD *)CardStack + 65) = 2;
                  }
                  v35 = v130;
                  v36 = L"up";
                  v37 = 3;
                  do
                  {
                    if ( !v37 )
                      break;
                    v33 = *v35++ == *v36++;
                    --v37;
                  }
                  while ( v33 );
                  if ( v33 )
                  {
                    Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", 0);
                    *((_DWORD *)CardStack + 82) = 0;
                  }
                  else
                  {
                    v38 = v130;
                    v39 = L"down";
                    v40 = 5;
                    do
                    {
                      if ( !v40 )
                        break;
                      v33 = *v38++ == *v39++;
                      --v40;
                    }
                    while ( v33 );
                    if ( v33 )
                    {
                      Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", 1);
                      *((_DWORD *)CardStack + 82) = 1;
                    }
                    else
                    {
                      v41 = v130;
                      v42 = L"left";
                      v43 = 5;
                      do
                      {
                        if ( !v43 )
                          break;
                        v33 = *v41++ == *v42++;
                        --v43;
                      }
                      while ( v33 );
                      if ( v33 )
                      {
                        Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", 2);
                        *((_DWORD *)CardStack + 82) = 2;
                      }
                      else
                      {
                        v44 = v130;
                        v45 = L"right";
                        v46 = 6;
                        do
                        {
                          if ( !v46 )
                            break;
                          v33 = *v44++ == *v45++;
                          --v46;
                        }
                        while ( v33 );
                        if ( v33 )
                        {
                          Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", 3);
                          *((_DWORD *)CardStack + 82) = 3;
                        }
                        else
                        {
                          v47 = v130;
                          v48 = L"vertical";
                          v49 = 9;
                          do
                          {
                            if ( !v49 )
                              break;
                            v33 = *v47++ == *v48++;
                            --v49;
                          }
                          while ( v33 );
                          if ( !v33 )
                          {
                            Log(0x10001u, L"CardTable::Init() - Unknown stack direction specified.");
                            CardTable::Cleanup(this);
                            operator delete(v115);
                            operator delete(v111);
                            operator delete(v124);
                            operator delete(v15);
                            operator delete(Source);
                            return 0;
                          }
                          Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", 4);
                          *((_DWORD *)CardStack + 82) = 4;
                        }
                      }
                    }
                  }
                  v50 = v122;
                  v51 = XmlNode::XPathElementSearchSingle(v122, L"/Label");
                  v52 = v51;
                  if ( v51 )
                  {
                    if ( XmlNode::GetXmlString(v51, &word_1000B1D10, 0x80u, L"/Text") )
                      CardStack::SetLabelText(CardStack, &word_1000B1D10);
                    v53 = XmlNode::GetXmlInt(v52, L"/Y", 0);
                    *((_DWORD *)CardStack + 60) = XmlNode::GetXmlInt(v52, L"/X", 0);
                    *((_DWORD *)CardStack + 61) = v53;
                    CardStack::SetX(CardStack, *(_DWORD *)(*((_QWORD *)CardStack + 18) + 8LL));
                    CardStack::SetY(CardStack, *(_DWORD *)(*((_QWORD *)CardStack + 18) + 12LL));
                    v54 = XmlNode::GetXmlInt(v52, L"/W", -1);
                    if ( v54 != -1 )
                    {
                      NodeBase::SetSize(
                        *((NodeBase **)CardStack + 19),
                        v54,
                        *(_DWORD *)(*((_QWORD *)CardStack + 19) + 20LL));
                      NodeBase::SetSize(
                        *((NodeBase **)CardStack + 20),
                        v55,
                        *(_DWORD *)(*((_QWORD *)CardStack + 20) + 20LL));
                    }
                    v56 = XmlNode::GetXmlInt(v52, L"/H", -1);
                    if ( v56 != -1 )
                    {
                      NodeBase::SetSize(
                        *((NodeBase **)CardStack + 19),
                        *(_DWORD *)(*((_QWORD *)CardStack + 19) + 16LL),
                        v56);
                      NodeBase::SetSize(
                        *((NodeBase **)CardStack + 20),
                        *(_DWORD *)(*((_QWORD *)CardStack + 20) + 16LL),
                        v57);
                    }
                    v58 = XmlNode::GetXmlInt(v52, L"/Justify", -1);
                    if ( v58 != -1 )
                    {
                      v59 = *((_QWORD *)CardStack + 19);
                      v60 = g_pRenderManager;
                      if ( v58 != *(_DWORD *)(v59 + 476) )
                      {
                        *(_DWORD *)(v59 + 476) = v58;
                        *((_BYTE *)v60 + 20) = 1;
                        *((_BYTE *)v60 + 88) = 1;
                      }
                      v61 = *((_QWORD *)CardStack + 20);
                      if ( v58 != *(_DWORD *)(v61 + 476) )
                      {
                        *(_DWORD *)(v61 + 476) = v58;
                        *((_BYTE *)v60 + 20) = 1;
                        *((_BYTE *)v60 + 88) = 1;
                      }
                    }
                    XmlNode::GetXmlString(v52, v133, 0x80u, L"/FontName");
                    v62 = XmlNode::GetXmlInt(v52, L"/FontSize", 14);
                    v63 = LocalizeMessage(v133);
                    LOBYTE(v108) = 0;
                    LOBYTE(v107) = 0;
                    LOBYTE(v106) = 1;
                    (*(void (__fastcall **)(TextRenderer *, int *, _QWORD, unsigned __int16 *, int, int, int))(*(_QWORD *)g_pTextRenderer + 8LL))(
                      g_pTextRenderer,
                      &v116,
                      v62,
                      v63,
                      v106,
                      v107,
                      v108);
                    v64 = v116;
                    v65 = *((_QWORD *)CardStack + 19);
                    v66 = g_pRenderManager;
                    if ( *(_DWORD *)(v65 + 472) != v116 )
                    {
                      *(_DWORD *)(v65 + 472) = v116;
                      *((_BYTE *)v66 + 20) = 1;
                      *((_BYTE *)v66 + 88) = 1;
                    }
                    v67 = *((_QWORD *)CardStack + 20);
                    if ( *(_DWORD *)(v67 + 472) != v64 )
                    {
                      *(_DWORD *)(v67 + 472) = v64;
                      *((_BYTE *)v66 + 20) = 1;
                      *((_BYTE *)v66 + 88) = 1;
                    }
                    LocalFree(v63);
                    v50 = v122;
                  }
                  *((_DWORD *)CardStack + 5) = XmlNode::GetXmlInt(
                                                 v50,
                                                 L"/SelectedVerticalOffset",
                                                 *((_DWORD *)this + 13));
                  *((_DWORD *)CardStack + 6) = XmlNode::GetXmlInt(
                                                 v50,
                                                 L"/VerticalSpacingFaceUp",
                                                 *((_DWORD *)this + 14));
                  *((_DWORD *)CardStack + 7) = XmlNode::GetXmlInt(
                                                 v50,
                                                 L"/VerticalSpacingFaceDown",
                                                 *((_DWORD *)this + 15));
                  *((_DWORD *)CardStack + 8) = XmlNode::GetXmlInt(
                                                 v50,
                                                 L"/HorizontalSpacingFaceUp",
                                                 *((_DWORD *)this + 16));
                  *((_DWORD *)CardStack + 9) = XmlNode::GetXmlInt(
                                                 v50,
                                                 L"/HorizontalSpacingFaceDown",
                                                 *((_DWORD *)this + 17));
                  *((_DWORD *)CardStack + 66) = XmlNode::GetXmlInt(v50, L"/MaxStackSize", *((_DWORD *)CardStack + 66));
                  *((_DWORD *)CardStack + 10) = XmlNode::GetXmlInt(v50, L"/UpSpacing", *((_DWORD *)this + 18));
                  *((_DWORD *)CardStack + 11) = XmlNode::GetXmlInt(v50, L"/SpacingCount", *((_DWORD *)this + 19));
                  *((_DWORD *)CardStack + 13) = XmlNode::GetXmlInt(v50, L"/EndSpacing", *((_DWORD *)this + 20));
                  *((_BYTE *)CardStack + 56) = XmlNode::GetXmlBool(
                                                 v50,
                                                 L"/IncludeFaceDownDesc",
                                                 *((_BYTE *)CardStack + 56));
                  *((_BYTE *)CardStack + 57) = XmlNode::GetXmlBool(
                                                 v50,
                                                 L"/LimitCoveredCardClickableArea",
                                                 *((_BYTE *)CardStack + 57));
                  v68 = Str::Str((Str *)v128, *((const unsigned __int16 **)CardStack + 36));
                  XmlStr = XmlNode::GetXmlStr(v50, v117, L"/StackAccessName", (__int64)v68);
                  Str::operator=((__int64)CardStack + 72, (__int64)XmlStr);
                  operator delete(Block);
                  v70 = XmlNode::GetXmlInt(v50, L"/ExposeCount", -1);
                  if ( v70 > 0 )
                    *((_DWORD *)CardStack + 83) = v70;
                  v71 = Str::Str((Str *)v128, &dword_1000028D4);
                  v72 = XmlNode::GetXmlStr(v50, v117, L"/NextRowStack", (__int64)v71);
                  Str::operator=((__int64)CardStack + 96, (__int64)v72);
                  operator delete(Block);
                  v73 = Str::Str((Str *)v128, &dword_1000028D4);
                  v74 = XmlNode::GetXmlStr(v50, v117, L"/PrevRowStack", (__int64)v73);
                  Str::operator=((__int64)CardStack + 120, (__int64)v74);
                  operator delete(Block);
                  *((_BYTE *)CardStack + 16) = XmlNode::XPathElementSearchSingle(v50, L"/NavigateAsSingleCard") != 0;
                  operator delete(v124);
                  ++v113;
                  v23 = ++v121;
                  if ( v113 >= v110 )
                  {
                    v24 = v111;
                    v19 = v114;
                    goto LABEL_89;
                  }
                }
                Log(0x10001u, L"CardTable::Init() - Failed to get the stack name.");
                CardTable::Cleanup(this);
                operator delete(v115);
                operator delete(v111);
                operator delete(v15);
                operator delete(Source);
                return 0;
              }
              else
              {
LABEL_99:
                if ( XmlNode::GetXmlString((XmlNode *)a3, v131, 0x80u, L"/DefaultBackground") )
                {
                  v111 = v131;
                  LocalizeDeckOrBackgroundName((const unsigned __int16 **)&v111, 0x80u);
                  if ( CardTable::SetBackground(this, v131) )
                  {
                    v114 = 0;
                    v113 = 0;
                    if ( v112 )
                    {
                      v75 = (char *)this + 352;
                      v76 = v18;
                      do
                      {
                        v77 = XmlNode::XPathAttributeSearchSingle(*v76, L"/@Name");
                        v78 = *(_QWORD *)(*((_QWORD *)v75 + 1)
                                        + 8LL * (int)SortedListW<Card *>::BinSearch(v75, v77, 0, *((_DWORD *)v75 + 4)));
                        *(_QWORD *)(v78 + 8) = 0;
                        *(_QWORD *)(v78 + 16) = 0;
                        operator delete(v77);
                        v79 = XmlNode::XPathElementSearchSingle(*v76, L"/NextGroup");
                        if ( v79 )
                          NodeValue = XmlNode::GetNodeValue(v79);
                        else
                          NodeValue = 0;
                        if ( NodeValue )
                        {
                          v109 = 0;
                          if ( (unsigned __int8)SortedListW<StackGroup *>::TryGet(v75, NodeValue, &v109) )
                          {
                            *(_QWORD *)(v78 + 8) = v109;
                          }
                          else
                          {
                            v81 = L"<no xml source file>";
                            if ( a3[12] )
                              v81 = a3[12];
                            Log(0x10001u, 0x227u, "CardTable.cpp", L"Invalid NextGroup %s in layout %s", NodeValue, v81);
                          }
                        }
                        operator delete(NodeValue);
                        v82 = XmlNode::XPathElementSearchSingle(*v76, L"/PrevGroup");
                        if ( v82 )
                          v83 = XmlNode::GetNodeValue(v82);
                        else
                          v83 = 0;
                        if ( v83 )
                        {
                          v109 = 0;
                          if ( (unsigned __int8)SortedListW<StackGroup *>::TryGet(v75, v83, &v109) )
                          {
                            *(_QWORD *)(v78 + 16) = v109;
                          }
                          else
                          {
                            v84 = L"<no xml source file>";
                            if ( a3[12] )
                              v84 = a3[12];
                            Log(0x10001u, 0x238u, "CardTable.cpp", L"Invalid PrevGroup %s in layout %s", v83, v84);
                          }
                        }
                        operator delete(v83);
                        v85 = XmlNode::XPathElementSearchSingle(*v76, L"/NonMCENextGroup");
                        if ( v85 )
                          v86 = XmlNode::GetNodeValue(v85);
                        else
                          v86 = 0;
                        if ( v86 )
                        {
                          v109 = 0;
                          if ( (unsigned __int8)SortedListW<StackGroup *>::TryGet(v75, v86, &v109) )
                          {
                            *(_QWORD *)(v78 + 8) = v109;
                          }
                          else
                          {
                            v87 = L"<no xml source file>";
                            if ( a3[12] )
                              v87 = a3[12];
                            Log(0x10001u, 0x24Bu, "CardTable.cpp", L"Invalid NextGroup %s in layout %s", v86, v87);
                          }
                        }
                        operator delete(v86);
                        v88 = XmlNode::XPathElementSearchSingle(*v76, L"/NonMCEPrevGroup");
                        if ( v88 )
                          v89 = XmlNode::GetNodeValue(v88);
                        else
                          v89 = 0;
                        if ( v89 )
                        {
                          v109 = 0;
                          if ( (unsigned __int8)SortedListW<StackGroup *>::TryGet(v75, v89, &v109) )
                          {
                            *(_QWORD *)(v78 + 16) = v109;
                          }
                          else
                          {
                            v90 = L"<no xml source file>";
                            if ( a3[12] )
                              v90 = a3[12];
                            Log(0x10001u, 0x25Cu, "CardTable.cpp", L"Invalid PrevGroup %s in layout %s", v89, v90);
                          }
                        }
                        operator delete(v89);
                        v110 = 0;
                        v91 = XmlNode::XPathElementSearch(*v76, L"/NotNavigableWhen", &v110);
                        v109 = v91;
                        *(_DWORD *)(v78 + 24) = 0;
                        v116 = 0;
                        if ( v110 )
                        {
                          v92 = v91;
                          for ( i = 0; i < v110; ++i )
                          {
                            v94 = XmlNode::GetNodeValue(*v92);
                            if ( _wcsicmp(v94, L"empty") )
                            {
                              if ( _wcsicmp(v94, L"cardselected") )
                              {
                                if ( _wcsicmp(v94, L"cardnotselected") )
                                {
                                  if ( !_wcsicmp(v94, L"always") )
                                    *(_DWORD *)(v78 + 24) ^= 8u;
                                }
                                else
                                {
                                  *(_DWORD *)(v78 + 24) ^= 4u;
                                }
                              }
                              else
                              {
                                *(_DWORD *)(v78 + 24) ^= 1u;
                              }
                            }
                            else
                            {
                              *(_DWORD *)(v78 + 24) ^= 2u;
                            }
                            operator delete(v94);
                            ++v92;
                          }
                          v75 = (char *)this + 352;
                          v91 = v109;
                        }
                        operator delete(v91);
                        *(_BYTE *)(v78 + 72) = XmlNode::XPathElementSearchSingle(*v76, L"/StacksAsCards") != 0;
                        *(_DWORD *)(v78 + 56) = -1;
                        *(_BYTE *)(v78 + 73) = 1;
                        if ( XmlNode::GetXmlInt(*v76, L"/NotAccessible", -1) <= 0 )
                        {
                          v95 = NodeBase::CreateFromType(L"Base", 0, 1);
                          *(_QWORD *)(v78 + 64) = v95;
                          *((_BYTE *)v95 + 73) = 1;
                          Array<IEventListener *>::Add(*(_QWORD *)(v78 + 64) + 200LL, v78);
                          *(_BYTE *)(v78 + 73) = 0;
                          NodeBase::SetPosition(*(NodeBase **)(v78 + 64), *(_DWORD *)(v78 + 84), *(_DWORD *)(v78 + 88));
                          NodeBase::SetSize(*(NodeBase **)(v78 + 64), *(_DWORD *)(v78 + 76), *(_DWORD *)(v78 + 80));
                          NodeBase::MoveToBack(*(NodeBase **)(v78 + 64));
                          v96 = XmlNode::XPathElementSearchSingle(*v76, L"/AccessName");
                          if ( v96 )
                            v97 = XmlNode::GetNodeValue(v96);
                          else
                            v97 = 0;
                          if ( v97 )
                          {
                            NodeBase::SetAccessName(*(HLOCAL **)(v78 + 64), v97);
                            operator delete(v97);
                          }
                          v98 = XmlNode::XPathElementSearchSingle(*v76, L"/AccessDesc");
                          if ( v98 )
                            v99 = XmlNode::GetNodeValue(v98);
                          else
                            v99 = 0;
                          if ( v99 )
                          {
                            NodeBase::SetAccessDescription(*(HLOCAL **)(v78 + 64), v99);
                            operator delete(v99);
                          }
                          v100 = *(_QWORD *)(v78 + 64);
                          if ( *(_BYTE *)(v100 + 144) != 1 )
                          {
                            *(_BYTE *)(v100 + 144) = 1;
                            *(_DWORD *)(v100 + 192) = 16;
                            UserInterface::Access_OnNodeAccessible(g_pUserInterface, (struct NodeBase *)v100);
                          }
                          v101 = v114;
                          *(_DWORD *)(v78 + 56) = v114;
                          v114 = v101 + 1;
                        }
                        ++v113;
                        ++v76;
                      }
                      while ( v113 < v112 );
                      v15 = v126;
                    }
                    operator delete(v115);
                    v102 = XmlNode::XPathElementSearchSingle((XmlNode *)a3, L"/InitialStackGroup");
                    if ( v102 )
                      v103 = XmlNode::GetNodeValue(v102);
                    else
                      v103 = 0;
                    *((_QWORD *)this + 47) = 0;
                    if ( v103 )
                    {
                      SortedListW<StackGroup *>::TryGet((char *)this + 352, v103, (char *)this + 376);
                      *((_QWORD *)g_pUserInterface + 21) = this;
                    }
                    operator delete(v103);
                    v104 = g_pRenderManager;
                    *(_BYTE *)(*((_QWORD *)g_pRenderManager + 15) + 73LL) = 1;
                    Array<IEventListener *>::Add(*((_QWORD *)v104 + 15) + 200LL, (__int64)this);
                    if ( *((_DWORD *)this + 40) )
                    {
                      v105 = 0;
                      do
                      {
                        CardStack::UpdateAccessibility(*(CardStack **)(v105 + *((_QWORD *)this + 19)));
                        ++v9;
                        v105 += 8;
                      }
                      while ( v9 < *((_DWORD *)this + 40) );
                    }
                    operator delete(v15);
                    LOBYTE(v9) = 1;
                  }
                  else
                  {
                    Log(0x10001u, L"CardTableInit() - Failed to load the background.");
                    CardTable::Cleanup(this);
                    operator delete(v15);
                  }
                  operator delete(Source);
                  return v9;
                }
                else
                {
                  Log(0x10001u, L"CardTableInit() - Failed to load the background name.");
                  CardTable::Cleanup(this);
                  operator delete(v15);
                  operator delete(Source);
                  return 0;
                }
              }
            }
            else
            {
              Log(0x10001u, L"CardTableInit() - Failed to load the card deck.");
              CardTable::Cleanup(this);
              return 0;
            }
          }
          else
          {
            Log(0x10001u, L"CardTableInit() - Failed to load the card deck name.");
            CardTable::Cleanup(this);
            return 0;
          }
        }
        else
        {
          Log(0x10001u, L"CardTableInit() - Failed to get the layout xml.");
          CardTable::Cleanup(this);
          return 0;
        }
      }
      else
      {
        Log(0x10001u, L"CardTable::Init() - Failed to get the deck list.");
        CardTable::Cleanup(this);
        return 0;
      }
    }
    else
    {
      Log(0x10001u, L"CardTable::Init() - Failed to get the background list.");
      CardTable::Cleanup(this);
      return 0;
    }
  }
  else
  {
    Log(0x10001u, L"CardTable::Init() - Failed to create the container.");
    CardTable::Cleanup(this);
    return 0;
  }
}
