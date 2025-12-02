void __fastcall CheckAllocation(const void *a1)
{
  unsigned __int16 *v1; // [rsp+30h] [rbp-18h]

  if ( !a1 )
  {
    LOBYTE(v1) = 1;
    DialogHelper::ShowMessageBox(0, 0, 1, (const unsigned __int16 *)0xFFFE, L"Fatal Error", L"Out of memory.", v1);
    ExitProcess(0);
  }
}
