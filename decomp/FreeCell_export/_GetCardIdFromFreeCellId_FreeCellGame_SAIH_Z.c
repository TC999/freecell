__int64 __fastcall FreeCellGame::GetCardIdFromFreeCellId(int a1)
{
  int v1; // r8d
  int v2; // ecx
  int v3; // eax

  v1 = a1 / 4;
  v2 = a1 % 4;
  v3 = 2;
  if ( v2 != 3 )
  {
    if ( v2 == 2 )
      v2 = 3;
    v3 = v2;
  }
  if ( !v1 )
    v1 = 13;
  return (unsigned int)(13 * v3 + v1 - 1);
}
