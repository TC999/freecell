void __fastcall NodeBase::SetAccessible(NodeBase *this, char a2, int a3)
{
  if ( *((_BYTE *)this + 144) != a2 )
  {
    *((_BYTE *)this + 144) = a2;
    *((_DWORD *)this + 48) = a3;
    if ( a2 )
      UserInterface::Access_OnNodeAccessible(g_pUserInterface, this);
    else
      UserInterface::Access_ClipNode(g_pUserInterface, this);
  }
}
