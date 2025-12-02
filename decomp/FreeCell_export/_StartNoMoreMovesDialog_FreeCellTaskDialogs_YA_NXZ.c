bool __fastcall FreeCellTaskDialogs::StartNoMoreMovesDialog(FreeCellTaskDialogs *this)
{
  unsigned int v2; // [rsp+28h] [rbp-D0h]
  _BYTE v3[12]; // [rsp+30h] [rbp-C8h] BYREF
  int v4; // [rsp+3Ch] [rbp-BCh]
  __int64 v5; // [rsp+40h] [rbp-B8h]
  _QWORD v6[21]; // [rsp+50h] [rbp-A8h] BYREF
  int v7; // [rsp+100h] [rbp+8h] BYREF
  int v8; // [rsp+104h] [rbp+Ch]

  LODWORD(v6[0]) = 160;
  memset((char *)v6 + 4, 0, 0x9Cu);
  v6[8] = v3;
  HIDWORD(v6[2]) = 24;
  *(_QWORD *)((char *)&v6[3] + 4) = 58129;
  *(_QWORD *)((char *)&v6[5] + 4) = 910;
  *(_DWORD *)v3 = 1;
  *(_QWORD *)&v3[4] = 908;
  v4 = 2;
  v5 = 909;
  HIDWORD(v6[7]) = 2;
  LODWORD(v6[9]) = 1;
  LOWORD(v2) = (_BYTE)g_bMediaCenter != 0 ? 117 : 130;
  v7 = 1;
  v8 = 2;
  return DialogHelper::ShowDialog(
           (DialogHelper *)v6,
           (struct _TASKDIALOGCONFIG *)&v7,
           2u,
           (unsigned int *const)0x438,
           0,
           v2,
           *(bool **)v3) == 1;
}
