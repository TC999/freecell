void __fastcall CardTable::HandleEvent(CardTable *this, struct Event *a2)
{
  int v2; // r8d
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // r8
  int v12; // eax
  Card *v13; // rcx
  struct CardStack *v14; // rax
  struct StackGroup *v15; // rdx
  struct CardStack *v16; // rax
  struct StackGroup *v17; // rdx
  bool v18; // zf
  UserInterface *v19; // rcx
  __int64 v20; // rax
  unsigned int v21; // edx
  _DWORD *v22; // rcx
  struct Card *Card; // rax
  const unsigned __int16 *v24; // rdx
  int v25; // r8d
  int v26; // r8d
  int v27; // r8d
  int v28; // r8d
  int v29; // edx
  unsigned int v30; // r8d
  __int64 v31; // rcx
  unsigned int v32; // r8d
  __int64 v33; // rdx
  __int64 v34; // rcx
  __int64 v35; // rax
  unsigned int v36; // ecx
  __int64 v37; // rdx
  __int64 v38; // r8
  int v39; // ecx
  unsigned int v40; // r8d
  __int64 v41; // rdx
  __int64 v42; // rdx
  struct CardStack *CardStackWithCard; // rax
  __int64 v44; // rdi
  const unsigned __int16 *v45; // rdx
  __int64 v46; // rbp
  CardStack *v47; // rax
  CardStack *v48; // r11
  NodeBase *v49; // rcx
  bool v50; // r8
  CardStack *v51; // r11

  v2 = *((_DWORD *)a2 + 4);
  if ( v2 > 25 )
  {
    v25 = v2 - 26;
    if ( v25 )
    {
      v26 = v25 - 1;
      if ( v26 )
      {
        v27 = v26 - 4;
        if ( v27 )
        {
          v28 = v27 - 1;
          if ( v28 )
          {
            if ( v28 == 1
              && *((_QWORD *)a2 + 1) == *((_QWORD *)g_pRenderManager + 15)
              && !*((_QWORD *)g_pUserInterface + 8) )
            {
              Log(0x20000u, 0x94Bu, "CardTable.cpp", L"AccessGetChild index %d", *((_DWORD *)a2 + 8));
              v29 = *((_DWORD *)this + 92);
              v30 = *((_DWORD *)a2 + 8);
              if ( v30 <= v29 + *((_DWORD *)this + 6) )
              {
                v31 = 0;
                if ( v29 )
                {
                  v32 = v30 - 1;
                  v33 = *((_QWORD *)this + 45);
                  while ( *(_DWORD *)(*(_QWORD *)v33 + 56LL) != v32 )
                  {
                    v31 = (unsigned int)(v31 + 1);
                    v33 += 8;
                    if ( (unsigned int)v31 >= *((_DWORD *)this + 92) )
                      goto LABEL_67;
                  }
                  v34 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 45) + 8 * v31) + 64LL);
                  *((_QWORD *)a2 + 3) = v34;
                  v35 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v34 + 56LL))(v34);
                  Log(0x20000u, 0x95Au, "CardTable.cpp", L"AccessGetChild name %s", v35);
                }
LABEL_67:
                if ( !*((_QWORD *)a2 + 3) )
                {
                  v36 = *((_DWORD *)this + 92);
                  if ( v36 )
                  {
                    v37 = *((_QWORD *)this + 45);
                    v38 = v36;
                    do
                    {
                      if ( *(_BYTE *)(*(_QWORD *)v37 + 73LL) )
                        --v36;
                      v37 += 8;
                      --v38;
                    }
                    while ( v38 );
                  }
                  *((_QWORD *)a2 + 3) = *(_QWORD *)(*((_QWORD *)this + 5) + 8LL * (*((_DWORD *)a2 + 8) - v36 - 1));
                }
              }
            }
          }
          else if ( *((_QWORD *)a2 + 1) == *((_QWORD *)g_pRenderManager + 15) && !*((_QWORD *)g_pUserInterface + 8) )
          {
            v39 = *((_DWORD *)this + 92);
            v40 = 0;
            *((_DWORD *)a2 + 6) = v39;
            *((_DWORD *)a2 + 6) = *((_DWORD *)this + 6) + v39;
            if ( *((_DWORD *)this + 92) )
            {
              v41 = 0;
              do
              {
                if ( *(_BYTE *)(*(_QWORD *)(*((_QWORD *)this + 45) + v41) + 73LL) )
                  --*((_DWORD *)a2 + 6);
                ++v40;
                v41 += 8;
              }
              while ( v40 < *((_DWORD *)this + 92) );
            }
          }
        }
        else
        {
          v42 = *((_QWORD *)a2 + 1);
          if ( v42 != *((_QWORD *)g_pRenderManager + 15) && !*((_QWORD *)g_pUserInterface + 8) )
          {
            CardStackWithCard = CardTable::GetCardStackWithCard(this, *(const unsigned __int16 **)(v42 + 128));
            if ( CardStackWithCard )
              *((_QWORD *)a2 + 3) = *((_QWORD *)CardStackWithCard + 18);
          }
        }
      }
      else
      {
        v44 = *((_QWORD *)a2 + 1);
        v45 = *(const unsigned __int16 **)(v44 + 128);
        v46 = *(_QWORD *)(v44 + 136);
        if ( v45 )
        {
          v47 = CardTable::GetCardStackWithCard(this, v45);
          if ( v47 )
          {
            CardStack::SetX(v47, *(_DWORD *)(v44 + 8) + *(_DWORD *)(v46 + 8));
            CardStack::SetY(v48, *(_DWORD *)(v44 + 12) + *(_DWORD *)(v46 + 12));
            NodeBase::SetPosition((NodeBase *)v44, 0, *(_DWORD *)(v44 + 12));
            NodeBase::SetPosition(v49, *(_DWORD *)(v44 + 8), 0);
            CardStack::Arrange(v51, 0, v50);
          }
        }
      }
    }
    return;
  }
  if ( v2 == 25 )
  {
    *((_BYTE *)a2 + 24) = 1;
    if ( *((_BYTE *)this + 50) )
    {
      *((_BYTE *)a2 + 24) = 0;
      return;
    }
    v20 = *((_QWORD *)a2 + 1);
    if ( v20 && (v21 = 0, *(_DWORD *)(v20 + 104)) )
    {
      v22 = *(_DWORD **)(v20 + 120);
      while ( *v22 != 2 )
      {
        ++v21;
        ++v22;
        if ( v21 >= *(_DWORD *)(v20 + 104) )
          goto LABEL_46;
      }
      v24 = *(const unsigned __int16 **)(v20 + 128);
      if ( !v24 )
        goto LABEL_50;
      Card = CardTable::GetCard(this, v24);
    }
    else
    {
LABEL_46:
      Card = 0;
    }
    if ( Card )
    {
      v18 = *((_BYTE *)Card + 17) == 0;
LABEL_49:
      if ( !v18 )
        return;
    }
LABEL_50:
    *((_BYTE *)a2 + 24) = 0;
    return;
  }
  v5 = v2 - 4;
  if ( !v5 )
  {
    if ( *((_DWORD *)a2 + 12) )
    {
      v19 = g_pUserInterface;
      if ( *((_DWORD *)a2 + 12) == 1 && *((_BYTE *)g_pUserInterface + 272) )
      {
        *((_BYTE *)a2 + 52) = 1;
        return;
      }
    }
    else
    {
      if ( *(_DWORD *)(*((_QWORD *)this + 11) + 40LL) )
        *((_BYTE *)this + 50) = 1;
      CardTable::ClearHintAnimations(this);
      CardAnimationManager::FinishAllAnimations(*((CardAnimationManager **)this + 11));
      CardAnimationManager::RemoveAllAnimations(*((CardAnimationManager **)this + 11), 1);
      v19 = g_pUserInterface;
    }
    UserInterface::UpdateMouseOverFocus(v19);
    return;
  }
  v6 = v5 - 7;
  if ( v6 )
  {
    v7 = v6 - 5;
    if ( v7 )
    {
      v8 = v7 - 5;
      if ( v8 )
      {
        if ( v8 == 1 && !*((_QWORD *)g_pUserInterface + 8) )
        {
          v9 = *((_QWORD *)a2 + 1);
          if ( v9 )
          {
            v14 = CardTable::GetCardStackWithCard(this, *(const unsigned __int16 **)(v9 + 128));
            if ( v14 )
            {
              v15 = (struct StackGroup *)*((_QWORD *)v14 + 8);
              if ( *((_BYTE *)a2 + 28) )
                CardTable::SelectGroupDown(this, v15);
              else
                CardTable::SelectGroupUp(this, v15);
            }
          }
          else
          {
            v10 = *((_QWORD *)this + 47);
            if ( v10 )
            {
              v11 = **(_QWORD **)(v10 + 48);
              v12 = *(_DWORD *)(v11 + 304);
              if ( v12
                && (v13 = *(Card **)(*(_QWORD *)(v11 + 320) + 8LL * (unsigned int)(v12 - 1)), *((_BYTE *)v13 + 17)) )
              {
                Card::SetFocus(v13);
              }
              else
              {
                CardStack::SetFocus((CardStack *)v11, -1);
              }
              (***((void (__fastcall ****)(_QWORD, struct Event *))this + 14))(*((_QWORD *)this + 14), a2);
            }
          }
        }
      }
      else if ( !*((_QWORD *)g_pUserInterface + 8) )
      {
        CardTable::HandleDirectionChange(this, *((_DWORD *)a2 + 6), *((struct NodeBase **)a2 + 1));
      }
      return;
    }
    if ( *((_BYTE *)this + 51) && *(_DWORD *)(*((_QWORD *)this + 11) + 40LL) )
      *((_BYTE *)a2 + 24) = 0;
    v16 = CardTable::GetCardStackWithCard(this, *(const unsigned __int16 **)(*((_QWORD *)a2 + 1) + 128LL));
    if ( v16 )
    {
      v17 = (struct StackGroup *)*((_QWORD *)v16 + 8);
      if ( v17 )
      {
        v18 = !CardTable::IsGroupSelectable(this, v17);
        goto LABEL_49;
      }
    }
  }
  else if ( !*((_DWORD *)a2 + 12) )
  {
    *((_BYTE *)this + 50) = 0;
  }
}
