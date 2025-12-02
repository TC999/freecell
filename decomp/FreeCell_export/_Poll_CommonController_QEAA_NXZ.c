char __fastcall CommonController::Poll(CommonController *this)
{
  HWND ForegroundWindow; // rax
  DWORD v4; // r12d
  __int64 v5; // rsi
  bool v6; // r13
  __int16 v7; // r8
  unsigned int v8; // ecx
  char v9; // bl
  bool v10; // zf
  __int64 v11; // r9
  __int64 v12; // r9
  __int64 v13; // r9
  __int64 v14; // r8
  __int64 v15; // r9
  __int64 v16; // r9
  __int64 v17; // r9
  UINT v18; // ebx
  __int64 v19; // r9
  __int64 v20; // r9
  char v21; // al
  int v22; // ecx
  bool v23; // bl
  bool v24; // zf
  __int64 v25; // r9
  __int64 v26; // r9
  SHORT sThumbLY; // ax
  __int64 v28; // r9
  __int64 v29; // r9
  SHORT sThumbLX; // ax
  int v31; // [rsp+20h] [rbp-58h]
  int v32; // [rsp+28h] [rbp-50h]
  int v33; // [rsp+30h] [rbp-48h]
  XINPUT_STATE pState; // [rsp+40h] [rbp-38h] BYREF

  if ( GetForegroundWindow() != *(HWND *)this )
  {
    ForegroundWindow = GetForegroundWindow();
    do
      ForegroundWindow = GetParent(ForegroundWindow);
    while ( ForegroundWindow != *(HWND *)this && ForegroundWindow );
    if ( ForegroundWindow != *(HWND *)this )
      return 1;
  }
  v4 = 0;
  v5 = 0;
  v6 = GetForegroundWindow() != *(HWND *)this;
  while ( !XInputGetState(v4, &pState) )
  {
    v7 = pState.Gamepad.wButtons & 1;
    if ( (pState.Gamepad.wButtons & 1) == 0 && (*((_BYTE *)this + 2 * v5 + 10) & 1) != 0 )
      *((_DWORD *)this + v5 + 23) = 0;
    if ( (pState.Gamepad.wButtons & 2) == 0 && (*((_BYTE *)this + 2 * v5 + 10) & 2) != 0 )
      *((_DWORD *)this + v5 + 23) = 0;
    if ( (pState.Gamepad.wButtons & 4) == 0 && (*((_BYTE *)this + 2 * v5 + 10) & 4) != 0 )
      *((_DWORD *)this + v5 + 23) = 0;
    if ( (pState.Gamepad.wButtons & 8) == 0 && (*((_BYTE *)this + 2 * v5 + 10) & 8) != 0 )
      *((_DWORD *)this + v5 + 23) = 0;
    v8 = *((_DWORD *)this + v5 + 23);
    v9 = 0;
    v10 = v8 == 0;
    if ( !v8 )
    {
      if ( *((_DWORD *)this + v5 + 19) != pState.dwPacketNumber )
        goto LABEL_23;
      v10 = 1;
    }
    if ( v10 )
      goto LABEL_29;
    if ( v8 < g_DelayCount || v8 % g_RepeatCount )
    {
      v9 = 0;
      *((_DWORD *)this + v5 + 23) = v8 + 1;
      goto LABEL_29;
    }
LABEL_23:
    v9 = 1;
LABEL_29:
    if ( v7 && v9 )
    {
      ++*((_DWORD *)this + v5 + 23);
      LOBYTE(v33) = 0;
      if ( v6 )
      {
        v11 = 9;
        LOBYTE(v32) = 1;
      }
      else
      {
        v11 = 38;
        LOBYTE(v32) = 0;
      }
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 1, v11, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 2) != 0 && v9 )
    {
      ++*((_DWORD *)this + v5 + 23);
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      v12 = 9;
      if ( !v6 )
        v12 = 40;
      CommonController::HandleEvent(this, v4, 2, v12, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 4) != 0 && v9 )
    {
      ++*((_DWORD *)this + v5 + 23);
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 3, 37, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 8) != 0 && v9 )
    {
      ++*((_DWORD *)this + v5 + 23);
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 4, 39, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 0x10) != 0 && (*((_BYTE *)this + 2 * v5 + 10) & 0x10) == 0 )
    {
      if ( v6 )
      {
        v13 = 13;
        v14 = 5;
        goto LABEL_54;
      }
      if ( *((_BYTE *)this + 8) )
      {
        FakeMCEMenu(*(HWND *)this);
      }
      else
      {
        LOBYTE(v33) = 0;
        LOBYTE(v32) = 0;
        LOBYTE(v31) = 0;
        if ( !(unsigned __int8)CommonController::HandleEvent(this, v4, 5, 121, v31, v32, v33) )
        {
          v13 = 40;
          v14 = 0;
LABEL_54:
          LOBYTE(v33) = 0;
          LOBYTE(v32) = 0;
          LOBYTE(v31) = 0;
          CommonController::HandleEvent(this, v4, v14, v13, v31, v32, v33);
        }
      }
    }
    if ( (pState.Gamepad.wButtons & 0x20) != 0 && (*((_BYTE *)this + 2 * v5 + 10) & 0x20) == 0 )
    {
      if ( v6 || (v15 = 166, *((_BYTE *)this + 108)) )
        v15 = 27;
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 6, v15, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 0x100) != 0 && (*((_WORD *)this + v5 + 5) & 0x100) == 0 )
    {
      LOBYTE(v33) = 0;
      if ( v6 )
      {
        v16 = 9;
        LOBYTE(v32) = 1;
      }
      else
      {
        v16 = 37;
        LOBYTE(v32) = 0;
      }
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 7, v16, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 0x200) != 0 && (*((_WORD *)this + v5 + 5) & 0x200) == 0 )
    {
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      v17 = 9;
      if ( !v6 )
        v17 = 39;
      CommonController::HandleEvent(this, v4, 8, v17, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 0x1000) != 0 && (*((_WORD *)this + v5 + 5) & 0x1000) == 0
      || (pState.Gamepad.wButtons & 0x4000) != 0 && (*((_WORD *)this + v5 + 5) & 0x4000) == 0 )
    {
      if ( v6 )
      {
        LOBYTE(v33) = 0;
        LOBYTE(v32) = 0;
        LOBYTE(v31) = 0;
        CommonController::HandleEvent(this, v4, 10, 32, v31, v32, v33);
      }
      else if ( *((_DWORD *)this + v5 + 11)
             && (v18 = timeGetTime() - *((_DWORD *)this + v5 + 11), v18 < GetDoubleClickTime()) )
      {
        FakeControllerDoubleTap(*(HWND *)this);
      }
      else
      {
        LOBYTE(v33) = (pState.Gamepad.wButtons & 0x4000) != 0 && (*((_WORD *)this + v5 + 5) & 0x4000) == 0;
        LOBYTE(v32) = 0;
        LOBYTE(v31) = 0;
        CommonController::HandleEvent(this, v4, 10, 13, v31, v32, v33);
        *((_DWORD *)this + v5 + 11) = timeGetTime();
      }
    }
    if ( (pState.Gamepad.wButtons & 0x2000) != 0 && (*((_WORD *)this + v5 + 5) & 0x2000) == 0 )
    {
      if ( v6 || (v19 = 166, *((_BYTE *)this + 108)) )
        v19 = 27;
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 11, v19, v31, v32, v33);
    }
    if ( (pState.Gamepad.wButtons & 0x8000u) != 0 && (*((_WORD *)this + v5 + 5) & 0x8000) == 0 )
    {
      if ( v6 )
      {
        if ( !*((_BYTE *)this + 8) )
        {
          v20 = 13;
LABEL_102:
          LOBYTE(v33) = 0;
          LOBYTE(v32) = 0;
          LOBYTE(v31) = 0;
          CommonController::HandleEvent(this, v4, 12, v20, v31, v32, v33);
          goto LABEL_103;
        }
LABEL_98:
        FakeMCEMenu(*(HWND *)this);
        goto LABEL_103;
      }
      if ( *((_BYTE *)this + 8) )
        goto LABEL_98;
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      v21 = CommonController::HandleEvent(this, v4, 12, 121, v31, v32, v33);
      if ( *((_BYTE *)this + 9) && !v21 )
      {
        v20 = 40;
        goto LABEL_102;
      }
    }
