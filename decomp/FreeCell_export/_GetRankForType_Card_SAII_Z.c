__int64 __fastcall Card::GetRankForType(unsigned int a1)
{
  if ( a1 <= 0xC )
    return a1 + 1;
  if ( a1 - 26 <= 0xC )
    return a1 - 25;
  if ( a1 - 13 <= 0xC )
    return a1 - 12;
  if ( a1 - 39 <= 0xC )
    return a1 - 38;
  Log(0x10001u, L"Card::GetColor() - The card defined does not make sense.");
  return 0;
}
