__int64 __fastcall Audio::GetMusicBufferVolume(Audio *this)
{
  __m128 v1; // xmm0
  float v2; // xmm6_4
  float v3; // xmm0_4
  float v4; // xmm6_4

  v1 = (__m128)COERCE_UNSIGNED_INT((float)*((int *)this + 1));
  v2 = FLOAT_N10000_0;
  v1.m128_f32[0] = (float)(v1.m128_f32[0] / 100.0) * (float)((float)*(int *)this / 100.0);
  v3 = _mm_unpacklo_ps(v1, v1).m128_f32[0];
  if ( v3 > 0.001 )
  {
    v4 = logf(v3);
    v2 = (float)(v4 * 300.0) / logf(CardAnimationManager::DEF_BASE_ANIM_SPEED);
  }
  return (unsigned int)(int)v2;
}
