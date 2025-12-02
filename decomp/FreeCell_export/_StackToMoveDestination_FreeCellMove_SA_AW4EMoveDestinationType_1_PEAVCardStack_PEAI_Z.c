__int64 __fastcall FreeCellMove::StackToMoveDestination(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // eax
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned int i; // eax
  _QWORD *v7; // rcx
  unsigned int v8; // eax

  v2 = 0;
  v4 = (_QWORD *)*((_QWORD *)g_pFreeCellGame + 28);
  do
  {
    if ( a1 == *v4 )
    {
      if ( a2 )
        *a2 = v2;
      return 0;
    }
    ++v2;
    ++v4;
  }
  while ( v2 < 4 );
  v5 = (_QWORD *)*((_QWORD *)g_pFreeCellGame + 25);
  for ( i = 0; i < 8; ++i )
  {
    if ( a1 == *v5 )
    {
      if ( a2 )
        *a2 = i;
      return 1;
    }
    ++v5;
  }
  v7 = (_QWORD *)*((_QWORD *)g_pFreeCellGame + 31);
  v8 = 0;
  while ( a1 != *v7 )
  {
    ++v8;
    ++v7;
    if ( v8 >= 4 )
      return 3;
  }
  if ( a2 )
    *a2 = v8;
  return 2;
}
