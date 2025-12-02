__int64 __fastcall CardStack::GetCardLocation(CardStack *this, struct Card *a2)
{
  unsigned int v4; // edx
  __int64 result; // rax
  struct Card **i; // rcx

  Log(0x10000u, L"CardStack::GetCardLocation()::pCard == %u", a2);
  v4 = *((_DWORD *)this + 76);
  result = 0;
  if ( !v4 )
    return 0xFFFFFFFFLL;
  for ( i = (struct Card **)*((_QWORD *)this + 40); *i != a2; ++i )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= v4 )
      return 0xFFFFFFFFLL;
  }
  return result;
}
