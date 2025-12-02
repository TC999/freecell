char __fastcall ResourceTextureD3D::CreateTextureFromSheet(
        const unsigned __int16 *Src,
        unsigned int a2,
        struct IDirect3DTexture9 **a3,
        unsigned int *a4,
        unsigned int *a5)
{
  __int64 v6; // rdi
  _WORD *v7; // rax
  _WORD *v8; // rbx
  __int64 v9; // r11
  __int64 v10; // r13
  __int64 v11; // rdi
  __int64 v12; // rsi
  unsigned int v13; // r15d
  _DWORD *v14; // rbp
  _DWORD *v15; // rsi
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rax
  __int64 v19; // rbx
  int v20; // eax
  int v21; // eax
  __int64 v22; // rcx
  int ImageWidth; // eax
  __int64 v24; // rcx
  int ImageHeight; // eax
  __int64 v26; // rcx
  int v27; // eax
  __int64 v28; // rcx
  int v29; // eax
  __int64 v30; // rbp
  unsigned int v31; // r13d
  unsigned int i; // r14d
  signed int v33; // eax
  signed int v34; // esi
  const unsigned __int16 *HResult; // rax
  int v36; // ecx
  RenderManager *v37; // rbx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  unsigned int j; // r11d
  __int64 v42; // r9
  __int64 v43; // r10
  __int64 v44; // rcx
  int v45; // r8d
  int v46; // eax
  int v47; // eax
  int v49; // eax
  int v50; // eax
  __int64 v51; // [rsp+20h] [rbp-E8h]
  _DWORD *v52; // [rsp+20h] [rbp-E8h]
  __int64 v53; // [rsp+28h] [rbp-E0h]
  __int64 v54; // [rsp+50h] [rbp-B8h] BYREF
  unsigned int v55; // [rsp+58h] [rbp-B0h] BYREF
  int v56; // [rsp+5Ch] [rbp-ACh] BYREF
  struct IDirect3DTexture9 *v57; // [rsp+60h] [rbp-A8h] BYREF
  _DWORD v58[4]; // [rsp+68h] [rbp-A0h] BYREF
  _DWORD v59[2]; // [rsp+78h] [rbp-90h] BYREF
  int v60; // [rsp+80h] [rbp-88h]
  int v61; // [rsp+84h] [rbp-84h]
  __int64 v62; // [rsp+88h] [rbp-80h]
  _DWORD v63[2]; // [rsp+98h] [rbp-70h] BYREF
  int v64; // [rsp+A0h] [rbp-68h]
  int v65; // [rsp+A4h] [rbp-64h]
  __int64 v66; // [rsp+A8h] [rbp-60h]
  int v67; // [rsp+B8h] [rbp-50h] BYREF
  __int64 v68; // [rsp+C0h] [rbp-48h]
  unsigned int v69; // [rsp+118h] [rbp+10h] BYREF
  struct IDirect3DTexture9 **v70; // [rsp+120h] [rbp+18h]
  unsigned int *v71; // [rsp+128h] [rbp+20h]

  v71 = a4;
  v70 = a3;
  v6 = a2;
  v7 = operator new[](saturated_mul(a2, 2u));
  v8 = v7;
  if ( !v7 )
    return 0;
  memcpy(v7, Src, 2 * v6);
  v9 = (unsigned int)(v6 - 2);
  v8[v9] = 103;
  v10 = (unsigned int)(v6 - 3);
  v8[v10] = 112;
  v11 = (unsigned int)(v6 - 4);
  v12 = (unsigned int)v9;
  v8[v11] = 106;
  v13 = 1;
  v14 = operator new(0x20u);
  if ( v14 )
  {
    *(_QWORD *)v14 = &FileMgrStream::`vftable';
    v14[6] = 1;
    *((_QWORD *)v14 + 1) = 0;
    v14[4] = 0;
    v14[5] = 0;
    *((_BYTE *)v14 + 28) = 1;
  }
  else
  {
    v14 = 0;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(_DWORD *, _WORD *, _QWORD))(*(_QWORD *)v14 + 112LL))(v14, v8, 0) )
  {
    Log(4u, 774, "ResourceTexture.cpp", L"Color sheet for %s doesn't exist", Src);
LABEL_7:
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v14 + 16LL))(v14);
    operator delete(v8);
    return 0;
  }
  v8[v12] = 112;
  v8[v10] = 109;
  v8[v11] = 98;
  v15 = operator new(0x20u);
  if ( v15 )
  {
    v15[6] = 1;
    *((_QWORD *)v15 + 1) = 0;
    v15[4] = 0;
    v15[5] = 0;
    *((_BYTE *)v15 + 28) = 1;
    *(_QWORD *)v15 = &FileMgrStream::`vftable';
  }
  else
  {
    v15 = 0;
  }
  if ( !(*(unsigned __int8 (__fastcall **)(_DWORD *, _WORD *, _QWORD))(*(_QWORD *)v15 + 112LL))(v15, v8, 0) )
  {
    Log(4u, 790, "ResourceTexture.cpp", L"Alpha sheet for %s doesn't exist", Src);
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v15 + 16LL))(v15);
    goto LABEL_7;
  }
  operator delete(v8);
  v16 = GdipAlloc(24);
  v17 = v16;
  if ( v16 )
  {
    *(_QWORD *)v16 = &Gdiplus::Image::`vftable';
    v54 = 0;
    *(_DWORD *)(v16 + 16) = GdipCreateBitmapFromStream(v14, &v54);
    *(_QWORD *)(v17 + 8) = v54;
  }
  else
  {
    v17 = 0;
  }
  v18 = GdipAlloc(24);
  v19 = v18;
  if ( v18 )
  {
    *(_QWORD *)v18 = &Gdiplus::Image::`vftable';
    v54 = 0;
    *(_DWORD *)(v18 + 16) = GdipCreateBitmapFromStream(v15, &v54);
    *(_QWORD *)(v19 + 8) = v54;
  }
  else
  {
    v19 = 0;
  }
  (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v14 + 16LL))(v14);
  (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v15 + 16LL))(v15);
  v20 = *(_DWORD *)(v17 + 16);
  *(_DWORD *)(v17 + 16) = 0;
  if ( v20 )
  {
    *(_DWORD *)(v17 + 16) = 0;
    Log(4u, 810, "ResourceTexture.cpp", L"Error in Gdiplus, loading color sheet %s. Status=%d", Src, 0);
    (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1);
    if ( !v19 )
      return 0;
LABEL_74:
    (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1);
    return 0;
  }
  v21 = *(_DWORD *)(v19 + 16);
  *(_DWORD *)(v19 + 16) = 0;
  if ( v21 )
  {
    *(_DWORD *)(v19 + 16) = 0;
    Log(4u, 817, "ResourceTexture.cpp", L"Error in Gdiplus, loading alpha sheet %s. Status=%d", Src, 0);
LABEL_73:
    (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1);
    goto LABEL_74;
  }
  v22 = *(_QWORD *)(v17 + 8);
  v56 = 0;
  ImageWidth = GdipGetImageWidth(v22, &v56);
  if ( ImageWidth )
    *(_DWORD *)(v17 + 16) = ImageWidth;
  v24 = *(_QWORD *)(v17 + 8);
  LODWORD(v54) = 0;
  ImageHeight = GdipGetImageHeight(v24, &v54);
  if ( ImageHeight )
    *(_DWORD *)(v17 + 16) = ImageHeight;
  v26 = *(_QWORD *)(v19 + 8);
  v69 = 0;
  v27 = GdipGetImageWidth(v26, &v69);
  if ( v27 )
    *(_DWORD *)(v19 + 16) = v27;
  v28 = *(_QWORD *)(v19 + 8);
  v55 = 0;
  v29 = GdipGetImageHeight(v28, &v55);
  if ( v29 )
    *(_DWORD *)(v19 + 16) = v29;
  v30 = v69;
  if ( v56 != v69 || (v31 = v55, (_DWORD)v54 != v55) )
  {
    Log(4u, 834, "ResourceTexture.cpp", L"Alpha and color dimensions don't match for %s", Src);
    goto LABEL_73;
  }
  for ( i = 1; i < v69; i *= 2 )
    ;
  if ( v55 > 1 )
  {
    do
      v13 *= 2;
    while ( v13 < v55 );
  }
  Log(4u, 861, "ResourceTexture.cpp", L"CreateTextureFromSheet() for %s", Src);
  v57 = 0;
  v33 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, _DWORD, int, int, struct IDirect3DTexture9 **, _QWORD))(**((_QWORD **)g_pRenderManager + 10) + 184LL))(
          *((_QWORD *)g_pRenderManager + 10),
          i,
          v13,
          1,
          0,
          21,
          1,
          &v57,
          0);
  v34 = v33;
  if ( v33 < 0 )
  {
    HResult = GetHResult(v33);
    LODWORD(v51) = v36;
    Log(4u, 879, "ResourceTexture.cpp", L"Error in CreateTexture: %x, %s, file: %s", v51, HResult, Src);
    (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1);
    (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1);
    if ( v34 == -2005532292 )
      Engine_ResourceLoadFail();
    if ( v34 == -2005530520 )
    {
      v37 = g_pRenderManager;
      RenderManager::SetEngineState((__int64)g_pRenderManager, 0x104u);
      *((_BYTE *)v37 + 209) = 1;
    }
    return 0;
  }
  v61 = 198659;
  v58[2] = v30;
  v58[3] = v31;
  v63[1] = 0;
  v63[0] = 0;
  v65 = 2498570;
  v66 = 0;
  v64 = 0;
  v59[1] = 0;
  v59[0] = 0;
  v62 = 0;
  v60 = 0;
  v58[0] = 0;
  v58[1] = 0;
  v38 = GdipBitmapLockBits(*(_QWORD *)(v17 + 8), v58, 1);
  if ( v38 )
    *(_DWORD *)(v17 + 16) = v38;
  else
    v38 = 0;
  if ( v38 )
  {
    LODWORD(v53) = v38;
    Log(4u, 924, "ResourceTexture.cpp", L"Can't lock color source for %s, status %d", Src, v53);
    (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1);
    goto LABEL_74;
  }
  v52 = v59;
  v39 = GdipBitmapLockBits(*(_QWORD *)(v19 + 8), v58, 1);
  if ( v39 )
    *(_DWORD *)(v19 + 16) = v39;
  else
    v39 = 0;
  if ( v39 )
  {
    LODWORD(v53) = v39;
    Log(4u, 935, "ResourceTexture.cpp", L"Can't lock alpha source for %s, status %d", Src, v53);
    v40 = GdipBitmapUnlockBits(*(_QWORD *)(v17 + 8), v63);
    if ( v40 )
      *(_DWORD *)(v17 + 16) = v40;
    goto LABEL_73;
  }
  if ( v60 < 0 || !v62 || !v66 )
  {
    Log(4u, 951, "ResourceTexture.cpp", L"Alpha source stride is negative for %s", Src);
    v49 = GdipBitmapUnlockBits(*(_QWORD *)(v17 + 8), v63);
    if ( v49 )
      *(_DWORD *)(v17 + 16) = v49;
    v50 = GdipBitmapUnlockBits(*(_QWORD *)(v19 + 8), v59);
    if ( v50 )
      *(_DWORD *)(v19 + 16) = v50;
    goto LABEL_73;
  }
  v67 = 0;
  v68 = 0;
  LODWORD(v52) = 0;
  ((void (__fastcall *)(struct IDirect3DTexture9 *, _QWORD, int *, _QWORD, _DWORD *))v57->lpVtbl->LockRect)(
    v57,
    0,
    &v67,
    0,
    v52);
  for ( j = 0; j < v31; ++j )
  {
    v42 = 0;
    if ( (_DWORD)v30 )
    {
      v43 = v30;
      do
      {
        v44 = v42 + ((unsigned __int64)(v67 * j) >> 2);
        v45 = (*(unsigned __int8 *)(v42 + v60 * j + v62) << 24)
            | *(_DWORD *)(v66 + 4 * (v42 + ((unsigned __int64)(v64 * j) >> 2))) & 0xFFFFFF;
        ++v42;
        --v43;
        *(_DWORD *)(v68 + 4 * v44) = v45;
      }
      while ( v43 );
    }
  }
  ((void (__fastcall *)(struct IDirect3DTexture9 *, _QWORD))v57->lpVtbl->UnlockRect)(v57, 0);
  v46 = GdipBitmapUnlockBits(*(_QWORD *)(v17 + 8), v63);
  if ( v46 )
    *(_DWORD *)(v17 + 16) = v46;
  v47 = GdipBitmapUnlockBits(*(_QWORD *)(v19 + 8), v59);
  if ( v47 )
    *(_DWORD *)(v19 + 16) = v47;
  (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1);
  (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1);
  *v70 = v57;
  *v71 = i;
  *a5 = v13;
  return 1;
}
