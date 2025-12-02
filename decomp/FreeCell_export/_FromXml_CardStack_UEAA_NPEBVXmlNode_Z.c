char __fastcall CardStack::FromXml(CardStack *this, const struct XmlNode *a2)
{
  int XmlInt; // eax
  int v6; // eax
  unsigned int XmlUInt; // eax
  XmlNode *v8; // rax
  const struct XmlNode **v9; // rax
  unsigned int v10; // r12d
  const struct XmlNode **v11; // rsi
  const struct XmlNode **v12; // rbp
  struct Card *BlankCard; // rax
  const wchar_t **v14; // rdi
  unsigned int v15; // [rsp+50h] [rbp+18h] BYREF

  XmlInt = XmlNode::GetXmlInt(a2, L"/X", -954380);
  if ( XmlInt == -954380 )
  {
    Log(0x10001u, L"CardStack::FromXml() - Failed to get the x position for the node.");
    return 0;
  }
  CardStack::SetX((NodeBase **)this, XmlInt);
  *((_DWORD *)this + 12) = XmlNode::GetXmlInt(a2, L"/NumEndCardsSpaced", 0);
  v6 = XmlNode::GetXmlInt(a2, L"/Y", -954380);
  if ( v6 == -954380 )
  {
    Log(0x10001u, L"CardStack::FromXml() - Failed to get the y position for the node.");
    return 0;
  }
  CardStack::SetY((NodeBase **)this, v6);
  if ( !XmlNode::GetXmlString(a2, word_1000B2630, 0x80u, L"/Name") )
  {
    Log(0x10001u, L"CardStack::FromXml() - Failed to get the card stack name.");
    return 0;
  }
  Log(0x10000u, L"CardStack::SetName()::wszName == %s", word_1000B2630);
  Str::operator=((__int64)this + 272, word_1000B2630);
  NodeBase::SetName(*((void ***)this + 18), word_1000B2630);
  XmlUInt = XmlNode::GetXmlUInt(a2, L"/Direction", -954380);
  if ( XmlUInt == -954380 )
  {
    Log(0x10001u, L"CardStack::FromXml() - Failed to get the card stack direction.");
    return 0;
  }
  if ( !CardStack::SetDirection(this, XmlUInt) )
  {
    Log(0x10001u, L"CardStack::FromXml() - Invalid card stack direction.");
    return 0;
  }
  v8 = XmlNode::XPathElementSearchSingle(a2, L"/Cards");
  if ( !v8 )
  {
    Log(0x10001u, L"CardStack::FromXml() - Failed to get the card stack info.");
    return 0;
  }
  v15 = 0;
  v9 = XmlNode::XPathElementSearch(v8, L"/Card", &v15);
  v10 = 0;
  v11 = v9;
  if ( v15 )
  {
    v12 = v9;
    while ( 1 )
    {
      BlankCard = CardTable::CreateBlankCard(*((CardTable **)this + 37));
      v14 = (const wchar_t **)BlankCard;
      if ( !BlankCard )
        break;
      if ( !(**(unsigned __int8 (__fastcall ***)(struct Card *, const struct XmlNode *))BlankCard)(BlankCard, *v12) )
      {
        Log(0x10001u, L"CardStack::FromXml() - Failed to recreate the card.");
        return 0;
      }
      if ( (int)SortedListW<Card *>::BinSearch(
                  (_QWORD *)(*((_QWORD *)this + 37) + 120LL),
                  v14[7],
                  0,
                  *(_DWORD *)(*((_QWORD *)this + 37) + 136LL)) >= 0 )
      {
        Log(0x10001u, L"CardStack::FromXml() - Failed to add card to table; card name is not unique");
        return 0;
      }
      SortedListW<CardStack *>::Add(*((_QWORD *)this + 37) + 120LL, v14[7], (__int64)v14);
      CardStack::Push(this, (struct Card *)v14);
      ++v10;
      ++v12;
      if ( v10 >= v15 )
        goto LABEL_20;
    }
    Log(0x10001u, L"CardStack::FromXml() - Failed to create a blank card.");
    return 0;
  }
LABEL_20:
  CardStack::Arrange(this, 0, 0);
  operator delete(v11);
  return 1;
}
