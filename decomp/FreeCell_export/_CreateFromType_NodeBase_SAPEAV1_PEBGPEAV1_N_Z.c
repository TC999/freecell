struct NodeBase *__fastcall NodeBase::CreateFromType(const unsigned __int16 *a1, struct NodeBase *a2, char a3)
{
  struct NodeBase *v3; // rdi
  __int64 v5; // rcx
  const unsigned __int16 *v6; // r8
  int v7; // r9d
  int v8; // eax
  __int64 v9; // rax
  __int64 v10; // rbx
  unsigned int v11; // ecx
  RenderManager *v12; // rcx
  __int64 v13; // r8
  unsigned int v14; // eax
  _QWORD *v15; // rcx
  int v16; // edx
  void (__fastcall **v17)(__int64); // rax
  void (__fastcall ***GameEvent)(_QWORD, __int64); // rdi
  int v20; // [rsp+50h] [rbp+18h] BYREF

  LOBYTE(v20) = a3;
  v3 = a2;
  if ( !a1 )
  {
    Log(0x100u, 199, "NodeBase.cpp", L"Zero passed in for type in CreateFromType");
    goto LABEL_12;
  }
  if ( !a2 )
    v3 = (struct NodeBase *)*((_QWORD *)g_pRenderManager + 15);
  v20 = 0;
  v5 = 0;
  if ( !NodeBase::m_TypeList )
    goto LABEL_11;
  while ( 1 )
  {
    v6 = a1;
    do
    {
      v7 = *(const unsigned __int16 *)((char *)v6 + (_BYTE *)qword_1000ACE90 + 48 * v5 - (_BYTE *)a1);
      v8 = *v6 - v7;
      if ( v8 )
        break;
      ++v6;
    }
    while ( v7 );
    if ( !v8 )
      break;
    v5 = (unsigned int)(v5 + 1);
    if ( (unsigned int)v5 >= NodeBase::m_TypeList )
      goto LABEL_11;
  }
  v9 = (*((__int64 (__fastcall **)(int *, __int64, const unsigned __int16 *))qword_1000ACE90 + 6 * v5 + 5))(
         &v20,
         6 * v5,
         v6);
  v10 = v9;
  if ( !v9 )
  {
LABEL_11:
    Log(0x100u, 229, "NodeBase.cpp", L"Could not create node from type - type %s not found", a1);
    goto LABEL_12;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 96LL))(v9, 0) )
  {
    Log(0x100u, 238, "NodeBase.cpp", L"Load(0) failed for CreateFromType: %s", a1);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 104LL))(v10, 1);
LABEL_12:
    SharedDialogs::FatalDialog::Show(0);
  }
  if ( v20 == 1 || v20 == 2 || !v20 )
    v11 = 0;
  else
    v11 = g_uiNextHandle++;
  *(_DWORD *)(v10 + 68) = v11;
  if ( v3 )
    Array<IEventListener *>::Add((char *)v3 + 80, v10);
  v12 = g_pRenderManager;
  *(_QWORD *)(v10 + 136) = v3;
  v13 = *(_QWORD *)(*((_QWORD *)v12 + 7) + 8LL);
  v14 = 0;
  v15 = (_QWORD *)((char *)v12 + 96);
  v16 = 3;
  while ( *v15 != v13 )
  {
    ++v14;
    ++v15;
    if ( v14 >= 3 )
      goto LABEL_28;
  }
  v16 = v14;
LABEL_28:
  v17 = *(void (__fastcall ***)(__int64))v10;
  *(_DWORD *)(v10 + 360) = v16;
  (*v17)(v10);
  GameEvent = (void (__fastcall ***)(_QWORD, __int64))Event::CreateGameEvent(23);
  (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 16LL))(v10, GameEvent);
  if ( GameEvent )
    (**GameEvent)(GameEvent, 1);
  return (struct NodeBase *)v10;
}
