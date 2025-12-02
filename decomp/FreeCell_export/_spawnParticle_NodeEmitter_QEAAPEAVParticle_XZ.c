struct Particle *__fastcall NodeEmitter::spawnParticle(NodeEmitter *this)
{
  float *v2; // rbx
  int v3; // eax
  struct Particle *result; // rax
  float *v5; // rax
  int v6; // eax
  float v7; // xmm0_4

  if ( *((_DWORD *)this + 124) )
  {
    v2 = *(float **)(*((_QWORD *)this + 64) + 8LL * (unsigned int)(*((_DWORD *)this + 124) - 1));
    v3 = *((_DWORD *)this + 124);
    if ( v3 )
      *((_DWORD *)this + 124) = v3 - 1;
  }
  else
  {
    v2 = 0;
  }
  if ( !v2 )
  {
    if ( *((_DWORD *)this + 118) >= 0x11170u )
      return 0;
    v5 = (float *)operator new(0x48u);
    v2 = v5;
    if ( v5 )
    {
      v5[15] = 0.0;
      v5[14] = 0.0;
      v5[3] = 0.0;
      v5[2] = 0.0;
      v5[10] = 0.0;
      v5[9] = 0.0;
      v5[8] = 0.0;
      v5[7] = 0.0;
      *(_QWORD *)v5 = &Particle::`vftable';
      *((_QWORD *)v5 + 2) = this;
      *((_BYTE *)v5 + 24) = 1;
    }
    else
    {
      v2 = 0;
    }
  }
  v6 = *((_DWORD *)this + 68);
  if ( *((_BYTE *)this + 577) )
  {
    v2[11] = (float)(v6 - *((_DWORD *)this + 66)) * 0.5;
    v7 = (float)(*((_DWORD *)this + 69) - *((_DWORD *)this + 67)) * 0.5;
  }
  else
  {
    v2[11] = (float)(*((_DWORD *)this + 66) + (v6 - *((_DWORD *)this + 66)) / 2);
    v7 = (float)(*((_DWORD *)this + 67) + (*((_DWORD *)this + 69) - *((_DWORD *)this + 67)) / 2);
  }
  v2[12] = v7;
  Array<IEventListener *>::Add((__int64)this + 472, (__int64)v2);
  result = (struct Particle *)v2;
  *((_DWORD *)this + 133) = *((_DWORD *)this + 132);
  return result;
}
