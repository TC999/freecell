// Hidden C++ exception states: #wind=4
__int64 __fastcall LoseDialog::DialogProc(DialogHelper *a1, int a2, __int64 a3, __int64 a4)
{
  int v4; // edx
  HWND v6; // rdx
  __int64 v7; // rdx
  __int64 v8; // rsi
  unsigned int v9; // ebx
  HMODULE ModuleHandleW; // rax
  int lpDirectory; // [rsp+20h] [rbp-1078h]
  int lpDirectoryb; // [rsp+20h] [rbp-1078h]
  int lpDirectorya; // [rsp+20h] [rbp-1078h]
  bool nShowCmd; // [rsp+28h] [rbp-1070h]
  bool nShowCmdb; // [rsp+28h] [rbp-1070h]
  bool nShowCmda; // [rsp+28h] [rbp-1070h]
  WCHAR Buffer[2088]; // [rsp+30h] [rbp-1068h] BYREF

  v4 = a2 - 78;
  if ( v4 )
  {
    v6 = (HWND)(unsigned int)(v4 - 194);
    if ( !(_DWORD)v6 )
    {
      DialogHelper::CenterDialog((HWND)a1, v6);
      v8 = *((_QWORD *)g_pFreeCellGame + 10);
      LOBYTE(lpDirectory) = 1;
      DialogHelper::SetStaticTextI(
        a1,
        (HWND)0x414,
        (unsigned int)L"|44689|FREECELL_STAT|Games played: %1!d!// Shows the number of games played.",
        (const unsigned __int16 *)*(unsigned int *)(v8 + 12),
        lpDirectory,
        nShowCmd);
      LOBYTE(lpDirectoryb) = 1;
      DialogHelper::SetStaticTextI(
        a1,
        (HWND)0x416,
        (unsigned int)L"|43090|FREECELL_STAT|Games won: %1!d!// Used to display the number of games won.",
        (const unsigned __int16 *)*(unsigned int *)(v8 + 16),
        lpDirectoryb,
        nShowCmdb);
      v9 = 0;
      if ( *(_DWORD *)(v8 + 12) )
        v9 = (unsigned int)(100 * *(_DWORD *)(v8 + 16)) / *(_DWORD *)(v8 + 12);
      LOBYTE(lpDirectorya) = 1;
      DialogHelper::SetStaticTextI(
        a1,
        (HWND)0x418,
        (unsigned int)L"|63341|FREECELL_STAT|Win percentage: %1!d!%%// Used to display the percentage of games won.",
        (const unsigned __int16 *)v9,
        lpDirectorya,
        nShowCmda);
      return 1;
    }
    if ( (_DWORD)v6 == 1 )
    {
      switch ( (unsigned __int16)a3 )
      {
        case 2u:
          v7 = 1041;
          break;
        case 0x407u:
          v7 = 1031;
          break;
        case 0x40Cu:
          v7 = 1036;
          break;
        default:
          return 1;
      }
      DialogHelper::DismissDialog((HWND)a1, (HWND)v7, a3);
      return 1;
    }
  }
  else if ( a3 == 1052 && a4 && (*(_DWORD *)(a4 + 16) == -4 || *(_DWORD *)(a4 + 16) == -2) )
  {
    ModuleHandleW = GetModuleHandleW(0);
    if ( LoadStringW(ModuleHandleW, 0x88u, Buffer, 2084) > 0 )
    {
      ShellExecuteW(0, L"open", Buffer, 0, 0, 1);
      return 1;
    }
  }
  return 0;
}
