// Hidden C++ exception states: #wind=1
void __fastcall FreeCellGame::SpecialDealCards(FreeCellGame *this, unsigned int a2)
{
  __int64 v4; // rsi
  unsigned int v5; // r12d
  __int64 v6; // r14
  CardStack **v7; // rcx
  CardStack *v8; // rdi
  Card *v9; // rbx
  int v10; // ebx
  __int64 v11; // r12
  __int64 v12; // rbp
  __int64 v13; // r14
  __int64 v14; // r15
  unsigned int CardIdFromFreeCellId; // eax
  __int64 v16; // rbp
  __int64 v17; // r14
  __int64 v18; // r15
  unsigned int v19; // eax
  int v20; // ebx
  __int64 v21; // rbp
  __int64 v22; // r12
  unsigned int v23; // eax
  int v24; // ebx
  __int64 v25; // r12
  __int64 v26; // r15
  __int64 v27; // rbp
  __int64 v28; // rsi
  unsigned int v29; // eax
  __int64 v30; // rbp
  __int64 v31; // r15
  __int64 v32; // r12
  unsigned int v33; // eax
  int v34; // ebx
  __int64 v35; // r12
  __int64 v36; // rbp
  __int64 v37; // r15
  __int64 v38; // rsi
  unsigned int v39; // eax
  __int64 v40; // rbp
  __int64 v41; // r15
  __int64 v42; // r12
  unsigned int v43; // eax
  int v44; // ebx
  __int64 v45; // r12
  __int64 v46; // r15
  __int64 v47; // rdi
  __int64 v48; // rsi
  unsigned int v49; // eax
  __int64 v50; // r12
  __int64 v51; // rdi
  __int64 v52; // r15
  __int64 v53; // rsi
  unsigned int v54; // eax
  unsigned int v55; // r15d
  unsigned int v56; // eax
  int *v57; // rcx
  int *v58; // r12
  __int64 v59; // rdx
  __int64 v60; // rbx
  unsigned int v61; // eax
  _QWORD v62[2]; // [rsp+20h] [rbp-118h] BYREF
  void *Block; // [rsp+30h] [rbp-108h]
  __int64 v64; // [rsp+38h] [rbp-100h]
  int v65[52]; // [rsp+40h] [rbp-F8h] BYREF
  char v66; // [rsp+110h] [rbp-28h] BYREF

  v64 = -2;
  v4 = 0;
  v62[0] = 0;
  v62[1] = 0;
  Block = 0;
  Str::Format((Str *)v62, L"Dealing out cards for game %d", a2);
  Log(0x40u, (const unsigned __int16 *)Block);
  while ( *(_DWORD *)(**((_QWORD **)this + 28) + 304LL) )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = (CardStack **)*((_QWORD *)this + 28);
      if ( !*((_DWORD *)*v7 + 76) )
        break;
      v8 = *(CardStack **)(v6 + *((_QWORD *)this + 25));
      v9 = CardStack::Pop(*v7);
      Card::SetFaceUp(v9, 1, 0);
      CardStack::Push(v8, v9);
      ++v5;
      v6 += 8;
    }
    while ( v5 < 8 );
  }
  switch ( a2 )
  {
    case 0xFFFFFFFF:
      v10 = 0;
      v11 = 0;
      v12 = 7;
      do
      {
        v13 = 0;
        v14 = 4;
        do
        {
          CardIdFromFreeCellId = FreeCellGame::GetCardIdFromFreeCellId(v10);
          Card::SetCardId(
            *(Card **)(v11 + *(_QWORD *)(*(_QWORD *)(v13 + *((_QWORD *)this + 25)) + 320LL)),
            CardIdFromFreeCellId);
          ++v10;
          v13 += 8;
          --v14;
        }
        while ( v14 );
        v10 += 4;
        v11 += 8;
        --v12;
      }
      while ( v12 );
      v16 = 6;
      do
      {
        v10 -= 12;
        v17 = 32;
        v18 = 4;
        do
        {
          v19 = FreeCellGame::GetCardIdFromFreeCellId(v10);
          Card::SetCardId(*(Card **)(v4 + *(_QWORD *)(*(_QWORD *)(v17 + *((_QWORD *)this + 25)) + 320LL)), v19);
          ++v10;
          v17 += 8;
          --v18;
        }
        while ( v18 );
        v4 += 8;
        --v16;
      }
      while ( v16 );
      break;
    case 0xFFFFFFFE:
      v20 = 3;
      v21 = 0;
      v22 = 4;
      do
      {
        v23 = FreeCellGame::GetCardIdFromFreeCellId(v20);
        Card::SetCardId(**(Card ***)(*(_QWORD *)(*((_QWORD *)this + 25) + v21) + 320LL), v23);
        --v20;
        v21 += 8;
        --v22;
      }
      while ( v22 );
      v24 = 51;
      v25 = 8;
      v26 = 6;
      do
      {
        v27 = 0;
        v28 = 4;
        do
        {
          v29 = FreeCellGame::GetCardIdFromFreeCellId(v24);
          Card::SetCardId(*(Card **)(v25 + *(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 25) + v27) + 320LL)), v29);
          --v24;
          v27 += 8;
          --v28;
        }
        while ( v28 );
        v25 += 8;
        --v26;
      }
      while ( v26 );
      v30 = 6;
      do
      {
        v31 = 32;
        v32 = 4;
        do
        {
          v33 = FreeCellGame::GetCardIdFromFreeCellId(v24);
          Card::SetCardId(*(Card **)(v28 + *(_QWORD *)(*(_QWORD *)(v31 + *((_QWORD *)this + 25)) + 320LL)), v33);
          --v24;
          v31 += 8;
          --v32;
        }
        while ( v32 );
        v28 += 8;
        --v30;
      }
      while ( v30 );
      break;
    case 0xFFFFFFFD:
      v34 = 51;
      v35 = 0;
      v36 = 7;
      do
      {
        v37 = 0;
        v38 = 4;
        do
        {
          v39 = FreeCellGame::GetCardIdFromFreeCellId(v34);
          Card::SetCardId(*(Card **)(v35 + *(_QWORD *)(*(_QWORD *)(v37 + *((_QWORD *)this + 25)) + 320LL)), v39);
          --v34;
          v37 += 8;
          --v38;
        }
        while ( v38 );
        v35 += 8;
        --v36;
      }
      while ( v36 );
      v40 = 6;
      do
      {
        v41 = 32;
        v42 = 4;
        do
        {
          v43 = FreeCellGame::GetCardIdFromFreeCellId(v34);
          Card::SetCardId(*(Card **)(v38 + *(_QWORD *)(*(_QWORD *)(v41 + *((_QWORD *)this + 25)) + 320LL)), v43);
          --v34;
          v41 += 8;
          --v42;
        }
        while ( v42 );
        v38 += 8;
        --v40;
      }
      while ( v40 );
      break;
    case 0xFFFFFFFC:
      v44 = 51;
      v45 = 0;
      v46 = 4;
      do
      {
        v47 = 0;
        v48 = 7;
        do
        {
          v49 = FreeCellGame::GetCardIdFromFreeCellId(v44);
          Card::SetCardId(*(Card **)(v47 + *(_QWORD *)(*(_QWORD *)(v45 + *((_QWORD *)this + 25)) + 320LL)), v49);
          --v44;
          v47 += 8;
          --v48;
        }
        while ( v48 );
        v45 += 8;
        --v46;
      }
      while ( v46 );
      v50 = 32;
      v51 = 4;
      do
      {
        v52 = 0;
        v53 = 6;
        do
        {
          v54 = FreeCellGame::GetCardIdFromFreeCellId(v44);
          Card::SetCardId(*(Card **)(v52 + *(_QWORD *)(*(_QWORD *)(v50 + *((_QWORD *)this + 25)) + 320LL)), v54);
          --v44;
          v52 += 8;
          --v53;
        }
        while ( v53 );
        v50 += 8;
        --v51;
      }
      while ( v51 );
      break;
    default:
      srand(a2);
      v55 = 52;
      v56 = 0;
      v57 = v65;
      do
        *v57++ = v56++;
      while ( v56 < 0x34 );
      v58 = (int *)&v66;
      do
      {
        v59 = rand() % v55;
        v60 = (unsigned int)v59;
        v61 = FreeCellGame::GetCardIdFromFreeCellId(v65[v59]);
        --v55;
        --v58;
        Card::SetCardId(
          *(Card **)(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)this + 25) + 8 * (v4 & 7)) + 320LL)
                   + 8LL * ((unsigned int)v4 >> 3)),
          v61);
        v65[v60] = *v58;
        LODWORD(v4) = v4 + 1;
      }
      while ( (unsigned int)v4 < 0x34 );
      break;
  }
  operator delete(Block);
}
