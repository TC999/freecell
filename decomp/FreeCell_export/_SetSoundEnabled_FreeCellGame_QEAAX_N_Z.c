void __fastcall FreeCellGame::SetSoundEnabled(FreeCellGame *this, char a2)
{
  Audio *v2; // rbp
  unsigned int v4; // ebx
  char v5; // r12
  int v6; // eax
  int v7; // eax
  unsigned int v8; // edx
  unsigned int MusicBufferVolume; // r13d
  __int64 v10; // rdi
  __int64 v11; // rax

  v2 = g_pAudio;
  v4 = 0;
  v5 = *((_QWORD *)g_pAudio + 2) != 0 ? a2 : 0;
  v6 = 0;
  if ( v5 == 1 )
    v6 = 100;
  *(_DWORD *)g_pAudio = v6;
  v7 = *((_DWORD *)v2 + 1);
  if ( v7 < 0 )
    v7 = 0;
  if ( v7 > 100 )
    v7 = 100;
  *((_DWORD *)v2 + 1) = v7;
  MusicBufferVolume = Audio::GetMusicBufferVolume(v2);
  if ( *((_DWORD *)v2 + 8) )
  {
    v10 = 0;
    do
    {
      v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)(v10 + *((_QWORD *)v2 + 6)) + 80LL))(
              *(_QWORD *)(v10 + *((_QWORD *)v2 + 6)),
              0);
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v11 + 120LL))(v11, MusicBufferVolume);
      ++v4;
      v10 += 8;
    }
    while ( v4 < *((_DWORD *)v2 + 8) );
  }
  *(_BYTE *)(*((_QWORD *)this + 11) + 28LL) = v5;
  FreeCellGame::CacheSounds(this, v8);
}
