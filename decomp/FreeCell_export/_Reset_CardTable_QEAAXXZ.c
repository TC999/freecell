// Hidden C++ exception states: #wind=2
void __fastcall CardTable::Reset(CardTable *this)
{
  unsigned int v2; // ebp
  __int64 v3; // rbx
  void **v4; // rsi
  unsigned int v5; // ebp
  __int64 v6; // rsi
  __int64 v7; // rbx
  unsigned int v8; // ebx
  __int64 v9; // rbp
  void **v10; // rsi

  v2 = 0;
  if ( *((_DWORD *)this + 60) )
  {
    v3 = 0;
    do
    {
      v4 = *(void ***)(v3 + *((_QWORD *)this + 32));
      if ( v4 )
      {
        operator delete(v4[6]);
        operator delete(v4[3]);
        operator delete(v4);
      }
      *(_QWORD *)(v3 + *((_QWORD *)this + 32)) = 0;
      ++v2;
      v3 += 8;
    }
    while ( v2 < *((_DWORD *)this + 60) );
  }
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  free(*((void **)this + 32));
  *((_QWORD *)this + 32) = 0;
  CardAnimationManager::RemoveAllAnimations(*((CardAnimationManager **)this + 11), 1);
  CardTable::ClearHintAnimations(this);
  v5 = 0;
  if ( *((_DWORD *)this + 40) )
  {
    v6 = 0;
    do
    {
      v7 = *(_QWORD *)(v6 + *((_QWORD *)this + 19));
      *(_DWORD *)(v7 + 304) = 0;
      *(_DWORD *)(v7 + 308) = 0;
      free(*(void **)(v7 + 320));
      *(_QWORD *)(v7 + 320) = 0;
      ++v5;
      v6 += 8;
    }
    while ( v5 < *((_DWORD *)this + 40) );
  }
  if ( (int)SortedListW<Card *>::BinSearch((_QWORD *)this + 18, L"DragStack", 0, *((_DWORD *)this + 40)) >= 0 )
    SortedListW<CardStack *>::Remove((char *)this + 144, L"DragStack");
  if ( (int)SortedListW<Card *>::BinSearch((_QWORD *)this + 18, L"MoveStack", 0, *((_DWORD *)this + 40)) >= 0 )
    SortedListW<CardStack *>::Remove((char *)this + 144, L"MoveStack");
  v8 = 0;
  if ( *((_DWORD *)this + 34) )
  {
    v9 = 0;
    do
    {
      v10 = *(void ***)(*((_QWORD *)this + 16) + v9);
      if ( v10 )
      {
        *v10 = &Card::`vftable';
        Card::Cleanup((Card *)v10);
        operator delete(v10[7]);
        operator delete(v10);
      }
      ++v8;
      v9 += 8;
    }
    while ( v8 < *((_DWORD *)this + 34) );
  }
  SortedListW<unsigned int>::RemoveAll((__int64)this + 120);
  CardTable::UpdateAccessibility(this);
}
