bool __fastcall Audio::StartEffect(Audio *this, unsigned int a2, char a3, unsigned int *a4)
{
  Audio *v4; // r12
  struct ResourceBase *Resource; // rax
  struct ResourceBase *v8; // rsi
  __int64 v9; // rbp
  bool v10; // zf
  __int64 v11; // rbx
  BOOL v12; // edi
  unsigned int v13; // eax
  unsigned int EffectBufferVolume; // eax
  _BYTE v15[40]; // [rsp+20h] [rbp-28h] BYREF
  Audio *v16; // [rsp+50h] [rbp+8h] BYREF

  v16 = this;
  v4 = g_pAudio;
  LOBYTE(v16) = 0;
  if ( !*((_QWORD *)g_pAudio + 2) )
    return 0;
  Resource = ResourceManager::GetResource(g_pResourceManager, a2, 0);
  v8 = Resource;
  if ( !Resource )
    return 0;
  if ( !(*(unsigned __int8 (__fastcall **)(struct ResourceBase *))(*(_QWORD *)Resource + 8LL))(Resource) )
    return 0;
  v9 = (*(__int64 (__fastcall **)(struct ResourceBase *, _BYTE *))(*(_QWORD *)v8 + 72LL))(v8, v15);
  if ( !v9
    || !(*(unsigned __int8 (__fastcall **)(struct ResourceBase *, __int64, Audio **))(*(_QWORD *)v8 + 88LL))(
          v8,
          v9,
          &v16) )
  {
    return 0;
  }
  v10 = a3 == 0;
  v11 = *(_QWORD *)v9;
  v12 = !v10;
  v13 = (*(__int64 (__fastcall **)(struct ResourceBase *, _QWORD))(*(_QWORD *)v8 + 120LL))(v8, 0);
  EffectBufferVolume = Audio::GetEffectBufferVolume(v4, v13);
  (*(void (__fastcall **)(__int64, _QWORD))(v11 + 120))(v9, EffectBufferVolume);
  (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 104LL))(v9, 0);
  return (*(int (__fastcall **)(__int64, _QWORD, _QWORD, BOOL))(*(_QWORD *)v9 + 96LL))(v9, 0, 0, v12) >= 0;
}
