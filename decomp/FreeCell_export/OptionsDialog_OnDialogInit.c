LRESULT __fastcall OptionsDialog::OnDialogInit(HWND hDlg, HWND a2)
{
  HWND DlgItem; // rax
  WPARAM v4; // rbx
  _DWORD v6[78]; // [rsp+20h] [rbp-138h] BYREF
  int pvParam; // [rsp+160h] [rbp+8h] BYREF

  DialogHelper::CenterDialog(hDlg, a2);
  qword_1000AE8C0 = (__int64)hDlg;
  hWnd = GetDlgItem(hDlg, 1025);
  qword_1000AE898 = GetDlgItem(hDlg, 1022);
  qword_1000AE8B8 = GetDlgItem(hDlg, 1033);
  qword_1000AE890 = GetDlgItem(hDlg, 1043);
  DlgItem = GetDlgItem(hDlg, 1064);
  v4 = 0;
  qword_1000AE888 = (__int64)DlgItem;
  if ( !*((_QWORD *)g_pAudio + 2) )
    EnableWindow(hWnd, 0);
  SendMessageW(hWnd, 0xF1u, *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 29LL) != 0, 0);
  (*(void (__fastcall **)(_QWORD, _DWORD *))(**((_QWORD **)g_pRenderManager + 10) + 56LL))(
    *((_QWORD *)g_pRenderManager + 10),
    v6);
  if ( v6[0] == 3 || (pvParam = 1, SystemParametersInfoW(0x1042u, 0, &pvParam, 0), !pvParam) )
    EnableWindow(qword_1000AE898, 0);
  SendMessageW(qword_1000AE898, 0xF1u, *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 31LL) != 0, 0);
  SendMessageW(qword_1000AE8B8, 0xF1u, *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 13LL) != 0, 0);
  SendMessageW(qword_1000AE890, 0xF1u, *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 14LL) == 0, 0);
  LOBYTE(v4) = *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 15LL) != 0;
  return SendMessageW((HWND)qword_1000AE888, 0xF1u, v4, 0);
}
