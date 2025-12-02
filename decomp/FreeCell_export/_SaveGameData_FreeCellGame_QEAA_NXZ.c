char __fastcall FreeCellGame::SaveGameData(FreeCellGame *this)
{
  XmlNode *v2; // rax
  XmlNode *v3; // rbx
  bool v5; // [rsp+20h] [rbp-8h]

  v2 = (XmlNode *)operator new(0x98u);
  if ( v2 )
    v3 = XmlNode::XmlNode(v2);
  else
    v3 = 0;
  XmlNode::SetNodeName(v3, L"Root");
  if ( !(*(unsigned __int8 (__fastcall **)(_QWORD, XmlNode *))(**((_QWORD **)this + 12) + 8LL))(
          *((_QWORD *)this + 12),
          v3) )
  {
    Log(
      0x10000001u,
      L"FreeCellGame::SaveStateData() - Unable to load the game state in %s",
      L"FreeCell.FreeCellSave-ms");
LABEL_6:
    if ( v3 )
    {
      XmlNode::~XmlNode(v3);
      operator delete(v3);
    }
    return 0;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, XmlNode *))(*(_QWORD *)(*((_QWORD *)this + 22) + 8LL) + 8LL))(
          *((_QWORD *)this + 22) + 8LL,
          v3) )
  {
    Log(
      0x10000001u,
      L"FreeCellGame::SaveStateData() - Unable to load the card table in %s",
      L"FreeCell.FreeCellSave-ms");
    goto LABEL_6;
  }
  if ( !Stash::SaveXMLFile((wchar_t *)L"FreeCell.FreeCellSave-ms", v3, (struct XmlNode *)0x28, 0, v5) )
  {
    Log(
      0x10000001u,
      L"FreeCellGame::SaveGeneralData() - Unable to save the settings to %s",
      L"FreeCell.FreeCellSave-ms");
    goto LABEL_6;
  }
  if ( v3 )
  {
    XmlNode::~XmlNode(v3);
    operator delete(v3);
  }
  return 1;
}
