// Hidden C++ exception states: #wind=1
void __fastcall CabLoader::CabStream::~CabStream(CabLoader::CabStream *this)
{
  const void *v2; // rdx

  v2 = (const void *)*((_QWORD *)this + 3);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 40) )
      operator delete(*((void **)this + 3));
    else
      DllFileMgr::UnloadResource(Singleton<DllFileMgr>::s_Singleton, v2);
  }
  operator delete(*((void **)this + 2));
}