LABEL_103:
    if ( !pState.Gamepad.bRightTrigger && *((_BYTE *)this + v5 + 22) )
      *((_DWORD *)this + v5 + 15) = 0;
    if ( !pState.Gamepad.bLeftTrigger && *((_BYTE *)this + v5 + 18) )
      *((_DWORD *)this + v5 + 15) = 0;
    v22 = *((_DWORD *)this + v5 + 15);
    v23 = 0;
    v24 = v22 == 0;
    if ( v22 )
      goto LABEL_115;
    if ( *((_DWORD *)this + v5 + 19) == pState.dwPacketNumber )
    {
      v24 = 1;
LABEL_115:
      if ( !v24 )
      {
        *((_DWORD *)this + v5 + 15) = v22 + 1;
        v23 = v22 + 1 >= g_DelayCount && (v22 + 1) % g_RepeatCount == 0;
      }
LABEL_119:
      if ( pState.Gamepad.bLeftTrigger && v23 )
      {
        LOBYTE(v33) = 0;
        if ( v6 )
        {
          v25 = 9;
          LOBYTE(v32) = 1;
        }
        else
        {
          v25 = 37;
          LOBYTE(v32) = 0;
        }
        LOBYTE(v31) = 0;
        CommonController::HandleEvent(this, v4, 13, v25, v31, v32, v33);
      }
      if ( pState.Gamepad.bRightTrigger && v23 )
      {
        LOBYTE(v33) = 0;
        LOBYTE(v32) = 0;
        LOBYTE(v31) = 0;
        v26 = 9;
        if ( !v6 )
          v26 = 39;
        CommonController::HandleEvent(this, v4, 14, v26, v31, v32, v33);
      }
      goto LABEL_130;
    }
    v23 = 1;
    if ( pState.Gamepad.bLeftTrigger || pState.Gamepad.bRightTrigger )
    {
      *((_DWORD *)this + v5 + 15) = 1;
      goto LABEL_119;
    }
