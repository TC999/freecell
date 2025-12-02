void __fastcall GameAudio::StopSound(GameAudio *this)
{
  if ( (unsigned int)GameAudio::aSoundEffects > 3 )
    Audio::StopSound(g_pAudio, **((_DWORD **)qword_1000ACE60 + 3), 0);
}
