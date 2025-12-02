void __fastcall Engine_SetStatusBarText(WPARAM wParam, LPARAM lParam)
{
  if ( g_hWndStatus )
    SendMessageW(g_hWndStatus, 0x464u, (unsigned int)wParam, lParam);
  else
    Log(0x800u, 2231, "Window.cpp", L"Attempted to set status bar text when no status bar is created");
}
