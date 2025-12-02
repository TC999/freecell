__int64 __fastcall CardTable::GetBackgroundList(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  unsigned int v3; // ebx
  __int64 v6; // rdi
  XmlNode *v7; // rsi
  const unsigned __int16 *v8; // rax
  const unsigned __int16 *v9; // [rsp+40h] [rbp+8h] BYREF

  result = *(_QWORD *)(a1 + 336);
  v3 = 0;
  if ( *(_DWORD *)(result + 24) )
  {
    v6 = 0;
    do
    {
      v7 = *(XmlNode **)(v6 + *(_QWORD *)(result + 40));
      if ( XmlNode::MatchName(v7, L"Background") )
      {
        v8 = XmlNode::XPathAttributeSearchSingle(v7, L"/@Name");
        v9 = v8;
        if ( v8 )
        {
          LocalizeDeckOrBackgroundName(&v9, 0);
          v8 = v9;
        }
        Array<IEventListener *>::Add(a2, (__int64)v8);
      }
      result = *(_QWORD *)(a1 + 336);
      ++v3;
      v6 += 8;
    }
    while ( v3 < *(_DWORD *)(result + 24) );
  }
  return result;
}