LABEL_130:
    sThumbLY = pState.Gamepad.sThumbLY;
    if ( pState.Gamepad.sThumbLY > 28672 && !*((_BYTE *)this + v5 + 26) )
    {
      LOBYTE(v33) = 0;
      if ( v6 )
      {
        v28 = 9;
        LOBYTE(v32) = 1;
      }
      else
      {
        v28 = 38;
        LOBYTE(v32) = 0;
      }
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 19, v28, v31, v32, v33);
      sThumbLY = pState.Gamepad.sThumbLY;
      *((_BYTE *)this + v5 + 26) = 1;
    }
    if ( sThumbLY < 18432 && *((_BYTE *)this + v5 + 26) )
      *((_BYTE *)this + v5 + 26) = 0;
    if ( sThumbLY < -28672 && !*((_BYTE *)this + v5 + 30) )
    {
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      v29 = 9;
      if ( !v6 )
        v29 = 40;
      CommonController::HandleEvent(this, v4, 20, v29, v31, v32, v33);
      sThumbLY = pState.Gamepad.sThumbLY;
      *((_BYTE *)this + v5 + 30) = 1;
    }
    if ( sThumbLY > -18432 && *((_BYTE *)this + v5 + 30) )
      *((_BYTE *)this + v5 + 30) = 0;
    sThumbLX = pState.Gamepad.sThumbLX;
    if ( pState.Gamepad.sThumbLX < -28672 && !*((_BYTE *)this + v5 + 34) )
    {
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 17, 37, v31, v32, v33);
      sThumbLX = pState.Gamepad.sThumbLX;
      *((_BYTE *)this + v5 + 34) = 1;
    }
    if ( sThumbLX > -18432 && *((_BYTE *)this + v5 + 34) )
      *((_BYTE *)this + v5 + 34) = 0;
    if ( sThumbLX > 28672 && !*((_BYTE *)this + v5 + 38) )
    {
      LOBYTE(v33) = 0;
      LOBYTE(v32) = 0;
      LOBYTE(v31) = 0;
      CommonController::HandleEvent(this, v4, 18, 39, v31, v32, v33);
      sThumbLX = pState.Gamepad.sThumbLX;
      *((_BYTE *)this + v5 + 38) = 1;
    }
    if ( sThumbLX < 18432 )
    {
      if ( *((_BYTE *)this + v5 + 38) )
        *((_BYTE *)this + v5 + 38) = 0;
    }
    ++v4;
    *((_WORD *)this + v5 + 5) = pState.Gamepad.wButtons;
    *((_BYTE *)this + v5 + 18) = pState.Gamepad.bLeftTrigger;
    *((_BYTE *)this + v5 + 22) = pState.Gamepad.bRightTrigger;
    *((_DWORD *)this + v5++ + 19) = pState.dwPacketNumber;
    if ( (int)v4 >= 4 )
      return 1;
  }
  return 1;
}
