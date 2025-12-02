void __fastcall NodeBase::SetName(void **this, const unsigned __int16 *a2)
{
  __int64 v4; // rcx
  const unsigned __int16 *v5; // rdi
  bool v6; // zf
  unsigned __int64 v7; // rdi
  void *v8; // rax

  operator delete(this[16]);
  v4 = -1;
  v5 = a2;
  do
  {
    if ( !v4 )
      break;
    v6 = *v5++ == 0;
    --v4;
  }
  while ( !v6 );
  v7 = (unsigned int)~(_DWORD)v4;
  v8 = operator new[](saturated_mul(v7, 2u));
  this[16] = v8;
  memcpy(v8, a2, 2 * v7);
}
