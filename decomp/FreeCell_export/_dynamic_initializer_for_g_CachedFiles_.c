int dynamic_initializer_for__g_CachedFiles__()
{
  void *v0; // rax

  g_CachedFiles = malloc(0x80u);
  v0 = malloc(0x80u);
  dword_1000B1840 = 0;
  qword_1000B1838 = v0;
  dword_1000B1844 = 16;
  return atexit((void (__cdecl *)())dynamic_atexit_destructor_for__g_CachedFiles__);
}
