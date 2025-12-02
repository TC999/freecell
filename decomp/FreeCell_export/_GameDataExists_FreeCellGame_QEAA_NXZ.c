char __fastcall FreeCellGame::GameDataExists(FreeCellGame *this)
{
  char v1; // bl
  __int64 SpecialFolderFile; // rax

  v1 = 1;
  SpecialFolderFile = CreateSpecialFolderFile((wchar_t *)L"FreeCell.FreeCellSave-ms", 1, 0x28u, 1, 101);
  if ( SpecialFolderFile == -1 )
    return 0;
  CloseSpecialFolderFile(SpecialFolderFile, 0x28u, 1);
  return v1;
}
