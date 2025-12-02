bool __fastcall FreeCellGame::RemoveGameData(FreeCellGame *this)
{
  const WCHAR *v1; // rax
  unsigned int i; // ecx
  int v3; // r11d
  WCHAR Buffer[264]; // [rsp+30h] [rbp-438h] BYREF
  WCHAR PathName[264]; // [rsp+240h] [rbp-228h] BYREF

  v1 = L"FreeCell.FreeCellSave-ms";
  for ( i = 0; i < 0x18; ++i )
  {
    if ( *v1 == 58 )
    {
      Log(0x80u, L"FileNames cannot have colons in them: %s", L"FreeCell.FreeCellSave-ms");
      goto LABEL_11;
    }
    ++v1;
  }
  memset(PathName, 0, 0x104u);
  SHGetFolderPathW(0, 40, 0, 0, PathName);
  memset(Buffer, 0, 0x104u);
  GetCurrentDirectoryW(0x104u, Buffer);
  SetCurrentDirectoryW(PathName);
  if ( SetCurrentDirectoryW(L"Saved Games")
    && SetCurrentDirectoryW(L"Microsoft Games")
    && SetCurrentDirectoryW(g_wszProjectName)
    && DeleteFileW(L"FreeCell.FreeCellSave-ms") )
  {
    SetCurrentDirectoryW(Buffer);
    v3 = 1;
    return v3 == 1;
  }
  SetCurrentDirectoryW(Buffer);
LABEL_11:
  v3 = 0;
  return v3 == 1;
}
