void __fastcall CardStack::Join(CardStack *this, struct CardStack *a2)
{
  struct Card *v4; // rax

  Log(0x10000u, L"CardStack::Join()::pCardStack->GetName() == %s", *((_QWORD *)a2 + 36));
  CardStack::Reverse(a2);
  while ( *((_DWORD *)a2 + 76) )
  {
    v4 = CardStack::Pop(a2);
    CardStack::Push(this, v4);
  }
  CardTable::PushAction(
    *((CardTable **)this + 37),
    8,
    *((const unsigned __int16 **)this + 36),
    *((const unsigned __int16 **)a2 + 36));
  SortedListW<CardStack *>::Remove(*((_QWORD *)this + 37) + 144LL, *((const wchar_t **)a2 + 36));
  (*(void (__fastcall **)(char *, __int64))(*((_QWORD *)a2 + 1) + 8LL))((char *)a2 + 8, 1);
  if ( *((_BYTE *)this + 56) )
    CardStack::UpdateAccessibility(this);
  if ( *((_BYTE *)this + 57) )
    CardStack::ResizeAccessAreas(this);
}
