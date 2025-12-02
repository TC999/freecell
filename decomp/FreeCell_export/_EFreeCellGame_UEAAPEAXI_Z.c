// Hidden C++ exception states: #wind=10
FreeCellGame *__fastcall FreeCellGame::`vector deleting destructor'(FreeCellGame *this, char a2)
{
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx

  *(_QWORD *)this = &FreeCellGame::`vftable'{for `IStateMachine'};
  *((_QWORD *)this + 2) = &FreeCellGame::`vftable'{for `IEventListener'};
  *((_QWORD *)this + 3) = &FreeCellGame::`vftable'{for `CardAnimationManager::ICardAnimationEventListener'};
  FreeCellGame::Cleanup(this);
  v4 = (void *)*((_QWORD *)this + 37);
  if ( v4 )
    free(v4);
  v5 = (void *)*((_QWORD *)this + 34);
  if ( v5 )
    free(v5);
  v6 = (void *)*((_QWORD *)this + 31);
  if ( v6 )
    free(v6);
  v7 = (void *)*((_QWORD *)this + 28);
  if ( v7 )
    free(v7);
  v8 = (void *)*((_QWORD *)this + 25);
  if ( v8 )
    free(v8);
  CSQMTimeRecorder::~CSQMTimeRecorder((FreeCellGame *)((char *)this + 160));
  v9 = (void *)*((_QWORD *)this + 9);
  if ( v9 )
    free(v9);
  v10 = (void *)*((_QWORD *)this + 6);
  if ( v10 )
    free(v10);
  *((_QWORD *)this + 2) = &IEventListener::`vftable';
  *(_QWORD *)this = &IStateMachine::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
