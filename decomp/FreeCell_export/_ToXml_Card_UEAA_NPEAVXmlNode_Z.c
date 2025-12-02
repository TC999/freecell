char __fastcall Card::ToXml(Card *this, struct XmlNode *a2)
{
  void **appended; // rbx
  const unsigned __int16 *v4; // rsi
  void **v5; // rax

  appended = SerializableData::AppendEmptyNode(a2, L"Card");
  if ( appended )
  {
    if ( SerializableData::AppendInt((struct XmlNode *)appended, L"X", *(_DWORD *)(*((_QWORD *)this + 8) + 8LL)) )
    {
      if ( SerializableData::AppendInt((struct XmlNode *)appended, L"Y", *(_DWORD *)(*((_QWORD *)this + 8) + 12LL)) )
      {
        v4 = (const unsigned __int16 *)*((_QWORD *)this + 7);
        v5 = SerializableData::AppendEmptyNode((struct XmlNode *)appended, L"Name");
        if ( v5 )
        {
          XmlNode::SetNodeValue(v5, v4);
          if ( SerializableData::AppendUInt((struct XmlNode *)appended, L"Type", *((_DWORD *)this + 2)) )
          {
            if ( SerializableData::AppendBool((struct XmlNode *)appended, L"FaceUp", *((_BYTE *)this + 17)) )
            {
              if ( SerializableData::AppendBool(
                     (struct XmlNode *)appended,
                     L"Enabled",
                     *(_BYTE *)(*((_QWORD *)this + 12) + 72LL)) )
              {
                return 1;
              }
              Log(0x10001u, L"Card::ToXml() - Failed to attach the enabled node.");
            }
            else
            {
              Log(0x10001u, L"Card::ToXml() - Failed to attach the face up node.");
            }
          }
          else
          {
            Log(0x10001u, L"Card::ToXml() - Failed to attach the type node.");
          }
        }
        else
        {
          Log(0x10001u, L"Card::ToXml() - Failed to attach the name node.");
        }
      }
      else
      {
        Log(0x10001u, L"Card::ToXml() - Failed to attach the Y node.");
      }
    }
    else
    {
      Log(0x10001u, L"Card::ToXml() - Failed to attach the X node.");
    }
  }
  else
  {
    Log(0x10001u, L"Card::ToXml() - Failed to create the root card node.");
  }
  return 0;
}
