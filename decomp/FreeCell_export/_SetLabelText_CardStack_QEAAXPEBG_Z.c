void __fastcall CardStack::SetLabelText(CardStack *this, const unsigned __int16 *a2)
{
  __int64 v2; // rax
  RenderManager *v4; // rax
  __int64 v5; // rdx
  UserInterface *v6; // rcx
  __int64 v7; // r11
  RenderManager *v8; // rax
  __int64 v9; // rcx
  __int64 v10; // r11
  RenderManager *v11; // rax
  __int64 v12; // rcx

  v2 = *((_QWORD *)this + 19);
  if ( *(_BYTE *)(v2 + 41) != 1 )
  {
    *(_BYTE *)(v2 + 41) = 1;
    v4 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v4 + 88) = 1;
  }
  v5 = *((_QWORD *)this + 19);
  if ( *(_BYTE *)(v5 + 144) != 1 )
  {
    v6 = g_pUserInterface;
    *(_BYTE *)(v5 + 144) = 1;
    *(_DWORD *)(v5 + 192) = 41;
    UserInterface::Access_OnNodeAccessible(v6, (struct NodeBase *)v5);
  }
  (*(void (__fastcall **)(_QWORD, unsigned __int16 *))(**((_QWORD **)this + 19) + 112LL))(
    *((_QWORD *)this + 19),
    &word_1000B1D10);
  v7 = *((_QWORD *)this + 19);
  v8 = g_pRenderManager;
  if ( *(_DWORD *)(v7 + 404) != -1 )
  {
    *(_DWORD *)(v7 + 404) = -1;
    *((_BYTE *)v8 + 20) = 1;
    *((_BYTE *)v8 + 88) = 1;
  }
  v9 = *((_QWORD *)this + 20);
  if ( *(_BYTE *)(v9 + 41) != 1 )
  {
    *(_BYTE *)(v9 + 41) = 1;
    *((_BYTE *)v8 + 20) = 1;
    *((_BYTE *)v8 + 88) = 1;
  }
  (*(void (__fastcall **)(_QWORD, unsigned __int16 *))(**((_QWORD **)this + 20) + 112LL))(
    *((_QWORD *)this + 20),
    &word_1000B1D10);
  v10 = *((_QWORD *)this + 20);
  v11 = g_pRenderManager;
  if ( *(_DWORD *)(v10 + 404) != -16777216 )
  {
    *(_DWORD *)(v10 + 404) = -16777216;
    *((_BYTE *)v11 + 20) = 1;
    *((_BYTE *)v11 + 88) = 1;
  }
  v12 = *((_QWORD *)this + 20);
  if ( *(_DWORD *)(v12 + 396) != 64 )
  {
    *(_DWORD *)(v12 + 396) = 64;
    *((_BYTE *)v11 + 20) = 1;
    *((_BYTE *)v11 + 88) = 1;
  }
}
