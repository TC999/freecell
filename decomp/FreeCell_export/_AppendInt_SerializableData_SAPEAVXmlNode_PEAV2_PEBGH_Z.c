void **__fastcall SerializableData::AppendInt(struct XmlNode *a1, const unsigned __int16 *a2, unsigned int a3)
{
  void **result; // rax
  void **v5; // rbx

  result = SerializableData::AppendEmptyNode(a1, a2);
  v5 = result;
  if ( result )
  {
    swprintf_s(Buffer, 0x100u, L"%d", a3);
    XmlNode::SetNodeValue(v5, Buffer);
    return v5;
  }
  return result;
}
