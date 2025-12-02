struct Affector_Base *__fastcall Affector_XScale::Copy(Affector_XScale *this, int a2)
{
  _DWORD *v4; // rbx

  v4 = operator new(0x38u);
  if ( v4 )
  {
    v4[8] = 0;
    v4[9] = 0;
    *((_QWORD *)v4 + 6) = 0;
    v4[10] = 16;
    v4[6] = 0;
    *(_QWORD *)v4 = &Affector_XScale::`vftable';
  }
  else
  {
    v4 = 0;
  }
  v4[4] = a2;
  Affector_Int::CopyMessageList(this, (struct Affector_Int *)v4);
  return (struct Affector_Base *)v4;
}
