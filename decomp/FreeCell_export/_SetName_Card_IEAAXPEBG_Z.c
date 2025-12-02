void __fastcall Card::SetName(void ***this, const unsigned __int16 *a2)
{
  Log(0x10000u, L"Card::SetName()::wszName == %s", a2);
  Str::operator=((__int64)(this + 5), a2);
  NodeBase::SetName(this[13], a2);
  NodeBase::SetName(this[12], a2);
}
