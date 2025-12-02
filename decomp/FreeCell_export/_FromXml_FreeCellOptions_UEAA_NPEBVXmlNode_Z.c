char __fastcall FreeCellOptions::FromXml(FreeCellOptions *this, const struct XmlNode *a2)
{
  XmlNode *v4; // rax
  XmlNode *v5; // rbx
  const wchar_t *v6; // r9
  const wchar_t *v7; // r8
  unsigned int XmlUInt; // eax
  bool XmlBool; // al
  bool v10; // zf
  int v11; // eax
  int v12; // eax

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellOptions::FromXml() - NULL source xml.");
    return 0;
  }
  v4 = XmlNode::XPathElementSearchSingle(a2, L"/Options");
  v5 = v4;
  if ( !v4 )
  {
    v6 = L"Unable to get the options node.";
    v7 = L"FreeCellOptions::ToXml";
LABEL_6:
    Log(0x10000001u, L"%s() - %s", v7, v6);
    return 0;
  }
  XmlUInt = XmlNode::GetXmlUInt(v4, L"/Version", 0xFFFFFFFF);
  *((_DWORD *)this + 2) = XmlUInt;
  if ( XmlUInt != 2 )
  {
    v6 = L"Invalid version in options data";
    v7 = L"FreeCellOptions::FromXml";
    goto LABEL_6;
  }
  *((_BYTE *)this + 29) = XmlNode::GetXmlBool(v5, L"/PlaySounds", 1);
  *((_BYTE *)this + 31) = XmlNode::GetXmlBool(v5, L"/PlayAnimations", 1);
  *((_BYTE *)this + 12) = XmlNode::GetXmlBool(v5, L"/RandomAppearance", 0);
  *((_BYTE *)this + 13) = XmlNode::GetXmlBool(v5, L"/AutoLoad", 0);
  *((_BYTE *)this + 14) = XmlNode::GetXmlBool(v5, L"/TurnOffTips", 0);
  *((_BYTE *)this + 15) = XmlNode::GetXmlBool(v5, L"/AutoSaveGameOnExit", 0);
  XmlBool = XmlNode::GetXmlBool(v5, L"/FirstPlay", 1);
  v10 = *((_BYTE *)this + 12) == 0;
  *((_BYTE *)this + 16) = XmlBool;
  if ( v10 )
  {
    v11 = XmlNode::GetXmlUInt(v5, L"/CurrDeckSkin", 0);
    FreeCellGame::SetCurrentDeckSkin(g_pFreeCellGame, v11);
    v12 = XmlNode::GetXmlUInt(v5, L"/CurrBackground", 0);
    FreeCellGame::SetCurrentBackground(g_pFreeCellGame, v12);
  }
  else
  {
    FreeCellGame::ChooseNewRandomAppearance(g_pFreeCellGame);
  }
  return 1;
}
