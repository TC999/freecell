LRESULT __fastcall DialogHelper::ShowEditBalloonTip(HWND hWnd, HWND a2)
{
  LPARAM lParam[3]; // [rsp+20h] [rbp-638h] BYREF
  int v5; // [rsp+38h] [rbp-620h]
  WCHAR Buffer[256]; // [rsp+40h] [rbp-618h] BYREF
  WCHAR v7[512]; // [rsp+240h] [rbp-418h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  memset(v7, 0, sizeof(v7));
  if ( DialogHelper::m_bIsMediaCenter
    || !LoadStringW(DialogHelper::m_hInstance, 0xE313u, Buffer, 256)
    || !LoadStringW(DialogHelper::m_hInstance, 0xE312u, v7, 512) )
  {
    return 0;
  }
  lParam[2] = (LPARAM)v7;
  LODWORD(lParam[0]) = 32;
  v5 = 3;
  lParam[1] = (LPARAM)Buffer;
  return SendMessageW(hWnd, 0x1503u, 0, (LPARAM)lParam);
}
