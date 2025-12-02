void __fastcall CardStack::Cleanup(CardStack *this)
{
  NodeBase *v2; // rcx
  NodeBase *v3; // rcx
  NodeBase *v4; // rcx
  NodeBase *v5; // rcx
  NodeBase *v6; // rcx
  NodeBase *v7; // rcx
  NodeBase *v8; // rcx
  NodeBase *v9; // rcx
  NodeBase *v10; // rcx
  NodeBase *v11; // rcx

  v2 = (NodeBase *)*((_QWORD *)this + 18);
  if ( v2 )
  {
    NodeBase::DeleteSelf(v2);
    *((_QWORD *)this + 18) = 0;
  }
  v3 = (NodeBase *)*((_QWORD *)this + 21);
  if ( v3 )
  {
    NodeBase::DeleteSelf(v3);
    *((_QWORD *)this + 21) = 0;
  }
  v4 = (NodeBase *)*((_QWORD *)this + 22);
  if ( v4 )
  {
    NodeBase::DeleteSelf(v4);
    *((_QWORD *)this + 22) = 0;
  }
  v5 = (NodeBase *)*((_QWORD *)this + 23);
  if ( v5 )
  {
    NodeBase::DeleteSelf(v5);
    *((_QWORD *)this + 23) = 0;
  }
  v6 = (NodeBase *)*((_QWORD *)this + 24);
  if ( v6 )
  {
    NodeBase::DeleteSelf(v6);
    *((_QWORD *)this + 24) = 0;
  }
  v7 = (NodeBase *)*((_QWORD *)this + 25);
  if ( v7 )
  {
    NodeBase::DeleteSelf(v7);
    *((_QWORD *)this + 25) = 0;
  }
  v8 = (NodeBase *)*((_QWORD *)this + 26);
  if ( v8 )
  {
    NodeBase::DeleteSelf(v8);
    *((_QWORD *)this + 26) = 0;
  }
  v9 = (NodeBase *)*((_QWORD *)this + 27);
  if ( v9 )
  {
    NodeBase::DeleteSelf(v9);
    *((_QWORD *)this + 27) = 0;
  }
  v10 = (NodeBase *)*((_QWORD *)this + 20);
  if ( v10 )
  {
    NodeBase::DeleteSelf(v10);
    *((_QWORD *)this + 20) = 0;
  }
  v11 = (NodeBase *)*((_QWORD *)this + 19);
  if ( v11 )
  {
    NodeBase::DeleteSelf(v11);
    *((_QWORD *)this + 19) = 0;
  }
}
