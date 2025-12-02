__int64 __fastcall FreeCellGame::CheckForSuitCompletions(FreeCellGame *this, char a2, __int64 a3, __int64 a4)
{
  FreeCellGame *v4; // rdi
  char v6; // si
  int v7; // eax
  __int64 v8; // r9
  __int64 v9; // r8

  v4 = g_pFreeCellGame;
  v6 = a3;
  LOBYTE(a4) = a3;
  LOBYTE(a3) = a2;
  v7 = FreeCellGame::checkForSuitCompletionsInStacks(g_pFreeCellGame, (char *)g_pFreeCellGame + 184, a3, a4);
  LOBYTE(v8) = v6;
  LOBYTE(v9) = a2;
  return v7 + (unsigned int)FreeCellGame::checkForSuitCompletionsInStacks(v4, (char *)v4 + 208, v9, v8);
}
