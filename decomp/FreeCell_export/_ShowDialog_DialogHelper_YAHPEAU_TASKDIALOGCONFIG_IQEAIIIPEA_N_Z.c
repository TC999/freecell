__int64 __fastcall DialogHelper::ShowDialog(
        DialogHelper *this,
        struct _TASKDIALOGCONFIG *a2,
        int a3,
        unsigned int *const a4,
        bool *a5,
        unsigned __int16 a6)
{
  int (*v9)(const struct _TASKDIALOGCONFIG *, int *, int *, int *); // r10
  int (*v10)(const struct _TASKDIALOGCONFIG_OLD *, int *, int *); // r11
  bool v11; // zf
  HWND v12; // rcx
  BOOL v13; // eax
  unsigned int v14; // eax
  int v15; // r11d
  __int64 v16; // rax
  unsigned int v17; // ebx
  signed int v18; // ecx
  HWND v19; // rdx
  __int64 v21; // [rsp+38h] [rbp-C0h]
  _DWORD v22[4]; // [rsp+40h] [rbp-B8h] BYREF
  int v23; // [rsp+50h] [rbp-A8h] BYREF
  __int64 v24; // [rsp+58h] [rbp-A0h]
  __int64 v25; // [rsp+60h] [rbp-98h]
  int v26; // [rsp+68h] [rbp-90h]
  int v27; // [rsp+6Ch] [rbp-8Ch]
  __int64 v28; // [rsp+70h] [rbp-88h]
  __int64 v29; // [rsp+78h] [rbp-80h]
  __int64 v30; // [rsp+80h] [rbp-78h]
  __int64 v31; // [rsp+88h] [rbp-70h]
  int v32; // [rsp+90h] [rbp-68h]
  __int64 v33; // [rsp+98h] [rbp-60h]
  int v34; // [rsp+A0h] [rbp-58h]
  __int64 v35; // [rsp+A8h] [rbp-50h]
  __int64 v36; // [rsp+B0h] [rbp-48h]
  __int64 v37; // [rsp+B8h] [rbp-40h]
  __int64 v38; // [rsp+C0h] [rbp-38h]
  __int64 v39; // [rsp+C8h] [rbp-30h]
  __int64 v40; // [rsp+D0h] [rbp-28h]
  __int64 v41; // [rsp+D8h] [rbp-20h]
  __int64 v42; // [rsp+E0h] [rbp-18h]
  int v43; // [rsp+E8h] [rbp-10h]
  unsigned int v44; // [rsp+110h] [rbp+18h] BYREF

  if ( !a3 || !this )
    return 0xFFFFFFFFLL;
  v9 = DialogHelper::m_TaskDialogIndirect;
  v10 = DialogHelper::m_TaskDialogIndirectOld;
  if ( !DialogHelper::m_TaskDialogIndirect && !DialogHelper::m_TaskDialogIndirectOld || DialogHelper::m_bIsMediaCenter )
  {
    v19 = *(HWND *)((char *)this + 4);
    if ( !v19 )
      v19 = DialogHelper::m_hWnd;
    v17 = DialogHelper::DialogBoxMCE(
            (LPCWSTR)a6,
            v19,
            (HWND)DialogProc,
            (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
            0,
            (bool)a4,
            0,
            v21);
    goto LABEL_29;
  }
  v11 = *(_QWORD *)((char *)this + 4) == 0;
  *(_QWORD *)((char *)this + 12) = DialogHelper::m_hInstance;
  if ( v11 )
    *(_QWORD *)((char *)this + 4) = DialogHelper::m_hWnd;
  v12 = *(HWND *)((char *)this + 4);
  if ( v12 )
  {
    v13 = IsIconic(v12);
    v9 = DialogHelper::m_TaskDialogIndirect;
    v10 = DialogHelper::m_TaskDialogIndirectOld;
    if ( !v13 )
      *((_DWORD *)this + 5) |= 0x1000u;
  }
  v14 = 0;
  v44 = 0;
  if ( v9 )
  {
    v22[0] = 0;
    v15 = ((__int64 (__fastcall *)(DialogHelper *, unsigned int *, _QWORD, _DWORD *))v9)(this, &v44, 0, v22);
    if ( a5 )
      *a5 = v22[0] != 0;
  }
  else
  {
    if ( !v10 )
      goto LABEL_23;
    v16 = *(_QWORD *)((char *)this + 4);
    v22[0] = 0;
    v24 = v16;
    v25 = *(_QWORD *)((char *)this + 12);
    v26 = *((_DWORD *)this + 5);
    LODWORD(v16) = *((_DWORD *)this + 6);
    v23 = 160;
    v27 = v16;
    v28 = *(_QWORD *)((char *)this + 28);
    v29 = *(_QWORD *)((char *)this + 36);
    v30 = *(_QWORD *)((char *)this + 44);
    v31 = *(_QWORD *)((char *)this + 52);
    v32 = *((_DWORD *)this + 15);
    v33 = *((_QWORD *)this + 8);
    v34 = *((_DWORD *)this + 18);
    v35 = *(_QWORD *)((char *)this + 92);
    v36 = *(_QWORD *)((char *)this + 100);
    v37 = *(_QWORD *)((char *)this + 108);
    v38 = *(_QWORD *)((char *)this + 116);
    v39 = *(_QWORD *)((char *)this + 124);
    v40 = *(_QWORD *)((char *)this + 132);
    v41 = *(_QWORD *)((char *)this + 140);
    v42 = *(_QWORD *)((char *)this + 148);
    v43 = *((_DWORD *)this + 39);
    v15 = ((__int64 (__fastcall *)(int *, unsigned int *, _DWORD *, unsigned int *const))v10)(&v23, &v44, v22, a4);
    if ( a5 )
      *a5 = v22[0] != 0;
    *(_QWORD *)((char *)this + 4) = v24;
    *(_QWORD *)((char *)this + 12) = v25;
    *((_DWORD *)this + 5) = v26;
    *((_DWORD *)this + 6) = v27;
    *(_QWORD *)((char *)this + 28) = v28;
    *(_QWORD *)((char *)this + 36) = v29;
    *(_QWORD *)((char *)this + 44) = v30;
    *(_QWORD *)((char *)this + 52) = v31;
    *((_DWORD *)this + 15) = v32;
    *((_QWORD *)this + 8) = v33;
    *((_DWORD *)this + 18) = v34;
    *(_QWORD *)((char *)this + 92) = v35;
    *(_QWORD *)((char *)this + 100) = v36;
    *(_QWORD *)((char *)this + 108) = v37;
    *(_QWORD *)((char *)this + 116) = v38;
    *(_QWORD *)((char *)this + 124) = v39;
    *(_QWORD *)((char *)this + 132) = v40;
    *(_QWORD *)((char *)this + 140) = v41;
    *(_QWORD *)((char *)this + 148) = v42;
    *((_DWORD *)this + 39) = v43;
  }
  if ( !v15 )
  {
    v14 = v44;
    if ( v44 == 1 || v44 == 2 )
    {
      v17 = v44;
      goto LABEL_29;
    }
LABEL_23:
    v17 = -1;
    v18 = -1 - v14;
    if ( (int)(-1 - v14) >= 0 && v18 < a3 )
      v17 = *(&a2->cbSize + v18);
    goto LABEL_29;
  }
  v17 = -1;
LABEL_29:
  if ( DialogHelper::m_DialogShutdown )
    DialogHelper::m_DialogShutdown();
  return v17;
}
