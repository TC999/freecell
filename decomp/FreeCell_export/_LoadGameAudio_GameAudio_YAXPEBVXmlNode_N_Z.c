void __fastcall GameAudio::LoadGameAudio(GameAudio *this, const struct XmlNode *a2)
{
  const struct XmlNode *v3; // rax
  const struct XmlNode *v4; // r14
  unsigned int v5; // esi
  __int64 v6; // r15
  XmlNode *v7; // r13
  unsigned int *v8; // rbx
  __int64 v9; // rcx
  wchar_t *v10; // rdi
  bool v11; // zf
  unsigned int v12; // ecx
  __int64 v13; // rdi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // edx
  struct ResourceBase *Resource; // rax
  _DWORD *v18; // rax
  const struct XmlNode *v19; // rax
  const struct XmlNode *v20; // r12
  unsigned int v21; // ecx
  unsigned int v22; // esi
  __int64 i; // r13
  XmlNode *v24; // rbp
  void *v25; // rbx
  int XmlInt; // eax
  wchar_t *v27; // rdi
  __int64 v28; // rcx
  __int64 v29; // rcx
  const wchar_t *v30; // rdi
  wchar_t *v31; // rdi
  __int64 v32; // rcx
  unsigned int v33; // eax
  wchar_t *v34; // rdi
  __int64 v35; // rcx
  unsigned int v36; // edi
  unsigned int v37; // edx
  struct ResourceBase *v38; // rax
  _DWORD *v39; // rax
  wchar_t String1[4]; // [rsp+28h] [rbp-140h] BYREF
  wchar_t Destination[10]; // [rsp+30h] [rbp-138h] BYREF
  unsigned __int16 v42; // [rsp+44h] [rbp-124h] BYREF
  unsigned __int16 v43[116]; // [rsp+48h] [rbp-120h] BYREF

  GameAudio::CleanupGameAudio(this);
  if ( this )
  {
    v3 = XmlNode::XPathElementSearchSingle(this, L"/Music");
    v4 = v3;
    if ( v3 )
    {
      v5 = 0;
      if ( *((_DWORD *)v3 + 6) )
      {
        v6 = 0;
        while ( 1 )
        {
          v7 = *(XmlNode **)(v6 + *((_QWORD *)v4 + 5));
          wcscpy_s(Destination, 0xDu, L"Audio\\Music\\");
          if ( XmlNode::GetXmlString(v7, v43, 0x74u, L"/File") )
            break;
          v18 = operator new(8u);
          if ( v18 )
          {
            *v18 = 0;
            v18[1] = 0;
          }
          else
          {
            v18 = 0;
          }
          *v18 = 0;
          v18[1] = 0;
          Array<GameAudio::MusicStream *>::SetAt(&GameAudio::aMusicStreams, v5, v18);
LABEL_28:
          ++v5;
          v6 += 8;
          if ( v5 >= *((_DWORD *)v4 + 6) )
            goto LABEL_29;
        }
        v8 = (unsigned int *)operator new(8u);
        if ( v8 )
        {
          *v8 = 0;
          v8[1] = 0;
        }
        else
        {
          v8 = 0;
        }
        v9 = -1;
        v10 = Destination;
        do
        {
          if ( !v9 )
            break;
          v11 = *v10++ == 0;
          --v9;
        }
        while ( !v11 );
        v12 = ~(_DWORD)v9;
        v13 = v12;
        if ( v12 >= 4 )
        {
          if ( !_wcsicmp(&String1[v12], L"wma") )
          {
            v14 = ResourceWMA::Create(Destination, v13, 1u, 0);
LABEL_17:
            *v8 = v14;
            goto LABEL_19;
          }
          if ( !_wcsicmp(&String1[v13], L"wav") )
          {
            v14 = ResourceWav::Create(Destination, v13, 1u);
            goto LABEL_17;
          }
        }
        Log(0x10u, 111, "GameAudio.cpp", L"Invalid audio source: %s", Destination);
LABEL_19:
        v8[1] = XmlNode::GetXmlInt(v7, L"/Volume", 100);
        Array<GameAudio::MusicStream *>::SetAt(&GameAudio::aMusicStreams, v5, v8);
        if ( *v8 )
        {
          v15 = v8[1];
          if ( GameAudio::aMusicStreams > v5 )
          {
            v16 = **(_DWORD **)((char *)qword_1000ACE78 + v6);
            if ( v16 )
            {
              Resource = ResourceManager::GetResource(g_pResourceManager, v16, 0);
              (*(void (__fastcall **)(struct ResourceBase *, _QWORD, _QWORD))(*(_QWORD *)Resource + 128LL))(
                Resource,
                v15,
                0);
            }
          }
        }
        else
        {
          v8[1] = 0;
        }
        goto LABEL_28;
      }
    }
LABEL_29:
    v19 = XmlNode::XPathElementSearchSingle(this, L"/Sounds");
    v20 = v19;
    if ( v19 )
    {
      v21 = *((_DWORD *)v19 + 6);
      v22 = 0;
      if ( v21 )
      {
        for ( i = 0; ; i += 8 )
        {
          v24 = v22 < v21 ? *(XmlNode **)(i + *((_QWORD *)v20 + 5)) : 0LL;
          wcscpy_s(Destination, 0xBu, L"Audio\\SFX\\");
          if ( XmlNode::GetXmlString(v24, &v42, 0x76u, L"/File") )
            break;
          v39 = operator new(0xCu);
          if ( v39 )
          {
            *v39 = 0;
            v39[1] = 0;
            v39[2] = 0;
          }
          else
          {
            v39 = 0;
          }
          v39[2] = 0;
          *v39 = 0;
          v39[1] = 0;
          Array<GameAudio::SoundEffect *>::SetAt(&GameAudio::aSoundEffects, v22, v39);
LABEL_65:
          v21 = *((_DWORD *)v20 + 6);
          if ( ++v22 >= v21 )
            return;
        }
        v25 = operator new(0xCu);
        if ( v25 )
        {
          *(_DWORD *)v25 = 0;
          *((_DWORD *)v25 + 1) = 0;
          *((_DWORD *)v25 + 2) = 0;
        }
        else
        {
          v25 = 0;
        }
        XmlInt = XmlNode::GetXmlInt(v24, L"/Buffers", 1);
        v27 = Destination;
        v28 = -1;
        *((_DWORD *)v25 + 2) = XmlInt;
        do
        {
          if ( !v28 )
            break;
          v11 = *v27++ == 0;
          --v28;
        }
        while ( !v11 );
        v29 = (unsigned int)~(_DWORD)v28;
        if ( (unsigned int)v29 >= 4 )
        {
          v30 = &String1[v29];
          if ( !_wcsicmp(v30, L"wma") )
          {
            v31 = Destination;
            v32 = -1;
            do
            {
              if ( !v32 )
                break;
              v11 = *v31++ == 0;
              --v32;
            }
            while ( !v11 );
            v33 = ResourceWMA::Create(Destination, ~(_DWORD)v32, *((_BYTE *)v25 + 8), 0);
LABEL_53:
            *(_DWORD *)v25 = v33;
            goto LABEL_55;
          }
          if ( !_wcsicmp(v30, L"wav") )
          {
            v34 = Destination;
            v35 = -1;
            do
            {
              if ( !v35 )
                break;
              v11 = *v34++ == 0;
              --v35;
            }
            while ( !v11 );
            v33 = ResourceWav::Create(Destination, ~(_DWORD)v35, *((_BYTE *)v25 + 8));
            goto LABEL_53;
          }
        }
        Log(0x10u, 178, "GameAudio.cpp", L"Invalid audio source: %s", Destination);
LABEL_55:
        *((_DWORD *)v25 + 1) = XmlNode::GetXmlInt(v24, L"/Volume", 100);
        Array<GameAudio::SoundEffect *>::SetAt(&GameAudio::aSoundEffects, v22, v25);
        if ( *(_DWORD *)v25 )
        {
          v36 = *((_DWORD *)v25 + 1);
          if ( GameAudio::aSoundEffects > v22 )
          {
            v37 = **(_DWORD **)((char *)qword_1000ACE60 + i);
            if ( v37 )
            {
              v38 = ResourceManager::GetResource(g_pResourceManager, v37, 1);
              if ( !v38 )
                SharedDialogs::FatalDialog::Show(0);
              (*(void (__fastcall **)(struct ResourceBase *, _QWORD, _QWORD))(*(_QWORD *)v38 + 128LL))(v38, v36, 0);
            }
          }
        }
        else
        {
          *((_DWORD *)v25 + 2) = 0;
          *((_DWORD *)v25 + 1) = 0;
        }
        goto LABEL_65;
      }
    }
  }
}
