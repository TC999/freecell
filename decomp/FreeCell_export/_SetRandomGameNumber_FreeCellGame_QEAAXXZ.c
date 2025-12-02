void __fastcall FreeCellGame::SetRandomGameNumber(FreeCellGame *this)
{
  unsigned int v2; // eax
  int v3; // eax

  v2 = time(0);
  srand(v2);
  rand();
  rand();
  do
  {
    do
      v3 = rand();
    while ( v3 < 1 );
  }
  while ( v3 > 1000000 );
  *(_DWORD *)(*((_QWORD *)this + 12) + 12LL) = v3;
  FreeCellGame::UpdateUI(this, 1);
}
