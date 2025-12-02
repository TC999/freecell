__int64 __fastcall FreeCellMove::MaxMove(char a1, char a2)
{
  int v3; // r10d
  __int64 v4; // r8
  __int64 v6; // r9
  __int64 v7; // rcx
  int v8; // r8d
  __int64 v9; // rdx
  int v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // edx

  v3 = 1;
  v4 = *((_QWORD *)g_pFreeCellGame + 28);
  v6 = 4;
  do
  {
    if ( !*(_DWORD *)(*(_QWORD *)v4 + 304LL) )
      ++v3;
    v4 += 8;
    --v6;
  }
  while ( v6 );
  v7 = *((_QWORD *)g_pFreeCellGame + 25);
  v8 = 1;
  v9 = 8;
  do
  {
    if ( !*(_DWORD *)(*(_QWORD *)v7 + 304LL) )
      ++v8;
    v7 += 8;
    --v9;
  }
  while ( v9 );
  if ( a1 )
  {
    v10 = v8 - 1;
    v11 = v8 - 1;
    v8 = 1;
    if ( v10 > 1 )
      v8 = v11;
  }
  if ( a2 )
  {
    v12 = v8 - 1;
    v13 = v8 - 1;
    v8 = 1;
    if ( v12 > 1 )
      v8 = v13;
  }
  return (unsigned int)(v3 * v8);
}
