void __fastcall FakeMCEMenu(HWND a1)
{
  UINT v2; // eax

  if ( (dword_1000B1CFC & 1) != 0 )
  {
    v2 = dword_1000B1CF8;
  }
  else
  {
    dword_1000B1CFC |= 1u;
    v2 = RegisterWindowMessageW(L"MCEGameMenu");
    dword_1000B1CF8 = v2;
  }
  PostMessageW(a1, v2, 0, 0);
}
