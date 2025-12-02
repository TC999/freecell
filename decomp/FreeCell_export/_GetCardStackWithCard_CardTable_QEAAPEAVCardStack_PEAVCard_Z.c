struct CardStack *__fastcall CardTable::GetCardStackWithCard(CardTable *this, struct Card *a2)
{
  unsigned int v2; // r10d
  int v3; // eax
  __int64 i; // r8
  unsigned int v5; // ecx
  unsigned int v6; // r11d
  struct Card **v7; // r9

  v2 = *((_DWORD *)this + 40);
  v3 = 0;
  if ( !v2 )
    return 0;
  for ( i = *((_QWORD *)this + 19); ; i += 8 )
  {
    v5 = 0;
    v6 = *(_DWORD *)(*(_QWORD *)i + 304LL);
    if ( v6 )
    {
      v7 = *(struct Card ***)(*(_QWORD *)i + 320LL);
      while ( *v7 != a2 )
      {
        ++v5;
        ++v7;
        if ( v5 >= v6 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v5 = -1;
    }
    if ( v5 != -1 )
      break;
    if ( ++v3 >= v2 )
      return 0;
  }
  return *(struct CardStack **)i;
}
