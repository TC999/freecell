// Hidden C++ exception states: #wind=1
void __fastcall NodeButton::~NodeButton(NodeButton *this)
{
  __int64 v2; // r11
  UserInterface *v3; // rbx
  unsigned int v4; // esi
  NodeButton **v5; // rax
  signed int v6; // eax
  unsigned int v7; // r11d
  __int64 v8; // r8
  __int64 v9; // r9

  *(_QWORD *)this = &NodeButton::`vftable';
  ResourceManager::DestroyResource(g_pResourceManager, *((_DWORD *)this + 121));
  ResourceManager::DestroyResource(g_pResourceManager, *((_DWORD *)this + 123));
  v2 = 0;
  v3 = g_pUserInterface;
  v4 = *((_DWORD *)g_pUserInterface + 4);
  if ( v4 )
  {
    v5 = (NodeButton **)*((_QWORD *)g_pUserInterface + 1);
    while ( *v5 != this )
    {
      v2 = (unsigned int)(v2 + 1);
      ++v5;
      if ( (unsigned int)v2 >= v4 )
        goto LABEL_10;
    }
    v6 = SortedListI<Event::RegisteredType>::BinSearch(
           (__int64 *)g_pUserInterface,
           *(_DWORD *)(*(_QWORD *)g_pUserInterface + 4 * v2),
           0,
           v4);
    v7 = v6;
    if ( v6 < v4 - 1 )
    {
      v8 = 8LL * v6;
      v9 = 4LL * v6;
      do
      {
        *(_DWORD *)(v9 + *(_QWORD *)v3) = *(_DWORD *)(v9 + *(_QWORD *)v3 + 4);
        *(_QWORD *)(*((_QWORD *)v3 + 1) + v8) = *(_QWORD *)(*((_QWORD *)v3 + 1) + v8 + 8);
        ++v7;
        v9 += 4;
        v8 += 8;
      }
      while ( v7 < *((_DWORD *)v3 + 4) - 1 );
    }
    --*((_DWORD *)v3 + 4);
  }
LABEL_10:
  NodeSprite::~NodeSprite(this);
}
