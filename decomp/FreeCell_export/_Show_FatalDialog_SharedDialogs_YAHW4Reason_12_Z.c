void __noreturn SharedDialogs::FatalDialog::Show()
{
  unsigned __int16 *v0; // [rsp+30h] [rbp-18h]

  LOBYTE(v0) = 1;
  DialogHelper::ShowMessageBox(0x1788u, 0x178Au, 1, (const unsigned __int16 *)0xFFFE, 0, 0, v0);
  ExitProcess(0);
}
