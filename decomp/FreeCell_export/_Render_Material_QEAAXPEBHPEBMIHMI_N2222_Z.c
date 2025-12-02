void __fastcall Material::Render(
        Material *this,
        const int *a2,
        const __m128i *a3,
        int a4,
        int a5,
        float a6,
        unsigned int a7,
        bool a8,
        bool a9,
        bool a10,
        bool a11,
        bool a12)
{
  struct ResourceBase *Resource; // rax
  struct ResourceBase *v16; // rdi
  struct IDirect3DTexture9 *v17; // r9
  float v18; // xmm9_4
  float v19; // xmm7_4
  float v20; // xmm10_4
  float v21; // xmm8_4
  unsigned int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  struct IDirect3DTexture9 *SplitTexture; // r9
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  bool v33; // cl
  bool v34; // al
  int v35; // ecx
  __int32 v36; // eax
  unsigned int v37; // ebp
  float v38; // xmm8_4
  struct IDirect3DTexture9 *v39; // r9
  __int32 v40; // eax
  float v41; // xmm1_4
  struct IDirect3DTexture9 *v42; // r9
  __int32 v43; // eax
  __int32 v44; // r11d
  float v45; // xmm1_4
  float v46; // xmm2_4
  struct IDirect3DTexture9 *v47; // r9
  __int32 v48; // eax
  float v49; // xmm1_4
  struct IDirect3DTexture9 *v50; // r9
  int v51; // ecx
  __int32 v52; // eax
  ResourceTextureD3D *v53; // rcx
  float v54; // xmm11_4
  unsigned int v55; // edx
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  struct IDirect3DTexture9 *v59; // rax
  unsigned int v60; // ebx
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm1_4
  ResourceTextureD3D *v65; // rcx
  float v66; // xmm11_4
  unsigned int v67; // edx
  float v68; // xmm1_4
  float v69; // xmm2_4
  struct IDirect3DTexture9 *v70; // rax
  unsigned int v71; // ebx
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  unsigned int v75; // xmm0_4
  __int32 v76; // xmm1_4
  float v77; // xmm2_4
  unsigned int v78; // [rsp+64h] [rbp-C4h] BYREF
  unsigned int v79; // [rsp+68h] [rbp-C0h] BYREF
  unsigned int v80; // [rsp+6Ch] [rbp-BCh] BYREF
  __m128i v81; // [rsp+70h] [rbp-B8h] BYREF
  __m128i v82[8]; // [rsp+80h] [rbp-A8h] BYREF

  Resource = ResourceManager::GetResource(g_pResourceManager, a4, 0);
  v16 = Resource;
  if ( !Resource )
    return;
  if ( *((_DWORD *)Resource + 6) == 1
    && !(*(unsigned __int8 (__fastcall **)(struct ResourceBase *))(*(_QWORD *)Resource + 80LL))(Resource)
    || *((_DWORD *)v16 + 6) == 2 )
  {
    v17 = (struct IDirect3DTexture9 *)*((_QWORD *)v16 + 6);
    if ( v17 )
      Material::PostQuad(this, (const __m128i *)a2, a3, v17, a5, a6, a7, a8, a9, a10, a11, a12);
    return;
  }
  v18 = *(float *)a3->m128i_i32;
  v19 = *(float *)&a3->m128i_i32[1];
  v20 = *(float *)&a3->m128i_i32[2];
  v21 = *(float *)&a3->m128i_i32[3];
  if ( *(float *)a3->m128i_i32 < 0.5 )
  {
    if ( v20 < 0.5 && v19 >= 0.5 && v21 >= 0.5 )
    {
      ResourceTextureD3D::GetSplitDims(v16, 2u, &v80, &v79);
      v22 = 2;
      v23 = (float)(int)(2 * (0x400 / v80));
      v24 = (float)(0x400 / v79);
      v25 = (float)((float)(v19 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v24;
      v26 = (float)((float)(v21 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v24;
LABEL_12:
      v27 = v18 * v23;
      v28 = v20 * v23;
      goto LABEL_13;
    }
    if ( v20 < 0.5 && v19 < 0.5 && v21 < 0.5 )
    {
      v23 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v22 = 0;
      v25 = (float)(v19 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v26 = (float)(v21 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      goto LABEL_12;
    }
  }
  if ( v18 >= 0.5 )
  {
    if ( v20 >= 0.5 && v19 < 0.5 && v21 < 0.5 )
    {
      ResourceTextureD3D::GetSplitDims(v16, 1u, &v80, &v79);
      v22 = 1;
      v30 = (float)(0x400 / v80);
      v27 = (float)((float)(v18 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v30;
      v28 = (float)((float)(v20 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v30;
      v31 = (float)(int)(2 * (0x400 / v79));
      v25 = v19 * v31;
      v26 = v21 * v31;
LABEL_13:
      v81.m128i_i64[1] = __PAIR64__(LODWORD(v26), LODWORD(v28));
      v81.m128i_i64[0] = __PAIR64__(LODWORD(v25), LODWORD(v27));
      SplitTexture = ResourceTextureD3D::GetSplitTexture(v16, v22);
      if ( SplitTexture )
        Material::PostQuad(this, (const __m128i *)a2, &v81, SplitTexture, a5, a6, a7, a8, a9, a10, a11, a12);
      return;
    }
    if ( v20 >= 0.5 && v19 >= 0.5 && v21 >= 0.5 )
    {
      ResourceTextureD3D::GetSplitDims(v16, 3u, &v80, &v79);
      v18 = (float)(v18 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v20 = (float)(v20 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v22 = 3;
      v23 = (float)(0x400 / v80);
      v32 = (float)(0x400 / v79);
      v25 = (float)((float)(v19 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v32;
      v26 = (float)((float)(v21 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v32;
      goto LABEL_12;
    }
  }
  v33 = v18 < 0.5 && v20 >= 0.5 || v18 >= 0.5 && v20 < 0.5;
  v34 = v19 < 0.5 && v21 >= 0.5 || v19 >= 0.5 && v21 < 0.5;
  if ( v33 )
  {
    if ( v34 )
    {
      v35 = *a2;
      v36 = a2[1];
      v82[0].m128i_i32[0] = *a2;
      v82[0].m128i_i32[1] = v36;
      if ( v18 > v20 )
      {
        v37 = v82[0].m128i_u32[2];
      }
      else
      {
        v37 = (int)(float)((float)((float)((float)(a2[2] - v35) * (float)(0.5 - v18)) / (float)(v20 - v18)) + (float)v35);
        v82[0].m128i_i32[2] = v37;
      }
      v80 = v37;
      if ( v19 <= v21 )
        v82[0].m128i_i32[3] = (int)(float)((float)((float)((float)(a2[3] - a2[1]) * (float)(0.5 - v19))
                                                 / (float)(v21 - v19))
                                         + (float)a2[1]);
      v38 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
      *(float *)v81.m128i_i32 = v18 * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      *(float *)&v81.m128i_i32[1] = v19 * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      *(float *)&v81.m128i_i32[2] = FLOAT_1_0;
      *(float *)&v81.m128i_i32[3] = FLOAT_1_0;
      v39 = ResourceTextureD3D::GetSplitTexture(v16, 0);
      if ( v39 )
        Material::PostQuad(this, v82, &v81, v39, a5, a6, a7, a8, a9, a10, a11, a12);
      ResourceTextureD3D::GetSplitDims(v16, 1u, &v78, &v79);
      v40 = a2[2];
      v41 = *(float *)&a3->m128i_i32[1];
      *(float *)&v81.m128i_i32[3] = FLOAT_1_0;
      v82[0].m128i_i32[2] = v40;
      v82[0].m128i_i32[0] = v37;
      v81.m128i_i32[0] = 0;
      *(float *)&v81.m128i_i32[1] = (float)((float)(v41 - 0.0) * v38) * (float)(0x400 / v79);
      *(float *)&v81.m128i_i32[2] = (float)((float)(*(float *)&a3->m128i_i32[2] - 0.5) * v38) * (float)(0x400 / v78);
      v42 = ResourceTextureD3D::GetSplitTexture(v16, 1u);
      if ( v42 )
        Material::PostQuad(this, v82, &v81, v42, a5, a6, a7, a8, a9, a10, a11, a12);
      ResourceTextureD3D::GetSplitDims(v16, 3u, &v78, &v79);
      v43 = a2[3];
      v44 = v82[0].m128i_i32[3];
      v45 = *(float *)&a3->m128i_i32[2];
      v46 = *(float *)&a3->m128i_i32[3];
      v81.m128i_i64[0] = 0;
      v82[0].m128i_i32[3] = v43;
      v82[0].m128i_i32[1] = v44;
      *(float *)&v81.m128i_i32[2] = (float)((float)(v45 - 0.5) * v38) * (float)(0x400 / v78);
      *(float *)&v81.m128i_i32[3] = (float)((float)(v46 - 0.5) * v38) * (float)(0x400 / v79);
      v47 = ResourceTextureD3D::GetSplitTexture(v16, 3u);
      if ( v47 )
        Material::PostQuad(this, v82, &v81, v47, a5, a6, a7, a8, a9, a10, a11, a12);
      ResourceTextureD3D::GetSplitDims(v16, 2u, &v78, &v79);
      v48 = *a2;
      v49 = *(float *)a3->m128i_i32;
      v81.m128i_i32[1] = 0;
      *(float *)&v81.m128i_i32[2] = FLOAT_1_0;
      v82[0].m128i_i32[0] = v48;
      v82[0].m128i_i32[2] = v80;
      *(float *)v81.m128i_i32 = (float)((float)(v49 - 0.0) * v38) * (float)(0x400 / v78);
      *(float *)&v81.m128i_i32[3] = (float)((float)(*(float *)&a3->m128i_i32[3] - 0.5) * v38) * (float)(0x400 / v79);
      v50 = ResourceTextureD3D::GetSplitTexture(v16, 2u);
      if ( v50 )
LABEL_79:
        Material::PostQuad(this, v82, &v81, v50, a5, a6, a7, a8, a9, a10, a11, a12);
    }
    else
    {
      v51 = *a2;
      v82[0].m128i_i32[1] = a2[1];
      v52 = a2[3];
      v82[0].m128i_i32[0] = v51;
      v82[0].m128i_i32[3] = v52;
      if ( v18 <= v20 )
        v82[0].m128i_i32[2] = (int)(float)((float)((float)((float)(a2[2] - v51) * (float)(0.5 - v18))
                                                 / (float)(v20 - v18))
                                         + (float)v51);
      v53 = v16;
      if ( v19 >= 0.5 )
      {
        ResourceTextureD3D::GetSplitDims(v16, 2u, &v79, &v80);
        v54 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
        v56 = *(float *)&a3->m128i_i32[1];
        v57 = *(float *)&a3->m128i_i32[3];
        v55 = 2;
        *(float *)v81.m128i_i32 = (float)(*(float *)a3->m128i_i32 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
        v58 = (float)(0x400 / v80);
        v53 = v16;
        *(float *)&v81.m128i_i32[1] = (float)((float)(v56 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v58;
        *(float *)&v81.m128i_i32[3] = (float)((float)(v57 - 0.5) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * v58;
      }
      else
      {
        v54 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
        v55 = 0;
        *(float *)v81.m128i_i32 = (float)(v18 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
        *(float *)&v81.m128i_i32[1] = (float)(v19 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
        *(float *)&v81.m128i_i32[3] = (float)(v21 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      }
      *(float *)&v81.m128i_i32[2] = FLOAT_1_0;
      v59 = ResourceTextureD3D::GetSplitTexture(v53, v55);
      if ( v59 )
        Material::PostQuad(this, v82, &v81, v59, a5, a6, a7, a8, a9, a10, a11, a12);
      v82[0].m128i_i32[0] = v82[0].m128i_i32[2];
      v82[0].m128i_i32[2] = a2[2];
      if ( v19 >= 0.5 )
      {
        v60 = 3;
        ResourceTextureD3D::GetSplitDims(v16, 3u, &v79, &v80);
        v64 = (float)(*(float *)&a3->m128i_i32[2] - 0.5) * v54;
        v62 = (float)(0x400 / v80);
        *(float *)&v81.m128i_i32[1] = (float)((float)(*(float *)&a3->m128i_i32[1] - 0.5) * v54) * v62;
        *(float *)&v81.m128i_i32[2] = v64 * (float)(0x400 / v79);
        v63 = *(float *)&a3->m128i_i32[3] - 0.5;
      }
      else
      {
        v60 = 1;
        ResourceTextureD3D::GetSplitDims(v16, 1u, &v79, &v80);
        v61 = (float)(*(float *)&a3->m128i_i32[2] - 0.5) * v54;
        v62 = (float)(0x400 / v80);
        *(float *)&v81.m128i_i32[1] = (float)((float)(*(float *)&a3->m128i_i32[1] - 0.0) * v54) * v62;
        *(float *)&v81.m128i_i32[2] = v61 * (float)(0x400 / v79);
        v63 = *(float *)&a3->m128i_i32[3] - 0.0;
      }
      v81.m128i_i32[0] = 0;
      *(float *)&v81.m128i_i32[3] = (float)(v63 * v54) * v62;
      v50 = ResourceTextureD3D::GetSplitTexture(v16, v60);
      if ( v50 )
        goto LABEL_79;
    }
  }
  else if ( v34 )
  {
    v82[0].m128i_i32[0] = *a2;
    *(__int64 *)((char *)v82[0].m128i_i64 + 4) = *(_QWORD *)(a2 + 1);
    if ( v19 <= v21 )
      v82[0].m128i_i32[3] = (int)(float)((float)((float)((float)(a2[3] - a2[1]) * (float)(0.5 - v19))
                                               / (float)(v21 - v19))
                                       + (float)a2[1]);
    v65 = v16;
    if ( v18 >= 0.5 )
    {
      ResourceTextureD3D::GetSplitDims(v16, 1u, &v80, &v79);
      v66 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v68 = (float)(*(float *)&a3->m128i_i32[1] - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v67 = 1;
      v69 = (float)(0x400 / v80);
      *(float *)v81.m128i_i32 = (float)((float)(*(float *)a3->m128i_i32 - 0.5)
                                      * CardAnimationManager::DEF_BASE_ANIM_SPEED)
                              * v69;
      v65 = v16;
      *(float *)&v81.m128i_i32[1] = v68 * (float)(0x400 / v79);
      *(float *)&v81.m128i_i32[2] = (float)((float)(*(float *)&a3->m128i_i32[2] - 0.5)
                                          * CardAnimationManager::DEF_BASE_ANIM_SPEED)
                                  * v69;
    }
    else
    {
      v66 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
      v67 = 0;
      *(float *)v81.m128i_i32 = (float)(v18 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      *(float *)&v81.m128i_i32[1] = (float)(v19 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
      *(float *)&v81.m128i_i32[2] = (float)(v20 - 0.0) * CardAnimationManager::DEF_BASE_ANIM_SPEED;
    }
    *(float *)&v81.m128i_i32[3] = FLOAT_1_0;
    v70 = ResourceTextureD3D::GetSplitTexture(v65, v67);
    if ( v70 )
      Material::PostQuad(this, v82, &v81, v70, a5, a6, a7, a8, a9, a10, a11, a12);
    v82[0].m128i_i32[1] = v82[0].m128i_i32[3];
    v82[0].m128i_i32[3] = a2[3];
    if ( v18 >= 0.5 )
    {
      v71 = 3;
      ResourceTextureD3D::GetSplitDims(v16, 3u, &v80, &v79);
      v72 = *(float *)a3->m128i_i32 - 0.5;
      v73 = *(float *)&a3->m128i_i32[2] - 0.5;
    }
    else
    {
      v71 = 2;
      ResourceTextureD3D::GetSplitDims(v16, 2u, &v80, &v79);
      v72 = *(float *)a3->m128i_i32 - 0.0;
      v73 = *(float *)&a3->m128i_i32[2] - 0.0;
    }
    v74 = (float)(0x400 / v80);
    *(float *)&v75 = (float)(v72 * v66) * v74;
    *(float *)&v76 = (float)(v73 * v66) * v74;
    v77 = *(float *)&a3->m128i_i32[3];
    v81.m128i_i64[0] = v75;
    v81.m128i_i32[2] = v76;
    *(float *)&v81.m128i_i32[3] = (float)((float)(v77 - 0.5) * v66) * (float)(0x400 / v79);
    v50 = ResourceTextureD3D::GetSplitTexture(v16, v71);
    if ( v50 )
      goto LABEL_79;
  }
}
