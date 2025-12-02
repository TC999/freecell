void dynamic_atexit_destructor_for__g_FileHandleMapping__()
{
  dword_1000B1858 = 0;
  dword_1000B185C = 0;
  free(g_FileHandleMapping);
  free(qword_1000B1850);
  g_FileHandleMapping = 0;
  qword_1000B1850 = 0;
}
