void __fastcall EngineHandler::ReportOutOfMemory(EngineHandler *this)
{
  unsigned __int16 *v1; // [rsp+30h] [rbp-18h]

  LOBYTE(v1) = 1;
  DialogHelper::ShowMessageBox(0x65u, 0x67u, 1, (const unsigned __int16 *)0xFFFE, 0, 0, v1);
}
