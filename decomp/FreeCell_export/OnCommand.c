// Hidden C++ exception states: #wind=1
void __fastcall OnCommand(OptionsDialog *a1, int a2, unsigned int a3)
{
  int v3; // esi
  __int64 v4; // rdx
  int v5; // edx
  int v6; // edx
  __int64 v7; // rdx
  __int64 v8; // rdx
  FreeCellGame *v9; // rbx
  HICON IconW; // rbp
  unsigned int v11; // r8d
  Str *v12; // rbx
  Str *v13; // rax
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // edx
  FreeCellGame *v19; // rbx
  FreeCellGame *v20; // rbx
  HMODULE ModuleHandleW; // rax
  int v22; // edx
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  FreeCellGame *v31; // rbx
  char v32[16]; // [rsp+38h] [rbp-10A0h] BYREF
  void *Block; // [rsp+48h] [rbp-1090h]
  char v34[16]; // [rsp+50h] [rbp-1088h] BYREF
  void *v35; // [rsp+60h] [rbp-1078h]
  WCHAR Buffer[2088]; // [rsp+70h] [rbp-1068h] BYREF

  v3 = 0;
  if ( a2 > 40031 )
  {
    if ( a2 > 40041 )
    {
      v27 = a2 - 40042;
      if ( !v27 )
      {
        g_cheatKeysEnabled = !g_cheatKeysEnabled;
        return;
      }
      v28 = v27 - 4;
      if ( !v28 )
      {
        v31 = g_pFreeCellGame;
        if ( *((_DWORD *)g_pFreeCellGame + 2) == 2 )
          *((_BYTE *)v31 + 362) = FreeCellGame::CheckForSuitCompletions(g_pFreeCellGame, 0, 0) != 0;
        return;
      }
      v29 = v28 - 1;
      if ( v29 )
      {
        v30 = v29 - 1;
        if ( v30 )
        {
          if ( v30 != 1 )
            return;
          v3 = 1;
        }
        ++v3;
        goto LABEL_61;
      }
      v3 = 1;
    }
    else
    {
      if ( a2 == 40041 )
      {
        *((_BYTE *)g_pFreeCellGame + 375) = 0;
        return;
      }
      v22 = a2 - 40032;
      if ( !v22 )
        goto LABEL_66;
      v23 = v22 - 1;
      if ( v23 )
      {
        v24 = v23 - 1;
        if ( !v24 )
        {
LABEL_63:
          FreeCellGame::SetCurrentBackground(g_pFreeCellGame, v3);
          FreeCellGame::SaveGeneralData(g_pFreeCellGame);
          (***(void (__fastcall ****)(_QWORD))(*((_QWORD *)g_pFreeCellGame + 22) + 96LL))(*(_QWORD *)(*((_QWORD *)g_pFreeCellGame + 22) + 96LL));
          return;
        }
        v25 = v24 - 1;
        if ( !v25 )
        {
LABEL_62:
          ++v3;
          goto LABEL_63;
        }
        v26 = v25 - 1;
        if ( v26 )
        {
          if ( v26 == 4 )
            *((_BYTE *)g_pFreeCellGame + 375) = 1;
          return;
        }
LABEL_61:
        ++v3;
        goto LABEL_62;
      }
    }
    ++v3;
LABEL_66:
    ++v3;
    goto LABEL_67;
  }
  if ( a2 == 40031 )
  {
LABEL_67:
    FreeCellGame::SetCurrentDeckSkin(g_pFreeCellGame, v3);
    FreeCellGame::SaveGeneralData(g_pFreeCellGame);
    (***(void (__fastcall ****)(_QWORD))(*((_QWORD *)g_pFreeCellGame + 22) + 96LL))(*(_QWORD *)(*((_QWORD *)g_pFreeCellGame
                                                                                                + 22)
                                                                                              + 96LL));
    return;
  }
  if ( a2 > 40007 )
  {
    v14 = a2 - 40008;
    if ( v14 )
    {
      v15 = v14 - 3;
      if ( v15 )
      {
        v16 = v15 - 1;
        if ( v16 )
        {
          v17 = v16 - 6;
          if ( v17 )
          {
            v18 = v17 - 9;
            if ( v18 )
            {
              if ( v18 == 1 )
              {
                v19 = g_pFreeCellGame;
                (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
                  g_pFreeCellGame,
                  *((unsigned int *)g_pFreeCellGame + 2));
                *((_DWORD *)v19 + 3) = *((_DWORD *)v19 + 2);
                *((_DWORD *)v19 + 2) = 4;
                (*(void (__fastcall **)(FreeCellGame *, __int64))(*(_QWORD *)v19 + 8LL))(v19, 4);
              }
            }
            else
            {
              FreeCellGame::FinishGame(g_pFreeCellGame);
              v20 = g_pFreeCellGame;
              (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
                g_pFreeCellGame,
                *((unsigned int *)g_pFreeCellGame + 2));
              *((_DWORD *)v20 + 3) = *((_DWORD *)v20 + 2);
              *((_DWORD *)v20 + 2) = 3;
              (*(void (__fastcall **)(FreeCellGame *, __int64))(*(_QWORD *)v20 + 8LL))(v20, 3);
            }
          }
          else
          {
            ModuleHandleW = GetModuleHandleW(0);
            if ( LoadStringW(ModuleHandleW, 0x88u, Buffer, 2084) > 0 )
              ShellExecuteW(0, L"open", Buffer, 0, 0, 1);
          }
        }
        else
        {
          FreeCellGame::ShowHint(g_pFreeCellGame, 1, 1);
        }
      }
      else
      {
        FreeCellGame::Undo(g_pFreeCellGame);
      }
    }
    else
    {
      Engine_ShowHelp();
    }
  }
  else if ( a2 == 40007 )
  {
    IconW = LoadIconW(g_hInstance, (LPCWSTR)0x79);
    if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
      GameAudio::StopSound((GameAudio *)3, 0, v11);
    v12 = Str::Str((Str *)v34, 0x38Bu);
    v13 = Str::Str((Str *)v32, 0x65u);
    ShellAboutW(g_hWnd, *((LPCWSTR *)v13 + 2), *((LPCWSTR *)v12 + 2), IconW);
    operator delete(Block);
    operator delete(v35);
    if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 && *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 29LL) )
      FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
    Engine_ResetTimer();
  }
  else
  {
    v4 = (unsigned int)(a2 - 40000);
    if ( (_DWORD)v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( v6 )
        {
          v7 = (unsigned int)(v6 - 1);
          if ( (_DWORD)v7 )
          {
            v8 = (unsigned int)(v7 - 1);
            if ( (_DWORD)v8 )
            {
              if ( (_DWORD)v8 == 1 )
                PostMessageW(g_hWnd, 0x10u, 0, 0);
            }
            else
            {
              OptionsDialog::Show(a1, v8, a3);
            }
          }
          else if ( !(_BYTE)g_bMediaCenter )
          {
            StatisticsDialog::Show(a1, v7, a3);
          }
        }
        else if ( !(_BYTE)g_bMediaCenter )
        {
          ChangeAppearenceDialog::Show(a1);
        }
      }
      else
      {
        if ( byte_1000B1CB0 )
        {
          if ( GetTickCount() - dword_1000B1CB4 < 0x4E2 )
            return;
          dword_1000B1CB4 = GetTickCount();
        }
        else
        {
          byte_1000B1CB0 = 1;
          dword_1000B1CB4 = GetTickCount();
        }
        if ( *((_DWORD *)g_pFreeCellGame + 2) == 3 )
        {
          FreeCellGame::SetRandomGameNumber(g_pFreeCellGame);
          v9 = g_pFreeCellGame;
          (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)g_pFreeCellGame + 16LL))(
            g_pFreeCellGame,
            *((unsigned int *)g_pFreeCellGame + 2));
          *((_DWORD *)v9 + 3) = *((_DWORD *)v9 + 2);
          *((_DWORD *)v9 + 2) = 0;
          (*(void (__fastcall **)(FreeCellGame *, _QWORD))(*(_QWORD *)v9 + 8LL))(v9, 0);
        }
        else
        {
          FreeCellTaskDialogs::StartNewGameDialog(g_pFreeCellGame);
        }
      }
    }
    else
    {
      SelectGameDialog::RecordAsLossOnNewGame = 1;
      SelectGameDialog::Show((__int64)a1, v4, a3);
    }
  }
}
