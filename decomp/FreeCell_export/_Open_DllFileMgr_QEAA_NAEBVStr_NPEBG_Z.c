// Hidden C++ exception states: #wind=4
char __fastcall DllFileMgr::Open(DllFileMgr *this, LPCWSTR *a2, __int64 a3, const unsigned __int16 *a4)
{
  bool v5; // bp
  DllFileMgr *v6; // rsi
  HMODULE Library; // r13
  DWORD LastError; // r12d
  const wchar_t *v9; // r9
  char v10; // di
  __int64 v11; // r8
  __int64 ModulePath; // rax
  Str *v13; // rax
  unsigned int v14; // ebx
  WCHAR *v15; // rbp
  HMODULE v16; // rax
  _BYTE v18[16]; // [rsp+38h] [rbp-50h] BYREF
  LPCWSTR lpLibFileName; // [rsp+48h] [rbp-40h]
  _BYTE v20[16]; // [rsp+50h] [rbp-38h] BYREF
  void *Block; // [rsp+60h] [rbp-28h]

  v5 = g_bDebugEnabled;
  v6 = qword_1000B10B0;
  DllFileMgr::Close(qword_1000B10B0);
  Library = LoadLibraryExW(a2[2], 0, 2u);
  LastError = GetLastError();
  v9 = L"failure";
  v10 = 0;
  if ( Library )
    v9 = L"success";
  Log(4u, L"Loading resource dll '%s', result = %s (0x%08X)", a2[2], v9, LastError);
  if ( Library )
  {
    Array<IEventListener *>::Add((__int64)v6 + 10272, (__int64)Library);
    if ( (unsigned int)*a2 > 4 )
    {
      Str::SubString(a2, v20, 0, (unsigned int)*a2 - 4);
      v14 = 2;
      while ( 1 )
      {
        Str::Str((Str *)v18, (const struct Str *)v20);
        Str::AppendF((Str *)v18, L"%d.dll", v14);
        v15 = (WCHAR *)lpLibFileName;
        v16 = LoadLibraryExW(lpLibFileName, 0, 2u);
        if ( !v16 )
          break;
        Array<IEventListener *>::Add((__int64)v6 + 10272, (__int64)v16);
        operator delete(v15);
        if ( ++v14 >= 0x64 )
          goto LABEL_13;
      }
      operator delete(v15);
LABEL_13:
      operator delete(Block);
    }
  }
  else if ( LastError == 2 && v5 )
  {
    LOBYTE(v11) = 1;
    ModulePath = GetModulePath(v20, 0, v11);
    Str::operator=((char *)v6 + 10296, ModulePath);
    operator delete(Block);
    v13 = Str::Str((Str *)v20, L"input\\");
    Str::operator+=((char *)v6 + 10296, v13);
    operator delete(Block);
    Log(4u, L"Falling back to loose files, loaded from '%s'...", *((_QWORD *)v6 + 1289));
  }
  if ( *((_DWORD *)v6 + 2568) || *((_QWORD *)v6 + 1287) )
    return 1;
  return v10;
}
