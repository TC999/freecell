char __fastcall FreeCellGameState::ToXml(FreeCellGameState *this, struct XmlNode *a2)
{
  struct XmlNode *appended; // rax
  struct XmlNode *v5; // rbx
  const wchar_t *v6; // r9

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellGameState::ToXml() - NULL parent tag.");
    return 0;
  }
  appended = SerializableData::AppendEmptyNode(a2, L"GameState");
  v5 = appended;
  if ( !appended )
  {
    v6 = L"Unable to create the GameState node.";
LABEL_6:
    Log(0x10000001u, L"%s() - %s", L"FreeCellGameState::ToXml", v6);
    return 0;
  }
  if ( !SerializableData::AppendUInt(appended, L"Version", *((_DWORD *)this + 2)) )
  {
    v6 = L"Unable to write the version to the GameState node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendInt(v5, L"GameNumber", *((_DWORD *)this + 3)) )
  {
    v6 = L"Unable to write game number to the GameState node";
    goto LABEL_6;
  }
  return 1;
}
