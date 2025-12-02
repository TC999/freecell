void **__fastcall SerializableData::AppendUInt(struct XmlNode *a1, const unsigned __int16 *a2, unsigned int a3)
{
  void **result; // rax
  void **v5; // rbx

  result = SerializableData::AppendEmptyNode(a1, a2);
  v5 = result;
  if ( result )
  {
    swprintf_s(word_1000B2030, 0x100u, L"%u", a3);
    XmlNode::SetNodeValue(v5, word_1000B2030);
    return v5;
  }
  return result;
}
