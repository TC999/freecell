bool __fastcall OptionsDialog::OnOkButton(HWND hDlg)
{
  UINT v2; // eax
  FreeCellGame *v3; // rcx
  UINT v4; // eax
  FreeCellGame *v5; // rcx
  UINT v6; // eax
  FreeCellGame *v7; // rdx
  TipManager *v8; // rcx
  UINT v9; // eax
  FreeCellGame *v10; // rcx

  v2 = IsDlgButtonChecked(hDlg, 1025);
  v3 = g_pFreeCellGame;
  *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 29LL) = v2 == 1;
  FreeCellGame::SetSoundEnabled(v3, v2 == 1);
  v4 = IsDlgButtonChecked(hDlg, 1022);
  v5 = g_pFreeCellGame;
  *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 31LL) = v4 == 1;
  FreeCellGame::SetAnimationEnabled(v5, v4 == 1);
  v6 = IsDlgButtonChecked(hDlg, 1043);
  v7 = g_pFreeCellGame;
  *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) = v6 == 0;
  if ( v6 == 0 )
  {
    v8 = (TipManager *)*((_QWORD *)v7 + 42);
    if ( v8 )
      TipManager::HideTip(v8, 0);
  }
  *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 13LL) = IsDlgButtonChecked(hDlg, 1033) == 1;
  v9 = IsDlgButtonChecked(hDlg, 1064);
  v10 = g_pFreeCellGame;
  *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 15LL) = v9 == 1;
  return FreeCellGame::SaveGeneralData(v10);
}
