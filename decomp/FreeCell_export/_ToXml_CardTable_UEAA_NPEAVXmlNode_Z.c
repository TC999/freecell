char __fastcall CardTable::ToXml(CardTable *this, struct XmlNode *a2)
{
  void **appended; // rax
  void **v5; // rbp
  int v6; // ebx
  __int64 i; // rdi

  appended = SerializableData::AppendEmptyNode(a2, L"CardTable");
  if ( !appended )
  {
    Log(0x10001u, L"CardTable::ToXml() - Failed to create the root CardTable node.");
    return 0;
  }
  v5 = SerializableData::AppendEmptyNode((struct XmlNode *)appended, L"CardStacks");
  if ( !v5 )
  {
    Log(0x10001u, L"CardTable::ToXml() - Failed to attach the stacks node.");
    return 0;
  }
  v6 = 0;
  if ( *((_DWORD *)this + 38) )
  {
    for ( i = 0;
          (*(unsigned __int8 (__fastcall **)(_QWORD, void **))(**(_QWORD **)(i + *((_QWORD *)this + 18)) + 8LL))(
            *(_QWORD *)(i + *((_QWORD *)this + 18)),
            v5);
          i += 8 )
    {
      if ( (unsigned int)++v6 >= *((_DWORD *)this + 38) )
        return 1;
    }
    Log(0x10001u, L"CardTable::ToXml() - Failed to serialize a stack.");
    return 0;
  }
  return 1;
}
