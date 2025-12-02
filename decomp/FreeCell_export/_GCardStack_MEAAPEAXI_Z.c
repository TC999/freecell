// Hidden C++ exception states: #wind=6
CardStack *__fastcall CardStack::`scalar deleting destructor'(CardStack *this, char a2)
{
  void *v4; // rcx

  *(_QWORD *)this = &CardStack::`vftable'{for `SerializableData'};
  *((_QWORD *)this + 1) = &CardStack::`vftable'{for `IEventListener'};
  CardStack::Cleanup(this);
  v4 = (void *)*((_QWORD *)this + 40);
  if ( v4 )
    free(v4);
  operator delete(*((void **)this + 36));
  operator delete(*((void **)this + 17));
  operator delete(*((void **)this + 14));
  operator delete(*((void **)this + 11));
  *((_QWORD *)this + 1) = &IEventListener::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
