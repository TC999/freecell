bool __fastcall GameAudio::Pin(GameAudio *this)
{
  return (unsigned int)this < GameAudio::aSoundEffects
      && *((_QWORD *)qword_1000ACE60 + (unsigned int)this)
      && ResourceManager::PinResource(g_pResourceManager, **((_DWORD **)qword_1000ACE60 + (unsigned int)this));
}
