char __fastcall FreeCellOptions::ToXml(FreeCellOptions *this, struct XmlNode *a2)
{
  struct XmlNode *appended; // rax
  struct XmlNode *v5; // rbx
  const wchar_t *v6; // r9

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellOptions::ToXml() - NULL parent tag.");
    return 0;
  }
  appended = SerializableData::AppendEmptyNode(a2, L"Options");
  v5 = appended;
  if ( !appended )
  {
    v6 = L"Unable to create the options node.";
LABEL_6:
    Log(0x10000001u, L"%s() - %s", L"FreeCellOptions::ToXml", v6);
    return 0;
  }
  if ( !SerializableData::AppendUInt(appended, L"Version", *((_DWORD *)this + 2)) )
  {
    v6 = L"Unable to write the version to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"PlaySounds", *((_BYTE *)this + 29)) )
  {
    v6 = L"Unable to write play sounds to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"PlayAnimations", *((_BYTE *)this + 31)) )
  {
    v6 = L"Unable to write play animations to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"RandomAppearance", *((_BYTE *)this + 12)) )
  {
    v6 = L"Unable to write random appearance to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"AutoLoad", *((_BYTE *)this + 13)) )
  {
    v6 = L"Unable to write auto load to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"TurnOffTips", *((_BYTE *)this + 14)) )
  {
    v6 = L"Unable to write turn off tips to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"AutoSaveGameOnExit", *((_BYTE *)this + 15)) )
  {
    v6 = L"Unable to write auto save game on exit to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(v5, L"FirstPlay", *((_BYTE *)this + 16)) )
  {
    v6 = L"Unable to write first play to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(v5, L"CurrDeckSkin", *(_DWORD *)(*((_QWORD *)g_pFreeCellGame + 11) + 20LL)) )
  {
    v6 = L"Unable to write current deck skin to the options node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(v5, L"CurrBackground", *(_DWORD *)(*((_QWORD *)g_pFreeCellGame + 11) + 24LL)) )
  {
    v6 = L"Unable to write current background to the options node";
    goto LABEL_6;
  }
  return 1;
}
