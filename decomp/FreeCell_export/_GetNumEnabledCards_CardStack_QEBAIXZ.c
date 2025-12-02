__int64 __fastcall CardStack::GetNumEnabledCards(CardStack *this)
{
  __int64 result; // rax
  __int64 v2; // r8
  __int64 v3; // r9

  result = 0;
  if ( *((_DWORD *)this + 76) )
  {
    v2 = *((_QWORD *)this + 40);
    v3 = *((unsigned int *)this + 76);
    do
    {
      if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v2 + 96LL) + 72LL) )
        result = (unsigned int)(result + 1);
      v2 += 8;
      --v3;
    }
    while ( v3 );
  }
  return result;
}
