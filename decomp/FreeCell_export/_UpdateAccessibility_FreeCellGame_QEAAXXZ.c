void __fastcall FreeCellGame::UpdateAccessibility(FreeCellGame *this)
{
  unsigned int v1; // ebx
  unsigned int v3; // esi
  __int64 v4; // rbp
  __int64 v5; // rsi

  v1 = 0;
  v3 = 0;
  if ( *((_DWORD *)this + 52) )
  {
    v4 = 0;
    do
    {
      CardStack::UpdateAccessibility(*(CardStack **)(*((_QWORD *)this + 28) + v4));
      ++v3;
      v4 += 8;
    }
    while ( v3 < *((_DWORD *)this + 52) );
  }
  if ( *((_DWORD *)this + 58) )
  {
    v5 = 0;
    do
    {
      CardStack::UpdateAccessibility(*(CardStack **)(*((_QWORD *)this + 31) + v5));
      ++v1;
      v5 += 8;
    }
    while ( v1 < *((_DWORD *)this + 58) );
  }
}
