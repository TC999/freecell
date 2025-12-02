void __fastcall CardStack::Arrange(CardStack *this, char a2, bool a3)
{
  int v3; // edi
  int v7; // eax
  float v8; // xmm6_4
  int v9; // r14d
  int v10; // r13d
  int v11; // r12d
  int v12; // eax
  int v13; // eax
  int v14; // eax
  signed int v15; // esi
  __int64 *v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rax
  __int64 v19; // rax
  RenderManager *v20; // rax
  float v21; // xmm8_4
  unsigned int v22; // eax
  bool v23; // cl
  bool v24; // zf
  bool v25; // cl
  __int64 v26; // rax
  int v27; // r8d
  int v28; // edx
  __int64 v29; // rax
  int v30; // r9d
  float v31; // xmm1_4
  float v32; // xmm6_4
  int v33; // r15d
  int v34; // ebp
  __int64 v35; // rdx
  __int64 v36; // rsi
  int v37; // r11d
  __int64 v38; // rax
  RenderManager *v39; // rax
  unsigned int v40; // ecx
  __int64 v41; // rax
  __int64 v42; // rax
  RenderManager *v43; // rax
  __int64 v44; // rax
  __int64 v45; // rax
  RenderManager *v46; // rax
  unsigned int v47; // eax
  bool v48; // cl
  bool v49; // zf
  bool v50; // dl
  __int64 v51; // rcx
  int v52; // r8d
  int v53; // ecx
  __int64 v54; // rax
  int v55; // r9d
  int v56; // eax
  float v57; // xmm6_4
  RenderManager *v58; // r9
  __int64 v59; // rdx
  __int64 v60; // rax
  unsigned int v61; // r8d
  unsigned int v62; // r10d
  unsigned int v63; // r11d
  unsigned int v64; // eax
  __int64 v65; // rdx
  __int64 v66; // rax
  int v67; // [rsp+50h] [rbp-A8h]
  int v68; // [rsp+54h] [rbp-A4h]
  int v69; // [rsp+58h] [rbp-A0h]
  int v70; // [rsp+5Ch] [rbp-9Ch]
  unsigned int v71; // [rsp+60h] [rbp-98h]
  signed int v72; // [rsp+64h] [rbp-94h]
  int v73; // [rsp+68h] [rbp-90h]
  __int64 v74; // [rsp+70h] [rbp-88h]
  char v75; // [rsp+100h] [rbp+8h]
  int v78; // [rsp+118h] [rbp+20h]

  v3 = *((_DWORD *)this + 76);
  if ( !v3 )
    return;
  v7 = *((_DWORD *)this + 82);
  v8 = CardStack::ANIM_TIME_CARD_DELAY;
  v73 = 0;
  v75 = 0;
  v9 = 0;
  v10 = 0;
  v69 = 0;
  v70 = 0;
  v11 = 0;
  v78 = 0;
  v67 = 0;
  v68 = 0;
  if ( !v7 )
  {
    v10 = -*((_DWORD *)this + 6);
    v69 = 0;
    v67 = 0;
    v78 = -*((_DWORD *)this + 13);
    v68 = v78;
    v70 = -*((_DWORD *)this + 7);
    goto LABEL_14;
  }
  v12 = v7 - 1;
  if ( v12 )
  {
    v13 = v12 - 1;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( v14 )
      {
        if ( v14 == 1 )
        {
          v9 = *((_DWORD *)this + 10);
          v11 = *((_DWORD *)this + 13);
          v10 = v9;
          v69 = v9;
          v70 = v9;
          v78 = v11;
          v67 = v11;
          v68 = v11;
        }
        goto LABEL_14;
      }
      v9 = *((_DWORD *)this + 8);
      v11 = *((_DWORD *)this + 13);
      v69 = *((_DWORD *)this + 9);
    }
    else
    {
      v9 = -*((_DWORD *)this + 8);
      v11 = -*((_DWORD *)this + 13);
      v69 = -*((_DWORD *)this + 9);
    }
    v70 = 0;
    v78 = 0;
    v67 = v11;
    v68 = 0;
    goto LABEL_14;
  }
  v10 = *((_DWORD *)this + 6);
  v73 = *((_DWORD *)this + 5);
  v69 = 0;
  v70 = *((_DWORD *)this + 7);
  v67 = 0;
  v78 = *((_DWORD *)this + 13);
  v68 = v78;
  if ( *((_DWORD *)this + 66) )
    v10 = CardStack::CalculateArrangeOffset(this, v10, *((_DWORD *)this + 7));
