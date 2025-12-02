void __fastcall FreeCellGame::UpdateUI(FreeCellGame *this, char a2)
{
  __int64 v2; // rax
  int v5; // ebx
  unsigned __int16 *v6; // rbp
  __int64 v7; // rcx
  __int64 v8; // r8
  int v9; // r11d
  const wchar_t *v10; // r9
  int v11; // r11d
  int v12; // r11d
  unsigned __int16 *v13; // rdi
  WPARAM v14; // rcx
  int v15; // eax
  __int64 v16; // [rsp+20h] [rbp-158h]
  WCHAR LCData[2]; // [rsp+30h] [rbp-148h] BYREF
  _BYTE v18[28]; // [rsp+34h] [rbp-144h] BYREF
  wchar_t Buffer[128]; // [rsp+50h] [rbp-128h] BYREF

  v2 = *((_QWORD *)this + 12);
  if ( v2 )
    LODWORD(v2) = *(_DWORD *)(v2 + 12);
  snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, L"%4d", v2);
  v5 = 52;
  v6 = LocalizeMessage(L"|54745|FreeCell_UI|Game #%1", Buffer);
  if ( *((_DWORD *)this + 58) )
  {
    v7 = *((_QWORD *)this + 31);
    v8 = *((unsigned int *)this + 58);
    do
    {
      if ( *(_QWORD *)v7 )
        v5 -= *(_DWORD *)(*(_QWORD *)v7 + 304LL);
      v7 += 8;
      --v8;
    }
    while ( v8 );
  }
  if ( byte_1000B1CB8 )
  {
    v9 = dword_1000AE010;
  }
  else
  {
    byte_1000B1CB8 = 1;
    wcscpy(LCData, L"1");
    memset(v18, 0, sizeof(v18));
    if ( !GetLocaleInfoW(0x400u, 0x1010u, LCData, 16) )
      Log(0x10000001u, L"BuildAPurbleGame::FormatScore() - Unable to get the negative number style");
    v9 = wcstol(LCData, 0, 10);
    dword_1000AE010 = v9;
  }
  if ( v5 >= 0 )
  {
    LODWORD(v16) = v5;
    v10 = L"%d";
LABEL_24:
    snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, v10, v16);
    goto LABEL_25;
  }
  LODWORD(v16) = -v5;
  if ( !v9 )
  {
    v10 = L"(%d)";
    goto LABEL_24;
  }
  v11 = v9 - 2;
  if ( v11 )
  {
    v12 = v11 - 1;
    if ( v12 )
    {
      if ( v12 == 1 )
        snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, L"%d -", v16);
      else
        snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, L"-%d", v16);
    }
    else
    {
      snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, L"%d-", v16);
    }
  }
  else
  {
    snwprintf_s(Buffer, 0x80u, 0xFFFFFFFFFFFFFFFFuLL, L"- %d", v16);
  }
LABEL_25:
  v13 = LocalizeMessage(L"|46379|FreeCell_UI|Cards left: %1", Buffer);
  Engine_SetStatusBarText(0, (LPARAM)v6);
  if ( a2 )
  {
    if ( *((_DWORD *)this + 92) == v5 )
      goto LABEL_34;
    v14 = 1;
  }
  else
  {
    v15 = *((_DWORD *)this + 92);
    if ( v15 == v5 )
      goto LABEL_34;
    if ( v5 )
    {
      if ( v15 == v5 )
        goto LABEL_34;
      v14 = 257;
    }
    else
    {
      v14 = 769;
    }
  }
  Engine_SetStatusBarText(v14, (LPARAM)v13);
LABEL_34:
  if ( v6 )
    LocalFree(v6);
  if ( v13 )
    LocalFree(v13);
  *((_DWORD *)this + 92) = v5;
  FreeCellGame::UpdateMenuState(this);
}
