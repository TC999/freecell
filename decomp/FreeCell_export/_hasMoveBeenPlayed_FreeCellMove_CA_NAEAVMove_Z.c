char __fastcall FreeCellMove::hasMoveBeenPlayed(struct Move *a1)
{
  char v1; // r10
  __int64 v2; // r9
  __int64 v3; // r11
  char *v4; // r8
  __int64 v5; // rdx

  v1 = 0;
  v2 = FreeCellMove::m_aPreviousMoves - 1;
  if ( FreeCellMove::m_aPreviousMoves - 1 >= 0 )
  {
    v3 = *((_QWORD *)a1 + 4);
    v4 = (char *)Block + 40 * v2 + 8;
    do
    {
      v5 = *((_QWORD *)v4 - 1);
      if ( v3 == v5
        && *((_QWORD *)a1 + 1) == *(_QWORD *)v4
        && *((_DWORD *)a1 + 4) == *((_DWORD *)v4 + 3)
        && *((_DWORD *)a1 + 6) == *((_DWORD *)v4 + 4)
        || v3 == *((_QWORD *)v4 + 3)
        && *(_QWORD *)a1 == v5
        && *((_QWORD *)a1 + 1) == *(_QWORD *)v4
        && *((_DWORD *)a1 + 4) == *((_DWORD *)v4 + 2)
        && *((_DWORD *)a1 + 5) == *((_DWORD *)v4 + 3)
        && *((_DWORD *)a1 + 6) == *((_DWORD *)v4 + 4) )
      {
        v1 = 1;
      }
      v4 -= 40;
      --v2;
    }
    while ( v2 >= 0 );
  }
  return v1;
}