LABEL_14:
  v15 = 0;
  v72 = 0;
  if ( *((int *)this + 12) > 0 )
  {
    v15 = v3 - *((_DWORD *)this + 12);
    v72 = v15;
  }
  v16 = (__int64 *)*((_QWORD *)this + 40);
  v17 = *v16;
  NodeBase::MoveToFront(*(NodeBase **)(*v16 + 64));
  if ( *((_DWORD *)this + 11) == 1 || *((int *)this + 12) > 0 && !v15 )
  {
    v19 = *(_QWORD *)(v17 + 64);
    *(_BYTE *)(v17 + 16) = 1;
    if ( *(_BYTE *)(v19 + 41) == 1 )
      goto LABEL_24;
    *(_BYTE *)(v19 + 41) = 1;
  }
  else
  {
    v18 = *(_QWORD *)(v17 + 64);
    *(_BYTE *)(v17 + 16) = 0;
    if ( !*(_BYTE *)(v18 + 41) )
      goto LABEL_24;
    *(_BYTE *)(v18 + 41) = 0;
  }
  v20 = g_pRenderManager;
  *((_BYTE *)g_pRenderManager + 88) = 1;
  *((_BYTE *)v20 + 20) = 1;
LABEL_24:
  v21 = 0.0;
  if ( a2 )
  {
    v22 = *((_DWORD *)this + 82);
    v23 = 0;
    if ( v22 == 2 || v22 == 3 )
    {
      v24 = *(_DWORD *)(*(_QWORD *)(v17 + 64) + 12LL) == *(_DWORD *)(*((_QWORD *)this + 18) + 12LL);
    }
    else
    {
      if ( v22 > 1 )
        goto LABEL_31;
      v24 = *(_DWORD *)(*(_QWORD *)(v17 + 64) + 8LL) == *(_DWORD *)(*((_QWORD *)this + 18) + 8LL);
    }
    v23 = v24;
LABEL_31:
    if ( *((_DWORD *)this + 76) <= 1u || *((_DWORD *)this + 11) != 1 || (v24 = !v23, v25 = 1, v24) )
      v25 = 0;
    v26 = *((_QWORD *)this + 18);
    v27 = *(_DWORD *)(v26 + 8);
    v28 = *(_DWORD *)(v26 + 12);
    v29 = *(_QWORD *)(v17 + 64);
    v30 = *(_DWORD *)(v29 + 8);
    if ( v30 == v27 && *(_DWORD *)(v29 + 12) == v28 )
    {
      CardTable::ClearMovementAnimation(*(CardTable **)(v17 + 24), (struct Card *)v17);
    }
    else
    {
      CardTable::AddMovementAnimation(
        *(CardTable **)(v17 + 24),
        (struct Card *)v17,
        0.0,
        v30,
        *(_DWORD *)(v29 + 12),
        v27,
        v28,
        a3,
        0,
        v25);
      v75 = 1;
      if ( *((_DWORD *)this + 76) == 1 )
      {
        v8 = 0.0;
      }
      else
      {
        v31 = (float)(*((_DWORD *)this + 76) - 1);
        v32 = v31 * CardStack::ANIM_TIME_CONST;
        if ( (float)(v31 * CardStack::ANIM_TIME_CONST) > CardStack::ANIM_TIME_MAX_DELAY )
          v32 = CardStack::ANIM_TIME_MAX_DELAY;
        v8 = v32 / v31;
      }
      v21 = v8 + 0.0;
    }
    goto LABEL_45;
  }
  CardTable::ClearMovementAnimation(*((CardTable **)this + 37), (struct Card *)v17);
  NodeBase::SetPosition(
    *(NodeBase **)(v17 + 64),
    *(_DWORD *)(*((_QWORD *)this + 18) + 8LL),
    *(_DWORD *)(*(_QWORD *)(v17 + 64) + 12LL));
  NodeBase::SetPosition(
    *(NodeBase **)(v17 + 64),
    *(_DWORD *)(*(_QWORD *)(v17 + 64) + 8LL),
    *(_DWORD *)(*((_QWORD *)this + 18) + 12LL));
