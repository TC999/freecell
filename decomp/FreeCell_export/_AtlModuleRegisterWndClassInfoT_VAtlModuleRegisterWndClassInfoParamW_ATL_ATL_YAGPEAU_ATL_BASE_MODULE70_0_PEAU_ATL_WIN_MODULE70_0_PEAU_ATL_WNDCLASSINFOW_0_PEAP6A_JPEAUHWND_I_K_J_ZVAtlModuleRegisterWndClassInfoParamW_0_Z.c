__int16 __fastcall ATL::AtlModuleRegisterWndClassInfoT<ATL::AtlModuleRegisterWndClassInfoParamW>(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _QWORD *a4)
{
  const WCHAR *v6; // rdx
  __int64 v7; // rbx
  __int64 v8; // rsi
  __int64 v10; // r11
  HINSTANCE v11; // rcx
  HINSTANCE v12; // rax
  __int16 ClassInfo; // ax
  ATOM v14; // ax
  int v15; // ecx
  ATOM v16; // si
  int v17; // ebx
  char *v18; // rax
  char *v19; // r11
  ATOM *v20; // rdx
  tagWNDCLASSEXW wcx; // [rsp+20h] [rbp-A8h] BYREF
  struct tagWNDCLASSEXW v22; // [rsp+70h] [rbp-58h] BYREF

  if ( !a3 || !a4 )
    return 0;
  if ( !*(_WORD *)(a3 + 108) )
  {
    EnterCriticalSection(&CriticalSection);
    if ( *(_WORD *)(a3 + 108) )
      goto LABEL_29;
    v6 = *(const WCHAR **)(a3 + 80);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a3 + 64);
      v8 = *(_QWORD *)(a3 + 8);
      wcx.cbSize = 80;
      if ( !GetClassInfoExW(0, v6, &wcx) && !GetClassInfoExW(hInstance, *(LPCWSTR *)(a3 + 80), &wcx) )
      {
        LeaveCriticalSection(&CriticalSection);
        return 0;
      }
      memcpy((void *)a3, &wcx, 0x50u);
      v10 = *(_QWORD *)(a3 + 8);
      *(_QWORD *)(a3 + 64) = v7;
      *(_QWORD *)(a3 + 88) = v10;
      *(_QWORD *)(a3 + 8) = v8;
    }
    else
    {
      v11 = (HINSTANCE)qword_1000AE760;
      if ( *(_DWORD *)(a3 + 104) )
        v11 = 0;
      *(_QWORD *)(a3 + 40) = LoadCursorW(v11, *(LPCWSTR *)(a3 + 96));
    }
    v12 = hInstance;
    *(_DWORD *)(a3 + 4) &= ~0x4000u;
    *(_QWORD *)(a3 + 24) = v12;
    if ( !*(_QWORD *)(a3 + 64) )
    {
      swprintf_s((wchar_t *const)(a3 + 110), 0x45u, L"ATL:%p", a3);
      *(_QWORD *)(a3 + 64) = a3 + 110;
    }
    memcpy(&v22, (const void *)a3, sizeof(v22));
    ClassInfo = GetClassInfoExW(*(HINSTANCE *)(a3 + 24), *(LPCWSTR *)(a3 + 64), &v22);
    *(_WORD *)(a3 + 108) = ClassInfo;
    if ( ClassInfo )
      goto LABEL_29;
    v14 = RegisterClassExW((const WNDCLASSEXW *)a3);
    v15 = dword_1000AE7F0;
    v16 = v14;
    if ( dword_1000AE7F0 != dword_1000AE7F4 )
    {
      v19 = (char *)qword_1000AE7E8;
      goto LABEL_25;
    }
    if ( dword_1000AE7F4 )
    {
      v17 = 2 * dword_1000AE7F0;
      if ( (dword_1000AE7F0 & 0x40000000) != 0 || (unsigned int)v17 > 0x3FFFFFFF )
        goto LABEL_28;
    }
    else
    {
      v17 = 1;
    }
    v18 = (char *)_recalloc(qword_1000AE7E8, v17, 2u);
    v19 = v18;
    if ( v18 )
    {
      v15 = dword_1000AE7F0;
      dword_1000AE7F4 = v17;
      qword_1000AE7E8 = v18;
LABEL_25:
      v20 = (ATOM *)&v19[2 * v15];
      if ( v20 )
      {
        *v20 = v16;
        v15 = dword_1000AE7F0;
      }
      dword_1000AE7F0 = v15 + 1;
    }
LABEL_28:
    *(_WORD *)(a3 + 108) = v16;
LABEL_29:
    LeaveCriticalSection(&CriticalSection);
  }
  if ( *(_QWORD *)(a3 + 80) )
    *a4 = *(_QWORD *)(a3 + 88);
  return *(_WORD *)(a3 + 108);
}
