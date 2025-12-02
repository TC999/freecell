// Hidden C++ exception states: #wind=2
char __fastcall FreeCellGame::Init(FreeCellGame *this)
{
  FreeCellGame *v1; // rdi
  const unsigned __int16 *(*v2)(unsigned int); // rax
  _DWORD *v3; // rax
  _DWORD *v4; // rax
  _DWORD *v5; // rbx
  _DWORD *v6; // rax
  unsigned __int16 *v7; // rbx
  struct NodeBase *v8; // rax
  struct XmlNode *Xml; // rbx
  CardTable *v11; // rax
  CardTable *v12; // rax
  __int64 v13; // rax
  unsigned __int16 *v14; // rsi
  unsigned __int16 *v15; // r13
  char v16; // r11
  unsigned int v17; // edx
  __int64 v18; // r9
  unsigned __int16 *v19; // rcx
  int v20; // r8d
  int v21; // eax
  char v22; // r11
  unsigned int v23; // edx
  __int64 v24; // r9
  unsigned __int16 *v25; // rcx
  int v26; // r8d
  int v27; // eax
  unsigned int v28; // ebx
  struct CardStack *CardStack; // rax
  unsigned int v30; // ebx
  struct CardStack *v31; // rax
  unsigned int v32; // ebx
  struct CardStack *v33; // rax
  unsigned int *v34; // rcx
  unsigned int v35; // r9d
  const struct XmlNode *v36; // rbx
  TipManager *v37; // rax
  TipManager *v38; // r11
  NodeBase *v39; // rcx
  NodeBase *v40; // rcx
  NodeBase *v41; // rcx
  NodeBase *v42; // rcx
  struct NodeBase *v43; // rbx
  const struct XmlNode *v44; // rax
  struct NodeBase *v45; // rax
  struct NodeBase *v46; // rbx
  const struct XmlNode *v47; // rax
  int v48; // edx
  struct NodeBase *v49; // rbx
  const struct XmlNode *v50; // rax
  struct NodeBase *v51; // rax
  struct NodeBase *v52; // rbx
  const struct XmlNode *v53; // rax
  DWORD pdwDefaultLayout[2]; // [rsp+20h] [rbp-2E8h] BYREF
  __int64 v55; // [rsp+28h] [rbp-2E0h]
  _DWORD v56[76]; // [rsp+30h] [rbp-2D8h] BYREF
  wchar_t Buffer[64]; // [rsp+160h] [rbp-1A8h] BYREF
  wchar_t v58[64]; // [rsp+1E0h] [rbp-128h] BYREF
  wchar_t v59[64]; // [rsp+260h] [rbp-A8h] BYREF

  v55 = -2;
  v1 = g_pFreeCellGame;
  (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
    g_pFreeCellGame,
    *((unsigned int *)g_pFreeCellGame + 2));
  *((_DWORD *)v1 + 3) = *((_DWORD *)v1 + 2);
  *((_DWORD *)v1 + 2) = 5;
  (*(void (__fastcall **)(FreeCellGame *))(*(_QWORD *)v1 + 8LL))(v1);
  g_pCardGameLogResolver = (const unsigned __int16 *(*)(unsigned int))FreeCellLogger::FreeCellLogResolver;
  v2 = g_pLoggerNameResolver;
  if ( CardLibLogger::CardLibLogResolver )
    v2 = (const unsigned __int16 *(*)(unsigned int))CardLibLogger::CardLibLogResolver;
  g_pLoggerNameResolver = v2;
  v3 = operator new(0x28u);
  if ( v3 )
  {
    *(_QWORD *)v3 = &FreeCellStatistics::`vftable';
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
    *((_BYTE *)v3 + 32) = 0;
  }
  else
  {
    v3 = 0;
  }
  *((_QWORD *)v1 + 10) = v3;
  v4 = operator new(0x20u);
  v5 = v4;
  *(_QWORD *)pdwDefaultLayout = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = &FreeCellOptions::`vftable';
    v4[2] = 2;
    *((_BYTE *)v4 + 16) = 1;
    *((_BYTE *)v4 + 13) = 0;
    *((_BYTE *)v4 + 28) = *((_QWORD *)g_pAudio + 2) != 0;
    (*(void (__fastcall **)(_QWORD, _DWORD *))(**((_QWORD **)g_pRenderManager + 10) + 56LL))(
      *((_QWORD *)g_pRenderManager + 10),
      v56);
    *((_BYTE *)v5 + 30) = v56[0] != 3;
    *((_BYTE *)v5 + 29) = 1;
    *((_BYTE *)v5 + 31) = 1;
    *((_BYTE *)v5 + 12) = 0;
    *((_BYTE *)v5 + 14) = (_BYTE)g_bMediaCenter != 0;
    *((_BYTE *)v5 + 15) = 0;
    *((_BYTE *)v5 + 16) = 1;
    v5[5] = 0;
    v5[6] = 0;
  }
  else
  {
    v5 = 0;
  }
  *((_QWORD *)v1 + 11) = v5;
  v6 = operator new(0x10u);
  if ( v6 )
  {
    *(_QWORD *)v6 = &FreeCellGameState::`vftable';
    v6[2] = 3;
    v6[3] = 0;
  }
  else
  {
    v6 = 0;
  }
  *((_QWORD *)v1 + 12) = v6;
  v7 = LocalizeMessage(L"|44129|ACC|FreeCell//accessibility root node name");
  NodeBase::SetAccessName(*((NodeBase **)g_pRenderManager + 15), v7);
  NodeBase::SetAccessDescription(*((NodeBase **)g_pRenderManager + 15), v7);
  LocalFree(v7);
  v8 = NodeBase::CreateFromType(L"Base", 0, 1);
  *((_QWORD *)v1 + 14) = v8;
  if ( v8 )
  {
    Xml = XmlManager::GetXml(g_pXmlManager, L"Layouts\\FreeCellLayout.xml");
    if ( Xml )
    {
      v11 = (CardTable *)operator new(0x188u);
      if ( v11 )
        v12 = CardTable::CardTable(v11);
      else
        v12 = 0;
      *((_QWORD *)v1 + 22) = v12;
      if ( CardTable::Init(v12, (FreeCellGame *)((char *)v1 + 16), Xml, *((struct NodeBase **)v1 + 14)) )
      {
        *(_QWORD *)(*((_QWORD *)v1 + 22) + 16LL) = FreeCellGame::UpdateCardAccessName;
        CardTable::GetCardDeckList(*((_QWORD *)v1 + 22), (char *)v1 + 32);
        CardTable::GetBackgroundList(*((_QWORD *)v1 + 22), (char *)v1 + 56);
        FreeCellGame::LoadGeneralData(v1);
        if ( *(_BYTE *)(*((_QWORD *)v1 + 11) + 16LL) )
        {
          v13 = *((_QWORD *)v1 + 22);
          v14 = *(unsigned __int16 **)(v13 + 280);
          v15 = *(unsigned __int16 **)(v13 + 304);
          v16 = 0;
          v17 = 0;
          v18 = 0;
          do
          {
            if ( v17 >= *((_DWORD *)v1 + 14) )
              break;
            v19 = v14;
            do
            {
              v20 = *(unsigned __int16 *)((char *)v19 + *(_QWORD *)(v18 + *((_QWORD *)v1 + 9)) - (_QWORD)v14);
              v21 = *v19 - v20;
              if ( v21 )
                break;
              ++v19;
            }
            while ( v20 );
            if ( !v21 )
            {
              *(_DWORD *)(*((_QWORD *)v1 + 11) + 24LL) = v17;
              v16 = 1;
            }
            ++v17;
            v18 += 8;
          }
          while ( !v16 );
          v22 = 0;
          v23 = 0;
          v24 = 0;
          do
          {
            if ( v23 >= *((_DWORD *)v1 + 8) )
              break;
            v25 = v15;
            do
            {
              v26 = *(unsigned __int16 *)((char *)v25 + *(_QWORD *)(v24 + *((_QWORD *)v1 + 6)) - (_QWORD)v15);
              v27 = *v25 - v26;
              if ( v27 )
                break;
              ++v25;
            }
            while ( v26 );
            if ( !v27 )
            {
              *(_DWORD *)(*((_QWORD *)v1 + 11) + 20LL) = v23;
              v22 = 1;
            }
            ++v23;
            v24 += 8;
          }
          while ( !v22 );
        }
        v28 = 0;
        while ( 1 )
        {
          swprintf_s(Buffer, 0x40u, L"SuitStack%d", ++v28, *(_QWORD *)pdwDefaultLayout);
          CardStack = CardTable::GetCardStack(*((CardTable **)v1 + 22), Buffer);
          if ( !CardStack )
            break;
          Array<IEventListener *>::Add((char *)v1 + 232, CardStack);
          if ( v28 >= 4 )
          {
            v30 = 0;
            while ( 1 )
            {
              swprintf_s(v59, 0x40u, L"FreeCell%d", ++v30);
              v31 = CardTable::GetCardStack(*((CardTable **)v1 + 22), v59);
              if ( !v31 )
                break;
              Array<IEventListener *>::Add((char *)v1 + 208, v31);
              if ( v30 >= 4 )
              {
                v32 = 0;
                do
                {
                  swprintf_s(v58, 0x40u, L"Stack%d", ++v32);
                  v33 = CardTable::GetCardStack(*((CardTable **)v1 + 22), v58);
                  if ( !v33 )
                  {
                    Log(0x10000001u, L"%s() - %s", L"FreeCellGame::Init", L"Missing a main stack in the layout");
                    FreeCellGame::Cleanup(v1);
                    return 0;
                  }
                  Array<IEventListener *>::Add((char *)v1 + 184, v33);
                }
                while ( v32 < 8 );
                v34 = (unsigned int *)NodeBase::CreateFromType(L"Base", 0, 1);
                *((_QWORD *)v1 + 15) = v34;
                if ( v34 )
                {
                  NodeBase::SetSize((NodeBase *)v34, *((_DWORD *)g_pUserInterface + 64), v34[5]);
                  NodeBase::SetSize(*((NodeBase **)v1 + 15), *(_DWORD *)(*((_QWORD *)v1 + 15) + 16LL), v35);
                  *(_BYTE *)(*((_QWORD *)v1 + 15) + 72LL) = 0;
                  v36 = XmlManager::GetXml(g_pXmlManager, L"Tips\\FreeCell\\FreeCellTips.xml");
                  if ( v36 )
                  {
                    v37 = (TipManager *)operator new(0x98u);
                    *(_QWORD *)pdwDefaultLayout = v37;
                    if ( v37 )
                      v38 = TipManager::TipManager(v37, v36, *((struct NodeBase **)v1 + 15), 1);
                    else
                      v38 = 0;
                    *((_QWORD *)v1 + 42) = v38;
                    *((_BYTE *)v38 + 145) = *(_BYTE *)(*((_QWORD *)v1 + 11) + 30LL);
                    v39 = (NodeBase *)*((_QWORD *)v1 + 18);
                    if ( v39 )
                    {
                      NodeBase::DeleteSelf(v39);
                      *((_QWORD *)v1 + 18) = 0;
                    }
                    v40 = (NodeBase *)*((_QWORD *)v1 + 16);
                    if ( v40 )
                    {
                      NodeBase::DeleteSelf(v40);
                      *((_QWORD *)v1 + 16) = 0;
                    }
                    v41 = (NodeBase *)*((_QWORD *)v1 + 19);
                    if ( v41 )
                    {
                      NodeBase::DeleteSelf(v41);
                      *((_QWORD *)v1 + 19) = 0;
                    }
                    v42 = (NodeBase *)*((_QWORD *)v1 + 17);
                    if ( v42 )
                    {
                      NodeBase::DeleteSelf(v42);
                      *((_QWORD *)v1 + 17) = 0;
                    }
                    if ( (_BYTE)g_bMediaCenter == 1 )
                    {
                      v43 = (struct NodeBase *)*((_QWORD *)v1 + 14);
                      v44 = XmlManager::GetXml(g_pXmlManager, L"NewGameLabel.xml");
                      v45 = NodeBase::CreateFromXmlNode(v44, v43);
                      *((_QWORD *)v1 + 18) = v45;
                      *((_BYTE *)v45 + 64) = 0;
                      v46 = (struct NodeBase *)*((_QWORD *)v1 + 14);
                      v47 = XmlManager::GetXml(g_pXmlManager, L"NewGameButton.xml");
                      *((_QWORD *)v1 + 16) = NodeBase::CreateFromXmlNode(v47, v46);
                      pdwDefaultLayout[0] = 0;
                      GetProcessDefaultLayout(pdwDefaultLayout);
                      if ( (pdwDefaultLayout[0] & 1) != 0 )
                      {
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 16),
                          800 - *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 16) + 12LL));
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 18),
                          800 - *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 18) + 12LL));
                      }
                      else
                      {
                        NodeBase::SetPosition(*((NodeBase **)v1 + 16), 0, *(_DWORD *)(*((_QWORD *)v1 + 16) + 12LL));
                        NodeBase::SetPosition(*((NodeBase **)v1 + 18), v48, *(_DWORD *)(*((_QWORD *)v1 + 18) + 12LL));
                      }
                      NodeBase::SetPosition(*((NodeBase **)v1 + 16), *(_DWORD *)(*((_QWORD *)v1 + 16) + 8LL), -51);
                      v49 = (struct NodeBase *)*((_QWORD *)v1 + 14);
                      v50 = XmlManager::GetXml(g_pXmlManager, L"ExitGameLabel.xml");
                      v51 = NodeBase::CreateFromXmlNode(v50, v49);
                      *((_QWORD *)v1 + 19) = v51;
                      *((_BYTE *)v51 + 64) = 0;
                      v52 = (struct NodeBase *)*((_QWORD *)v1 + 14);
                      v53 = XmlManager::GetXml(g_pXmlManager, L"ExitGameButton.xml");
                      *((_QWORD *)v1 + 17) = NodeBase::CreateFromXmlNode(v53, v52);
                      pdwDefaultLayout[0] = 0;
                      GetProcessDefaultLayout(pdwDefaultLayout);
                      if ( (pdwDefaultLayout[0] & 1) != 0 )
                      {
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 17),
                          800 - *(_DWORD *)(*((_QWORD *)v1 + 17) + 16LL) - *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 17) + 12LL));
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 19),
                          800 - *(_DWORD *)(*((_QWORD *)v1 + 17) + 16LL) - *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 19) + 12LL));
                      }
                      else
                      {
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 17),
                          *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 17) + 12LL));
                        NodeBase::SetPosition(
                          *((NodeBase **)v1 + 19),
                          *(_DWORD *)(*((_QWORD *)v1 + 16) + 16LL),
                          *(_DWORD *)(*((_QWORD *)v1 + 19) + 12LL));
                      }
                      NodeBase::SetPosition(*((NodeBase **)v1 + 17), *(_DWORD *)(*((_QWORD *)v1 + 17) + 8LL), -51);
                      Array<IEventListener *>::Add(*((_QWORD *)v1 + 16) + 200LL, (char *)v1 + 16);
                      Array<IEventListener *>::Add(*((_QWORD *)v1 + 17) + 200LL, (char *)v1 + 16);
                      Array<IEventListener *>::Add(*((_QWORD *)v1 + 22) + 24LL, *((_QWORD *)v1 + 17));
                      Array<IEventListener *>::Add(*((_QWORD *)v1 + 22) + 24LL, *((_QWORD *)v1 + 16));
                      *(_BYTE *)(*((_QWORD *)v1 + 17) + 74LL) = 1;
                      *(_BYTE *)(*((_QWORD *)v1 + 16) + 74LL) = 1;
                    }
                    *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v1 + 22) + 88LL) + 24LL) = (char *)v1 + 24;
                    Array<IEventListener *>::Add((char *)g_pUserInterface + 96, (char *)v1 + 16);
                    Array<IEventListener *>::Add((char *)g_pUserInterface + 120, (char *)v1 + 16);
                    Array<IEventListener *>::Add((char *)g_pUserInterface + 144, (char *)v1 + 16);
                    FreeCellGame::CacheSounds(v1);
                    return 1;
                  }
                  else
                  {
                    Log(0x10000001u, L"%s() - %s", L"FreeCellGame::Init", L"Failed to get the tips xml");
                    FreeCellGame::Cleanup(v1);
                    return 0;
                  }
                }
                else
                {
                  Log(0x10000001u, L"%s() - %s", L"SpiderGame::Init", L"Failed to create tip container");
                  FreeCellGame::Cleanup(v1);
                  return 0;
                }
              }
            }
            break;
          }
        }
        Log(0x10000001u, L"%s() - %s", L"FreeCellGame::Init", L"Missing a suit stack in the layout");
        FreeCellGame::Cleanup(v1);
        return 0;
      }
      else
      {
        Log(0x10000001u, L"FreeCellGame::Init() - Failed to create the CardTable.");
        FreeCellGame::Cleanup(v1);
        return 0;
      }
    }
    else
    {
      Log(
        0x10000001u,
        L"%s() - %s",
        L"FreeCellGame::Init",
        L"Failed to get the freecell layout xml",
        *(_QWORD *)pdwDefaultLayout);
      FreeCellGame::Cleanup(v1);
      return 0;
    }
  }
  else
  {
    Log(
      0x10000001u,
      L"%s() - %s",
      L"FreeCellGame::Init",
      L"Failed to create a new container",
      *(_QWORD *)pdwDefaultLayout);
    FreeCellGame::Cleanup(v1);
    return 0;
  }
}
