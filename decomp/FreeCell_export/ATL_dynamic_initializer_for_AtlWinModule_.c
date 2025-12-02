int ATL::_dynamic_initializer_for___AtlWinModule__()
{
  memset(&CriticalSection, 0, sizeof(CriticalSection));
  qword_1000AE7E8 = 0;
  dword_1000AE7F0 = 0;
  dword_1000AE7F4 = 0;
  qword_1000AE7E0 = 0;
  ATL::_AtlWinModule = 72;
  if ( (int)ATL::CComCriticalSection::Init(&CriticalSection) < 0 )
  {
    ATL::_AtlWinModule = 0;
    ATL::CAtlBaseModule::m_bInitFailed = 1;
  }
  return atexit((void (__cdecl *)())ATL::_dynamic_atexit_destructor_for___AtlWinModule__);
}
