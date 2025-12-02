char __fastcall FreeCellGame::SaveGeneralData(FreeCellGame *this)
{
  XmlNode *v2; // rax
  XmlNode *v3; // rbx
  struct XmlNode *appended; // rax
  __int64 v5; // rcx
  bool v7; // [rsp+20h] [rbp-8h]

  v2 = (XmlNode *)operator new(0x98u);
  if ( v2 )
    v3 = XmlNode::XmlNode(v2);
  else
    v3 = 0;
  XmlNode::SetNodeName(v3, L"Root");
  appended = SerializableData::AppendEmptyNode(v3, L"Stats");
  v5 = *((_QWORD *)this + 10);
  if ( !v5
    || !appended
    || !(*(unsigned __int8 (__fastcall **)(__int64, struct XmlNode *))(*(_QWORD *)v5 + 8LL))(v5, appended) )
  {
    Log(0x10000001u, L"FreeCellGame::SaveGeneralData() - Unable to save the stats to %s", g_SETTINGS_SAVE_FILENAME);
    goto LABEL_15;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(_QWORD, XmlNode *))(**((_QWORD **)this + 11) + 8LL))(
          *((_QWORD *)this + 11),
          v3) )
  {
    Log(0x10000001u, L"FreeCellGame::SaveGeneralData() - Unable to save the options to %s", g_SETTINGS_SAVE_FILENAME);
LABEL_15:
    if ( v3 )
    {
      XmlNode::~XmlNode(v3);
      operator delete(v3);
    }
    return 0;
  }
  if ( !Stash::SaveXMLFile(g_SETTINGS_SAVE_FILENAME, v3, (struct XmlNode *)0x1C, 1, v7) )
  {
    Log(0x10000001u, L"FreeCellGame::SaveGeneralData() - Unable to save the settings to %s", g_SETTINGS_SAVE_FILENAME);
    goto LABEL_15;
  }
  FreeCellGame::SaveGameExplorerStatistics(this);
  if ( v3 )
  {
    XmlNode::~XmlNode(v3);
    operator delete(v3);
  }
  return 1;
}
