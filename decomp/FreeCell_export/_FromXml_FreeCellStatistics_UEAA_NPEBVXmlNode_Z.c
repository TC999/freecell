char __fastcall FreeCellStatistics::FromXml(FreeCellStatistics *this, const struct XmlNode *a2)
{
  unsigned int XmlUInt; // eax

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellStatistics::FromXml() - NULL source xml.");
    return 0;
  }
  XmlUInt = XmlNode::GetXmlUInt(a2, L"/Version", 0xFFFFFFFF);
  *((_DWORD *)this + 2) = XmlUInt;
  if ( XmlUInt )
  {
    Log(0x10000001u, L"%s() - %s", L"FreeCellStatistics::FromXml", L"Invalid version in statistics data");
    return 0;
  }
  *((_DWORD *)this + 3) = XmlNode::GetXmlUInt(a2, L"/GamesPlayed", 0);
  *((_DWORD *)this + 4) = XmlNode::GetXmlUInt(a2, L"/GamesWon", 0);
  *((_DWORD *)this + 5) = XmlNode::GetXmlUInt(a2, L"/MaxWinStreakLength", 0);
  *((_DWORD *)this + 6) = XmlNode::GetXmlUInt(a2, L"/MaxLoseStreakLength", 0);
  *((_DWORD *)this + 7) = XmlNode::GetXmlUInt(a2, L"/CurrStreakLength", 0);
  *((_BYTE *)this + 32) = XmlNode::GetXmlBool(a2, L"/WonlastGame", 0);
  return 1;
}
