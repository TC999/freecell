char __fastcall CardTable::FromXml(CardTable *this, const struct XmlNode *a2, char a3)
{
  XmlNode *v5; // rax
  XmlNode *v7; // rax
  const struct XmlNode **v8; // rax
  unsigned int v9; // edi
  const struct XmlNode **v10; // rsi
  XmlNode **v11; // rbx
  struct CardStack *CardStack; // rcx
  unsigned int v13; // [rsp+58h] [rbp+20h] BYREF

  v5 = XmlNode::XPathElementSearchSingle(a2, L"/CardTable");
  if ( !v5 )
  {
    Log(0x10001u, L"CardTable::ToXml() - Failed to create the root CardTable node.");
    return 0;
  }
  v7 = XmlNode::XPathElementSearchSingle(v5, L"/CardStacks");
  if ( !v7 )
  {
    Log(0x10001u, L"CardTable::FromXml() - Failed to get the card stack info.");
    return 0;
  }
  v13 = 0;
  v8 = XmlNode::XPathElementSearch(v7, L"/CardStack", &v13);
  v9 = 0;
  v10 = v8;
  if ( v13 )
  {
    v11 = v8;
    while ( 1 )
    {
      XmlNode::GetXmlString(*v11, &word_1000B2530, 0x80u, L"/Name");
      CardStack = CardTable::GetCardStack(this, &word_1000B2530);
      if ( !CardStack )
      {
        if ( !a3 )
        {
          Log(0x10001u, L"CardTable::FromXml() - Invalid XML.");
          return 0;
        }
        CardStack = CardTable::CreateCardStack(this, &word_1000B2530);
        if ( !CardStack )
        {
          Log(0x10001u, L"CardTable::FromXml() - Failed to create the card stack.");
          return 0;
        }
      }
      if ( !(**(unsigned __int8 (__fastcall ***)(struct CardStack *, XmlNode *))CardStack)(CardStack, *v11) )
        break;
      ++v9;
      ++v11;
      if ( v9 >= v13 )
        goto LABEL_13;
    }
    Log(0x10001u, L"CardTable::FromXml() - Failed to recreate the card stack.");
    return 0;
  }
LABEL_13:
  operator delete(v10);
  CardTable::EmptyStates(this);
  return 1;
}
