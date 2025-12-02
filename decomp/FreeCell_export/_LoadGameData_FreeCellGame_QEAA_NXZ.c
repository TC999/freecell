char __fastcall FreeCellGame::LoadGameData(FreeCellGame *this)
{
  char v2; // bl
  unsigned int v3; // r8d
  struct XmlNode *XMLFile; // rax
  XmlNode *v5; // rbx
  wchar_t Destination[264]; // [rsp+20h] [rbp-228h] BYREF

  v2 = 0;
  memset(Destination, 0, 0x104u);
  if ( GetCommandLineFilename(Destination, 0x104u) )
  {
    if ( wcschr(Destination, 0x5Cu) || wcschr(Destination, 0x2Fu) || wcschr(Destination, 0x3Au) )
      v2 = 1;
  }
  else
  {
    wcscpy_s(Destination, 0x104u, L"FreeCell.FreeCellSave-ms");
  }
  XMLFile = Stash::LoadXMLFile((Stash *)Destination, v2 == 0 ? (const unsigned __int16 *)0x28 : 0, v3);
  v5 = XMLFile;
  if ( !XMLFile )
  {
    Log(
      0x10000000u,
      L"FreeCellGame::LoadStateData() - Unable to load the game state file %s",
      L"FreeCell.FreeCellSave-ms");
    return 0;
  }
  if ( !(***((unsigned __int8 (__fastcall ****)(_QWORD, struct XmlNode *))this + 12))(*((_QWORD *)this + 12), XMLFile) )
  {
    Log(
      0x10000001u,
      L"FreeCellGame::LoadStateData() - Unable to load the game state in %s",
      L"FreeCell.FreeCellSave-ms");
LABEL_12:
    XmlNode::~XmlNode(v5);
    operator delete(v5);
    return 0;
  }
  CardTable::Reset(*((CardTable **)this + 22));
  if ( !CardTable::FromXml(*((CardTable **)this + 22), v5, 0) )
  {
    Log(
      0x10000001u,
      L"FreeCellGame::LoadStateData() - Unable to load the card table in %s",
      L"FreeCell.FreeCellSave-ms");
    goto LABEL_12;
  }
  CardTable::UpdateAccessibility(*((CardTable **)this + 22));
  XmlNode::~XmlNode(v5);
  operator delete(v5);
  *((_BYTE *)this + 363) = 1;
  *((_BYTE *)this + 364) = 1;
  *((_BYTE *)this + 376) = 1;
  return 1;
}
