__int64 __fastcall FreeCellMove::GetHighestPlaceableCardIndex(struct CardStack *a1, struct Card *a2)
{
  bool v3; // di
  int v4; // ebx
  unsigned int v5; // esi
  struct Card *v6; // rdx
  __int64 v8; // r12
  __int64 v9; // rax
  struct Card *v10; // rbp

  v3 = 0;
  v4 = *((_DWORD *)a1 + 76) - 1;
  v5 = -1;
  v6 = 0;
  v8 = 8LL * v4;
  do
  {
    if ( v4 < 0 )
      break;
    v9 = *((_QWORD *)a1 + 40);
    v10 = *(struct Card **)(v8 + v9);
    if ( v6 )
      v3 = !FreeCellMove::DoesCardFollowSequence(*(struct Card **)(v8 + v9), v6);
    if ( !v3 && FreeCellMove::DoesCardFollowSequence(a2, v10) )
    {
      v3 = 1;
      v5 = v4;
    }
    --v4;
    v8 -= 8;
    v6 = v10;
  }
  while ( !v3 );
  return v5;
}
