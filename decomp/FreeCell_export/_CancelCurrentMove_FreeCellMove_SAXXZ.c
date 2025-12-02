void FreeCellMove::CancelCurrentMove(void)
{
  FreeCellGame *v0; // rcx
  FreeCellGame *v1; // rcx

  v0 = g_pFreeCellGame;
  *((_DWORD *)g_pFreeCellGame + 26) = 0;
  CardTable::PopState(*((CardTable **)v0 + 22));
  v1 = g_pFreeCellGame;
  if ( *((_QWORD *)g_pFreeCellGame + 41) )
  {
    CardStack::Arrange(*((CardStack **)g_pFreeCellGame + 41), 1, 0);
    v1 = g_pFreeCellGame;
    *((_QWORD *)g_pFreeCellGame + 41) = 0;
  }
  FreeCellGame::SetSelectedCard(v1, 0, 1, 1, 1);
}
