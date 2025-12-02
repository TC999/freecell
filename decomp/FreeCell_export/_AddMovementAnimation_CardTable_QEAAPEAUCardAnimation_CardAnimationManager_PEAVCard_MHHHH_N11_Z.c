struct CardAnimationManager::CardAnimation *__fastcall CardTable::AddMovementAnimation(
        CardTable *this,
        struct Card *a2,
        float a3,
        int a4,
        int a5,
        int a6,
        int a7,
        bool a8,
        bool a9,
        bool a10)
{
  CardAnimationManager *v10; // rdi
  float v13; // xmm6_4
  float *v14; // rbx

  v10 = (CardAnimationManager *)*((_QWORD *)this + 11);
  v13 = (float)(powf((float)((a5 - a7) * (a5 - a7) + (a4 - a6) * (a4 - a6)), CardAnimationManager::ANIM_DUR_EXP)
              * CardAnimationManager::ANIM_DUR_MULT)
      + CardAnimationManager::ANIM_DUR_BASE;
  v14 = (float *)operator new(0x50u);
  if ( v14 )
  {
    v14[8] = a3;
    v14[9] = v13;
    *(_QWORD *)v14 = v10;
    *((_QWORD *)v14 + 1) = a2;
    *((_DWORD *)v14 + 11) = a4;
    *((_DWORD *)v14 + 12) = a5;
    *((_DWORD *)v14 + 13) = a6;
    *((_DWORD *)v14 + 14) = a7;
    *((_BYTE *)v14 + 69) = a8;
    *((_BYTE *)v14 + 71) = 1;
    *((_BYTE *)v14 + 72) = 0;
    v14[19] = 0.0;
    v14[15] = 0.0;
    v14[16] = 0.0;
    v14[10] = 0.0;
    *((_QWORD *)v14 + 3) = 0;
    *((_QWORD *)v14 + 2) = 0;
    *((_BYTE *)v14 + 70) = 1;
    *((_BYTE *)v14 + 68) = 0;
  }
  else
  {
    v14 = 0;
  }
  Array<IEventListener *>::Add((__int64)v10 + 64, (__int64)v14);
  if ( a10 )
    *((_BYTE *)v14 + 72) = 1;
  CardAnimationManager::QueueOrSetAnimation(v10, (struct CardAnimationManager::CardAnimation *)v14, a2, a8, a9);
  return (struct CardAnimationManager::CardAnimation *)v14;
}
