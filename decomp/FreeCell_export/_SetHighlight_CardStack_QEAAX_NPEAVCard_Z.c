void __fastcall CardStack::SetHighlight(CardStack *this, char a2, struct Card *a3)
{
  const wchar_t *v6; // r8
  Card *v7; // rcx
  __int64 v8; // rcx
  RenderManager *v9; // rax
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // r11
  RenderManager *v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rcx

  v6 = L"false";
  if ( a2 )
    v6 = L"true";
  Log(0x10000u, L"CardStack::SetHighlight()::bHighlight == %s", v6);
  v7 = (Card *)*((_QWORD *)this + 28);
  if ( v7 )
  {
    Card::SetHighlight(v7, 0);
    *((_QWORD *)this + 28) = 0;
  }
  if ( a3 )
  {
    Card::SetHighlight(a3, 0);
    CardStack::ArrangeHighlight((NodeBase **)this);
  }
  v8 = *((_QWORD *)this + 21);
  v9 = g_pRenderManager;
  if ( *(_BYTE *)(v8 + 41) )
  {
    *(_BYTE *)(v8 + 41) = 0;
    *((_BYTE *)v9 + 20) = 1;
    *((_BYTE *)v9 + 88) = 1;
  }
  v10 = *((_QWORD *)this + 22);
  if ( *(_BYTE *)(v10 + 41) )
  {
    *(_BYTE *)(v10 + 41) = 0;
    *((_BYTE *)v9 + 20) = 1;
    *((_BYTE *)v9 + 88) = 1;
  }
  v11 = *((_QWORD *)this + 23);
  if ( *(_BYTE *)(v11 + 41) )
  {
    *(_BYTE *)(v11 + 41) = 0;
    *((_BYTE *)v9 + 20) = 1;
    *((_BYTE *)v9 + 88) = 1;
  }
  if ( a2 == 1 && *((_DWORD *)this + 76) )
  {
    if ( !a3 )
      a3 = (struct Card *)**((_QWORD **)this + 40);
    if ( (unsigned int)CardStack::GetCardLocation(this, a3) != -1 )
    {
      *((_QWORD *)this + 28) = a3;
      Card::SetHighlight(a3, 1);
      v12 = *((_QWORD *)this + 21);
      v13 = g_pRenderManager;
      if ( *(_BYTE *)(v12 + 41) != 1 )
      {
        *(_BYTE *)(v12 + 41) = 1;
        *((_BYTE *)v13 + 20) = 1;
        *((_BYTE *)v13 + 88) = 1;
      }
      v14 = *((_QWORD *)this + 22);
      if ( *(_BYTE *)(v14 + 41) != 1 )
      {
        *(_BYTE *)(v14 + 41) = 1;
        *((_BYTE *)v13 + 20) = 1;
        *((_BYTE *)v13 + 88) = 1;
      }
      v15 = *((_QWORD *)this + 23);
      if ( *(_BYTE *)(v15 + 41) != 1 )
      {
        *(_BYTE *)(v15 + 41) = 1;
        *((_BYTE *)v13 + 20) = 1;
        *((_BYTE *)v13 + 88) = 1;
      }
      CardStack::ArrangeHighlight((NodeBase **)this);
    }
  }
}
