void __fastcall Affector_Int::CopyMessageList(Affector_Int *this, struct Affector_Int *a2)
{
  int v2; // edi
  __int64 i; // rbp
  unsigned int v6; // ecx
  int v7; // r12d
  __int64 v8; // rdx
  void *v9; // rax

  v2 = 0;
  if ( *((_DWORD *)this + 8) )
  {
    for ( i = 0; ; i += 4 )
    {
      v6 = *((_DWORD *)a2 + 9);
      v7 = *(_DWORD *)(*((_QWORD *)this + 6) + i);
      if ( ++*((_DWORD *)a2 + 8) <= v6 )
        goto LABEL_7;
      v8 = *((_DWORD *)a2 + 10) + v6;
      *((_DWORD *)a2 + 9) = v8;
      v9 = realloc(*((void **)a2 + 6), 4 * v8);
      if ( v9 )
        break;
      CheckAllocation(0);
LABEL_8:
      if ( (unsigned int)++v2 >= *((_DWORD *)this + 8) )
        return;
    }
    *((_QWORD *)a2 + 6) = v9;
LABEL_7:
    *(_DWORD *)(*((_QWORD *)a2 + 6) + 4LL * (unsigned int)(*((_DWORD *)a2 + 8) - 1)) = v7;
    goto LABEL_8;
  }
}
