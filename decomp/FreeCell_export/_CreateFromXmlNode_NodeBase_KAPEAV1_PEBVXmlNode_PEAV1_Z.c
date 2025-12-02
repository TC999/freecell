struct NodeBase *__fastcall NodeBase::CreateFromXmlNode(const wchar_t **a1, struct NodeBase *a2)
{
  struct NodeBase *v2; // rdi
  unsigned __int16 *v5; // rbp
  __int64 v6; // rbx
  __int64 v7; // rcx
  unsigned __int16 *v8; // rax
  int v9; // r9d
  int v10; // r8d
  const wchar_t *v11; // rax
  const wchar_t *v12; // rax
  unsigned int v13; // ecx
  RenderManager *v14; // rcx
  __int64 v15; // r8
  unsigned int v16; // eax
  _QWORD *v17; // rcx
  int v18; // edx
  void (__fastcall **v19)(__int64); // rax
  void (__fastcall ***GameEvent)(_QWORD, __int64); // rdi
  int v21; // [rsp+40h] [rbp+8h] BYREF

  v2 = a2;
  if ( !a1 )
    return 0;
  if ( !a2 )
    v2 = (struct NodeBase *)*((_QWORD *)g_pRenderManager + 15);
  v5 = XmlNode::XPathAttributeSearchSingle((XmlNode *)a1, L"/@Type");
  if ( !v5 )
  {
    Log(0x100u, 337, "NodeBase.cpp", L"No type found in xml");
    return 0;
  }
  v6 = 0;
  v7 = 0;
  v21 = 0;
  if ( NodeBase::m_TypeList )
  {
    while ( 1 )
    {
      v8 = v5;
      do
      {
        v9 = *(unsigned __int16 *)((char *)v8 + (_BYTE *)qword_1000ACE90 + 48 * v7 - (_BYTE *)v5);
        v10 = *v8 - v9;
        if ( v10 )
          break;
        ++v8;
      }
      while ( v9 );
      if ( !v10 )
        break;
      v7 = (unsigned int)(v7 + 1);
      if ( (unsigned int)v7 >= NodeBase::m_TypeList )
        goto LABEL_15;
    }
    v6 = (*((__int64 (__fastcall **)(int *))qword_1000ACE90 + 6 * v7 + 5))(&v21);
  }
LABEL_15:
  operator delete(v5);
  if ( !v6 )
  {
    v11 = L"<no xml source file>";
    if ( a1[12] )
      v11 = a1[12];
    Log(0x100u, 360, "NodeBase.cpp", L"Unknown node type: %s, in xml: %s", v5, v11);
    return 0;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, const wchar_t **))(*(_QWORD *)v6 + 96LL))(v6, a1) )
  {
    v12 = L"<no xml source file>";
    if ( a1[12] )
      v12 = a1[12];
    Log(0x100u, 369, "NodeBase.cpp", L"Node Load() Failed for xml: %s", v12);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v6 + 104LL))(v6, 1);
    return 0;
  }
  if ( v21 == 1 || v21 == 2 || !v21 )
    v13 = 0;
  else
    v13 = g_uiNextHandle++;
  *(_DWORD *)(v6 + 68) = v13;
  if ( v2 )
    Array<IEventListener *>::Add((char *)v2 + 80, v6);
  v14 = g_pRenderManager;
  *(_QWORD *)(v6 + 136) = v2;
  v15 = *(_QWORD *)(*((_QWORD *)v14 + 7) + 8LL);
  v16 = 0;
  v17 = (_QWORD *)((char *)v14 + 96);
  v18 = 3;
  while ( *v17 != v15 )
  {
    ++v16;
    ++v17;
    if ( v16 >= 3 )
      goto LABEL_35;
  }
  v18 = v16;
LABEL_35:
  v19 = *(void (__fastcall ***)(__int64))v6;
  *(_DWORD *)(v6 + 360) = v18;
  (*v19)(v6);
  GameEvent = (void (__fastcall ***)(_QWORD, __int64))Event::CreateGameEvent(23);
  (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 16LL))(v6, GameEvent);
  if ( GameEvent )
    (**GameEvent)(GameEvent, 1);
  return (struct NodeBase *)v6;
}
