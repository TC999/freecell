char __fastcall FreeCellGameState::FromXml(FreeCellGameState *this, const struct XmlNode *a2)
{
  XmlNode *v4; // rax
  XmlNode *v5; // rdi
  const wchar_t *v6; // r9
  const wchar_t *v7; // r8
  unsigned int XmlUInt; // eax

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellGameState::FromXml() - NULL source xml.");
    return 0;
  }
  v4 = XmlNode::XPathElementSearchSingle(a2, L"/GameState");
  v5 = v4;
  if ( !v4 )
  {
    v6 = L"Unable to get the game node.";
    v7 = L"FreeCellGameState::ToXml";
LABEL_6:
    Log(0x10000001u, L"%s() - %s", v7, v6);
    return 0;
  }
  XmlUInt = XmlNode::GetXmlUInt(v4, L"/Version", 0xFFFFFFFF);
  *((_DWORD *)this + 2) = XmlUInt;
  if ( XmlUInt != 3 )
  {
    v6 = L"Invalid version in game state data";
    v7 = L"FreeCellGameState::FromXml";
    goto LABEL_6;
  }
  *((_DWORD *)this + 3) = XmlNode::GetXmlInt(v5, L"/GameNumber", 0);
  return 1;
}
