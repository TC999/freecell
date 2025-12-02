void __fastcall FreeCellTaskDialogs::StartResetStatsDialog(FreeCellTaskDialogs *this, HWND a2)
{
  __int64 v3; // rcx
  unsigned int v4; // [rsp+28h] [rbp-D0h]
  _BYTE v5[12]; // [rsp+30h] [rbp-C8h] BYREF
  int v6; // [rsp+3Ch] [rbp-BCh]
  __int64 v7; // [rsp+40h] [rbp-B8h]
  _QWORD v8[21]; // [rsp+50h] [rbp-A8h] BYREF
  int v9; // [rsp+100h] [rbp+8h] BYREF
  int v10; // [rsp+104h] [rbp+Ch]

  LODWORD(v8[0]) = 160;
  memset((char *)v8 + 4, 0, 0x9Cu);
  *(_QWORD *)((char *)v8 + 4) = this;
  v8[8] = v5;
  LOWORD(v4) = 503;
  v6 = 2;
  HIDWORD(v8[7]) = 2;
  v10 = 2;
  HIDWORD(v8[2]) = 8;
  *(_QWORD *)((char *)&v8[3] + 4) = 6010;
  *(_QWORD *)((char *)&v8[5] + 4) = 6011;
  *(_DWORD *)v5 = 1;
  *(_QWORD *)&v5[4] = 6012;
  v7 = 6013;
  LODWORD(v8[9]) = 1;
  v9 = 1;
  if ( DialogHelper::ShowDialog((DialogHelper *)v8, (struct _TASKDIALOGCONFIG *)&v9, 2u, 0, 0, v4, *(bool **)v5) == 1 )
  {
    v3 = *((_QWORD *)g_pFreeCellGame + 10);
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 16) = 0;
    *(_DWORD *)(v3 + 20) = 0;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 + 28) = 0;
    *(_BYTE *)(v3 + 32) = 0;
  }
}
