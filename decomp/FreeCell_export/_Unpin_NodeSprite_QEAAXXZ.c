void __fastcall NodeSprite::Unpin(NodeSprite *this)
{
  unsigned int v1; // ebx
  __int64 v3; // rsi

  v1 = 0;
  if ( *((_DWORD *)this + 106) )
  {
    v3 = 0;
    do
    {
      ResourceManager::UnpinResource(g_pResourceManager, *(_DWORD *)(*((_QWORD *)this + 52) + v3));
      ++v1;
      v3 += 32;
    }
    while ( v1 < *((_DWORD *)this + 106) );
  }
}
