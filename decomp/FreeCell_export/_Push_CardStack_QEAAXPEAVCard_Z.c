void __fastcall CardStack::Push(CardStack *this, struct Card *a2)
{
  if ( a2 )
  {
    Log(0x10000u, L"CardStack::Push()::pCard->GetName == %s", *((_QWORD *)a2 + 7));
    CardTable::PushAction(
      *((CardTable **)this + 37),
      4,
      *((const unsigned __int16 **)a2 + 7),
      *((const unsigned __int16 **)this + 36));
    Array<IEventListener *>::Add((__int64)this + 304, (__int64)a2);
    Card::RefreshAccessibility(a2);
  }
  else
  {
    Log(0x10001u, L"CardStack::Push() - Tried to push a null card.");
  }
}
