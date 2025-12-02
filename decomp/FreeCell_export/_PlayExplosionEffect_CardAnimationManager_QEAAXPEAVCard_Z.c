void __fastcall CardAnimationManager::PlayExplosionEffect(CardAnimationManager *this, struct Card *a2)
{
  const wchar_t **Xml; // rax
  struct NodeBase *v5; // rax
  struct NodeBase *v6; // rbx
  __int64 v7; // rcx
  RenderManager *v8; // rax
  __int64 v9; // rax
  const unsigned __int16 *v10; // rbx
  const wchar_t **v11; // rax
  struct NodeBase *v12; // rdi
  __int64 v13; // rcx
  RenderManager *v14; // rax
  __int64 v15; // rax
  const wchar_t **v16; // rax
  struct NodeBase *v17; // rdi
  __int64 v18; // rcx
  RenderManager *v19; // rax
  __int64 v20; // rax
  int SuitForType; // eax
  int v22; // eax
  int v23; // eax
  const wchar_t **v24; // rax
  struct NodeBase *v25; // rbx
  __int64 v26; // rcx
  RenderManager *v27; // rax
  __int64 v28; // rax
  int v29; // eax
  __int64 v30; // r11
  __int64 v31; // rax
  RenderManager *v32; // rax

  Xml = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"PaperEmitter01.xml");
  v5 = NodeBase::CreateFromXmlNode(Xml, 0);
  *((_DWORD *)v5 + 90) = 0;
  *((_QWORD *)v5 + 73) = ParticleUpdate;
  *((_BYTE *)v5 + 577) = 1;
  v6 = v5;
  NodeBase::SetPosition(v5, *(_DWORD *)(*((_QWORD *)a2 + 8) + 8LL) + 60, *(_DWORD *)(*((_QWORD *)a2 + 8) + 12LL) - 70);
  if ( *(_BYTE *)(v7 + 41) != 1 )
  {
    v8 = g_pRenderManager;
    *(_BYTE *)(v7 + 41) = 1;
    *((_BYTE *)v8 + 20) = 1;
    *((_BYTE *)v8 + 88) = 1;
  }
  v9 = *(_QWORD *)v6;
  *((_DWORD *)v6 + 145) = 1;
  (*(void (__fastcall **)(__int64, __int64))(v9 + 112))(v7, 1);
  *((_QWORD *)v6 + 69) = particlePaperCreation;
  CardAnimationManager::AddParticleAnimation(this, v6, 1.2);
  v10 = L"PaperEmitter02.xml";
  v11 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"PaperEmitter02.xml");
  v12 = NodeBase::CreateFromXmlNode(v11, 0);
  *((_DWORD *)v12 + 90) = 0;
  *((_QWORD *)v12 + 73) = ParticleUpdate;
  *((_BYTE *)v12 + 577) = 1;
  NodeBase::SetPosition(v12, *(_DWORD *)(*((_QWORD *)a2 + 8) + 8LL) + 60, *(_DWORD *)(*((_QWORD *)a2 + 8) + 12LL) - 70);
  if ( *(_BYTE *)(v13 + 41) != 1 )
  {
    v14 = g_pRenderManager;
    *(_BYTE *)(v13 + 41) = 1;
    *((_BYTE *)v14 + 20) = 1;
    *((_BYTE *)v14 + 88) = 1;
  }
  v15 = *(_QWORD *)v12;
  *((_DWORD *)v12 + 145) = 1;
  (*(void (__fastcall **)(__int64, __int64))(v15 + 112))(v13, 1);
  *((_QWORD *)v12 + 69) = particlePaperCreation;
  CardAnimationManager::AddParticleAnimation(this, v12, 1.2);
  v16 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, L"StarEmitter.xml");
  v17 = NodeBase::CreateFromXmlNode(v16, 0);
  *((_QWORD *)v17 + 73) = ParticleUpdate;
  *((_DWORD *)v17 + 90) = 2;
  *((_BYTE *)v17 + 577) = 1;
  NodeBase::SetPosition(v17, *(_DWORD *)(*((_QWORD *)a2 + 8) + 8LL) + 60, *(_DWORD *)(*((_QWORD *)a2 + 8) + 12LL) - 70);
  if ( *(_BYTE *)(v18 + 41) != 1 )
  {
    v19 = g_pRenderManager;
    *(_BYTE *)(v18 + 41) = 1;
    *((_BYTE *)v19 + 20) = 1;
    *((_BYTE *)v19 + 88) = 1;
  }
  v20 = *(_QWORD *)v17;
  *((_DWORD *)v17 + 145) = 1;
  (*(void (__fastcall **)(__int64, __int64))(v20 + 112))(v18, 1);
  *((_QWORD *)v17 + 69) = particleStarCreation;
  CardAnimationManager::AddParticleAnimation(this, v17, 1.2);
  SuitForType = Card::GetSuitForType(*((_DWORD *)a2 + 2));
  if ( SuitForType )
  {
    v22 = SuitForType - 1;
    if ( v22 )
    {
      v23 = v22 - 1;
      if ( v23 )
      {
        if ( v23 == 1 )
          v10 = L"HeartEmitter.xml";
      }
      else
      {
        v10 = L"SpadeEmitter.xml";
      }
    }
    else
    {
      v10 = L"DiamondEmitter.xml";
    }
  }
  else
  {
    v10 = L"ClubEmitter.xml";
  }
  v24 = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, v10);
  v25 = NodeBase::CreateFromXmlNode(v24, 0);
  *((_DWORD *)v25 + 90) = 0;
  *((_QWORD *)v25 + 73) = ParticleUpdate;
  *((_BYTE *)v25 + 577) = 1;
  NodeBase::SetPosition(v25, *(_DWORD *)(*((_QWORD *)a2 + 8) + 8LL) + 60, *(_DWORD *)(*((_QWORD *)a2 + 8) + 12LL) - 70);
  if ( *(_BYTE *)(v26 + 41) != 1 )
  {
    v27 = g_pRenderManager;
    *(_BYTE *)(v26 + 41) = 1;
    *((_BYTE *)v27 + 20) = 1;
    *((_BYTE *)v27 + 88) = 1;
  }
  v28 = *(_QWORD *)v25;
  *((_DWORD *)v25 + 145) = 1;
  (*(void (__fastcall **)(__int64, __int64))(v28 + 112))(v26, 1);
  *((_QWORD *)v25 + 69) = particleSuitCreation;
  CardAnimationManager::AddParticleAnimation(this, v25, 1.2);
  v29 = rand();
  if ( ((v29 >> 31) ^ v29 & 1) != v29 >> 31 )
  {
    v30 = (unsigned int)(rand() % 3 + 23);
    if ( GameAudio::aSoundEffects > (unsigned int)v30 )
      Audio::StartEffect(g_pAudio, **((_DWORD **)qword_1000ACE60 + v30), 0, 0);
  }
  v31 = *((_QWORD *)a2 + 8);
  if ( *(_BYTE *)(v31 + 41) )
  {
    *(_BYTE *)(v31 + 41) = 0;
    v32 = g_pRenderManager;
    *((_BYTE *)g_pRenderManager + 20) = 1;
    *((_BYTE *)v32 + 88) = 1;
  }
}
