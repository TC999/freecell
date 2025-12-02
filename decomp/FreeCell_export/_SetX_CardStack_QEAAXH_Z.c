void __fastcall CardStack::SetX(NodeBase **this, int a2)
{
  __int64 v2; // r9
  int v3; // edx
  __int64 v4; // r9
  int v5; // r10d

  NodeBase::SetPosition(this[18], a2, *((_DWORD *)this[18] + 3));
  NodeBase::SetPosition(*(NodeBase **)(v2 + 152), v3 + *(_DWORD *)(v2 + 240), *(_DWORD *)(*(_QWORD *)(v2 + 152) + 12LL));
  NodeBase::SetPosition(
    *(NodeBase **)(v4 + 160),
    v5 + *(_DWORD *)(v4 + 240) + 2,
    *(_DWORD *)(*(_QWORD *)(v4 + 160) + 12LL));
}
