void __fastcall FreeCellGame::RecordCurrentGameAsLoss(FreeCellGame *this)
{
  __int64 v2; // rax
  __int64 v3; // rcx

  ++*(_DWORD *)(*((_QWORD *)this + 10) + 12LL);
  v2 = *((_QWORD *)this + 10);
  if ( *(_BYTE *)(v2 + 32) )
    *(_DWORD *)(v2 + 28) = 1;
  else
    ++*(_DWORD *)(v2 + 28);
  *(_BYTE *)(*((_QWORD *)this + 10) + 32LL) = 0;
  v3 = *((_QWORD *)this + 10);
  if ( *(_DWORD *)(v3 + 28) > *(_DWORD *)(v3 + 24) )
    *(_DWORD *)(v3 + 24) = *(_DWORD *)(v3 + 28);
  FreeCellGame::SaveGeneralData(this);
}
