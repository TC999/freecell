void __fastcall Card::SetFocus(Card *this)
{
  Log(0x10000u, 0x295u, "Card.cpp", L"SetFocus(%s)", *(_QWORD *)(*((_QWORD *)this + 12) + 128LL));
  UserInterface::SetFocus(g_pUserInterface, *((struct NodeBase **)this + 12));
}
