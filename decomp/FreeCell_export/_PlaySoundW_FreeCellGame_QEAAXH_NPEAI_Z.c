void __fastcall FreeCellGame::PlaySoundW(FreeCellGame *this, unsigned int a2, bool a3, unsigned int *a4)
{
  if ( *(_BYTE *)(*((_QWORD *)this + 11) + 28LL) )
  {
    if ( GameAudio::aSoundEffects > a2 )
      Audio::StartEffect(g_pAudio, **((_DWORD **)qword_1000ACE60 + a2), a3, 0);
  }
}
