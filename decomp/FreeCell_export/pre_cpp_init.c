__int64 pre_cpp_init()
{
  __int64 result; // rax

  dword_1000AE1BC = newmode;
  result = __getmainargs(&unk_1000AE1A0, &unk_1000AE1B0, &unk_1000AE1A8, (unsigned int)dowildcard, &dword_1000AE1BC);
  dword_1000AE1B8 = result;
  return result;
}
