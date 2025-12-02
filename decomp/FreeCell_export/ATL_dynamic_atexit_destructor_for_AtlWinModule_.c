void ATL::_dynamic_atexit_destructor_for___AtlWinModule__()
{
  ATL::AtlWinModuleTerm((struct ATL::_ATL_WIN_MODULE70 *)&ATL::_AtlWinModule, hInstance);
  if ( qword_1000AE7E8 )
  {
    free(qword_1000AE7E8);
    qword_1000AE7E8 = 0;
  }
  dword_1000AE7F0 = 0;
  dword_1000AE7F4 = 0;
}
