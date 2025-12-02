void __fastcall FreeCellGame::doFakeClick(FreeCellGame *this, struct CardStack *a2)
{
  int v4; // eax
  bool v5; // r12
  _DWORD *v6; // rbx
  int v7; // ebp
  __int64 v8; // r12
  __int64 v9; // rbx
  _DWORD *v10; // rbx

  UserInterface::ClearFocus(g_pUserInterface);
  FreeCellGame::RequestSkipAnimation(this);
  if ( *((_BYTE *)this + 360) )
    *((_BYTE *)this + 360) = 0;
  Log(0x10000000u, L"FreeCellGame::doFakeClick() - %p (move pending=%d)", a2, *((unsigned __int8 *)this + 360));
  v4 = *((_DWORD *)a2 + 76);
  if ( v4 )
  {
    v5 = *((_QWORD *)this + 38) == *(_QWORD *)(*((_QWORD *)a2 + 40) + 8LL * (unsigned int)(v4 - 1));
    v6 = operator new(0x28u);
    if ( v6 )
    {
      v6[4] = 1;
      *(_QWORD *)v6 = &Event_ButtonClick::`vftable';
    }
    else
    {
      v6 = 0;
    }
    *((_QWORD *)v6 + 1) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40) + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - 1))
                                    + 96LL);
    *((_QWORD *)v6 + 3) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)a2 + 40) + 8LL * (unsigned int)(*((_DWORD *)a2 + 76) - 1))
                                    + 96LL);
    (**((void (__fastcall ***)(char *, void *))this + 2))((char *)this + 16, v6);
    (**(void (__fastcall ***)(void *, __int64))v6)(v6, 1);
    if ( v5 && *((_DWORD *)a2 + 76) > 1u )
    {
      v7 = 1;
      v8 = 8;
      do
      {
        v9 = *(_QWORD *)(v8 + *((_QWORD *)a2 + 40));
        CardTable::AddMovementAnimation(
          *(CardTable **)(v9 + 24),
          (struct Card *)v9,
          0.0,
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 8LL),
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 12LL),
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 8LL),
          *((_DWORD *)a2 + 6) + *(_DWORD *)(*(_QWORD *)(v9 + 64) + 12LL),
          0,
          1,
          0);
        CardTable::AddMovementAnimation(
          *(CardTable **)(v9 + 24),
          (struct Card *)v9,
          (float)v7++ * 0.333,
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 8LL),
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 12LL),
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 8LL),
          *(_DWORD *)(*(_QWORD *)(v9 + 64) + 12LL),
          0,
          1,
          0);
        v8 += 8;
      }
      while ( (unsigned int)v7 < *((_DWORD *)a2 + 76) );
    }
  }
  else
  {
    v10 = operator new(0x28u);
    if ( v10 )
    {
      v10[4] = 1;
      *(_QWORD *)v10 = &Event_ButtonClick::`vftable';
    }
    else
    {
      v10 = 0;
    }
    *((_QWORD *)v10 + 1) = *((_QWORD *)a2 + 18);
    *((_QWORD *)v10 + 3) = *((_QWORD *)a2 + 18);
    (**((void (__fastcall ***)(char *, void *))this + 2))((char *)this + 16, v10);
    (**(void (__fastcall ***)(void *, __int64))v10)(v10, 1);
  }
}
