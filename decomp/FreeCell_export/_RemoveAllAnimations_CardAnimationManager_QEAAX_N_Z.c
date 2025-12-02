void __fastcall CardAnimationManager::RemoveAllAnimations(CardAnimationManager *this, char a2)
{
  __int64 v4; // rdx
  __int64 v5; // rbx

  while ( *((_DWORD *)this + 10) )
  {
    v4 = *(_QWORD *)(*((_QWORD *)this + 7) + 8LL * (unsigned int)(*((_DWORD *)this + 10) - 1));
    if ( *(_QWORD *)(v4 + 24) )
    {
      do
      {
        v5 = *(_QWORD *)(v4 + 24);
        CardAnimationManager::RemoveAnimation((CardTable **)this, (struct CardAnimationManager::CardAnimation *)v4, 1);
        v4 = v5;
      }
      while ( *(_QWORD *)(v5 + 24) );
    }
    CardAnimationManager::RemoveAnimation((CardTable **)this, (struct CardAnimationManager::CardAnimation *)v4, a2);
  }
}
