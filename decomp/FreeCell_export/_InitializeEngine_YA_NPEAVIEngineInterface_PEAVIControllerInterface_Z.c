bool __fastcall InitializeEngine(struct IEngineInterface *a1, struct IControllerInterface *a2)
{
  DialogHelper *ModuleHandleW; // rax
  bool v4; // r9
  _WORD *v5; // rdi
  __int64 v6; // rcx
  unsigned __int64 v7; // rdi
  wchar_t *v8; // rax
  wchar_t *v9; // rsi
  const wchar_t *v11; // rax
  HANDLE MutexW; // rdi
  const unsigned __int16 *v13; // rax
  WCHAR *v14; // rdi
  HWND WindowW; // rsi
  const WCHAR *CommandLineW; // rax
  LPWSTR *v17; // r8
  const wchar_t **v18; // r8
  __int64 v19; // r9
  char v20; // al
  bool v21; // cf
  bool v22; // zf
  int v23; // edx
  const wchar_t *v24; // rdi
  const wchar_t *v25; // rsi
  __int64 v26; // rcx
  const WCHAR *v27; // rax
  bool v28; // si
  __int64 v29; // r11
  __int64 v30; // rdx
  OLECHAR *v31; // rcx
  __int64 v32; // rdi
  OLECHAR *v33; // rax
  int v34; // r8d
  __int64 v35; // rdx
  __int64 v36; // r11
  OLECHAR v37; // cx
  unsigned __int16 *v38; // rax
  _QWORD *v39; // rax
  const unsigned __int16 *v40; // rax
  DWORD ModuleFileNameW; // eax
  __int64 v42; // rcx
  WCHAR *v43; // rdx
  _DWORD *v44; // rax
  DllFileMgr *v45; // rax
  DllFileMgr *v46; // rax
  const unsigned __int16 *v47; // rax
  bool v48; // di
  const unsigned __int16 *v49; // rdi
  __int64 v50; // rax
  const unsigned __int16 *v51; // rdx
  Timekeeping *v52; // rcx
  ResourceManager *v53; // rax
  ResourceManager *v54; // rax
  RenderManager *v55; // rax
  RenderManager *v56; // rax
  _DWORD *v57; // rax
  CommonControllerThread *v58; // rax
  CommonControllerThread *v59; // rdi
  void **v60; // rdi
  XmlNode *Xml; // rax
  const struct XmlNode **v62; // r12
  unsigned int v63; // ebp
  XmlNode **v64; // rsi
  unsigned __int16 *NodeValue; // rdi
  unsigned int v66; // eax
  int v67; // ecx
  _QWORD *v68; // rax
  _QWORD *v69; // rdx
  XmlNode *v70; // rdi
  const WCHAR *v71; // rdi
  HMODULE v72; // rax
  LPVOID *ppv; // [rsp+20h] [rbp-728h]
  LPVOID *ppva; // [rsp+20h] [rbp-728h]
  unsigned __int16 *v75; // [rsp+30h] [rbp-718h]
  bool v76; // [rsp+38h] [rbp-710h]
  unsigned int v77; // [rsp+40h] [rbp-708h] BYREF
  RAWINPUTDEVICE pRawInputDevices; // [rsp+48h] [rbp-700h] BYREF
  void *Block; // [rsp+58h] [rbp-6F0h]
  int pNumArgs; // [rsp+60h] [rbp-6E8h] BYREF
  HWND v81; // [rsp+68h] [rbp-6E0h] BYREF
  _QWORD v82[2]; // [rsp+70h] [rbp-6D8h] BYREF
  int v83; // [rsp+80h] [rbp-6C8h] BYREF
  __int64 v84; // [rsp+88h] [rbp-6C0h]
  int v85; // [rsp+90h] [rbp-6B8h]
  int v86; // [rsp+94h] [rbp-6B4h]
  _QWORD v87[3]; // [rsp+98h] [rbp-6B0h] BYREF
  tagMSG Msg; // [rsp+B0h] [rbp-698h] BYREF
  char v89[16]; // [rsp+E0h] [rbp-668h] BYREF
  void *v90; // [rsp+F0h] [rbp-658h]
  OLECHAR psz[264]; // [rsp+100h] [rbp-648h] BYREF
  WCHAR Filename[512]; // [rsp+310h] [rbp-438h] BYREF

  v87[2] = -2;
  ModuleHandleW = (DialogHelper *)GetModuleHandleW(0);
  DialogHelper::Init(ModuleHandleW, 0, 0, v4);
  v5 = (_WORD *)(*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 32LL))(a1);
  v6 = -1;
  do
  {
    if ( !v6 )
      break;
    v22 = *v5++ == 0;
    --v6;
  }
  while ( !v22 );
  v7 = (unsigned int)(-(int)v6 - 2 + 24);
  v8 = (wchar_t *)operator new[](saturated_mul(v7, 2u));
  v9 = v8;
  if ( v8 )
  {
    wcscpy_s(v8, v7, L"Local\\Oberon_");
    v11 = (const wchar_t *)(*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 32LL))(a1);
    wcscat_s(v9, v7, v11);
    wcscat_s(v9, v7, L"_Singleton");
    MutexW = CreateMutexW(0, 1, v9);
    operator delete(v9);
    if ( !MutexW )
      ExitProcess(0);
    if ( GetLastError() == 183 )
    {
      v13 = (const unsigned __int16 *)(*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 32LL))(a1);
      v14 = LocalizeMessage(v13);
      WindowW = FindWindowW(v14, 0);
      LocalFree(v14);
      if ( WindowW )
      {
        if ( IsIconic(WindowW) )
          ShowWindow(WindowW, 10);
        BringWindowToTop(WindowW);
        SetForegroundWindow(WindowW);
      }
      ExitProcess(0);
    }
    CommandLineW = GetCommandLineW();
    pNumArgs = 0;
    v17 = CommandLineToArgvW(CommandLineW, &pNumArgs);
    if ( pNumArgs > 1 )
    {
      v18 = (const wchar_t **)(v17 + 1);
      v19 = (unsigned int)(pNumArgs - 1);
      v20 = (char)g_bMediaCenter;
      do
      {
        v21 = 0;
        v22 = 1;
        v23 = 0;
        v24 = L"-mce";
        v25 = *v18;
        v26 = 5;
        do
        {
          if ( !v26 )
            break;
          v21 = *v25 < *v24;
          v22 = *v25++ == *v24++;
          --v26;
        }
        while ( v22 );
        if ( !v22 )
          v23 = -v21 - (v21 - 1);
        if ( !v23 )
          v20 = 1;
        LOBYTE(g_bMediaCenter) = v20;
        ++v18;
        --v19;
      }
      while ( v19 );
    }
    v27 = GetCommandLineW();
    RegisterApplicationRestart(v27, 0);
    CoInitialize(0);
    v28 = 0;
    *(_QWORD *)&pRawInputDevices.usUsagePage = 0;
    if ( CoCreateInstance(
           &GUID_9a5ea990_3034_4d6f_9128_01f3c61022bc,
           0,
           1u,
           &GUID_e7b2fb72_d728_49b3_a5f2_18ebf5f1349e,
           (LPVOID *)&pRawInputDevices) >= 0
      && (int)SHGetFolderPathEx(&FOLDERID_ProgramFiles, 0, 0, psz, 260) >= 0 )
    {
      v29 = (*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 168LL))(a1);
      v30 = 260;
      v31 = psz;
      do
      {
        if ( !*v31 )
          break;
        ++v31;
        --v30;
      }
      while ( v30 );
      if ( v30 )
      {
        v32 = v30;
        v33 = &psz[260 - v30];
        v34 = 0;
        v35 = 0x7FFFFFFF;
        v36 = v29 - (_QWORD)v33;
        do
        {
          if ( !v35 )
            break;
          v37 = *(OLECHAR *)((char *)v33 + v36);
          if ( !v37 )
            break;
          *v33++ = v37;
          --v32;
          --v35;
        }
        while ( v32 );
        if ( !v32 )
        {
          --v33;
          v34 = -2147024774;
        }
        *v33 = 0;
        if ( v34 >= 0 )
        {
          v38 = SysAllocString(psz);
          g_bstrGDFPath = v38;
          if ( v38 )
          {
            if ( SysStringLen(v38)
              && (*(int (__fastcall **)(_QWORD, unsigned __int16 *, unsigned int *))(**(_QWORD **)&pRawInputDevices.usUsagePage
                                                                                   + 48LL))(
                   *(_QWORD *)&pRawInputDevices.usUsagePage,
                   g_bstrGDFPath,
                   &v77) >= 0 )
            {
              v28 = v77 != 0;
            }
          }
        }
      }
    }
    if ( *(_QWORD *)&pRawInputDevices.usUsagePage )
      (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&pRawInputDevices.usUsagePage + 16LL))(*(_QWORD *)&pRawInputDevices.usUsagePage);
    if ( !v28 )
      CleanupEngine(5u);
    v39 = operator new(8u);
    if ( v39 )
    {
      *v39 = 0;
      g_pSecondTimerCallback = v39;
    }
    else
    {
      g_pSecondTimerCallback = 0;
    }
    _set_new_handler((int (*)(unsigned __int64))HandleNewFail);
    _set_new_mode(1);
    g_pInterface = a1;
    v40 = (const unsigned __int16 *)(*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 32LL))(a1);
    g_wszProjectName = LocalizeMessage(v40);
    ModuleFileNameW = GetModuleFileNameW(0, Filename, 0x200u);
    v42 = ModuleFileNameW - 1;
    if ( ModuleFileNameW )
    {
      v43 = &Filename[(int)v42];
      while ( *v43 != 47 && *v43 != 92 )
      {
        v42 = (unsigned int)(v42 - 1);
        --v43;
        if ( (unsigned int)v42 > ModuleFileNameW )
          goto LABEL_55;
      }
      Filename[v42] = 0;
    }
