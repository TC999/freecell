Str *__fastcall Str::SubString(__int64 a1, Str *a2, int a3, int a4)
{
  __int64 v4; // r11
  int v6; // r8d

  v4 = a3;
  if ( a3 < 0 || a4 < 0 || *(_QWORD *)a1 < (unsigned __int64)(unsigned int)(a3 + a4) )
    v6 = *(_DWORD *)a1 - a3;
  else
    v6 = a4;
  Str::Str(a2, (const unsigned __int16 *)(*(_QWORD *)(a1 + 16) + 2 * v4), v6);
  return a2;
}
