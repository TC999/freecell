IStateMachine *__fastcall IStateMachine::`vector deleting destructor'(IStateMachine *this, char a2)
{
  *(_QWORD *)this = &IStateMachine::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
