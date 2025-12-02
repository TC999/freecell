void __fastcall CardAnimationManager::FinishAllAnimations(CardAnimationManager *this)
{
  unsigned int v2; // ecx
  unsigned int v3; // r10d
  __int64 v4; // r9
  __int64 v5; // rdx
  unsigned int v6; // ecx
  __int64 v7; // r8
  __int64 v8; // rcx
  __int64 v9; // rdi
  __int64 v10; // rbx
  __int64 v11; // rcx
  int v12; // ecx
  int v13; // ecx
  RenderManager *v14; // r9
  __int64 v15; // rax
  UserInterface *v16; // r10
  __int64 v17; // rcx
  __int64 v18; // r9
  __int64 v19; // r10
  __int64 v20; // rax
  __int64 v21; // rcx
  __int64 v22; // r9
  __int64 v23; // r10
  __int64 v24; // rax
  __int64 v25; // rcx
  int v26; // r8d
  int *v27; // rcx

  v2 = *((_DWORD *)this + 10);
  v3 = 0;
  if ( (v2 & 0xFFFFFFFE) != 0 )
  {
    v4 = 0;
    do
    {
      v5 = *((_QWORD *)this + 7);
      v6 = v2 - v3++;
      v7 = *(_QWORD *)(v4 + v5);
      v8 = (int)(v6 - 1);
      *(_QWORD *)(v4 + v5) = *(_QWORD *)(v5 + 8 * v8);
      v4 += 8;
      *(_QWORD *)(*((_QWORD *)this + 7) + 8 * v8) = v7;
      v2 = *((_DWORD *)this + 10);
    }
    while ( v3 < v2 >> 1 );
  }
  if ( *((_DWORD *)this + 10) )
  {
    while ( 1 )
    {
      v9 = *(_QWORD *)(*((_QWORD *)this + 7) + 8LL * (unsigned int)(*((_DWORD *)this + 10) - 1));
      if ( *(_QWORD *)(v9 + 24) )
      {
        do
        {
          v10 = *(_QWORD *)(v9 + 24);
          CardAnimationManager::RemoveAnimation((CardTable **)this, (struct CardAnimationManager::CardAnimation *)v9, 1);
          v9 = v10;
        }
        while ( *(_QWORD *)(v10 + 24) );
      }
      v11 = *(_QWORD *)(v9 + 8);
      if ( !v11 && *(_DWORD *)(v9 + 76) != 2 )
        goto LABEL_32;
      if ( *(_BYTE *)(v9 + 69) && v11 )
        NodeBase::MoveToFront(*(NodeBase **)(v11 + 64));
      v12 = *(_DWORD *)(v9 + 76);
      if ( !v12 )
        break;
      v13 = v12 - 2;
      if ( v13 )
      {
        if ( v13 != 1 )
          goto LABEL_32;
        Card::SetFaceUp(*(Card **)(v9 + 8), 1, 1);
        Card::SetXScale(*(Card **)(v9 + 8), 100);
        v14 = g_pRenderManager;
        v15 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 96LL);
        v16 = g_pUserInterface;
        if ( *(_DWORD *)(v15 + 28) != 100 )
        {
          *(_DWORD *)(v15 + 28) = 100;
          *((_BYTE *)v14 + 20) = 1;
          *((_BYTE *)v14 + 88) = 1;
          *((_BYTE *)v16 + 275) = 1;
        }
        v17 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 96LL);
        if ( *(_DWORD *)(v17 + 32) != 100 )
        {
          *(_DWORD *)(v17 + 32) = 100;
          *((_BYTE *)v14 + 20) = 1;
          *((_BYTE *)v14 + 88) = 1;
          *((_BYTE *)v16 + 275) = 1;
        }
        NodeBase::SetPosition(
          *(NodeBase **)(*(_QWORD *)(v9 + 8) + 96LL),
          0,
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 96LL) + 12LL));
        NodeBase::SetPosition(
          *(NodeBase **)(*(_QWORD *)(v9 + 8) + 96LL),
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 96LL) + 8LL),
          0);
        v20 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 104LL);
        if ( *(_DWORD *)(v20 + 28) != 100 )
        {
          *(_DWORD *)(v20 + 28) = 100;
          *(_BYTE *)(v18 + 20) = 1;
          *(_BYTE *)(v18 + 88) = 1;
          *(_BYTE *)(v19 + 275) = 1;
        }
        v21 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 104LL);
        if ( *(_DWORD *)(v21 + 32) != 100 )
        {
          *(_DWORD *)(v21 + 32) = 100;
          *(_BYTE *)(v18 + 20) = 1;
          *(_BYTE *)(v18 + 88) = 1;
          *(_BYTE *)(v19 + 275) = 1;
        }
        NodeBase::SetPosition(
          *(NodeBase **)(*(_QWORD *)(v9 + 8) + 104LL),
          0,
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 104LL) + 12LL));
        NodeBase::SetPosition(
          *(NodeBase **)(*(_QWORD *)(v9 + 8) + 104LL),
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 104LL) + 8LL),
          0);
        v24 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 80LL);
        if ( !v24 )
          goto LABEL_32;
        if ( *(_DWORD *)(v24 + 28) != 100 )
        {
          *(_DWORD *)(v24 + 28) = 100;
          *(_BYTE *)(v22 + 20) = 1;
          *(_BYTE *)(v22 + 88) = 1;
          *(_BYTE *)(v23 + 275) = 1;
        }
        v25 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 80LL);
        if ( *(_DWORD *)(v25 + 32) != 100 )
        {
          *(_DWORD *)(v25 + 32) = 100;
          *(_BYTE *)(v22 + 20) = 1;
          *(_BYTE *)(v22 + 88) = 1;
          *(_BYTE *)(v23 + 275) = 1;
        }
        NodeBase::SetPosition(
          *(NodeBase **)(*(_QWORD *)(v9 + 8) + 80LL),
          0,
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 80LL) + 12LL));
        v26 = 0;
        v27 = *(int **)(*(_QWORD *)(v9 + 8) + 80LL);
        goto LABEL_31;
      }
      NodeBase::DeleteSelf(*(NodeBase **)(v9 + 16));
LABEL_32:
      CardAnimationManager::RemoveAnimation((CardTable **)this, (struct CardAnimationManager::CardAnimation *)v9, 1);
      if ( !*((_DWORD *)this + 10) )
        return;
    }
    NodeBase::SetPosition(
      *(NodeBase **)(*(_QWORD *)(v9 + 8) + 64LL),
      *(_DWORD *)(v9 + 52),
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 64LL) + 12LL));
    v26 = *(_DWORD *)(v9 + 56);
    v27 = *(int **)(*(_QWORD *)(v9 + 8) + 64LL);
LABEL_31:
    NodeBase::SetPosition((NodeBase *)v27, v27[2], v26);
    goto LABEL_32;
  }
}
