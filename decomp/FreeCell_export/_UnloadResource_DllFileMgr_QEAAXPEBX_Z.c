void __fastcall DllFileMgr::UnloadResource(DllFileMgr *this, const void *a2)
{
  __int64 v3; // rcx
  char *v5; // rax
  CabLoader::CabStream *v6; // rbx
  __int64 v7; // rax
  CabLoader::CabStream **v8; // rcx
  unsigned int v9; // ecx
  unsigned int v10; // edi
  const void **i; // rax
  __int64 v12; // rbx
  __int64 v13; // rdx

  v3 = 0;
  if ( CabLoader::sCabStreams )
  {
    v5 = (char *)qword_1000ADCF0;
    while ( !*(_QWORD *)v5 || *(const void **)(*(_QWORD *)v5 + 24LL) != a2 || !*(_BYTE *)(*(_QWORD *)v5 + 40LL) )
    {
      v3 = (unsigned int)(v3 + 1);
      v5 += 8;
      if ( (unsigned int)v3 >= CabLoader::sCabStreams )
        goto LABEL_7;
    }
    v6 = (CabLoader::CabStream *)*((_QWORD *)qword_1000ADCF0 + v3);
  }
  else
  {
LABEL_7:
    v6 = 0;
  }
  if ( v6 )
  {
    v7 = 0;
    if ( CabLoader::sCabStreams )
    {
      v8 = (CabLoader::CabStream **)qword_1000ADCF0;
      while ( *v8 != v6 )
      {
        v7 = (unsigned int)(v7 + 1);
        ++v8;
        if ( (unsigned int)v7 >= CabLoader::sCabStreams )
          goto LABEL_16;
      }
      *((_QWORD *)qword_1000ADCF0 + v7) = 0;
    }
LABEL_16:
    CabLoader::CabStream::~CabStream(v6);
    operator delete(v6);
  }
  v9 = *((_DWORD *)this + 2580);
  v10 = 0;
  if ( v9 )
  {
    for ( i = (const void **)*((_QWORD *)this + 1292); *i != a2; i += 2 )
    {
      if ( ++v10 >= v9 )
        return;
    }
    v12 = *((_QWORD *)this + 1292) + 16LL * v10;
    operator delete(*(void **)v12);
    *(_QWORD *)v12 = 0;
    *(_DWORD *)(v12 + 8) = 0;
    if ( v10 < *((_DWORD *)this + 2580) - 1 )
    {
      v13 = 16LL * (int)v10;
      do
      {
        ++v10;
        *(__m128i *)(v13 + *((_QWORD *)this + 1292)) = _mm_loadu_si128((const __m128i *)(v13
                                                                                       + *((_QWORD *)this + 1292)
                                                                                       + 16));
        v13 += 16;
      }
      while ( v10 < *((_DWORD *)this + 2580) - 1 );
    }
    --*((_DWORD *)this + 2580);
  }
}
