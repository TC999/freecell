void __fastcall CardStack::UpdateAccessibility(CardStack *this)
{
  int v2; // eax
  __int64 v3; // rcx
  const unsigned __int16 *v4; // rax
  unsigned __int16 *v5; // rdi
  unsigned __int16 *v6; // rbx
  HLOCAL *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // r8
  __int64 v10; // rcx
  __int64 v11; // rdx
  const unsigned __int16 *v12; // rax
  __int64 v13; // rax
  wchar_t Buffer[256]; // [rsp+30h] [rbp-218h] BYREF

  if ( *(_BYTE *)(*((_QWORD *)this + 8) + 72LL) )
  {
    v2 = *((_DWORD *)this + 76);
    if ( v2 )
    {
      Card::RefreshAccessibility(*(Card **)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(v2 - 1)));
      v3 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 40) + 8LL * (unsigned int)(*((_DWORD *)this + 76) - 1)) + 96LL);
      v4 = (const unsigned __int16 *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 56LL))(v3);
      NodeBase::SetAccessName(*((HLOCAL **)this + 18), v4);
      goto LABEL_16;
    }
    v5 = LocalizeMessage(*((const unsigned __int16 **)this + 11));
    v6 = LocalizeMessage(L"|54827|CardNames|Empty");
    swprintf_s(Buffer, 0x100u, L"%s %s", v5, v6);
    v7 = (HLOCAL *)*((_QWORD *)this + 18);
    Buffer[255] = 0;
    NodeBase::SetAccessName(v7, Buffer);
    LocalFree(v5);
    goto LABEL_15;
  }
  if ( !*((_BYTE *)this + 56) )
  {
    v12 = LocalizeMessage(*((const unsigned __int16 **)this + 11));
    v6 = (unsigned __int16 *)v12;
LABEL_14:
    NodeBase::SetAccessName(*((HLOCAL **)this + 18), v12);
LABEL_15:
    LocalFree(v6);
    goto LABEL_16;
  }
  v8 = *((unsigned int *)this + 76);
  v9 = 0;
  if ( (_DWORD)v8 )
  {
    v10 = *((_QWORD *)this + 40);
    v11 = v8;
    do
    {
      if ( !*(_BYTE *)(*(_QWORD *)v10 + 17LL) )
        v9 = (unsigned int)(v9 + 1);
      v10 += 8;
      --v11;
    }
    while ( v11 );
  }
  v12 = LocalizeMessage(
          L"|65000|CardStackName|%1, %2!d! face down card(s)//Name of cardstack appended with face down card count",
          *((_QWORD *)this + 11),
          v9);
  v6 = (unsigned __int16 *)v12;
  if ( v12 )
    goto LABEL_14;
LABEL_16:
  v13 = *((_QWORD *)this + 18);
  if ( *((_DWORD *)this + 76) )
    *(_DWORD *)(v13 + 192) = 16;
  else
    *(_DWORD *)(v13 + 192) = 43;
}
