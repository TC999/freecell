void __fastcall FreeCellGame::SetAnimationEnabled(FreeCellGame *this, char a2)
{
  char v4; // bl
  __int64 v5; // rax
  char v6; // cl
  char v7; // si
  __int64 v8; // rax
  _DWORD v9[76]; // [rsp+20h] [rbp-138h] BYREF
  int pvParam; // [rsp+168h] [rbp+10h] BYREF

  (*(void (__fastcall **)(_QWORD, _DWORD *))(**((_QWORD **)g_pRenderManager + 10) + 56LL))(
    *((_QWORD *)g_pRenderManager + 10),
    v9);
  v4 = 0;
  if ( v9[0] != 3 )
    v4 = a2;
  pvParam = 1;
  SystemParametersInfoW(0x1042u, 0, &pvParam, 0);
  v5 = *((_QWORD *)this + 11);
  v6 = *(_BYTE *)(v5 + 30);
  v7 = pvParam != 0 ? v4 : 0;
  *(_BYTE *)(v5 + 30) = v7;
  if ( v6 != *(_BYTE *)(*((_QWORD *)this + 11) + 30LL) && !a2 )
    CardAnimationManager::FinishAllAnimations(*(CardAnimationManager **)(*((_QWORD *)this + 22) + 88LL));
  **(_BYTE **)(*((_QWORD *)this + 22) + 88LL) = v7;
  v8 = *((_QWORD *)this + 42);
  if ( v8 )
    *(_BYTE *)(v8 + 145) = v7;
}
