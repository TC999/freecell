void __fastcall FreeCellGame::UpdateMenuState(FreeCellGame *this)
{
  HMENU Menu; // rax
  UINT v3; // r8d

  Menu = GetMenu(g_hWnd);
  if ( *((_DWORD *)this + 2) == 2 && *(_DWORD *)(*((_QWORD *)this + 22) + 240LL) && !*((_QWORD *)g_pUserInterface + 8) )
  {
    EnableMenuItem(Menu, 0x9C4Bu, 0);
    v3 = 0;
  }
  else
  {
    EnableMenuItem(Menu, 0x9C4Bu, 3u);
    v3 = 3;
  }
  EnableMenuItem(g_hContextMenu, 0x9C4Bu, v3);
}
