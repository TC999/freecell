void __fastcall GameAudio::Unpin(GameAudio *this)
{
  if ( (unsigned int)this < GameAudio::aSoundEffects )
  {
    if ( *((_QWORD *)qword_1000ACE60 + (unsigned int)this) )
      ResourceManager::UnpinResource(g_pResourceManager, **((_DWORD **)qword_1000ACE60 + (unsigned int)this));
  }
}
