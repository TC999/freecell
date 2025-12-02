char __fastcall CardTable::SetCardDeck(CardTable *this, const unsigned __int16 *a2)
{
  __int64 v2; // rax
  unsigned int v3; // ebx
  __int64 i; // rbp
  XmlNode *v7; // rdi
  const unsigned __int16 *v8; // rax
  int v9; // r8d
  int v10; // edx
  int v12; // ebx
  __int64 j; // rdi
  void *Block; // [rsp+20h] [rbp-138h] BYREF
  unsigned __int16 v15[128]; // [rsp+30h] [rbp-128h] BYREF

  v2 = *((_QWORD *)this + 43);
  v3 = 0;
  if ( !*(_DWORD *)(v2 + 24) )
    return 0;
  for ( i = 0; ; i += 8 )
  {
    if ( v3 < *(_DWORD *)(v2 + 24) )
      v7 = *(XmlNode **)(*(_QWORD *)(v2 + 40) + i);
    else
      v7 = 0;
    if ( !XmlNode::MatchName(v7, L"Deck") )
      goto LABEL_14;
    Block = XmlNode::XPathAttributeSearchSingle(v7, L"/@Name");
    if ( !Block )
      goto LABEL_14;
    LocalizeDeckOrBackgroundName((const unsigned __int16 **)&Block, 0);
    if ( !Block )
      goto LABEL_14;
    v8 = a2;
    do
    {
      v9 = *(const unsigned __int16 *)((char *)v8 + (_BYTE *)Block - (_BYTE *)a2);
      v10 = *v8 - v9;
      if ( v10 )
        break;
      ++v8;
    }
    while ( v9 );
    if ( !v10 )
      break;
    operator delete(Block);
LABEL_14:
    v2 = *((_QWORD *)this + 43);
    if ( ++v3 >= *(_DWORD *)(v2 + 24) )
      return 0;
  }
  operator delete(Block);
  if ( !XmlNode::GetNodeValue(v7, v15, 0x80u) )
  {
    Log(0x10001u, L"CardTable::SetCardDeck() - Unable to get the filename.");
    return 0;
  }
  Str::operator=((__int64)this + 288, a2);
  Str::operator=((__int64)this + 312, v15);
  v12 = 0;
  if ( !*((_DWORD *)this + 34) )
    return 1;
  for ( j = 0; Card::SetCardSprite(*(Card **)(j + *((_QWORD *)this + 16)), *((const unsigned __int16 **)this + 41)); j += 8 )
  {
    if ( (unsigned int)++v12 >= *((_DWORD *)this + 34) )
      return 1;
  }
  Log(0x10001u, L"CardTable::SetCardDeck() - Unable to set the card sprite.");
  return 0;
}
