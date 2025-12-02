void __fastcall CardStack::HandleEvent(CardStack *this, struct Event *a2)
{
  __int64 v4; // rax
  int v5; // r12d
  unsigned int v6; // r13d
  unsigned int v7; // eax
  unsigned int v8; // r10d
  unsigned int v9; // eax
  int v10; // r8d
  unsigned int v11; // edx
  __int64 v12; // r9
  int v13; // eax
  int v14; // r13d
  unsigned int v15; // r12d
  __int64 v16; // r15
  unsigned int v17; // r14d
  __int64 v18; // rdx
  __int64 v19; // r8
  unsigned int v20; // eax
  __int64 v21; // rcx
  __int64 v22; // rdx
  int v23; // eax
  UserInterface *v24; // rcx
  __int64 v25; // rax
  int v26; // ebx
  unsigned int NumEnabledCards; // eax
  unsigned int v28; // r10d
  __int64 v29; // rax
  __int64 GameEvent; // rbx
  CardTable *v31; // rcx
  bool v32; // zf
  struct StackGroup *v33; // rdx
  CardTable *v34; // rcx
  __int64 v35; // rcx
  struct StackGroup *v36; // rdx
  __int64 v37; // r12
  char v38; // si
  struct CardStack *CardStackWithCard; // rdi
  unsigned int v40; // ecx
  __int64 v41; // rdx
  __int64 v42; // [rsp+58h] [rbp+10h]

  switch ( *((_DWORD *)a2 + 4) )
  {
    case 0xD:
      v37 = *((_QWORD *)this + 36);
      if ( v37 && *((_DWORD *)a2 + 8) == *((_DWORD *)this + 60) )
      {
        v38 = 0;
        CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 36), *((struct Card **)this + 28));
        if ( !CardStackWithCard )
          Log(0x10001u, L"Couldn't find cardstack for animation completion");
        v40 = 0;
        v41 = 0;
        do
        {
          if ( v40 >= *(_DWORD *)(v37 + 216) )
            break;
          if ( *(struct CardStack **)(v41 + *(_QWORD *)(v37 + 232)) == CardStackWithCard )
            v38 = 1;
          ++v40;
          v41 += 8;
        }
        while ( !v38 );
      }
      return;
    case 0x10:
      v35 = *((_QWORD *)this + 36);
      if ( v35 )
      {
        if ( *(_BYTE *)(v35 + 51) && *(_DWORD *)(*(_QWORD *)(v35 + 88) + 40LL) )
        {
          *((_BYTE *)a2 + 24) = 0;
        }
        else
        {
          v36 = (struct StackGroup *)*((_QWORD *)this + 7);
          if ( !v36 )
            goto LABEL_71;
          if ( !CardTable::IsGroupSelectable((CardTable *)v35, v36) )
            *((_BYTE *)a2 + 24) = 0;
          if ( *((_DWORD *)this + 74) )
LABEL_71:
            *((_BYTE *)a2 + 24) = 0;
        }
      }
      return;
    case 0x15:
      v34 = (CardTable *)*((_QWORD *)this + 36);
      if ( v34 && g_pUserInterface && !*((_QWORD *)g_pUserInterface + 8) )
        CardTable::HandleDirectionChange(v34, *((_DWORD *)a2 + 6), *((const unsigned __int16 ***)a2 + 1));
      return;
    case 0x16:
      v31 = (CardTable *)*((_QWORD *)this + 36);
      if ( v31 && g_pUserInterface && !*((_QWORD *)g_pUserInterface + 8) )
      {
        v32 = *((_BYTE *)a2 + 28) == 0;
        v33 = (struct StackGroup *)*((_QWORD *)this + 7);
        if ( v32 )
          CardTable::SelectGroupUp(v31, v33);
        else
          CardTable::SelectGroupDown(v31, v33);
      }
      return;
    case 0x18:
      if ( *((_QWORD *)this + 36) )
      {
        v29 = *((_QWORD *)this + 7);
        if ( v29 )
        {
          if ( *(_BYTE *)(v29 + 72) && *((_DWORD *)this + 74) )
          {
            GameEvent = Event::CreateGameEvent(1u);
            *(_BYTE *)(GameEvent + 32) = GetKeyState(17) < 0;
            *(_QWORD *)(GameEvent + 24) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 39)
                                                                + 8LL * (unsigned int)(*((_DWORD *)this + 74) - 1))
                                                    + 96LL);
            (***(void (__fastcall ****)(_QWORD, __int64))(*((_QWORD *)this + 36) + 112LL))(
              *(_QWORD *)(*((_QWORD *)this + 36) + 112LL),
              GameEvent);
            (**(void (__fastcall ***)(__int64, __int64))GameEvent)(GameEvent, 1);
          }
        }
      }
      return;
    case 0x1F:
      if ( g_pUserInterface && !*((_QWORD *)g_pUserInterface + 8) )
        *((_QWORD *)a2 + 3) = *(_QWORD *)(*((_QWORD *)this + 7) + 64LL);
      return;
    case 0x20:
      v25 = *((_QWORD *)this + 7);
      if ( v25 && g_pUserInterface && !*((_QWORD *)g_pUserInterface + 8) )
      {
        if ( *(_BYTE *)(v25 + 72) )
        {
          *((_DWORD *)a2 + 6) = 0;
        }
        else
        {
          v26 = *((_DWORD *)this + 81);
          NumEnabledCards = CardStack::GetNumEnabledCards((CardStack *)((char *)this - 8));
          if ( v28 >= v26 + NumEnabledCards )
            v28 = v26 + CardStack::GetNumEnabledCards((CardStack *)((char *)this - 8));
          *((_DWORD *)a2 + 6) = v28;
        }
      }
      return;
  }
  if ( *((_DWORD *)a2 + 4) != 33 )
    return;
  v4 = *((_QWORD *)this + 7);
  if ( !v4 || !g_pUserInterface || *((_QWORD *)g_pUserInterface + 8) || *(_BYTE *)(v4 + 72) )
    return;
  v5 = *((_DWORD *)this + 81);
  v6 = *((_DWORD *)a2 + 8) - 1;
  v7 = CardStack::GetNumEnabledCards((CardStack *)((char *)this - 8));
  v9 = v8 >= v5 + v7 ? v5 + CardStack::GetNumEnabledCards((CardStack *)((char *)this - 8)) : v8;
  if ( v6 >= v9 )
    return;
  v10 = 0;
  v11 = 0;
  if ( !v8 )
    goto LABEL_25;
  v12 = *((_QWORD *)this + 39);
  while ( !*(_BYTE *)(*(_QWORD *)(*(_QWORD *)v12 + 96LL) + 72LL) )
  {
LABEL_22:
    ++v11;
    v12 += 8;
    if ( v11 >= v8 )
      goto LABEL_25;
  }
  if ( v10 != v6 )
  {
    ++v10;
    goto LABEL_22;
  }
  *((_QWORD *)a2 + 3) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 39) + 8LL * v11) + 96LL);
