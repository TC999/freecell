int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  struct IEngineInterface *v5; // rbx
  BOOL v6; // edi
  unsigned __int16 *v7; // [rsp+30h] [rbp-18h]
  bool v8; // [rsp+38h] [rbp-10h]
  DWORD pdwValue; // [rsp+50h] [rbp+8h] BYREF

  g_hInstance = hInstance;
  HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
  if ( GetSystemMetrics(67) )
  {
    LOBYTE(v7) = 1;
    DialogHelper::ShowMessageBox(0x385u, 0x374u, 1u, 0xFFFEu, 0, 0, v7, v8);
    return 1;
  }
  else
  {
    pdwValue = 1;
    SLGetWindowsInformationDWORD(L"Shell-InBoxGames-FreeCell-EnableGame", &pdwValue);
    v5 = (struct IEngineInterface *)operator new(8u);
    if ( v5 )
      *(_QWORD *)v5 = &EngineHandler::`vftable';
    else
      v5 = 0;
    v6 = !InitializeEngine(v5, 0);
    if ( v5 )
    {
      *(_QWORD *)v5 = &IEngineInterface::`vftable';
      operator delete(v5);
    }
    return v6;
  }
}
