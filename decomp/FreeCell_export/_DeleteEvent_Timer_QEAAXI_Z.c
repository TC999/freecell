void __fastcall Timer::DeleteEvent(Timer *this, unsigned int a2)
{
  Timer *v2; // rdi
  unsigned int v4; // [rsp+38h] [rbp+10h] BYREF

  v4 = a2;
  v2 = g_pTimer;
  if ( *((_BYTE *)g_pTimer + 72) )
  {
    if ( (int)SortedListI<Event::RegisteredType>::BinSearch((__int64 *)g_pTimer + 3, a2, 0, *((_DWORD *)g_pTimer + 10)) < 0 )
      SortedListI<int>::Add((char *)v2 + 24, a2, &v4);
  }
  else if ( (int)SortedListI<Event::RegisteredType>::BinSearch((__int64 *)g_pTimer, a2, 0, *((_DWORD *)g_pTimer + 4)) >= 0 )
  {
    SortedListI<Timer::TimerEvent>::Remove(v2, a2);
  }
}
