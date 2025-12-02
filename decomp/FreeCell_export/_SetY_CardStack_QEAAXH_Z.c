void __fastcall CardStack::SetY(NodeBase **this, int a2)
{
  __int64 v2; // r9
  int v3; // r8d
  __int64 v4; // r9
  int v5; // r10d

  NodeBase::SetPosition(this[18], *((_DWORD *)this[18] + 2), a2);
  NodeBase::SetPosition(*(NodeBase **)(v2 + 152), *(_DWORD *)(*(_QWORD *)(v2 + 152) + 8LL), v3 + *(_DWORD *)(v2 + 244));
  NodeBase::SetPosition(
    *(NodeBase **)(v4 + 160),
    *(_DWORD *)(*(_QWORD *)(v4 + 160) + 8LL),
    *(_DWORD *)(v4 + 244) + v5 + 2);
}
