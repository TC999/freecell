void __fastcall FreeCellGame::RequestSkipAnimation(FreeCellGame *this)
{
  if ( *((_DWORD *)this + 2) == 1 || *((_DWORD *)this + 2) == 3 || *((_DWORD *)this + 2) == 2 )
    CardAnimationManager::FinishAllAnimations(*(CardAnimationManager **)(*((_QWORD *)this + 22) + 88LL));
}
