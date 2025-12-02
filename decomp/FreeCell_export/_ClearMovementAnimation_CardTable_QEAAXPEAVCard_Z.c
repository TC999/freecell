void __fastcall CardTable::ClearMovementAnimation(CardTable *this, struct Card *a2)
{
  __int64 v2; // rcx
  int v3; // r8d
  __int64 *i; // rax
  __int64 v6; // rdx

  v2 = *((_QWORD *)this + 11);
  v3 = 0;
  if ( *(_DWORD *)(v2 + 40) )
  {
    for ( i = *(__int64 **)(v2 + 56); ; ++i )
    {
      v6 = *i;
      if ( a2 == *(struct Card **)(*i + 8) && !*(_DWORD *)(v6 + 76) )
        break;
      if ( (unsigned int)++v3 >= *(_DWORD *)(v2 + 40) )
        return;
    }
    CardAnimationManager::RemoveAnimation(
      (CardAnimationManager *)v2,
      (struct CardAnimationManager::CardAnimation *)v6,
      1);
  }
}
