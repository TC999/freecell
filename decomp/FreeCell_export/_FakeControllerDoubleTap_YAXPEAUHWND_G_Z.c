void __fastcall FakeControllerDoubleTap(HWND hWnd)
{
  HWND ForegroundWindow; // rax
  HWND Parent; // rax
  UINT v4; // eax

  if ( GetForegroundWindow() == hWnd )
    goto LABEL_6;
  ForegroundWindow = GetForegroundWindow();
  Parent = GetParent(ForegroundWindow);
  if ( Parent == hWnd )
    goto LABEL_6;
  do
  {
    if ( !Parent )
      break;
    Parent = GetParent(Parent);
  }
  while ( Parent != hWnd );
  if ( Parent == hWnd )
  {
LABEL_6:
    if ( (dword_1000B1D04 & 1) != 0 )
    {
      v4 = dword_1000B1D00;
    }
    else
    {
      dword_1000B1D04 |= 1u;
      v4 = RegisterWindowMessageW(L"XNAControllerDoubleClick");
      dword_1000B1D00 = v4;
    }
    PostMessageW(hWnd, v4, 0x41u, 0);
  }
}
