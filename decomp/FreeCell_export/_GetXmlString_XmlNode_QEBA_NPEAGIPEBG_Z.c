bool __fastcall XmlNode::GetXmlString(XmlNode *this, unsigned __int16 *a2, unsigned int a3, const unsigned __int16 *a4)
{
  XmlNode *v8; // rax

  memset(a2, 0, 2LL * a3);
  v8 = XmlNode::XPathElementSearchSingle(this, a4);
  return v8 && XmlNode::GetNodeValue(v8, a2, a3);
}
