void __fastcall ParticleUpdate(float a1, struct NodeEmitter *a2)
{
  __int64 v2; // rbx
  float v3; // xmm3_4
  float v4; // xmm0_4
  __m128 v5; // xmm2
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  __m128 v9; // xmm0
  RenderManager *v10; // rax

  v2 = *((_QWORD *)a2 + 71);
  v3 = *(float *)(v2 + 40);
  v4 = *(float *)(v2 + 36);
  v5 = (__m128)*(unsigned int *)(v2 + 12);
  *(_DWORD *)(v2 + 52) = 255;
  v6 = _mm_unpacklo_ps(v5, v5).m128_f32[0];
  v7 = v3 + 0.5;
  v8 = v7 + *(float *)(v2 + 32);
  *(float *)(v2 + 28) = v4 + *(float *)(v2 + 28);
  *(float *)(v2 + 32) = v8;
  *(float *)(v2 + 40) = v7;
  if ( v6 < 0.2 )
    *(_DWORD *)(v2 + 52) = (int)(float)(v6 * 1275.0);
  v9 = (__m128)_mm_and_pd((__m128d)COERCE_UNSIGNED_INT64(*(float *)(v2 + 36)), (__m128d)_mask__AbsDouble_);
  v9.m128_f32[0] = *(double *)v9.m128_u64;
  if ( _mm_unpacklo_ps(v9, v9).m128_f32[0] >= 0.0001 )
    *(float *)(v2 + 64) = atanf(v7 / *(float *)(v2 + 36)) + 1.5707951;
  else
    *(_DWORD *)(v2 + 64) = 1078530000;
  v10 = g_pRenderManager;
  *((_BYTE *)g_pRenderManager + 20) = 1;
  *((_BYTE *)v10 + 88) = 1;
}
