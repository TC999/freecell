void *__fastcall Array<GameAudio::MusicStream *>::SetAt(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // rdi
  void *v5; // rbp
  void *result; // rax

  v4 = a2;
  if ( a2 >= GameAudio::aMusicStreams )
  {
    if ( a2 + 1 > dword_1000ACE6C )
    {
      dword_1000ACE6C = a2 + 1;
      v5 = realloc(qword_1000ACE78, 8LL * (a2 + 1));
      if ( !v5 )
        CheckAllocation(0);
      qword_1000ACE78 = v5;
    }
    GameAudio::aMusicStreams = v4 + 1;
  }
  result = qword_1000ACE78;
  *((_QWORD *)qword_1000ACE78 + v4) = a3;
  return result;
}
