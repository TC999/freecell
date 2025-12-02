char __fastcall Card::FromXml(NodeBase **this, const struct XmlNode *a2)
{
  int XmlInt; // eax
  int v6; // eax
  unsigned int XmlUInt; // eax
  char XmlBool; // al
  char v9; // al

  XmlInt = XmlNode::GetXmlInt(a2, L"/X", -954380);
  if ( XmlInt == -954380 )
  {
    Log(0x10001u, L"Card::FromXml() - Failed to get the x position for the node.");
    return 0;
  }
  NodeBase::SetPosition(this[8], XmlInt, *((_DWORD *)this[8] + 3));
  v6 = XmlNode::GetXmlInt(a2, L"/Y", -954380);
  if ( v6 == -954380 )
  {
    Log(0x10001u, L"Card::FromXml() - Failed to get the y position for the node.");
    return 0;
  }
  NodeBase::SetPosition(this[8], *((_DWORD *)this[8] + 2), v6);
  if ( !XmlNode::GetXmlString(a2, &word_1000B1F30, 0x80u, L"/Name") )
  {
    Log(0x10001u, L"Card::FromXml() - Failed to get the card name.");
    return 0;
  }
  Card::SetName((Card *)this, &word_1000B1F30);
  XmlUInt = XmlNode::GetXmlUInt(a2, L"/Type", -954380);
  if ( XmlUInt == -954380 )
  {
    Log(0x10001u, L"Card::FromXml() - Failed to get the card type.");
    return 0;
  }
  *((_DWORD *)this + 2) = XmlUInt;
  XmlBool = XmlNode::GetXmlBool(a2, L"/FaceUp", 0);
  Card::SetFaceUp((Card *)this, XmlBool, 0);
  v9 = XmlNode::GetXmlBool(a2, L"/Enabled", 1);
  Card::SetEnabled((Card *)this, v9);
  Card::UpdateCardFace((Card *)this);
  return 1;
}
