void **__fastcall SerializableData::AppendBool(struct XmlNode *a1, const unsigned __int16 *a2, char a3)
{
  void **result; // rax
  void **v5; // rbx
  const unsigned __int16 *v6; // rdx

  result = SerializableData::AppendEmptyNode(a1, a2);
  v5 = result;
  if ( result )
  {
    v6 = L"false";
    if ( a3 == 1 )
      v6 = L"true";
    XmlNode::SetNodeValue(result, v6);
    return v5;
  }
  return result;
}
