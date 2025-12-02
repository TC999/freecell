void __fastcall FreeCellGame::OnGameStart(FreeCellGame *this)
{
  const WCHAR *CommandLineW; // rax
  LPWSTR *v3; // rax
  int v4; // r8d
  bool v5; // zf
  _WORD **v6; // rdx
  _WORD *v7; // rsi
  const wchar_t *v8; // rdi
  __int64 v9; // rcx
  HWND v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rdx
  int v13; // edx
  int v14; // edx
  __int64 v15; // rax
  unsigned __int16 *v16; // [rsp+30h] [rbp-18h]
  int pNumArgs; // [rsp+50h] [rbp+8h] BYREF

  if ( !FreeCellGame::GameDataExists(this) && !GetCommandLineFilename(0, 0) )
    goto LABEL_17;
  CommandLineW = GetCommandLineW();
  pNumArgs = 0;
  v3 = CommandLineToArgvW(CommandLineW, &pNumArgs);
  v4 = 1;
  v5 = pNumArgs == 1;
  if ( pNumArgs > 1 )
  {
    v6 = v3 + 1;
    while ( 1 )
    {
      v7 = *v6;
      v8 = L"-newgame";
      v9 = 9;
      do
      {
        if ( !v9 )
          break;
        v5 = *v7++ == *v8++;
        --v9;
      }
      while ( v5 );
      if ( v5 )
        break;
      ++v4;
      ++v6;
      v5 = v4 == pNumArgs;
      if ( v4 >= pNumArgs )
        goto LABEL_10;
    }
    LocalFree(v3);
    goto LABEL_17;
  }
LABEL_10:
  LocalFree(v3);
  if ( !*(_BYTE *)(*((_QWORD *)this + 11) + 13LL) && !GetCommandLineFilename(0, 0) )
  {
    FreeCellTaskDialogs::StartLoadSaveGameDialog((FreeCellTaskDialogs *)g_hWnd, v10);
    goto LABEL_19;
  }
  if ( !FreeCellGame::LoadGameData(this) )
  {
    LOBYTE(v16) = 1;
    DialogHelper::ShowMessageBox(0x1784u, 0x1785u, 1, (const unsigned __int16 *)0xFFFF, 0, 0, v16);
    FreeCellGame::RemoveGameData(this);
LABEL_17:
    FreeCellGame::SetRandomGameNumber(this);
    v11 = *(_QWORD *)this;
    v12 = *((unsigned int *)this + 2);
    *((_BYTE *)this + 381) = 1;
    (*(void (__fastcall **)(FreeCellGame *, __int64))(v11 + 16))(this, v12);
    v13 = *((_DWORD *)this + 2);
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 3) = v13;
    goto LABEL_18;
  }
  (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)this + 16LL))(this, *((unsigned int *)this + 2));
  *((_DWORD *)this + 3) = *((_DWORD *)this + 2);
  *((_DWORD *)this + 2) = 2;
LABEL_18:
  (*(void (__fastcall **)(FreeCellGame *))(*(_QWORD *)this + 8LL))(this);
LABEL_19:
  if ( *((_DWORD *)this + 2) == 5 )
  {
    (*(void (__fastcall **)(FreeCellGame *))(*(_QWORD *)this + 16LL))(this);
    v14 = *((_DWORD *)this + 2);
    v15 = *(_QWORD *)this;
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 3) = v14;
    (*(void (__fastcall **)(FreeCellGame *, _QWORD))(v15 + 8))(this, 0);
  }
}
