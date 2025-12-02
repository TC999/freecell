__int64 __fastcall EngineHandler::HandleWindowsMessage(
        EngineHandler *this,
        HWND a2,
        int a3,
        __int64 a4,
        __int64 a5,
        bool *a6)
{
  int v6; // r8d
  int v8; // r8d
  int v9; // r8d
  int v10; // r8d
  int v11; // r8d
  WCHAR *v13; // rbx
  tagGESTURECONFIG pGestureConfig; // [rsp+30h] [rbp-38h] BYREF
  int v15; // [rsp+3Ch] [rbp-2Ch]
  int v16; // [rsp+40h] [rbp-28h]
  int v17; // [rsp+44h] [rbp-24h]
  int v18; // [rsp+48h] [rbp-20h]
  int v19; // [rsp+4Ch] [rbp-1Ch]
  int v20; // [rsp+50h] [rbp-18h]

  v6 = a3 - 1;
  *a6 = 0;
  if ( v6 )
  {
    v8 = v6 - 255;
    if ( v8 )
    {
      v9 = v8 - 2;
      if ( v9 )
      {
        v10 = v9 - 15;
        if ( v10 )
        {
          v11 = v10 - 256;
          if ( v11 )
          {
            if ( v11 == 1 && *((_DWORD *)g_pFreeCellGame + 2) == 1 )
            {
              if ( *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 29LL) )
                FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
            }
          }
          else if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
          {
            GameAudio::StopSound((GameAudio *)3, 0, 0);
          }
          return 0;
        }
        if ( g_pRenderManager && *((_DWORD *)g_pRenderManager + 53) )
        {
          OnCommand(a2, (unsigned __int16)a4, a5, WORD1(a4));
          return 1;
        }
      }
      else if ( g_pRenderManager && *((_DWORD *)g_pRenderManager + 53) )
      {
        if ( g_cheatKeysEnabled && (_WORD)a4 == 59 )
          FreeCellGame::PlayHint(g_pFreeCellGame, 1);
        return 1;
      }
    }
    else if ( g_pRenderManager && *((_DWORD *)g_pRenderManager + 53) && a4 == 166 )
    {
      PostMessageW(g_hWnd, 0x111u, 0x9C4Bu, 0);
      return 1;
    }
  }
  else
  {
    v13 = LocalizeMessage(L"|42022|GameWindowTitle|FreeCell");
    SetWindowTextW(g_hWnd, v13);
    LocalFree(v13);
    pGestureConfig.dwWant = 0;
    v16 = 0;
    v19 = 0;
    pGestureConfig.dwID = 4;
    pGestureConfig.dwBlock = 1;
    v15 = 3;
    v17 = 1;
    v18 = 5;
    v20 = 1;
    SetGestureConfig(a2, 0, 3u, &pGestureConfig, 0xCu);
  }
  return 0;
}
