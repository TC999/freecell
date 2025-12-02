struct Card *__fastcall CardStack::Pop(CardStack *this)
{
  __int64 v2; // rdi
  int v4; // eax
  __int64 v5; // r8
  __int64 v6; // rcx
  RenderManager *v7; // rcx

  Log(0x10000u, L"CardStack::Pop()");
  v2 = *(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1));
  if ( v2 )
  {
    CardTable::PushAction(
      *((CardTable **)this + 37),
      5,
      *(const unsigned __int16 **)(v2 + 56),
      *((const unsigned __int16 **)this + 36));
    v4 = *((_DWORD *)this + 76);
    if ( v4 )
      *((_DWORD *)this + 76) = v4 - 1;
    if ( *((_BYTE *)this + 56) )
      CardStack::UpdateAccessibility(this);
    if ( *((_BYTE *)this + 57) )
      CardStack::ResizeAccessAreas(this);
    if ( *((_DWORD *)this + 76) )
    {
      v5 = *(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1));
      v6 = *(_QWORD *)(v5 + 64);
      *(_BYTE *)(v5 + 16) = 1;
      if ( *(_BYTE *)(v6 + 41) != 1 )
      {
        *(_BYTE *)(v6 + 41) = 1;
        v7 = g_pRenderManager;
        *((_BYTE *)g_pRenderManager + 20) = 1;
        *((_BYTE *)v7 + 88) = 1;
      }
    }
    return (struct Card *)v2;
  }
  else
  {
    Log(0x10001u, L"CardStack::Pop() - Popped and got a null card.");
    return 0;
  }
}
