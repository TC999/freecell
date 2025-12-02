char __fastcall DialogHelper::SetStaticTextI(
        DialogHelper *this,
        HWND a2,
        const unsigned __int16 *a3,
        const unsigned __int16 *a4)
{
  unsigned int v4; // esi
  HWND DlgItem; // rdi
  const WCHAR *v8; // rax
  WCHAR *v9; // rbx
  wchar_t *v10; // rax
  wchar_t *v11; // rbx

  v4 = (unsigned int)a4;
  DlgItem = GetDlgItem((HWND)this, (int)a2);
  if ( !DlgItem )
    return 0;
  if ( a3 )
  {
    v8 = LocalizeMessage(a3, v4);
    v9 = (WCHAR *)v8;
    if ( !v8 )
      return 0;
    if ( !SetWindowTextW(DlgItem, v8) )
    {
      LocalFree(v9);
      return 0;
    }
    LocalFree(v9);
  }
  else
  {
    v10 = (wchar_t *)operator new(0x200u);
    v11 = v10;
    if ( !v10 )
      return 0;
    swprintf_s(v10, 0x100u, L"%d", v4);
    if ( !SetWindowTextW(DlgItem, v11) )
    {
      operator delete(v11);
      return 0;
    }
    operator delete(v11);
  }
  return 1;
}
