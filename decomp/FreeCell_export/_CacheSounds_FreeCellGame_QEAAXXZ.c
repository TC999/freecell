void __fastcall FreeCellGame::CacheSounds(FreeCellGame *this, unsigned int a2)
{
  unsigned int v2; // edx
  unsigned int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // edx
  unsigned int v17; // edx

  if ( *(_BYTE *)(*((_QWORD *)this + 11) + 28LL) )
  {
    GameAudio::Pin(0, a2);
    GameAudio::Pin((GameAudio *)1, v2);
    GameAudio::Pin((GameAudio *)2, v3);
    GameAudio::Pin((GameAudio *)5, v4);
    GameAudio::Pin((GameAudio *)6, v5);
    GameAudio::Pin((GameAudio *)7, v6);
    GameAudio::Pin((GameAudio *)8, v7);
    GameAudio::Pin((GameAudio *)9, v8);
    GameAudio::Pin((GameAudio *)0xA, v9);
  }
  else
  {
    GameAudio::Unpin(0, a2);
    GameAudio::Unpin((GameAudio *)1, v10);
    GameAudio::Unpin((GameAudio *)2, v11);
    GameAudio::Unpin((GameAudio *)5, v12);
    GameAudio::Unpin((GameAudio *)6, v13);
    GameAudio::Unpin((GameAudio *)7, v14);
    GameAudio::Unpin((GameAudio *)8, v15);
    GameAudio::Unpin((GameAudio *)9, v16);
    GameAudio::Unpin((GameAudio *)0xA, v17);
  }
}
