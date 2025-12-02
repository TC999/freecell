char __fastcall FreeCellStatistics::ToXml(FreeCellStatistics *this, struct XmlNode *a2)
{
  const wchar_t *v5; // r9

  if ( !a2 )
  {
    Log(0x10000001u, L"FreeCellStatistics::ToXml() - NULL parent tag.");
    return 0;
  }
  if ( !SerializableData::AppendUInt(a2, L"Version", *((_DWORD *)this + 2)) )
  {
    v5 = L"Unable to write the version to the stat node";
LABEL_6:
    Log(0x10000001u, L"%s() - %s", L"FreeCellStatistics::ToXml", v5);
    return 0;
  }
  if ( !SerializableData::AppendUInt(a2, L"GamesPlayed", *((_DWORD *)this + 3)) )
  {
    v5 = L"Unable to write the number of games played to the stat node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(a2, L"GamesWon", *((_DWORD *)this + 4)) )
  {
    v5 = L"Unable to write the number of games won to the stat node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(a2, L"MaxWinStreakLength", *((_DWORD *)this + 5)) )
  {
    v5 = L"Unable to write the max win streak length to the stat node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(a2, L"MaxLoseStreakLength", *((_DWORD *)this + 6)) )
  {
    v5 = L"Unable to write the max losing streak length to the stat node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendUInt(a2, L"CurrStreakLength", *((_DWORD *)this + 7)) )
  {
    v5 = L"Unable to write the current streak length to the stat node";
    goto LABEL_6;
  }
  if ( !SerializableData::AppendBool(a2, L"WonlastGame", *((_BYTE *)this + 32)) )
  {
    v5 = L"Unable to write the won last game flag to the stat node";
    goto LABEL_6;
  }
  return 1;
}
