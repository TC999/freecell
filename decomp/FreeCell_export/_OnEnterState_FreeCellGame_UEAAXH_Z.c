void __fastcall FreeCellGame::OnEnterState(FreeCellGame *this, int a2)
{
  __int64 v2; // r12
  __int64 v5; // rdx
  unsigned int v6; // r8d
  CardTable *v7; // rcx
  int v8; // edi
  int v9; // edi
  FreeCellGame *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rcx
  unsigned int v13; // esi
  __int64 v14; // rbp
  __int64 v15; // rdi
  int v16; // r14d
  __int64 v17; // r15
  struct Card *v18; // r13
  int v19; // eax
  CardAnimationManager *v20; // r13
  float v21; // xmm6_4
  unsigned int v22; // edx
  unsigned int i; // edi
  float *v24; // rdi
  __int64 v25; // rax
  int v26; // edx
  int v27; // ecx
  HMENU Menu; // rax
  unsigned int v29; // r8d
  __int64 v30; // rax
  unsigned int v31; // edx
  __int64 v32; // r11
  struct Card *v33; // [rsp+80h] [rbp+8h]
  __int64 v34; // [rsp+90h] [rbp+18h]

  v2 = 0;
  *((_BYTE *)this + 374) = 0;
  *((_QWORD *)this + 39) = 0;
  FreeCellGame::invalidateHints(this);
  v7 = (CardTable *)*((_QWORD *)this + 22);
  if ( v7 )
    CardTable::ClearHintAnimations(v7);
  *((_BYTE *)this + 380) = 0;
  *((_DWORD *)this + 26) = 0;
  if ( *((_BYTE *)this + 360) )
    *((_BYTE *)this + 360) = 0;
  *((_BYTE *)this + 372) = 0;
  if ( a2 )
  {
    v8 = a2 - 1;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v10 = g_pFreeCellGame;
          ++*(_DWORD *)(*((_QWORD *)g_pFreeCellGame + 10) + 12LL);
          ++*(_DWORD *)(*((_QWORD *)v10 + 10) + 16LL);
          v11 = *((_QWORD *)v10 + 10);
          if ( *(_BYTE *)(v11 + 32) )
            ++*(_DWORD *)(v11 + 28);
          else
            *(_DWORD *)(v11 + 28) = 1;
          *(_BYTE *)(*((_QWORD *)v10 + 10) + 32LL) = 1;
          v12 = *((_QWORD *)v10 + 10);
          if ( *(_DWORD *)(v12 + 20) < *(_DWORD *)(v12 + 28) )
            *(_DWORD *)(v12 + 20) = *(_DWORD *)(v12 + 28);
          FreeCellGame::RemoveGameData(this);
          FreeCellGame::SaveGeneralData(this);
          if ( *(_BYTE *)(*((_QWORD *)this + 11) + 30LL) )
          {
            v13 = 0;
            v14 = 0;
            do
            {
              v15 = 13;
              v16 = v13;
              v17 = 96;
              v34 = 13;
              do
              {
                NodeBase::MoveToFront(*(NodeBase **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 31) + v14)
                                                                           + 320LL)
                                                               + v2)
                                                   + 64LL));
                v18 = *(struct Card **)(v17 + *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 31) + v14) + 320LL));
                v33 = v18;
                v19 = rand();
                v20 = *(CardAnimationManager **)(*((_QWORD *)v18 + 3) + 88LL);
                v21 = (float)(v19 % 170 - 250);
                if ( *(_BYTE *)v20 )
                {
                  if ( !*((_DWORD *)v20 + 10) )
                  {
                    if ( GameAudio::Pin((GameAudio *)0x16, 170 * (v19 / 170)) )
                      GameAudio::Unpin((GameAudio *)0x16, v22);
                    for ( i = 23; i < 0x1A; ++i )
                    {
                      if ( GameAudio::Pin((GameAudio *)i, v22) )
                        GameAudio::Unpin((GameAudio *)i, v22);
                    }
                    Engine_ResetTimer();
                  }
                  v24 = (float *)operator new(0x50u);
                  if ( v24 )
                  {
                    v25 = *((_QWORD *)v33 + 8);
                    v26 = *(_DWORD *)(v25 + 12);
                    v27 = *(_DWORD *)(v25 + 8);
                    v24[15] = v21;
                    *(_QWORD *)v24 = v20;
                    *((_QWORD *)v24 + 1) = v33;
                    v24[16] = -50.0;
                    *((_DWORD *)v24 + 11) = v27;
                    *((_DWORD *)v24 + 12) = v26;
                    *((_BYTE *)v24 + 69) = 0;
                    v24[8] = (float)v16 * 0.15000001;
                    *((_BYTE *)v24 + 71) = 0;
                    *((_BYTE *)v24 + 72) = 0;
                    v24[9] = 0.0;
                    *((_DWORD *)v24 + 19) = 1;
                    v24[13] = 0.0;
                    v24[14] = 0.0;
                    v24[10] = 0.0;
                    *((_QWORD *)v24 + 3) = 0;
                    *((_QWORD *)v24 + 2) = 0;
                    *((_BYTE *)v24 + 70) = 0;
                    *((_BYTE *)v24 + 68) = 0;
                  }
                  else
                  {
                    v24 = 0;
                  }
                  Array<IEventListener *>::Add((char *)v20 + 64, v24);
                  CardAnimationManager::QueueOrSetAnimation(
                    v20,
                    (struct CardAnimationManager::CardAnimation *)v24,
                    v33,
                    0,
                    0);
                  v15 = v34;
                }
                NodeBase::MoveToFront(*(NodeBase **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 31) + v14)
                                                                           + 320LL)
                                                               + v2)
                                                   + 64LL));
                v16 += 3;
                v17 -= 8;
                v2 += 8;
                v34 = --v15;
              }
              while ( v15 );
              ++v13;
              v14 += 8;
              v2 = 0;
            }
            while ( v13 < 4 );
          }
          Engine_ResetTimer();
        }
      }
      else
      {
        Menu = GetMenu(g_hWnd);
        if ( Menu )
          EnableMenuItem(Menu, 0x9C4Cu, 0);
        if ( *((_DWORD *)this + 3) == 5
          && *((_BYTE *)this + 363)
          && !*((_BYTE *)this + 361)
          && !*(_BYTE *)(*((_QWORD *)this + 11) + 14LL) )
        {
          TipManager::ShowTipIfEnabled(*((TipManager **)this + 42), L"Start", 0, 1);
        }
        GameAudio::StopSound((GameAudio *)3, 0, v29);
      }
    }
    else
    {
      v30 = *((_QWORD *)this + 11);
      if ( *(_BYTE *)(v30 + 28) && *(_BYTE *)(v30 + 30) )
      {
        if ( GameAudio::Pin((GameAudio *)3, v5) )
        {
          GameAudio::Unpin((GameAudio *)3, v31);
          Engine_ResetTimer();
        }
        FreeCellGame::PlaySoundW(this, 3u, 1, 0);
      }
      Engine_ResetTimer();
      v32 = *((_QWORD *)this + 11);
      if ( *(_BYTE *)(v32 + 16) )
      {
        if ( !*(_BYTE *)(v32 + 14) )
          TipManager::ShowTipIfEnabled(*((TipManager **)this + 42), L"Start", 0, 1);
        *(_BYTE *)(*((_QWORD *)this + 11) + 16LL) = 0;
      }
    }
  }
  else
  {
    FreeCellGame::NewGame(this, v5, v6);
    FreeCellGame::UpdateUI(this, 0);
  }
  FreeCellGame::UpdateUI(this, 1);
}
