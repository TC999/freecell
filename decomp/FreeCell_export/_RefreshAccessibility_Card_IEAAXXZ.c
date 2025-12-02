void __fastcall Card::RefreshAccessibility(Card *this)
{
  __int64 v1; // rax
  bool v3; // zf
  __int64 v4; // rdx
  int v5; // eax
  UserInterface *v6; // rcx
  const unsigned __int16 *v7; // rdx
  UserInterface *v8; // rcx
  __int64 v9; // rax
  unsigned __int8 (__fastcall *v10)(Card *); // rdx
  const unsigned __int16 *v11; // rdx
  unsigned __int8 (__fastcall *v12)(Card *); // r8

  v1 = *((_QWORD *)this + 12);
  v3 = *(_BYTE *)(v1 + 72) == 0;
  v4 = v1;
  v5 = *(_DWORD *)(v1 + 192);
  if ( v3 )
  {
    if ( *(_BYTE *)(v4 + 144) )
    {
      v8 = g_pUserInterface;
      *(_BYTE *)(v4 + 144) = 0;
      *(_DWORD *)(v4 + 192) = v5;
      UserInterface::Access_ClipNode(v8, (struct NodeBase *)v4);
    }
    v7 = &dword_1000028D4;
  }
  else
  {
    if ( *(_BYTE *)(v4 + 144) != 1 )
    {
      v6 = g_pUserInterface;
      *(_BYTE *)(v4 + 144) = 1;
      *(_DWORD *)(v4 + 192) = v5;
      UserInterface::Access_OnNodeAccessible(v6, (struct NodeBase *)v4);
    }
    v7 = L"|64717|CardButtonText|Click Card";
  }
  NodeBase::SetAccessDefaultAction(*((HLOCAL **)this + 12), v7);
  v9 = *((_QWORD *)this + 3);
  if ( *((_BYTE *)this + 17) )
  {
    v10 = *(unsigned __int8 (__fastcall **)(Card *))(v9 + 16);
    if ( !v10 || !v10(this) )
      NodeBase::SetAccessName(
        *((HLOCAL **)this + 12),
        (const unsigned __int16 *)(&Card::CARD_HUMAN_NAME)[*((unsigned int *)this + 2)]);
    v11 = (const unsigned __int16 *)(&Card::CARD_HUMAN_NAME)[*((unsigned int *)this + 2)];
  }
  else
  {
    v12 = *(unsigned __int8 (__fastcall **)(Card *))(v9 + 16);
    if ( !v12 || !v12(this) )
      NodeBase::SetAccessName(*((HLOCAL **)this + 12), L"|60374|CardNames|Face Down");
    v11 = L"|60374|CardNames|Face Down";
  }
  NodeBase::SetAccessDescription(*((HLOCAL **)this + 12), v11);
}
