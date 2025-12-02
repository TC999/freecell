char __fastcall FreeCellGame::UpdateCardAccessName(struct Card *a1)
{
  FreeCellGame *v3; // rdi
  unsigned int v4; // r13d
  unsigned int v5; // r12d
  unsigned int v6; // esi
  unsigned int v7; // r14d
  struct CardStack *CardStackWithCard; // rax
  unsigned int v9; // ecx
  CardStack *v10; // rbx
  unsigned int v11; // eax
  CardStack **v12; // rdx
  unsigned int v13; // edx
  unsigned int v14; // eax
  CardStack **v15; // rcx
  unsigned int v16; // edx
  int v17; // eax
  CardStack **i; // rcx
  unsigned __int16 *v19; // rbx
  unsigned __int16 *v20; // rax
  unsigned __int16 *v21; // rdi
  __int64 v22; // rcx
  bool v23; // zf
  __int64 v24; // rsi
  unsigned __int16 *v25; // rax
  __int64 v26; // rcx
  unsigned __int16 *v27; // r12
  unsigned __int16 *v28; // rdi
  __int64 v29; // rcx
  unsigned int v30; // eax
  size_t v31; // rsi
  wchar_t *v32; // rax
  unsigned __int16 *v33; // rdi

  if ( !a1 )
  {
    Log(0x10000001u, L"UpdateCardAccessName() - Bad parameters.");
    return 0;
  }
  if ( !*((_BYTE *)a1 + 17) )
    return 0;
  v3 = g_pFreeCellGame;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  CardStackWithCard = CardTable::GetCardStackWithCard(*((CardTable **)g_pFreeCellGame + 22), a1);
  v9 = 0;
  v10 = CardStackWithCard;
  v11 = *((_DWORD *)v3 + 46);
  if ( v11 )
  {
    v12 = (CardStack **)*((_QWORD *)v3 + 25);
    while ( v10 != *v12 )
    {
      ++v9;
      ++v12;
      if ( v9 >= v11 )
        goto LABEL_14;
    }
    v4 = v9 + 1;
    if ( !v10 )
      SharedDialogs::FatalDialog::Show(0);
    v7 = CardStack::GetCardLocation(v10, a1) + 1;
    if ( v4 )
      goto LABEL_26;
    v3 = g_pFreeCellGame;
  }
LABEL_14:
  v13 = *((_DWORD *)v3 + 52);
  v14 = 0;
  if ( !v13 )
    goto LABEL_20;
  v15 = (CardStack **)*((_QWORD *)v3 + 28);
  while ( v10 != *v15 )
  {
    ++v14;
    ++v15;
    if ( v14 >= v13 )
      goto LABEL_20;
  }
  v5 = v14 + 1;
  if ( v14 == -1 )
  {
LABEL_20:
    v16 = *((_DWORD *)v3 + 58);
    v17 = 0;
    if ( !v16 )
      return 0;
    for ( i = (CardStack **)*((_QWORD *)v3 + 31); v10 != *i; ++i )
    {
      if ( ++v17 >= v16 )
        return 0;
    }
    v6 = v17 + 1;
    if ( v17 == -1 )
      return 0;
  }
LABEL_26:
  v19 = 0;
  if ( v4 )
  {
    v20 = LocalizeMessage(L"|61500|CardAccess|Stack %1!d! Number %2!d!", v4, v7);
LABEL_32:
    v19 = v20;
    goto LABEL_33;
  }
  if ( v5 )
  {
    v20 = LocalizeMessage(L"|50799|CardAccess|Free Cell %1!d!", v5);
    goto LABEL_32;
  }
  if ( v6 )
  {
    v20 = LocalizeMessage(L"|41077|CardAccess|Home Cell %1!d!", v6);
    goto LABEL_32;
  }
LABEL_33:
  v21 = v19;
  v22 = -1;
  do
  {
    if ( !v22 )
      break;
    v23 = *v21++ == 0;
    --v22;
  }
  while ( !v23 );
  v24 = -v22 - 2;
  if ( -(int)v22 == 2 )
  {
    Log(0x10000001u, L"UpdateCardAccessName() - Zero length card prefix string.");
    return 0;
  }
  v25 = LocalizeMessage((const unsigned __int16 *)(&Card::CARD_HUMAN_NAME)[*((unsigned int *)a1 + 2)]);
  v26 = -1;
  v27 = v25;
  v28 = v25;
  do
  {
    if ( !v26 )
      break;
    v23 = *v28++ == 0;
    --v26;
  }
  while ( !v23 );
  v29 = -v26 - 2;
  if ( !(_DWORD)v29 )
  {
    Log(0x10000001u, L"UpdateCardAccessName() - Zero length name string.");
    return 0;
  }
  v30 = v29 + v24 + 2;
  if ( (_DWORD)v29 + (_DWORD)v24 == -2 )
  {
    Log(0x10000001u, L"UpdateCardAccessName() - Zero length final name string.");
    return 0;
  }
  v31 = v30;
  v32 = (wchar_t *)operator new[](saturated_mul(v30, 2u));
  v33 = v32;
  if ( !v32 )
  {
    Log(0x10000001u, L"UpdateCardAccessName() - Null card name string.");
    return 0;
  }
  swprintf_s(v32, v31, L"%s %s", v19, v27);
  NodeBase::SetAccessName(*((NodeBase **)a1 + 12), v33);
  LocalFree(v27);
  LocalFree(v19);
  operator delete(v33);
  return 1;
}
