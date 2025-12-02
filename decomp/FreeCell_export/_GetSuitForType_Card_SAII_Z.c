__int64 __fastcall Card::GetSuitForType(unsigned int a1)
{
  if ( a1 > 0xC )
  {
    if ( a1 - 26 <= 0xC )
      return 2;
    if ( a1 - 13 <= 0xC )
      return 1;
    if ( a1 - 39 <= 0xC )
      return 3;
    Log(0x10001u, L"Card::GetColor() - The card defined does not make sense.");
  }
  return 0;
}
