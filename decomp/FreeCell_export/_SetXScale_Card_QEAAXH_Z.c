void __fastcall Card::SetXScale(Card *this, int a2)
{
  __int64 v2; // r9
  RenderManager *v3; // rax
  UserInterface *v4; // r8
  __int64 v5; // rcx

  v2 = *((_QWORD *)this + 13);
  v3 = g_pRenderManager;
  v4 = g_pUserInterface;
  if ( *(_DWORD *)(v2 + 28) != a2 )
  {
    *(_DWORD *)(v2 + 28) = a2;
    *((_BYTE *)v3 + 20) = 1;
    *((_BYTE *)v3 + 88) = 1;
    *((_BYTE *)v4 + 275) = 1;
  }
  v5 = *((_QWORD *)this + 10);
  if ( *(_DWORD *)(v5 + 28) != a2 )
  {
    *(_DWORD *)(v5 + 28) = a2;
    *((_BYTE *)v3 + 20) = 1;
    *((_BYTE *)v3 + 88) = 1;
    *((_BYTE *)v4 + 275) = 1;
  }
}
