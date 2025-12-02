void __fastcall CardStack::ArrangeHighlight(NodeBase **this)
{
  unsigned int v2; // edi
  char v3; // bp
  __int64 v4; // rsi
  __int64 v5; // r9
  __int64 v6; // r9
  __int64 v7; // r9

  if ( this[28] )
  {
    NodeBase::MoveToFront(this[21]);
    NodeBase::MoveToFront(this[22]);
    NodeBase::MoveToFront(this[23]);
    v2 = 0;
    v3 = 0;
    if ( *((_DWORD *)this + 76) )
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = *(_QWORD *)((char *)this[40] + v4);
        if ( !v5 )
          break;
        if ( (NodeBase *)v5 == this[28] )
        {
          v3 = 1;
          NodeBase::SetPosition(
            this[21],
            *(_DWORD *)(*(_QWORD *)(v5 + 64) + 8LL) + *(_DWORD *)(*(_QWORD *)(v5 + 72) + 8LL),
            *((_DWORD *)this[21] + 3));
          NodeBase::SetPosition(
            this[21],
            *((_DWORD *)this[21] + 2),
            *(_DWORD *)(*(_QWORD *)(v6 + 64) + 12LL) + *(_DWORD *)(*(_QWORD *)(v6 + 72) + 12LL));
        }
        if ( v2 == *((_DWORD *)this + 76) - 1 )
        {
          NodeBase::SetPosition(
            this[23],
            *(_DWORD *)(*(_QWORD *)(v5 + 64) + 8LL) + *(_DWORD *)(*(_QWORD *)(v5 + 72) + 8LL),
            *((_DWORD *)this[23] + 3));
          NodeBase::SetPosition(
            this[23],
            *((_DWORD *)this[23] + 2),
            *(_DWORD *)(*(_QWORD *)(v7 + 64) + 12LL)
          + *(_DWORD *)(*(_QWORD *)(v7 + 72) + 12LL)
          + *(_DWORD *)(*(_QWORD *)(v7 + 72) + 20LL)
          - *((_DWORD *)this[23] + 5));
        }
        if ( v3 == 1 )
          NodeBase::MoveToFront(*(NodeBase **)(v5 + 64));
        ++v2;
        v4 += 8;
        if ( v2 >= *((_DWORD *)this + 76) )
          goto LABEL_12;
      }
      Log(0x10001u, L"CardStack::ArrangeHighlight() - Got a null card from the card array.");
    }
    else
    {
LABEL_12:
      NodeBase::SetPosition(this[22], *((_DWORD *)this[21] + 2), *((_DWORD *)this[22] + 3));
      NodeBase::SetPosition(this[22], *((_DWORD *)this[22] + 2), *((_DWORD *)this[21] + 3) + *((_DWORD *)this[21] + 5));
      NodeBase::SetSize(
        this[22],
        *((_DWORD *)this[22] + 4),
        *((_DWORD *)this[23] + 3) - *((_DWORD *)this[21] + 5) - *((_DWORD *)this[21] + 3));
    }
  }
}
