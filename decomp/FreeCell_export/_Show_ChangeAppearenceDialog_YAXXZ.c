// Hidden C++ exception states: #wind=4
void __fastcall ChangeAppearenceDialog::Show(ChangeAppearenceDialog *this)
{
  _QWORD *v1; // rbx
  unsigned int v2; // r8d
  unsigned int v3; // edi
  __int64 v4; // rax
  __int64 v5; // rsi
  XmlNode *v6; // rbp
  unsigned __int16 *v7; // rax
  unsigned int v8; // edi
  __int64 v9; // rax
  __int64 v10; // rsi
  XmlNode *v11; // rbp
  unsigned __int16 *v12; // rax
  int v13; // esi
  unsigned int v14; // eax
  unsigned __int16 **v15; // rdx
  unsigned __int16 *v16; // rcx
  int v17; // r9d
  int v18; // edi
  unsigned int v19; // eax
  __int64 v20; // rbx
  unsigned __int16 **v21; // rdx
  unsigned __int16 *v22; // rcx
  int v23; // r9d
  HWND v24; // rbx
  unsigned int v25; // edx
  unsigned int v26; // ebx
  unsigned int v27; // edx
  unsigned int v28; // ebx
  FreeCellGame *v29; // rcx
  unsigned int v30; // edi
  __int64 v31; // rbx
  unsigned int v32; // edi
  __int64 v33; // rbx
  unsigned int v34; // edi
  __int64 v35; // rbx
  unsigned int v36; // edi
  __int64 v37; // rbx
  __int64 v38; // [rsp+38h] [rbp-110h]
  unsigned int v39; // [rsp+40h] [rbp-108h] BYREF
  int v40; // [rsp+44h] [rbp-104h]
  int v41; // [rsp+48h] [rbp-100h]
  void *Block; // [rsp+50h] [rbp-F8h]
  unsigned int v43; // [rsp+58h] [rbp-F0h] BYREF
  int v44; // [rsp+5Ch] [rbp-ECh]
  int v45; // [rsp+60h] [rbp-E8h]
  void *v46; // [rsp+68h] [rbp-E0h]
  unsigned int v47; // [rsp+70h] [rbp-D8h] BYREF
  int v48; // [rsp+74h] [rbp-D4h]
  int v49; // [rsp+78h] [rbp-D0h]
  void *v50; // [rsp+80h] [rbp-C8h]
  unsigned int v51; // [rsp+88h] [rbp-C0h] BYREF
  int v52; // [rsp+8Ch] [rbp-BCh]
  int v53; // [rsp+90h] [rbp-B8h]
  void *v54; // [rsp+98h] [rbp-B0h]
  HINSTANCE v55; // [rsp+A0h] [rbp-A8h] BYREF
  HWND v56; // [rsp+A8h] [rbp-A0h]
  _QWORD *(__fastcall *v57)(__int64); // [rsp+B0h] [rbp-98h]
  void (__fastcall *v58)(int, const unsigned __int16 *); // [rsp+B8h] [rbp-90h]
  const wchar_t *v59; // [rsp+C0h] [rbp-88h]
  unsigned int *v60; // [rsp+C8h] [rbp-80h]
  unsigned int *v61; // [rsp+D0h] [rbp-78h]
  unsigned int v62; // [rsp+D8h] [rbp-70h]
  const wchar_t *v63; // [rsp+E0h] [rbp-68h]
  unsigned int *v64; // [rsp+E8h] [rbp-60h]
  unsigned int *v65; // [rsp+F0h] [rbp-58h]
  unsigned int v66; // [rsp+F8h] [rbp-50h]
  __int64 v67; // [rsp+100h] [rbp-48h]
  const wchar_t *v68; // [rsp+108h] [rbp-40h]
  __int64 v69; // [rsp+110h] [rbp-38h]
  __int64 v70; // [rsp+118h] [rbp-30h]
  char v71; // [rsp+120h] [rbp-28h]
  __int64 v72; // [rsp+130h] [rbp-18h]

  v72 = -2;
  v39 = 0;
  v40 = 0;
  v41 = 16;
  Block = 0;
  v47 = 0;
  v48 = 0;
  v49 = 16;
  v50 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 16;
  v46 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 16;
  v54 = 0;
  v1 = (_QWORD *)*((_QWORD *)g_pFreeCellGame + 22);
  CardTable::GetCardDeckList(v1, &v39);
  CardTable::GetBackgroundList(v1, &v43);
  v3 = 0;
  v4 = v1[43];
  if ( *(_DWORD *)(v4 + 24) )
  {
    v5 = 0;
    do
    {
      if ( v3 < *(_DWORD *)(v4 + 24) )
        v6 = *(XmlNode **)(v5 + *(_QWORD *)(v4 + 40));
      else
        v6 = 0;
      if ( XmlNode::MatchName(v6, L"Deck") )
      {
        v7 = XmlNode::XPathAttributeSearchSingle(v6, L"/@Thumbnail");
        Array<IEventListener *>::Add(&v47, v7);
      }
      ++v3;
      v5 += 8;
      v4 = v1[43];
    }
    while ( v3 < *(_DWORD *)(v4 + 24) );
  }
  v8 = 0;
  v9 = v1[42];
  if ( *(_DWORD *)(v9 + 24) )
  {
    v10 = 0;
    do
    {
      if ( v8 < *(_DWORD *)(v9 + 24) )
        v11 = *(XmlNode **)(v10 + *(_QWORD *)(v9 + 40));
      else
        v11 = 0;
      if ( XmlNode::MatchName(v11, L"Background") )
      {
        v12 = XmlNode::XPathAttributeSearchSingle(v11, L"/@Thumbnail");
        Array<IEventListener *>::Add(&v51, v12);
      }
      ++v8;
      v10 += 8;
      v9 = v1[42];
    }
    while ( v8 < *(_DWORD *)(v9 + 24) );
  }
  v13 = -1;
  v14 = 0;
  if ( v39 )
  {
    v15 = (unsigned __int16 **)Block;
    while ( 1 )
    {
      v16 = *v15;
      do
      {
        v17 = *(unsigned __int16 *)((char *)v16 + v1[38] - (_QWORD)*v15);
        v2 = *v16 - v17;
        if ( v2 )
          break;
        ++v16;
      }
      while ( v17 );
      if ( !v2 )
        break;
      ++v14;
      ++v15;
      if ( v14 >= v39 )
        goto LABEL_26;
    }
    v13 = v14;
  }
LABEL_26:
  v18 = -1;
  v19 = 0;
  if ( v43 )
  {
    v20 = v1[35];
    v21 = (unsigned __int16 **)v46;
    while ( 1 )
    {
      v22 = *v21;
      do
      {
        v23 = *(unsigned __int16 *)((char *)v22 + v20 - (_QWORD)*v21);
        v2 = *v22 - v23;
        if ( v2 )
          break;
        ++v22;
      }
      while ( v23 );
      if ( !v2 )
        break;
      ++v19;
      ++v21;
      if ( v19 >= v43 )
        goto LABEL_35;
    }
    v18 = v19;
  }
LABEL_35:
  v55 = g_hInstance;
  v24 = g_hWnd;
  v56 = g_hWnd;
  v57 = ChangeAppearenceDialog::StreamFromFileCallback;
  v58 = ChangeAppearenceDialog::LogErrorCallback;
  v70 = 0;
  v67 = 0;
  v71 = *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 12LL);
  v61 = &v47;
  v60 = &v39;
  v59 = L"|52507|ChangeApp|Select Card Deck// Label above top listview";
  v62 = v13;
  v65 = &v51;
  v64 = &v43;
  v63 = L"|54956|ChangeApp|Select Background// Label above second listview";
  v66 = v18;
  v69 = 0;
  v68 = L"|59678|ChangeApp|&Randomly choose deck and background// Checkbox for random selection";
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
  {
    GameAudio::StopSound((GameAudio *)3, 0, v2);
    v24 = v56;
  }
  qword_1000AE978 = (__int64)&v55;
  qword_1000AE970 = 0;
  memset(&qword_1000AE930, 0, 0x40u);
  qword_1000AE928 = 0;
  byte_1000AE8EC = 0;
  DialogHelper::DialogBoxMCE(
    (LPCWSTR)0x1F4,
    v24,
    (HWND)SharedDialogs::ChangeAppearance::DialogProc,
    (__int64 (*)(HWND, unsigned int, unsigned __int64, __int64))2,
    0,
    0,
    0,
    v38);
  if ( byte_1000AE8EC == 1 )
  {
    v25 = v62;
    if ( v71 )
    {
      v26 = v39;
      v25 = rand() % v26;
    }
    if ( v25 != -1 && v25 < v39 )
      FreeCellGame::SetCurrentDeckSkin(g_pFreeCellGame, v25);
    v27 = v66;
    if ( v71 )
    {
      v28 = v43;
      v27 = rand() % v28;
    }
    if ( v27 != -1 && v27 < v43 )
      FreeCellGame::SetCurrentBackground(g_pFreeCellGame, v27);
    v29 = g_pFreeCellGame;
    *(_BYTE *)(*((_QWORD *)g_pFreeCellGame + 11) + 12LL) = v71;
    FreeCellGame::SaveGeneralData(v29);
    (***(void (__fastcall ****)(_QWORD))(*((_QWORD *)g_pFreeCellGame + 22) + 96LL))(*(_QWORD *)(*((_QWORD *)g_pFreeCellGame
                                                                                                + 22)
                                                                                              + 96LL));
  }
  if ( *((_DWORD *)g_pFreeCellGame + 2) == 1 )
    FreeCellGame::PlaySoundW(g_pFreeCellGame, 3, 1, 0);
  v30 = 0;
  if ( v39 )
  {
    v31 = 0;
    do
    {
      operator delete(*(void **)((char *)Block + v31));
      *(_QWORD *)((char *)Block + v31) = 0;
      ++v30;
      v31 += 8;
    }
    while ( v30 < v39 );
  }
  v39 = 0;
  v40 = 0;
  free(Block);
  Block = 0;
  v32 = 0;
  if ( v47 )
  {
    v33 = 0;
    do
    {
      operator delete(*(void **)((char *)v50 + v33));
      *(_QWORD *)((char *)v50 + v33) = 0;
      ++v32;
      v33 += 8;
    }
    while ( v32 < v47 );
  }
  v47 = 0;
  v48 = 0;
  free(v50);
  v50 = 0;
  v34 = 0;
  if ( v43 )
  {
    v35 = 0;
    do
    {
      operator delete(*(void **)((char *)v46 + v35));
      *(_QWORD *)((char *)v46 + v35) = 0;
      ++v34;
      v35 += 8;
    }
    while ( v34 < v43 );
  }
  v43 = 0;
  v44 = 0;
  free(v46);
  v46 = 0;
  v36 = 0;
  if ( v51 )
  {
    v37 = 0;
    do
    {
      operator delete(*(void **)((char *)v54 + v37));
      *(_QWORD *)((char *)v54 + v37) = 0;
      ++v36;
      v37 += 8;
    }
    while ( v36 < v51 );
  }
  v51 = 0;
  v52 = 0;
  free(v54);
  v54 = 0;
  if ( v46 )
    free(v46);
  if ( v50 )
    free(v50);
  if ( Block )
    free(Block);
}
