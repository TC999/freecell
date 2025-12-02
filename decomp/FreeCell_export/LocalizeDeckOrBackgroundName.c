unsigned __int16 *__fastcall LocalizeDeckOrBackgroundName(const unsigned __int16 **a1, unsigned int a2)
{
  unsigned __int64 v3; // rdi
  unsigned __int16 *result; // rax
  unsigned __int16 *v5; // rbx
  unsigned __int16 *v6; // rcx
  const wchar_t *v7; // r8
  __int64 v8; // rcx
  unsigned __int16 *v9; // rdi
  bool v10; // zf
  unsigned __int16 *v11; // rax

  v3 = a2;
  result = LocalizeMessage(*a1);
  v5 = result;
  if ( result )
  {
    v6 = (unsigned __int16 *)*a1;
    if ( (_DWORD)v3 )
    {
      v7 = result;
    }
    else
    {
      operator delete(v6);
      *a1 = 0;
      v8 = -1;
      v9 = v5;
      do
      {
        if ( !v8 )
          break;
        v10 = *v9++ == 0;
        --v8;
      }
      while ( !v10 );
      v3 = (unsigned int)~(_DWORD)v8;
      v11 = (unsigned __int16 *)operator new(saturated_mul(v3, 2u));
      v7 = v5;
      *a1 = v11;
      v6 = v11;
    }
    wcscpy_s(v6, v3, v7);
    return (unsigned __int16 *)LocalFree(v5);
  }
  return result;
}
