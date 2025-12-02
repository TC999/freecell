void __fastcall CardTable::PushAction(CardTable *this, int a2, const unsigned __int16 *a3, const unsigned __int16 *a4)
{
  _QWORD *v8; // rax
  _DWORD *v9; // rbx
  unsigned int v10; // ecx
  __int64 v11; // rdx
  void *v12; // rax

  if ( *((_BYTE *)this + 49) )
  {
    v8 = operator new(0x38u);
    v9 = v8;
    if ( v8 )
    {
      v8[1] = 0;
      v8[2] = 0;
      v8[3] = 0;
      v8[4] = 0;
      v8[5] = 0;
      v8[6] = 0;
    }
    else
    {
      v9 = 0;
    }
    *v9 = a2;
    Str::operator=((__int64)(v9 + 2), a3);
    Str::operator=((__int64)(v9 + 8), a4);
    v10 = *((_DWORD *)this + 61);
    if ( ++*((_DWORD *)this + 60) > v10 )
    {
      v11 = *((_DWORD *)this + 62) + v10;
      *((_DWORD *)this + 61) = v11;
      v12 = realloc(*((void **)this + 32), 8 * v11);
      if ( !v12 )
      {
        CheckAllocation(0);
        return;
      }
      *((_QWORD *)this + 32) = v12;
    }
    *(_QWORD *)(*((_QWORD *)this + 32) + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1)) = v9;
  }
}
