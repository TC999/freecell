void __fastcall Card::Cleanup(Card *this)
{
  NodeBase *v2; // rcx
  NodeBase *v3; // rcx
  NodeBase *v4; // rcx
  NodeBase *v5; // rcx
  NodeBase *v6; // rcx

  v2 = (NodeBase *)*((_QWORD *)this + 9);
  if ( v2 )
  {
    NodeBase::DeleteSelf(v2);
    *((_QWORD *)this + 9) = 0;
  }
  v3 = (NodeBase *)*((_QWORD *)this + 10);
  if ( v3 )
  {
    NodeBase::DeleteSelf(v3);
    *((_QWORD *)this + 10) = 0;
  }
  v4 = (NodeBase *)*((_QWORD *)this + 12);
  if ( v4 )
  {
    NodeBase::DeleteSelf(v4);
    *((_QWORD *)this + 12) = 0;
  }
  v5 = (NodeBase *)*((_QWORD *)this + 13);
  if ( v5 )
  {
    NodeBase::DeleteSelf(v5);
    *((_QWORD *)this + 13) = 0;
  }
  v6 = (NodeBase *)*((_QWORD *)this + 8);
  if ( v6 )
  {
    NodeBase::DeleteSelf(v6);
    *((_QWORD *)this + 8) = 0;
  }
}
