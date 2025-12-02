void __fastcall CardTable::UpdateAccessibility(CardTable *this)
{
  unsigned int v1; // ebx
  __int64 v3; // rsi

  v1 = 0;
  if ( *((_DWORD *)this + 40) )
  {
    v3 = 0;
    do
    {
      CardStack::UpdateAccessibility(*(CardStack **)(*((_QWORD *)this + 19) + v3));
      ++v1;
      v3 += 8;
    }
    while ( v1 < *((_DWORD *)this + 40) );
  }
}