LABEL_55:
    SetCurrentDirectoryW(Filename);
    XmlNode::SetNodeName((XmlNode *)&ErrorXml, L"ErrorLog");
    v44 = operator new(0x18u);
    if ( v44 )
    {
      *v44 = 0;
      v44[1] = 0;
      v44[2] = 16;
      *((_QWORD *)v44 + 2) = 0;
    }
    else
    {
      v44 = 0;
    }
    g_pXmlManager = (XmlManager *)v44;
    CheckAllocation(v44);
    Log(0x10u, 1129, "Engine.cpp", L"Initializing Virtual FS");
    Log(0x10u, 1138, "Engine.cpp", L"Project name localized to: %s", g_wszProjectName);
    OutputDebugStringW(Filename);
    Log(0x10u, 1142, "Engine.cpp", L"Using working directory: %s", Filename);
    Log(0x10u, 1146, "Engine.cpp", L"Initializing GDI+");
    v83 = 1;
    v84 = 0;
    v86 = 0;
    v85 = 1;
    GdiplusStartup(&g_GdiPlusToken, &v83, v87);
    LoadWindowPrefs((int *)&pRawInputDevices, (int *)&v77);
    v45 = (DllFileMgr *)operator new(0x2868u);
    *(_QWORD *)&pRawInputDevices.usUsagePage = v45;
    if ( v45 )
      v46 = DllFileMgr::DllFileMgr(v45, 0);
    else
      v46 = 0;
    qword_1000B10B0 = v46;
    v47 = (const unsigned __int16 *)(**(__int64 (__fastcall ***)(struct IEngineInterface *))a1)(a1);
    Str::Str((Str *)&pRawInputDevices, v47);
    v48 = !DllFileMgr::Open(qword_1000B10B0, (const struct Str *)&pRawInputDevices, g_bDebugEnabled, L"input\\");
    operator delete(Block);
    if ( v48 )
    {
      *(_QWORD *)&pRawInputDevices.usUsagePage = 0;
      pRawInputDevices.hwndTarget = 0;
      Block = 0;
      v49 = (const unsigned __int16 *)*((_QWORD *)Str::Str((Str *)v89, 0x37Cu) + 2);
      v50 = (**(__int64 (__fastcall ***)(struct IEngineInterface *))a1)(a1);
      Str::Format((Str *)&pRawInputDevices, v49, v50);
      operator delete(v90);
      LOBYTE(v75) = 1;
      DialogHelper::ShowMessageBox(0x385u, 0, 1u, 0xFFFEu, 0, (const unsigned __int16 *)Block, v75, v76);
      CleanupEngine(0);
    }
    if ( !CreateGameWindow() )
    {
      Log(0x10u, 1198, "Engine.cpp", L"Window Creation Failed");
      CleanupEngine(0);
    }
    if ( (_BYTE)g_bMediaCenter )
    {
      Log(0x10u, 1211, "Engine.cpp", L"Initializing MCE Dialog");
      DialogHelper::InitMCE(0, v51);
      if ( (_BYTE)g_bMediaCenter )
      {
        Log(0x10u, 1220, "Engine.cpp", L"Registering for raw input, for remote control");
        pRawInputDevices.usUsagePage = 12;
        pRawInputDevices.usUsage = 1;
        pRawInputDevices.dwFlags = 0;
        pRawInputDevices.hwndTarget = g_hWnd;
        if ( !RegisterRawInputDevices(&pRawInputDevices, 1u, 0x10u) )
        {
          LODWORD(ppv) = GetLastError();
          Log(0x10u, 1231, "Engine.cpp", L"Register failed, winerror %d", ppv);
        }
      }
    }
    Log(0x10u, 1237, "Engine.cpp", L"Adding system events");
    Event::RegisterEventType(2, Event_MouseEnter::Create);
    Event::RegisterEventType(4, Event_MouseDown::Create);
    Event::RegisterEventType(5, Event_MouseDoubleClick::Create);
    Event::RegisterEventType(3, Event_MouseLeave::Create);
    Event::RegisterEventType(6, Event_MouseRelease::Create);
    Event::RegisterEventType(7, Event_MouseReleaseOut::Create);
    Event::RegisterEventType(8, Event_MouseStatusBarClick::Create);
    Event::RegisterEventType(9, Event_MouseOuterDown::Create);
    Event::RegisterEventType(10, Event_MouseOuterRelease::Create);
    Event::RegisterEventType(11, Event_MouseGlobalRelease::Create);
    Event::RegisterEventType(1, Event_ButtonClick::Create);
    Event::RegisterEventType(13, Event_AnimationComplete::Create);
    Event::RegisterEventType(12, Event_AnimationFrame::Create);
    Event::RegisterEventType(14, Event_AnimationInt::Create);
    Event::RegisterEventType(15, Event_Timer::Create);
    Event::RegisterEventType(16, Event_FocusCheck::Create);
    Event::RegisterEventType(17, Event_FocusGot::Create);
    Event::RegisterEventType(18, Event_FocusLost::Create);
    Event::RegisterEventType(19, Event_FocusSelect::Create);
    Event::RegisterEventType(20, Event_FocusUnSelect::Create);
    Event::RegisterEventType(21, Event_FocusGetNodeAtDir::Create);
    Event::RegisterEventType(22, Event_FocusGetNextTabNode::Create);
    Event::RegisterEventType(23, Event_InitComplete::Create);
    Event::RegisterEventType(24, Event_DoDefaultAction::Create);
    Event::RegisterEventType(25, Event_DragCheck::Create);
    Event::RegisterEventType(26, Event_DragStart::Create);
    Event::RegisterEventType(27, Event_DragMove::Create);
    Event::RegisterEventType(28, Event_DragEnd::Create);
    Event::RegisterEventType(29, Event_KeyDown::Create);
    Event::RegisterEventType(30, Event_KeyUp::Create);
    Event::RegisterEventType(31, Event_AccessGetParent::Create);
    Event::RegisterEventType(32, Event_AccessGetChildCount::Create);
    Event::RegisterEventType(33, Event_AccessGetChild::Create);
    Event::RegisterEventType(34, Event_TipClose::Create);
    Event::RegisterEventType(37, Event_DpiChange::Create);
    Event::RegisterEventType(35, Event_ControllerKey::Create);
    Log(0x10u, 1280, "Engine.cpp", L"Registering Node Types");
    NodeBase::RegisterNodeType((wchar_t *)L"Button", (struct NodeBase *(*const)(unsigned int *))NodeButton::CreateNode);
    NodeBase::RegisterNodeType((wchar_t *)L"Label", (struct NodeBase *(*const)(unsigned int *))NodeLabel::CreateNode);
    NodeBase::RegisterNodeType((wchar_t *)L"Base", (struct NodeBase *(*const)(unsigned int *))NodeBase::CreateNode);
    memset(&NodeBase::m_RenderLayerNodeCount, 0, 0x18u);
    NodeBase::m_RenderLayerNodeCountInitialized = 1;
    NodeBase::RegisterNodeType((wchar_t *)L"Sprite", (struct NodeBase *(*const)(unsigned int *))NodeSprite::CreateNode);
    NodeBase::RegisterNodeType(
      (wchar_t *)L"Emitter",
      (struct NodeBase *(*const)(unsigned int *))NodeEmitter::CreateNode);
    NodeBase::RegisterNodeType((wchar_t *)L"Shot", (struct NodeBase *(*const)(unsigned int *))NodeShot::CreateNode);
    NodeBase::RegisterNodeType((wchar_t *)L"Number", (struct NodeBase *(*const)(unsigned int *))NodeNumber::CreateNode);
    Log(0x10u, 1291, "Engine.cpp", L"Initializing Timekeeping");
    if ( !Timekeeping::InitializeTimekeeping(v52) )
    {
      Log(0x10u, 1294, "Engine.cpp", L"Failed to initialize timekeeping");
      CleanupEngine(0);
    }
    DialogHelper::m_DialogShutdown = Engine_ResetTimer;
    Log(0x10u, 1304, "Engine.cpp", L"Initializing ResourceManager");
    v53 = (ResourceManager *)operator new(0x80u);
    if ( v53 )
      v54 = ResourceManager::ResourceManager(v53);
    else
      v54 = 0;
    g_pResourceManager = v54;
    CheckAllocation(v54);
    if ( !ResourceManager::Initialize(g_pResourceManager) )
    {
      Log(0x10u, 1308, "Engine.cpp", L"Failed to initialize ResourceManager");
      CleanupEngine(0);
    }
    v82[0] = 0;
    v81 = g_hRenderWindow;
    v82[1] = 32;
    (*(void (__fastcall **)(void *, _QWORD *, char *))(*(_QWORD *)g_pInterface + 24LL))(
      g_pInterface,
      v82,
      (char *)v82 + 4);
    if ( g_bDoubleDPI )
    {
      LODWORD(v82[0]) *= 2;
      HIDWORD(v82[0]) *= 2;
    }
    Log(0x10u, 1331, "Engine.cpp", L"Initializing RenderManager");
    v55 = (RenderManager *)operator new(0xD8u);
    if ( v55 )
      v56 = RenderManager::RenderManager(v55);
    else
      v56 = 0;
    g_pRenderManager = v56;
    CheckAllocation(v56);
    if ( !RenderManager::Initialize(g_pRenderManager, (const struct RenderInitializeOptions *)&v81) )
    {
      Log(0x10u, 1335, "Engine.cpp", L"Failed to initialize RenderManager");
      CleanupEngine(0);
    }
    Log(0x10u, 1342, "Engine.cpp", L"Initializing Audio");
    v57 = operator new(0x38u);
    if ( v57 )
    {
      v57[8] = 0;
      v57[9] = 0;
      v57[10] = 16;
      *((_QWORD *)v57 + 6) = 0;
      *((_QWORD *)v57 + 2) = 0;
      *((_QWORD *)v57 + 3) = 2;
      v57[2] = 100;
      *v57 = 100;
      v57[1] = 100;
    }
    else
    {
      v57 = 0;
    }
    g_pAudio = (Audio *)v57;
    CheckAllocation(v57);
    if ( !Audio::Initialize(g_pAudio) )
    {
      Log(0x10u, 1346, "Engine.cpp", L"Failed to initialize Audio");
      CleanupEngine(0);
    }
    Log(0x10u, 1354, "Engine.cpp", L"Initializing XNA Common Controller");
    v58 = (CommonControllerThread *)operator new(0x90u);
    if ( v58 )
      v59 = CommonControllerThread::CommonControllerThread(v58, g_hWnd, (bool)g_bMediaCenter, 0);
    else
      v59 = 0;
    g_pCommonController = v59;
    if ( *((_QWORD *)v59 + 1) )
      Thread::End(v59);
    *((_BYTE *)v59 + 20) = 1;
    *((_QWORD *)v59 + 1) = CreateThread(0, 0, sThreadProc, v59, 0, (LPDWORD)v59 + 4);
    Log(0x10u, 1361, "Engine.cpp", L"Initializing Timer");
    v60 = (void **)operator new(0x50u);
    if ( v60 )
    {
      *v60 = malloc(0x40u);
      v60[1] = malloc(0x200u);
      *((_DWORD *)v60 + 4) = 0;
      *((_DWORD *)v60 + 5) = 16;
      v60[3] = malloc(0x40u);
      v60[4] = malloc(0x40u);
      *((_DWORD *)v60 + 10) = 0;
      *((_DWORD *)v60 + 11) = 16;
      v60[6] = malloc(0x40u);
      v60[7] = malloc(0x200u);
      *((_DWORD *)v60 + 16) = 0;
      *((_DWORD *)v60 + 17) = 16;
    }
    else
    {
      v60 = 0;
    }
    g_pTimer = (Timer *)v60;
    CheckAllocation(v60);
    Log(0x10u, 1372, "Engine.cpp", L"Loading Fonts");
    Xml = XmlManager::GetXml(g_pXmlManager, L"xml\\Fonts.xml");
    if ( Xml )
    {
      v62 = XmlNode::XPathElementSearch(Xml, L"/Font", &v77);
      LODWORD(ppva) = v77;
      Log(0x10u, 1383, "Engine.cpp", L"%d Fonts Found", ppva);
      v63 = 0;
      if ( v77 )
      {
        v64 = v62;
        do
        {
          NodeValue = XmlNode::GetNodeValue(*v64);
          Log(0x10u, 1388, "Engine.cpp", L"Loading Font: %s", NodeValue);
          if ( AddFontResourceW(NodeValue) )
          {
            v66 = LoadedFonts + 1;
            LoadedFonts = v66;
            v67 = dword_1000ACE3C;
            if ( v66 <= dword_1000ACE3C )
            {
              v69 = qword_1000ACE48;
              goto LABEL_106;
            }
            dword_1000ACE3C += dword_1000ACE40;
            v68 = realloc(qword_1000ACE48, 8LL * (unsigned int)(dword_1000ACE40 + v67));
            v69 = v68;
            if ( v68 )
            {
              qword_1000ACE48 = v68;
              v66 = LoadedFonts;
LABEL_106:
              v69[v66 - 1] = NodeValue;
              goto LABEL_107;
            }
            CheckAllocation(0);
          }
          else
          {
            Log(0x10u, 1412, "Engine.cpp", L"Couldn't add font: %s", NodeValue);
            operator delete(NodeValue);
          }
LABEL_107:
          ++v63;
          ++v64;
        }
        while ( v63 < v77 );
      }
      operator delete(v62);
    }
    else
    {
      Log(0x10u, 1426, "Engine.cpp", L"No Font Xml Found");
    }
    Log(0x10u, 1431, "Engine.cpp", L"Registering for session notification");
    WTSRegisterSessionNotification(g_hWnd, 0);
    v70 = XmlManager::GetXml(g_pXmlManager, L"engine.xml");
    g_bInInitializer = 1;
    Log(0x10u, 1439, "Engine.cpp", L"Engine Initialization Complete: Initializing Game Code.");
    if ( !(*(unsigned __int8 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 96LL))(a1) )
    {
      Log(0x10u, 1442, "Engine.cpp", L"Game code initialization failed.");
      CleanupEngine(0);
    }
    g_bInInitializer = 0;
    if ( v70 )
      g_bFocusPause = (int)XmlNode::GetXmlInt(v70, L"/PauseOnLostFocus", -1) > 0;
    Engine_LoadingComplete();
    g_Accelerator = 0;
    if ( (*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 80LL))(a1) )
    {
      v71 = (const WCHAR *)(*(__int64 (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 80LL))(a1);
      v72 = GetModuleHandleW(0);
      g_Accelerator = LoadAcceleratorsW(v72, v71);
    }
    g_bInitializing = 0;
    ((void (__fastcall *)(unsigned __int64 *))v87[0])(&g_GdiPlusToken);
    while ( 1 )
    {
      while ( !PeekMessageW(&Msg, 0, 0, 0, 0) )
        RunEngine();
      if ( !GetMessageW(&Msg, 0, 0, 0) )
        break;
      if ( !g_Accelerator || !TranslateAcceleratorW(g_hWnd, g_Accelerator, &Msg) )
      {
        TranslateMessage(&Msg);
        DispatchMessageW(&Msg);
      }
    }
    ((void (__fastcall *)(unsigned __int64))v87[1])(g_GdiPlusToken);
    (*(void (__fastcall **)(struct IEngineInterface *))(*(_QWORD *)a1 + 144LL))(a1);
    CleanupEngine(0);
  }
  return 0;
}
