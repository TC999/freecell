void __fastcall CardStack::ResizeAccessAreas(CardStack *this)
{
  unsigned int v1; // edi
  int v3; // r8d
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rcx
  int v7; // r9d
  int v8; // r13d
  int v9; // r14d
  int v10; // r15d
  int v11; // esi
  int v12; // ebp
  int v13; // r8d
  int v14; // r12d
  __int64 i; // r11
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // rdx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax

  v1 = *((_DWORD *)this + 76);
  if ( v1 )
  {
    v3 = *((_DWORD *)this + 82);
    if ( v3 != 4 )
    {
      v4 = **((_QWORD **)this + 40);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v4 + 104);
        v6 = *(_QWORD *)(v4 + 96);
        v7 = 0;
        v8 = 0;
        v9 = *(_DWORD *)(v6 + 16) - *(_DWORD *)(v5 + 16);
        v10 = *(_DWORD *)(v6 + 20) - *(_DWORD *)(v5 + 20);
        v11 = v9 / 2;
        v12 = v10 / 2;
        if ( v3 && (v13 = v3 - 1) != 0 )
        {
          if ( (unsigned int)(v13 - 1) <= 1 )
            v8 = *((_DWORD *)this + 8);
        }
        else
        {
          v7 = *((_DWORD *)this + 6);
          if ( *((_DWORD *)this + 66) )
            v7 = CardStack::CalculateArrangeOffset(this, v7, *((_DWORD *)this + 7));
        }
        v14 = 0;
        for ( i = 0; ; i += 8 )
        {
          v16 = *((_QWORD *)this + 40);
          v17 = *(_QWORD *)(i + v16);
          if ( !v17 )
            goto LABEL_31;
          v18 = *(_QWORD *)(v17 + 96);
          if ( v17 == *(_QWORD *)(v16 + 8LL * (v1 - 1)) )
          {
            *(_DWORD *)(v18 + 52) = *(_DWORD *)(v18 + 16) - v9;
            goto LABEL_14;
          }
          v21 = *((_DWORD *)this + 82);
          if ( !v21 )
          {
            *(_DWORD *)(v18 + 48) = *(_DWORD *)(v18 + 20) - v12 - v7;
            *(_DWORD *)(v18 + 52) = *(_DWORD *)(v18 + 16) - v9;
            v20 = v7 - v12;
            goto LABEL_26;
          }
          v22 = v21 - 1;
          if ( !v22 )
            break;
          v23 = v22 - 1;
          if ( !v23 )
          {
            v24 = *(_DWORD *)(v18 + 16);
            *(_DWORD *)(v18 + 48) = v12;
            *(_DWORD *)(v18 + 44) = v24 - v11 - v8;
            *(_DWORD *)(v18 + 52) = v8 - v11;
            v20 = *(_DWORD *)(v18 + 20) - v10;
            goto LABEL_27;
          }
          if ( v23 == 1 )
          {
            *(_DWORD *)(v18 + 52) = v8;
LABEL_14:
            v19 = *(_DWORD *)(v18 + 20);
            *(_DWORD *)(v18 + 48) = v12;
            v20 = v19 - v10;
LABEL_26:
            *(_DWORD *)(v18 + 44) = v11;
LABEL_27:
            *(_DWORD *)(v18 + 56) = v20;
LABEL_28:
            *(_BYTE *)(v18 + 42) = 1;
          }
          v1 = *((_DWORD *)this + 76);
          if ( ++v14 >= v1 )
            return;
        }
        if ( *(_BYTE *)(v17 + 18) || *(_BYTE *)(v17 + 19) )
        {
          v26 = *((_DWORD *)this + 5);
          v27 = *(_DWORD *)(v18 + 16);
          *(_DWORD *)(v18 + 44) = v11;
          *(_DWORD *)(v18 + 48) = v12;
          *(_DWORD *)(v18 + 56) = v26;
          *(_DWORD *)(v18 + 52) = v27 - v9;
        }
        else
        {
          v25 = *(_DWORD *)(v18 + 16);
          *(_DWORD *)(v18 + 44) = v11;
          *(_DWORD *)(v18 + 48) = v12;
          *(_DWORD *)(v18 + 56) = v7;
          *(_DWORD *)(v18 + 52) = v25 - v9;
        }
        goto LABEL_28;
      }
LABEL_31:
      Log(0x10001u, L"CardStack::ResizeClickAreas() - Got a null card from the card array.");
    }
  }
}
