void __fastcall FreeCellGame::ChooseNewRandomAppearance(FreeCellGame *this)
{
  unsigned int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax

  v2 = time(0);
  srand(v2);
  v3 = *((_DWORD *)this + 8);
  v4 = rand();
  FreeCellGame::SetCurrentDeckSkin(this, v4 % v3);
  v5 = *((_DWORD *)this + 14);
  v6 = rand();
  FreeCellGame::SetCurrentBackground(this, v6 % v5);
}
