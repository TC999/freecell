Particle *__fastcall Particle::`scalar deleting destructor'(Particle *this, char a2)
{
  *(_QWORD *)this = &Particle::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
