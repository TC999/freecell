// Hidden C++ exception states: #wind=2
void __fastcall FreeCellGame::SaveGameExplorerStatistics(FreeCellGame *this)
{
  LPVOID v2; // rcx
  unsigned __int16 *v3; // rbx
  unsigned __int16 *v4; // rdi
  unsigned __int16 *v5; // rbx
  unsigned __int16 *v6; // rdi
  unsigned __int16 *v7; // rbx
  unsigned __int16 *v8; // rdi
  __int64 v9; // rcx
  unsigned __int16 *v10; // rbx
  unsigned __int16 *v11; // rdi
  unsigned __int16 *v12; // rbx
  unsigned __int16 *v13; // rdi
  unsigned __int16 *v14; // rbx
  unsigned __int16 *v15; // rdi
  __int64 v16; // rdx
  unsigned __int16 *v17; // rbx
  char v18; // [rsp+68h] [rbp+10h] BYREF
  __int64 v19; // [rsp+70h] [rbp+18h] BYREF
  LPVOID v20; // [rsp+78h] [rbp+20h] BYREF

  if ( g_bstrGDFPath )
  {
    v20 = 0;
    if ( CoCreateInstance(
           &GUID_dbc85a2c_c0dc_4961_b6e2_d28b62c11ad4,
           0,
           0x17u,
           &GUID_aff3ea11_e70e_407d_95dd_35e612c41ce2,
           &v20) < 0 )
    {
      v2 = v20;
      if ( !v20 )
        return;
      goto LABEL_19;
    }
    v19 = 0;
    if ( (*(int (__fastcall **)(LPVOID, unsigned __int16 *, _QWORD, char *, __int64 *))(*(_QWORD *)v20 + 24LL))(
           v20,
           g_bstrGDFPath,
           0,
           &v18,
           &v19) >= 0 )
    {
      v3 = LocalizeMessage(L"|7200|WGX_STATS|Overall");
      (*(void (__fastcall **)(__int64, _QWORD, unsigned __int16 *))(*(_QWORD *)v19 + 64LL))(v19, 0, v3);
      LocalFree(v3);
      v4 = LocalizeMessage(L"|7201|WGX_STATS|Games Played");
      v5 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", *(unsigned int *)(*((_QWORD *)this + 10) + 12LL));
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        0,
        v4,
        v5);
      LocalFree(v4);
      LocalFree(v5);
      v6 = LocalizeMessage(L"|7202|WGX_STATS|Games Won");
      v7 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", *(unsigned int *)(*((_QWORD *)this + 10) + 16LL));
      (*(void (__fastcall **)(__int64, _QWORD, __int64, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        1,
        v6,
        v7);
      LocalFree(v6);
      LocalFree(v7);
      v8 = LocalizeMessage(L"|7203|WGX_STATS|Win Percentage");
      v9 = *((_QWORD *)this + 10);
      if ( *(_DWORD *)(v9 + 12) )
        v10 = LocalizeMessage(
                L"|7208|WGX_STATS|%1!d!%%",
                (unsigned int)(100 * *(_DWORD *)(v9 + 16)) / *(_DWORD *)(v9 + 12));
      else
        v10 = LocalizeMessage(L"|7208|WGX_STATS|%1!d!%%", 0);
      (*(void (__fastcall **)(__int64, _QWORD, __int64, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        2,
        v8,
        v10);
      LocalFree(v8);
      LocalFree(v10);
      v11 = LocalizeMessage(L"|7204|WGX_STATS|Longest Winning Streak");
      v12 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", *(unsigned int *)(*((_QWORD *)this + 10) + 20LL));
      (*(void (__fastcall **)(__int64, _QWORD, __int64, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        3,
        v11,
        v12);
      LocalFree(v11);
      LocalFree(v12);
      v13 = LocalizeMessage(L"|7205|WGX_STATS|Longest Losing Streak");
      v14 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", *(unsigned int *)(*((_QWORD *)this + 10) + 24LL));
      (*(void (__fastcall **)(__int64, _QWORD, __int64, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        4,
        v13,
        v14);
      LocalFree(v13);
      LocalFree(v14);
      v15 = LocalizeMessage(L"|7206|WGX_STATS|Current Streak");
      v16 = *((_QWORD *)this + 10);
      if ( *(_BYTE *)(v16 + 32) )
        v17 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", *(unsigned int *)(v16 + 28));
      else
        v17 = LocalizeMessage(L"|7207|WGX_STATS|%1!d!", (unsigned int)-*(_DWORD *)(v16 + 28));
      (*(void (__fastcall **)(__int64, _QWORD, __int64, unsigned __int16 *, unsigned __int16 *))(*(_QWORD *)v19 + 88LL))(
        v19,
        0,
        5,
        v15,
        v17);
      LocalFree(v15);
      LocalFree(v17);
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 96LL))(v19, 1);
      if ( v19 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16LL))(v19);
      v2 = v20;
      if ( v20 )
        goto LABEL_19;
    }
    else
    {
      if ( v19 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16LL))(v19);
      v2 = v20;
      if ( v20 )
LABEL_19:
        (*(void (__fastcall **)(LPVOID))(*(_QWORD *)v20 + 16LL))(v2);
    }
  }
}
