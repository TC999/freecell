void __fastcall Card::SetHighlight(Card *this, char a2)
{
  const wchar_t *v4; // r8
  __int64 v5; // r11
  RenderManager *v6; // rax

  v4 = L"false";
  if ( a2 )
    v4 = L"true";
  Log(0x10000u, L"Card::SetHighlight()::bHighlight == %s", v4);
  v5 = *((_QWORD *)this + 9);
  if ( *(_DWORD *)(v5 + 404) != 0xFFFFFF )
  {
    *(_DWORD *)(v5 + 404) = 0xFFFFFF;
    v6 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v6 + 88) = 1;
  }
  *((_BYTE *)this + 18) = a2;
}
