char __fastcall FreeCellGame::LoadGeneralData(FreeCellGame *this)
{
  unsigned int v2; // r8d
  XmlNode *XMLFile; // rax
  XmlNode *v4; // rbx
  const struct XmlNode *v5; // rdx

  FreeCellGame::SetAnimationEnabled(this, 1);
  XMLFile = Stash::LoadXMLFile((Stash *)g_SETTINGS_SAVE_FILENAME, (const unsigned __int16 *)0x1C, v2);
  *((_BYTE *)this + 361) = 0;
  v4 = XMLFile;
  if ( XMLFile )
  {
    v5 = XmlNode::XPathElementSearchSingle(XMLFile, L"/Stats");
    if ( v5
      && (***((unsigned __int8 (__fastcall ****)(_QWORD, const struct XmlNode *))this + 10))(*((_QWORD *)this + 10), v5) )
    {
      if ( (***((unsigned __int8 (__fastcall ****)(_QWORD, XmlNode *))this + 11))(*((_QWORD *)this + 11), v4) )
      {
        XmlNode::~XmlNode(v4);
        operator delete(v4);
        FreeCellGame::SetSoundEnabled(this, *(_BYTE *)(*((_QWORD *)this + 11) + 29LL));
        FreeCellGame::SetAnimationEnabled(this, *(_BYTE *)(*((_QWORD *)this + 11) + 31LL));
        *((_BYTE *)this + 361) = 1;
        return 1;
      }
      Log(0x10000001u, L"FreeCellGame::LoadGeneralData() - Unable to load the options in %s", g_SETTINGS_SAVE_FILENAME);
    }
    else
    {
      Log(0x10000001u, L"FreeCellGame::LoadGeneralData() - Unable to load the stats in %s", g_SETTINGS_SAVE_FILENAME);
    }
    XmlNode::~XmlNode(v4);
    operator delete(v4);
  }
  else
  {
    Log(0x10000000u, L"FreeCellGame::LoadGeneralData() - Unable to load the settings file %s", g_SETTINGS_SAVE_FILENAME);
  }
  return 0;
}
