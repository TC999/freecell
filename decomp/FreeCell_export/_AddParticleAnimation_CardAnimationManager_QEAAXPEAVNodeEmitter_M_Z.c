void __fastcall CardAnimationManager::AddParticleAnimation(
        CardAnimationManager *this,
        struct NodeEmitter *a2,
        float a3)
{
  float *v5; // rbx

  v5 = (float *)operator new(0x50u);
  if ( v5 )
  {
    v5[9] = a3;
    *(_QWORD *)v5 = this;
    *((_QWORD *)v5 + 2) = a2;
    *((_BYTE *)v5 + 69) = 1;
    *((_BYTE *)v5 + 71) = 0;
    *((_BYTE *)v5 + 72) = 0;
    v5[8] = 0.0;
    *((_DWORD *)v5 + 19) = 2;
    v5[11] = 0.0;
    v5[12] = 0.0;
    v5[15] = 0.0;
    v5[16] = 0.0;
    v5[13] = 0.0;
    v5[14] = 0.0;
    v5[10] = 0.0;
    *((_QWORD *)v5 + 3) = 0;
    *((_QWORD *)v5 + 1) = 0;
    *((_BYTE *)v5 + 70) = 0;
    *((_BYTE *)v5 + 68) = 0;
  }
  else
  {
    v5 = 0;
  }
  Array<IEventListener *>::Add((__int64)this + 64, (__int64)v5);
  Array<IEventListener *>::Add((__int64)this + 40, (__int64)v5);
}
