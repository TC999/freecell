void **__fastcall SerializableData::AppendEmptyNode(struct XmlNode *this, const unsigned __int16 *a2)
{
  void **v2; // rbx
  XmlNode *v5; // rax

  v2 = 0;
  if ( !a2 || !this )
    return 0;
  v5 = (XmlNode *)operator new(0x98u);
  if ( v5 )
    v2 = (void **)XmlNode::XmlNode(v5);
  XmlNode::SetNodeName(v2, a2);
  XmlNode::InsertNode(this, (struct XmlNode *)v2);
  return v2;
}