LABEL_25:
  if ( *((_DWORD *)this + 81) )
  {
    if ( !*((_QWORD *)a2 + 3) )
    {
      *((_QWORD *)a2 + 3) = 0;
      v13 = *((_DWORD *)this + 74);
      v14 = v6 - v10;
      v15 = v13 - 1;
      if ( v13 )
      {
        v16 = (int)v15 - 1LL;
        v17 = v13 - 2;
        v18 = 8LL * (int)v15;
        v42 = v18;
        do
        {
          v19 = *((_QWORD *)this + 39);
          if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v18 + v19) + 96LL) + 72LL) )
          {
            v20 = v17;
            v21 = v16;
            if ( v17 < v15 )
            {
              while ( v14 )
              {
                --v20;
                --v14;
                --v21;
                if ( v20 >= v15 )
                  goto LABEL_37;
              }
              v22 = *(_QWORD *)(*(_QWORD *)(v19 + 8 * v21) + 96LL);
              *((_QWORD *)a2 + 3) = v22;
              v23 = *(_DWORD *)(v22 + 192);
              if ( *(_BYTE *)(v22 + 144) != 1 )
              {
                v24 = g_pUserInterface;
                *(_BYTE *)(v22 + 144) = 1;
                *(_DWORD *)(v22 + 192) = v23;
                UserInterface::Access_OnNodeAccessible(v24, (struct NodeBase *)v22);
              }
              v18 = v42;
            }
          }
LABEL_37:
          if ( *((_QWORD *)a2 + 3) )
            break;
          v18 -= 8;
          --v15;
          --v17;
          --v16;
          v42 = v18;
        }
        while ( v15 < *((_DWORD *)this + 74) );
      }
    }
  }
}
