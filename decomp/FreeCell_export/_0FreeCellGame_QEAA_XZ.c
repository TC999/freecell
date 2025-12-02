FreeCellGame *__fastcall FreeCellGame::FreeCellGame(FreeCellGame *this)
{
  ULONGLONG TickCount64; // rax
  bool v3; // zf
  wchar_t *v4; // rax

  *(_QWORD *)this = &FreeCellGame::`vftable'{for `IStateMachine'};
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_QWORD *)this + 2) = &FreeCellGame::`vftable'{for `IEventListener'};
  *((_QWORD *)this + 3) = &FreeCellGame::`vftable'{for `CardAnimationManager::ICardAnimationEventListener'};
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_QWORD *)this + 6) = 0;
  *((_DWORD *)this + 10) = 16;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 16;
  *((_QWORD *)this + 9) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_QWORD *)this + 21) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 16;
  *((_QWORD *)this + 25) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 16;
  *((_QWORD *)this + 28) = 0;
  *((_DWORD *)this + 58) = 0;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 16;
  *((_QWORD *)this + 31) = 0;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 66) = 16;
  *((_QWORD *)this + 34) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 16;
  *((_QWORD *)this + 37) = 0;
  *((_DWORD *)this + 92) = -1;
  *((_QWORD *)this + 39) = 0;
  *((_QWORD *)this + 38) = 0;
  *((_QWORD *)this + 14) = 0;
  *((_QWORD *)this + 22) = 0;
  *((_QWORD *)this + 42) = 0;
  *((_QWORD *)this + 44) = 0;
  *((_QWORD *)this + 41) = 0;
  *((_QWORD *)this + 40) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_QWORD *)this + 10) = 0;
  *((_QWORD *)this + 11) = 0;
  *((_QWORD *)this + 12) = 0;
  *((_DWORD *)this + 86) = 0;
  *((_BYTE *)this + 362) = 0;
  *((_BYTE *)this + 372) = 0;
  *((_QWORD *)this + 16) = 0;
  *((_QWORD *)this + 17) = 0;
  *((_QWORD *)this + 18) = 0;
  *((_QWORD *)this + 19) = 0;
  *((_BYTE *)this + 373) = 0;
  *((_BYTE *)this + 375) = 0;
  *((_BYTE *)this + 364) = 0;
  *((_BYTE *)this + 363) = 0;
  *((_BYTE *)this + 380) = 0;
  *((_BYTE *)this + 378) = 0;
  *((_DWORD *)this + 96) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_BYTE *)this + 381) = 0;
  if ( *((_BYTE *)this + 360) )
    *((_BYTE *)this + 360) = 0;
  *((_BYTE *)this + 379) = 0;
  *((_DWORD *)this + 40) = 6085;
  TickCount64 = GetTickCount64();
  v3 = (_BYTE)g_bMediaCenter == 0;
  *((_QWORD *)this + 21) = TickCount64;
  v4 = L"FreeCellSettingsMCE.xml";
  if ( v3 )
    v4 = L"FreeCellSettings.xml";
  g_SETTINGS_SAVE_FILENAME = v4;
  return this;
}
