char __fastcall FreeCellGame::IsGameLost(FreeCellGame *this)
{
  __int64 v1; // r15
  unsigned int v3; // r8d
  __int64 v4; // rdx
  unsigned int v5; // edx
  __int64 v6; // rcx
  unsigned int v7; // r12d
  __int64 v8; // r14
  unsigned int RankForType; // eax
  unsigned int v10; // r13d
  __int64 v11; // rbp
  unsigned int v12; // eax
  unsigned int SuitForType; // eax
  int v14; // ebp
  unsigned int v15; // eax
  int v16; // r11d
  int v17; // ebp
  __int64 i; // r13
  unsigned int v19; // r15d
  unsigned int v20; // r12d
  __int64 v21; // r14
  __int64 v22; // rsi
  unsigned int v23; // eax
  unsigned int v24; // eax
  int v25; // esi
  unsigned int v26; // eax
  int v27; // r11d
  unsigned int v29; // [rsp+60h] [rbp+8h]
  __int64 v30; // [rsp+60h] [rbp+8h]
  __int64 v31; // [rsp+68h] [rbp+10h]

  v1 = 0;
  v3 = 0;
  if ( *((_DWORD *)this + 52) )
  {
    v4 = *((_QWORD *)this + 28);
    while ( *(_DWORD *)(*(_QWORD *)v4 + 304LL) )
    {
      ++v3;
      v4 += 8;
      if ( v3 >= *((_DWORD *)this + 52) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v5 = 0;
    if ( *((_DWORD *)this + 46) )
    {
      v6 = *((_QWORD *)this + 25);
      while ( *(_DWORD *)(*(_QWORD *)v6 + 304LL) )
      {
        ++v5;
        v6 += 8;
        if ( v5 >= *((_DWORD *)this + 46) )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      if ( !(unsigned int)FreeCellGame::checkForSuitCompletionsInStacks((__int64)this, (__int64)this + 184, 0, 1)
        && !(unsigned int)FreeCellGame::checkForSuitCompletionsInStacks((__int64)this, (__int64)this + 208, 0, 1) )
      {
        v7 = 0;
        if ( *((_DWORD *)this + 52) )
        {
          v8 = 0;
          while ( 1 )
          {
            v31 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + *((_QWORD *)this + 28)) + 320LL)
                            + 8LL * (unsigned int)(*(_DWORD *)(*(_QWORD *)(v8 + *((_QWORD *)this + 28)) + 304LL) - 1));
            RankForType = Card::GetRankForType(*(_DWORD *)(v31 + 8));
            if ( RankForType == 13 )
              RankForType = 0;
            v29 = RankForType;
            if ( RankForType != 12 )
            {
              v10 = 0;
              if ( *((_DWORD *)this + 46) )
                break;
            }
LABEL_37:
            ++v7;
            v8 += 8;
            if ( v7 >= *((_DWORD *)this + 52) )
              goto LABEL_38;
          }
          while ( 1 )
          {
            v11 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + *((_QWORD *)this + 25)) + 320LL)
                            + 8LL * (unsigned int)(*(_DWORD *)(*(_QWORD *)(v1 + *((_QWORD *)this + 25)) + 304LL) - 1));
            v12 = Card::GetRankForType(*(_DWORD *)(v11 + 8));
            if ( v12 == 13 )
              v12 = 0;
            if ( v12 && v29 == v12 - 1 )
            {
              SuitForType = Card::GetSuitForType(*(_DWORD *)(v11 + 8));
              v14 = 0;
              if ( SuitForType && SuitForType != 2 )
              {
                if ( SuitForType == 1 || SuitForType == 3 )
                  v14 = 1;
                else
                  Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
              }
              v15 = Card::GetSuitForType(*(_DWORD *)(v31 + 8));
              if ( !v15 || v15 == 2 )
              {
                v16 = 0;
              }
              else if ( v15 == 1 || v15 == 3 )
              {
                v16 = 1;
              }
              else
              {
                Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
                v16 = 0;
              }
              if ( v14 != v16 )
                break;
            }
            ++v10;
            v1 += 8;
            if ( v10 >= *((_DWORD *)this + 46) )
            {
              v1 = 0;
              goto LABEL_37;
            }
          }
        }
        else
        {
LABEL_38:
          v17 = 0;
          if ( !*((_DWORD *)this + 46) )
            return 1;
          for ( i = 0; ; i += 8 )
          {
            v30 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(i + *((_QWORD *)this + 25)) + 320LL)
                            + 8LL * (unsigned int)(*(_DWORD *)(*(_QWORD *)(i + *((_QWORD *)this + 25)) + 304LL) - 1));
            v19 = Card::GetRankForType(*(_DWORD *)(v30 + 8));
            if ( v19 == 13 )
              v19 = 0;
            if ( v19 != 12 )
            {
              v20 = 0;
              if ( *((_DWORD *)this + 46) )
                break;
            }
LABEL_64:
            if ( (unsigned int)++v17 >= *((_DWORD *)this + 46) )
              return 1;
          }
          v21 = 0;
          while ( 1 )
          {
            v22 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v21 + *((_QWORD *)this + 25)) + 320LL)
                            + 8LL * (unsigned int)(*(_DWORD *)(*(_QWORD *)(v21 + *((_QWORD *)this + 25)) + 304LL) - 1));
            v23 = Card::GetRankForType(*(_DWORD *)(v22 + 8));
            if ( v23 == 13 )
              v23 = 0;
            if ( v23 && v19 == v23 - 1 )
            {
              v24 = Card::GetSuitForType(*(_DWORD *)(v22 + 8));
              v25 = 0;
              if ( v24 && v24 != 2 )
              {
                if ( v24 == 1 || v24 == 3 )
                  v25 = 1;
                else
                  Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
              }
              v26 = Card::GetSuitForType(*(_DWORD *)(v30 + 8));
              if ( !v26 || v26 == 2 )
              {
                v27 = 0;
              }
              else if ( v26 == 1 || v26 == 3 )
              {
                v27 = 1;
              }
              else
              {
                Log(0x10001u, L"Card::GetColorForType() - Card defined does not make sense.");
                v27 = 0;
              }
              if ( v25 != v27 )
                break;
            }
            ++v20;
            v21 += 8;
            if ( v20 >= *((_DWORD *)this + 46) )
              goto LABEL_64;
          }
        }
      }
    }
  }
  return 0;
}
