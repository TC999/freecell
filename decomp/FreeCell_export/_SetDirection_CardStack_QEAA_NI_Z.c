char __fastcall CardStack::SetDirection(CardStack *this, unsigned int a2)
{
  Log(0x10000u, L"CardStack::SetDirection()::uiDirection == %u", a2);
  if ( a2 < 5 )
  {
    *((_DWORD *)this + 82) = a2;
    return 1;
  }
  else
  {
    Log(0x10001u, L"CardStack::SetDirection() - Tried to set the direction with a bad value.");
    return 0;
  }
}
