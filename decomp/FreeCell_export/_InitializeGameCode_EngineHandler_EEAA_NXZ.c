char __fastcall EngineHandler::InitializeGameCode(EngineHandler *this, __int64 a2, HWND a3, bool a4)
{
  HMENU MenuW; // rbx
  HMENU Menu; // rax
  GameAudio *Xml; // rax
  const struct XmlNode *v7; // rdx
  bool v8; // r8
  FreeCellGame *v9; // rax
  FreeCellGame *v10; // rax
  unsigned __int16 *v12; // [rsp+30h] [rbp-18h]

  if ( g_bDebugEnabled )
  {
    MenuW = LoadMenuW(g_hInstance, (LPCWSTR)0x67);
    Menu = GetMenu(g_hWnd);
    DestroyMenu(Menu);
    SetMenu(g_hWnd, MenuW);
    DrawMenuBar(g_hWnd);
  }
  LOBYTE(a3) = (_BYTE)g_bMediaCenter;
  DialogHelper::Init((DialogHelper *)g_hInstance, (HINSTANCE)g_hWnd, a3, a4);
  Xml = XmlManager::GetXml(g_pXmlManager, L"Audio/Audio.xml");
  LOBYTE(v7) = 1;
  GameAudio::LoadGameAudio(Xml, v7, v8);
  v9 = (FreeCellGame *)operator new(0x188u);
  if ( v9 )
    v10 = FreeCellGame::FreeCellGame(v9);
  else
    v10 = 0;
  g_pFreeCellGame = v10;
  if ( FreeCellGame::Init(v10) )
  {
    Engine_ResetTimer();
    return 1;
  }
  else
  {
    LOBYTE(v12) = 1;
    DialogHelper::ShowMessageBox(0x65u, 0x66u, 1, (const unsigned __int16 *)0xFFFE, 0, 0, v12);
    if ( g_pFreeCellGame )
      (**(void (__fastcall ***)(FreeCellGame *, __int64))g_pFreeCellGame)(g_pFreeCellGame, 1);
    g_pFreeCellGame = 0;
    return 0;
  }
}
