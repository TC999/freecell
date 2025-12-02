// Hidden C++ exception states: #wind=10
CardTable *__fastcall CardTable::`vector deleting destructor'(CardTable *this, char a2)
{
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx

  *(_QWORD *)this = &CardTable::`vftable'{for `IEventListener'};
  *((_QWORD *)this + 1) = &CardTable::`vftable'{for `SerializableData'};
  CardTable::Cleanup(this);
  SortedListW<StackGroup *>::RemoveAll((__int64)this + 352, 1);
  operator delete(*((void **)this + 41));
  operator delete(*((void **)this + 38));
  operator delete(*((void **)this + 35));
  v4 = (void *)*((_QWORD *)this + 32);
  if ( v4 )
    free(v4);
  v5 = (void *)*((_QWORD *)this + 29);
  if ( v5 )
    free(v5);
  SortedListW<unsigned int>::RemoveAll((__int64)this + 144);
  SortedListW<unsigned int>::RemoveAll((__int64)this + 120);
  v6 = (void *)*((_QWORD *)this + 5);
  if ( v6 )
    free(v6);
  *(_QWORD *)this = &IEventListener::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
