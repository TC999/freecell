char __fastcall Event::RegisterEventType(unsigned int a1, __int64 a2)
{
  __int64 v5; // [rsp+40h] [rbp+18h] BYREF

  if ( (int)SortedListI<Event::RegisteredType>::BinSearch((__int64 *)&Event::m_RegisteredTypes, a1, 0, dword_1000B1828) < 0 )
  {
    v5 = a2;
    SortedListI<Event::RegisteredType>::Add(a1, &v5);
    return 1;
  }
  else
  {
    Log(0x40u, L"RegisterEventType(), EventId %d already exists", a1);
    return 0;
  }
}
