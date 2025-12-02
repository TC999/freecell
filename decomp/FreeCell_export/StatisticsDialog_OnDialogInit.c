// Hidden C++ exception states: #wind=1
void __fastcall StatisticsDialog::OnDialogInit(DialogHelper *this, HWND a2)
{
  bool v3; // al
  bool v4; // bl
  WCHAR *v5; // rbx
  _BYTE v6[16]; // [rsp+28h] [rbp-40h] BYREF
  void *v7; // [rsp+38h] [rbp-30h]
  _BYTE v8[16]; // [rsp+40h] [rbp-28h] BYREF
  void *Block; // [rsp+50h] [rbp-18h]

  DialogHelper::CenterDialog((HWND)this, a2);
  RequestGetUsername(v6, 256);
  Str::Str((Str *)v8, &dword_1000028D4);
  if ( v7 )
    v3 = Str::Equals((Str *)v6, (const struct Str *)v8);
  else
    v3 = 0;
  v4 = !v3;
  operator delete(Block);
  if ( v4 )
    v5 = LocalizeMessage(L"|6408|UI_STATS|FreeCell Statistics - %1//statistics dialog title (with username)", v7);
  else
    v5 = LocalizeMessage(L"|6409|UI_STATS|FreeCell Statistics//statistics dialog title (no username)", v7);
  SetWindowTextW((HWND)this, v5);
  LocalFree(v5);
  StatisticsDialog::Update(this);
  operator delete(v7);
}
