BOOL __fastcall StatisticsDialog::Update(DialogHelper *this)
{
  char v1; // di
  __int64 v2; // rbx
  unsigned int v4; // eax
  unsigned __int64 v5; // r9
  bool v6; // di
  HWND DlgItem; // rbx
  HWND v8; // rax
  int v10; // [rsp+20h] [rbp-18h]
  int v11; // [rsp+20h] [rbp-18h]
  int v12; // [rsp+20h] [rbp-18h]
  int v13; // [rsp+20h] [rbp-18h]
  int v14; // [rsp+20h] [rbp-18h]
  int v15; // [rsp+20h] [rbp-18h]
  bool v16; // [rsp+28h] [rbp-10h]
  bool v17; // [rsp+28h] [rbp-10h]
  bool v18; // [rsp+28h] [rbp-10h]
  bool v19; // [rsp+28h] [rbp-10h]
  bool v20; // [rsp+28h] [rbp-10h]
  bool v21; // [rsp+28h] [rbp-10h]

  v1 = 1;
  v2 = *((_QWORD *)g_pFreeCellGame + 10);
  LOBYTE(v10) = 1;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x3FD,
    (unsigned int)L"|44689|FREECELL_STAT|Games played: %1!d!// Shows the number of games played.",
    (const unsigned __int16 *)*(unsigned int *)(v2 + 12),
    v10,
    v16);
  LOBYTE(v11) = 1;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x400,
    (unsigned int)L"|43090|FREECELL_STAT|Games won: %1!d!// Used to display the number of games won.",
    (const unsigned __int16 *)*(unsigned int *)(v2 + 16),
    v11,
    v17);
  v4 = 0;
  if ( *(_DWORD *)(v2 + 12) )
    v4 = (unsigned int)(100 * *(_DWORD *)(v2 + 16)) / *(_DWORD *)(v2 + 12);
  LOBYTE(v12) = 1;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x403,
    (unsigned int)L"|63341|FREECELL_STAT|Win percentage: %1!d!%%// Used to display the percentage of games won.",
    (const unsigned __int16 *)v4,
    v12,
    v18);
  LOBYTE(v13) = 1;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x406,
    (unsigned int)L"|46905|FREECELL_STAT|Longest winning streak: %1!d!// Used to display the longest winning streak.",
    (const unsigned __int16 *)*(unsigned int *)(v2 + 20),
    v13,
    v19);
  LOBYTE(v14) = 1;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x40B,
    (unsigned int)L"|46897|FREECELL_STAT|Longest losing streak: %1!d!// Used to display the longest losing streak.",
    (const unsigned __int16 *)*(unsigned int *)(v2 + 24),
    v14,
    v20);
  v5 = *(unsigned int *)(v2 + 28);
  LOBYTE(v15) = 1;
  if ( !*(_BYTE *)(v2 + 32) )
    v5 = (unsigned int)-(int)v5;
  DialogHelper::SetStaticTextI(
    this,
    (HWND)0x410,
    (unsigned int)L"|54339|FREECELL_STAT|Current streak: %1!d!// Used to display the current streak.",
    (const unsigned __int16 *)v5,
    v15,
    v21);
  if ( *(_DWORD *)(v2 + 12)
    || *(_DWORD *)(v2 + 16)
    || *(_DWORD *)(v2 + 20)
    || *(_DWORD *)(v2 + 24)
    || *(_DWORD *)(v2 + 28)
    || *(_BYTE *)(v2 + 32) )
  {
    v1 = 0;
  }
  v6 = v1 == 0;
  DlgItem = GetDlgItem((HWND)this, 1049);
  if ( !v6 && GetFocus() == DlgItem )
  {
    v8 = GetDlgItem((HWND)this, 2);
    SetFocus(v8);
  }
  return EnableWindow(DlgItem, v6);
}