LABEL_45:
  v33 = 0;
  v34 = 0;
  if ( *(_BYTE *)(v17 + 18) || *(_BYTE *)(v17 + 19) )
  {
    v8 = 0.0;
    v75 = 1;
    v34 = v73 - v10;
  }
  v71 = 1;
  if ( *((_DWORD *)this + 76) > 1u )
  {
    v35 = 8;
    v74 = 8;
    do
    {
      v36 = *(_QWORD *)(v35 + *((_QWORD *)this + 40));
      if ( !v36 )
      {
        Log(0x10001u, L"CardStack::Arrange() - Got a null card from the card array.");
        return;
      }
      NodeBase::MoveToFront(*(NodeBase **)(v36 + 64));
      v37 = *((_DWORD *)this + 12);
      if ( v37 <= 0 || (int)v71 <= v72 )
      {
        v40 = *((_DWORD *)this + 11);
        if ( !(v71 % v40) )
        {
          if ( v40 == 1 || v37 > 0 && v71 == v72 )
          {
            v42 = *(_QWORD *)(v36 + 64);
            *(_BYTE *)(v36 + 16) = 1;
            if ( *(_BYTE *)(v42 + 41) != 1 )
            {
              *(_BYTE *)(v42 + 41) = 1;
LABEL_67:
              v43 = g_pRenderManager;
              *((_BYTE *)g_pRenderManager + 88) = 1;
              *((_BYTE *)v43 + 20) = 1;
            }
          }
          else
          {
            v41 = *(_QWORD *)(v36 + 64);
            *(_BYTE *)(v36 + 16) = 0;
            if ( *(_BYTE *)(v41 + 41) )
            {
              *(_BYTE *)(v41 + 41) = 0;
              goto LABEL_67;
            }
          }
          if ( *(_BYTE *)(v17 + 17) == 1 && *(_BYTE *)(v36 + 17) == 1 )
          {
            v33 += v9;
            v34 += v10;
          }
          else
          {
            v33 += v69;
            v34 += v70;
          }
          goto LABEL_81;
        }
        if ( !((v71 + 1) % v40) || v37 > 0 && v71 == v72 || v40 == 1 )
        {
          v45 = *(_QWORD *)(v36 + 64);
          *(_BYTE *)(v36 + 16) = 1;
          if ( *(_BYTE *)(v45 + 41) == 1 )
            goto LABEL_81;
          *(_BYTE *)(v45 + 41) = 1;
        }
        else
        {
          v44 = *(_QWORD *)(v36 + 64);
          *(_BYTE *)(v36 + 16) = 0;
          if ( !*(_BYTE *)(v44 + 41) )
            goto LABEL_81;
          *(_BYTE *)(v44 + 41) = 0;
        }
        v46 = g_pRenderManager;
        *((_BYTE *)g_pRenderManager + 88) = 1;
        *((_BYTE *)v46 + 20) = 1;
      }
      else
      {
        v38 = *(_QWORD *)(v36 + 64);
        *(_BYTE *)(v36 + 16) = 1;
        if ( *(_BYTE *)(v38 + 41) != 1 )
        {
          *(_BYTE *)(v38 + 41) = 1;
          v39 = g_pRenderManager;
          *((_BYTE *)g_pRenderManager + 20) = 1;
          *((_BYTE *)v39 + 88) = 1;
        }
        if ( *(_BYTE *)(v17 + 17) == 1 && *(_BYTE *)(v36 + 17) == 1 )
        {
          v33 += v11;
          v34 += v78;
        }
        else
        {
          v33 += v67;
          v34 += v68;
        }
      }
LABEL_81:
      if ( a2 )
      {
        v47 = *((_DWORD *)this + 82);
        v48 = 0;
        if ( v47 == 2 || v47 == 3 )
        {
          v49 = *(_DWORD *)(*(_QWORD *)(v36 + 64) + 12LL) == v34 + *(_DWORD *)(*((_QWORD *)this + 18) + 12LL);
LABEL_87:
          v48 = v49;
        }
        else if ( v47 <= 1 )
        {
          v49 = *(_DWORD *)(*(_QWORD *)(v36 + 64) + 8LL) == v33 + *(_DWORD *)(*((_QWORD *)this + 18) + 8LL);
          goto LABEL_87;
        }
        if ( *((_DWORD *)this + 76) <= 1u || *((_DWORD *)this + 11) != 1 || (v50 = 1, !v48) )
          v50 = 0;
        v51 = *((_QWORD *)this + 18);
        v52 = v34 + *(_DWORD *)(v51 + 12);
        v53 = v33 + *(_DWORD *)(v51 + 8);
        v54 = *(_QWORD *)(v36 + 64);
        v55 = *(_DWORD *)(v54 + 8);
        if ( v55 == v53 && *(_DWORD *)(v54 + 12) == v52 )
        {
          CardTable::ClearMovementAnimation(*(CardTable **)(v36 + 24), (struct Card *)v36);
        }
        else
        {
          CardTable::AddMovementAnimation(
            *(CardTable **)(v36 + 24),
            (struct Card *)v36,
            v21,
            v55,
            *(_DWORD *)(v54 + 12),
            v53,
            v52,
            a3,
            0,
            v50);
          if ( !v75 )
          {
            v75 = 1;
            v56 = *((_DWORD *)this + 76) - v71;
            if ( v56 )
            {
              v57 = (float)v56 * CardStack::ANIM_TIME_CONST;
              if ( v57 > CardStack::ANIM_TIME_MAX_DELAY )
                v57 = CardStack::ANIM_TIME_MAX_DELAY;
              v8 = v57 / (float)v56;
            }
            else
            {
              v8 = 0.0;
            }
          }
          v21 = v21 + v8;
        }
        goto LABEL_103;
      }
      CardTable::ClearMovementAnimation(*((CardTable **)this + 37), (struct Card *)v36);
      NodeBase::SetPosition(
        *(NodeBase **)(v36 + 64),
        v33 + *(_DWORD *)(*((_QWORD *)this + 18) + 8LL),
        *(_DWORD *)(*(_QWORD *)(v36 + 64) + 12LL));
      NodeBase::SetPosition(
        *(NodeBase **)(v36 + 64),
        *(_DWORD *)(*(_QWORD *)(v36 + 64) + 8LL),
        v34 + *(_DWORD *)(*((_QWORD *)this + 18) + 12LL));
LABEL_103:
      v17 = v36;
      if ( *(_BYTE *)(v36 + 18) || *(_BYTE *)(v36 + 19) )
      {
        v8 = 0.0;
        v75 = 1;
        v34 += v73 - v10;
      }
      v35 = v74 + 8;
      ++v71;
      v74 += 8;
    }
    while ( v71 < *((_DWORD *)this + 76) );
  }
  v58 = g_pRenderManager;
  if ( *((_DWORD *)this + 76) )
  {
    v59 = *(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1));
    v60 = *(_QWORD *)(v59 + 64);
    *(_BYTE *)(v59 + 16) = 1;
    if ( *(_BYTE *)(v60 + 41) != 1 )
    {
      *(_BYTE *)(v60 + 41) = 1;
      *((_BYTE *)v58 + 20) = 1;
      *((_BYTE *)v58 + 88) = 1;
    }
  }
  v61 = 1;
  v62 = 0;
  if ( *((int *)this + 12) > 0 )
    v61 = *((_DWORD *)this + 12);
  if ( v61 )
  {
    v63 = v61 + 1;
    do
    {
      v64 = *((_DWORD *)this + 76);
      if ( v63 > v64 )
        break;
      v65 = *(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (v64 - v62 - v61 - 1));
      v66 = *(_QWORD *)(v65 + 64);
      *(_BYTE *)(v65 + 16) = 1;
      if ( *(_BYTE *)(v66 + 41) != 1 )
      {
        *(_BYTE *)(v66 + 41) = 1;
        *((_BYTE *)v58 + 20) = 1;
        *((_BYTE *)v58 + 88) = 1;
      }
      ++v62;
      ++v63;
    }
    while ( v62 < v61 );
  }
  CardStack::ArrangeHighlight(this);
  if ( *((_BYTE *)this + 56) )
    CardStack::UpdateAccessibility(this);
  if ( *((_BYTE *)this + 57) )
    CardStack::ResizeAccessAreas(this);
}
