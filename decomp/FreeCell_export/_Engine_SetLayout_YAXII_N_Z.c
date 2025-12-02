void __fastcall Engine_SetLayout(unsigned int a1)
{
  int v1; // ebx
  int v2; // edi
  signed int v3; // r8d
  signed int v4; // edx
  float v5; // xmm6_4
  UserInterface *v6; // rax
  float v7; // xmm7_4
  unsigned int v8; // ebx
  unsigned int v9; // edi
  int v10; // r8d
  int v11; // r9d
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int i; // ebp
  HMONITOR v16; // rax
  float v17; // xmm6_4
  unsigned int v18; // r11d
  unsigned int v19; // eax
  LONG right; // edx
  int left; // ecx
  LONG top; // edx
  int bottom; // ecx
  UINT showCmd; // r11d
  struct tagRECT rcDst; // [rsp+30h] [rbp-A8h] BYREF
  struct tagMONITORINFO mi; // [rsp+40h] [rbp-98h] BYREF
  WINDOWPLACEMENT wndpl; // [rsp+68h] [rbp-70h] BYREF
  unsigned int v28; // [rsp+E0h] [rbp+8h] BYREF
  unsigned int v29; // [rsp+F8h] [rbp+20h] BYREF

  v28 = a1;
  v1 = g_uiLayoutY;
  v2 = g_uiLayoutX;
  Log(0x10u, 2043, "Engine.cpp", L"Setting Layout Resolution To: %d x %d", g_uiLayoutX, g_uiLayoutY);
  if ( g_pRenderManager && !g_CurrentBackStyle )
  {
    if ( g_bDoubleDPI )
    {
      v3 = 2 * v1;
      v4 = 2 * v2;
    }
    else
    {
      v3 = v1;
      v4 = v2;
    }
    RenderManager::SetResolution(g_pRenderManager, v4, v3);
  }
  v5 = (float)v2 / (float)(int)g_uiLayoutX;
  v6 = g_pUserInterface;
  v7 = (float)v1 / (float)(int)g_uiLayoutY;
  if ( g_pUserInterface )
  {
    *((_DWORD *)g_pUserInterface + 64) = v2;
    *((_DWORD *)v6 + 65) = v1;
  }
  g_uiLayoutX = v2;
  g_uiLayoutY = v1;
  GetContentAreaDimensions(&v28, &v29, g_hWnd, g_hWndStatus);
  v8 = (int)(float)((float)(int)v28 * v5);
  v9 = (int)(float)((float)(int)v29 * v7);
  if ( g_bLockWindowAspect )
  {
    v10 = (int)(float)((float)(int)v29 * v7);
    v11 = (int)(float)((float)(int)v28 * v5);
    if ( v8 )
    {
      do
      {
        v12 = v10;
        v13 = v10 >> 31;
        v10 = v11;
        v11 = __SPAIR64__(v13, v12) % v11;
      }
      while ( v11 );
    }
    if ( v10 > 0 )
    {
      v14 = v8 / v10;
      for ( i = v9 / v10; ; v9 += i )
      {
        GetWindowDimensionsFromContentAreaDimensions(v8, v9, &v28, &v29, g_hWnd, g_hWndStatus);
        if ( v28 >= g_uiMinWidth && v29 >= g_uiMinHeight )
          break;
        v8 += v14;
      }
    }
  }
  memset(&mi.rcMonitor, 0, 0x24u);
  mi.cbSize = 40;
  v16 = MonitorFromWindow(g_hWnd, 2u);
  GetMonitorInfoW(v16, &mi);
  v17 = (float)(int)g_uiLayoutX / (float)(int)g_uiLayoutY;
  GetWindowDimensionsFromContentAreaDimensions(0, 0, &v28, &v29, g_hWnd, g_hWndStatus);
  v18 = mi.rcWork.right - mi.rcWork.left - v28;
  if ( v18 < v8 )
  {
    v8 = mi.rcWork.right - mi.rcWork.left - v28;
    v9 = (int)(float)((float)(int)v18 / v17);
  }
  v19 = mi.rcWork.bottom - mi.rcWork.top - v29;
  if ( v19 < v9 )
  {
    v9 = mi.rcWork.bottom - mi.rcWork.top - v29;
    v8 = (int)(float)((float)(int)v19 * v17);
  }
  SetWindowSizeFromClientSize(v8, v9);
  memset(&wndpl, 0, sizeof(wndpl));
  GetWindowPlacement(g_hWnd, &wndpl);
  rcDst.left = 0;
  rcDst.top = 0;
  rcDst.right = 0;
  rcDst.bottom = 0;
  UnionRect(&rcDst, &mi.rcWork, &wndpl.rcNormalPosition);
  if ( !EqualRect(&rcDst, &mi.rcWork) && !(_BYTE)g_bMediaCenter )
  {
    right = wndpl.rcNormalPosition.right;
    left = wndpl.rcNormalPosition.left;
    if ( wndpl.rcNormalPosition.right > mi.rcWork.right )
    {
      right = mi.rcWork.right;
      left = wndpl.rcNormalPosition.left - (wndpl.rcNormalPosition.right - mi.rcWork.right);
      wndpl.rcNormalPosition.left = left;
      wndpl.rcNormalPosition.right = mi.rcWork.right;
    }
    if ( left < mi.rcWork.left )
    {
      wndpl.rcNormalPosition.right = mi.rcWork.left - left + right;
      wndpl.rcNormalPosition.left = mi.rcWork.left;
    }
    top = wndpl.rcNormalPosition.top;
    bottom = wndpl.rcNormalPosition.bottom;
    if ( wndpl.rcNormalPosition.top < mi.rcWork.top )
    {
      top = mi.rcWork.top;
      bottom = mi.rcWork.top - wndpl.rcNormalPosition.top + wndpl.rcNormalPosition.bottom;
      wndpl.rcNormalPosition.bottom = bottom;
      wndpl.rcNormalPosition.top = mi.rcWork.top;
    }
    if ( bottom > mi.rcWork.bottom )
    {
      wndpl.rcNormalPosition.top = top - (bottom - mi.rcWork.bottom);
      wndpl.rcNormalPosition.bottom = mi.rcWork.bottom;
    }
    OffsetRect(&wndpl.rcNormalPosition, mi.rcMonitor.left - mi.rcWork.left, mi.rcMonitor.top - mi.rcWork.top);
    showCmd = wndpl.showCmd;
    if ( g_bInitializing )
      showCmd = 0;
    wndpl.showCmd = showCmd;
    SetWindowPlacement(g_hWnd, &wndpl);
  }
  CenterRenderWindow();
}
