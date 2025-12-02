__int64 __fastcall StatisticsDialog::DialogProc(DialogHelper *this, int a2, __int16 a3)
{
  HWND v3; // rdx

  v3 = (HWND)(unsigned int)(a2 - 272);
  if ( (_DWORD)v3 )
  {
    if ( (_DWORD)v3 != 1 )
      return 0;
    if ( a3 == 2 )
    {
      DialogHelper::DismissDialog((HWND)this, 0, a3);
    }
    else if ( a3 == 1049 )
    {
      FreeCellTaskDialogs::StartResetStatsDialog(this, v3);
      StatisticsDialog::Update(this);
    }
  }
  else
  {
    StatisticsDialog::OnDialogInit(this, v3);
  }
  return 1;
}
