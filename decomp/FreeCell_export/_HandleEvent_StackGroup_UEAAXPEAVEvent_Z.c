void __fastcall StackGroup::HandleEvent(StackGroup *this, struct Event *a2)
{
  unsigned int v4; // esi
  __int64 v5; // rax
  bool v6; // zf
  __int64 v7; // rax

  switch ( *((_DWORD *)a2 + 4) )
  {
    case 0x1F:
      *((_QWORD *)a2 + 3) = *((_QWORD *)g_pRenderManager + 15);
      break;
    case 0x20:
      *((_DWORD *)a2 + 6) = *((_DWORD *)this + 8);
      Log(0x20000u, 0xDEAu, "CardTable.cpp", L"Stack Access Get Child Count");
      break;
    case 0x21:
      v4 = *((_DWORD *)a2 + 8) - 1;
      Log(0x20000u, 0xDF4u, "CardTable.cpp", L"Stack Access Get Child (%d)", v4);
      if ( v4 < *((_DWORD *)this + 8) )
      {
        v5 = *(_QWORD *)(*((_QWORD *)this + 6) + 8LL * v4);
        v6 = *(_DWORD *)(v5 + 304) == 0;
        v7 = *(_QWORD *)(v5 + 144);
        if ( v6 )
          *(_DWORD *)(v7 + 192) = 43;
        else
          *(_DWORD *)(v7 + 192) = 16;
        *((_QWORD *)a2 + 3) = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 6) + 8LL * v4) + 144LL);
      }
      break;
  }
}
