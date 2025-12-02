void __fastcall __noreturn HandleNewFail()
{
  unsigned __int16 *v0; // [rsp+30h] [rbp-18h]

  LOBYTE(v0) = 1;
  DialogHelper::ShowMessageBox(0x385u, 0x384u, 1, (const unsigned __int16 *)0xFFFE, 0, 0, v0);
  LaunchMediaCenter((bool)g_bMediaCenter);
  ExitProcess(0);
}
