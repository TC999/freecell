void __fastcall Card::UpdateCardFace(Card *this)
{
  __int64 v2; // rcx
  unsigned int RankForType; // edi
  unsigned int SuitForType; // eax
  NodeSprite *v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rcx
  int v8; // r11d
  int v9; // ecx
  __int64 v10; // rax
  RenderManager *v11; // rax
  struct CardStack *CardStackWithCard; // rax
  CardStack *v13; // rbx

  Log(0x10000u, L"Card::UpdateCardFace()");
  if ( *((_BYTE *)this + 17) )
  {
    RankForType = Card::GetRankForType(*((_DWORD *)this + 2));
    SuitForType = Card::GetSuitForType(*((_DWORD *)this + 2));
    v5 = (NodeSprite *)*((_QWORD *)this + 13);
    if ( RankForType > 9 )
    {
      if ( RankForType == 13 )
      {
        NodeSprite::SetAnimation(v5, SuitForType);
        v7 = *((_QWORD *)this + 13);
        if ( !*(_DWORD *)(v7 + 384) )
          goto LABEL_13;
        *(_DWORD *)(v7 + 384) = 0;
      }
      else
      {
        NodeSprite::SetAnimation(v5, 4u);
        v9 = v8 + RankForType + 2 * v8 - 10;
        v10 = *((_QWORD *)this + 13);
        if ( v9 == *(_DWORD *)(v10 + 384) )
          goto LABEL_13;
        *(_DWORD *)(v10 + 384) = v9;
      }
    }
    else
    {
      NodeSprite::SetAnimation(v5, SuitForType);
      v6 = *((_QWORD *)this + 13);
      if ( RankForType == *(_DWORD *)(v6 + 384) )
        goto LABEL_13;
      *(_DWORD *)(v6 + 384) = RankForType;
    }
  }
  else
  {
    NodeSprite::SetAnimation(*((NodeSprite **)this + 13), 4u);
    v2 = *((_QWORD *)this + 13);
    if ( *(_DWORD *)(v2 + 384) == 12 )
      goto LABEL_13;
    *(_DWORD *)(v2 + 384) = 12;
  }
  v11 = g_pRenderManager;
  *((_BYTE *)g_pRenderManager + 88) = 1;
  *((_BYTE *)v11 + 20) = 1;
LABEL_13:
  CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)this + 3), this);
  v13 = CardStackWithCard;
  if ( CardStackWithCard )
  {
    if ( *((_BYTE *)CardStackWithCard + 56) )
      CardStack::UpdateAccessibility(CardStackWithCard);
    if ( *((_BYTE *)v13 + 57) )
      CardStack::ResizeAccessAreas(v13);
  }
}
