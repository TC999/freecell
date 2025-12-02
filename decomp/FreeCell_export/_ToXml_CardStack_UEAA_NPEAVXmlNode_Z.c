char __fastcall CardStack::ToXml(CardStack *this, struct XmlNode *a2)
{
  void **appended; // rax
  struct XmlNode *v4; // rdi
  const unsigned __int16 *v5; // rsi
  void **v6; // rax
  void **v7; // rbp
  int v8; // edi
  __int64 i; // rsi

  appended = SerializableData::AppendEmptyNode(a2, L"CardStack");
  v4 = (struct XmlNode *)appended;
  if ( appended )
  {
    if ( SerializableData::AppendInt((struct XmlNode *)appended, L"NumEndCardsSpaced", *((_DWORD *)this + 12)) )
    {
      if ( SerializableData::AppendInt(v4, L"X", *(_DWORD *)(*((_QWORD *)this + 18) + 8LL)) )
      {
        if ( SerializableData::AppendInt(v4, L"Y", *(_DWORD *)(*((_QWORD *)this + 18) + 12LL)) )
        {
          v5 = (const unsigned __int16 *)*((_QWORD *)this + 36);
          v6 = SerializableData::AppendEmptyNode(v4, L"Name");
          if ( v6 )
          {
            XmlNode::SetNodeValue(v6, v5);
            if ( SerializableData::AppendUInt(v4, L"Direction", *((_DWORD *)this + 82)) )
            {
              v7 = SerializableData::AppendEmptyNode(v4, L"Cards");
              if ( v7 )
              {
                v8 = 0;
                if ( !*((_DWORD *)this + 76) )
                  return 1;
                for ( i = 0;
                      (*(unsigned __int8 (__fastcall **)(_QWORD, void **))(**(_QWORD **)(i + *((_QWORD *)this + 40))
                                                                         + 8LL))(
                        *(_QWORD *)(i + *((_QWORD *)this + 40)),
                        v7);
                      i += 8 )
                {
                  if ( (unsigned int)++v8 >= *((_DWORD *)this + 76) )
                    return 1;
                }
                Log(0x10001u, L"CardStack::ToXml() - Failed to serialize a card.");
              }
              else
              {
                Log(0x10001u, L"CardStack::ToXml() - Failed to attach the cards node.");
              }
            }
            else
            {
              Log(0x10001u, L"CardStack::ToXml() - Failed to attach the direction node.");
            }
          }
          else
          {
            Log(0x10001u, L"CardStack::ToXml() - Failed to attach the name node.");
          }
        }
        else
        {
          Log(0x10001u, L"CardStack::ToXml() - Failed to attach the Y node.");
        }
      }
      else
      {
        Log(0x10001u, L"CardStack::ToXml() - Failed to attach the X node.");
      }
    }
    else
    {
      Log(0x10001u, L"CardStack::ToXml() - Failed to attach the number of end cards spaced.");
    }
  }
  else
  {
    Log(0x10001u, L"CardStack::ToXml() - Failed to create the root card stack xml.");
  }
  return 0;
}
