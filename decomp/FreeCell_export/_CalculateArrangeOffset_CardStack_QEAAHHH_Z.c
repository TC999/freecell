__int64 __fastcall CardStack::CalculateArrangeOffset(CardStack *this, unsigned int a2, int a3)
{
  int v5; // edx
  int v6; // r9d
  __int64 v7; // r10
  __int64 v8; // r11
  __int64 result; // rax

  v5 = 0;
  v6 = 0;
  if ( !*((_DWORD *)this + 76) )
    return a2;
  v7 = *((_QWORD *)this + 40);
  v8 = *((unsigned int *)this + 76);
  do
  {
    if ( *(_BYTE *)(*(_QWORD *)v7 + 17LL) )
      ++v6;
    else
      v5 += a3;
    v7 += 8;
    --v8;
  }
  while ( v8 );
  if ( !v6 )
    return a2;
  result = (unsigned int)((*((_DWORD *)this + 66) - v5 - 97) / v6);
  if ( (int)a2 < (int)result )
    return a2;
  return result;
}
