void __fastcall CardStack::SetFocus(CardStack *this)
{
  int v2; // eax
  struct NodeBase *v3; // rdx

  Log(0x10000u, 0x5D1u, "CardStack.cpp", L"SetFocus(%s)", *(_QWORD *)(*((_QWORD *)this + 18) + 128LL));
  v2 = *((_DWORD *)this + 76);
  if ( v2 )
    v3 = *(struct NodeBase **)(*(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(v2 - 1)) + 96LL);
  else
    v3 = (struct NodeBase *)*((_QWORD *)this + 18);
  UserInterface::SetFocus(g_pUserInterface, v3);
}
