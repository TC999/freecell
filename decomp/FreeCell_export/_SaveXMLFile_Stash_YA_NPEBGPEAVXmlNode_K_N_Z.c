// Hidden C++ exception states: #wind=2
char __fastcall Stash::SaveXMLFile(wchar_t *Source, XmlNode *this, struct XmlNode *a3, bool a4)
{
  unsigned int v5; // r12d
  void *v7; // rbp
  __int64 v8; // r13
  void *SpecialFolderFile; // rsi
  bool v11; // bl
  DWORD v12; // [rsp+40h] [rbp-98h] BYREF
  unsigned int v13; // [rsp+44h] [rbp-94h] BYREF
  DWORD v14; // [rsp+48h] [rbp-90h] BYREF
  int Buffer; // [rsp+4Ch] [rbp-8Ch] BYREF
  DWORD NumberOfBytesWritten; // [rsp+50h] [rbp-88h] BYREF
  _DWORD v17[4]; // [rsp+58h] [rbp-80h] BYREF
  void *v18; // [rsp+68h] [rbp-70h]
  void *Block[2]; // [rsp+70h] [rbp-68h] BYREF
  __int64 v20; // [rsp+80h] [rbp-58h]
  _BYTE v21[16]; // [rsp+88h] [rbp-50h] BYREF
  void *v22; // [rsp+98h] [rbp-40h]
  _BYTE v23[16]; // [rsp+A0h] [rbp-38h] BYREF
  char v24; // [rsp+E0h] [rbp+8h] BYREF
  char v25; // [rsp+E1h] [rbp+9h]

  v20 = -2;
  v5 = (unsigned int)a3;
  if ( Source && this )
  {
    Block[0] = 0;
    v13 = 0;
    XmlNode::PrintToString(this, (unsigned __int16 **)Block, &v13);
    v7 = Block[0];
    if ( Block[0] && (v8 = v13) != 0 )
    {
      SpecialFolderFile = (void *)CreateSpecialFolderFile(Source, 0, v5, 1, 101);
      if ( SpecialFolderFile == (void *)-1LL )
      {
        Log(0x10000001u, L"Stash::SaveXMLFile(): Unable to open %s", Source);
        operator delete(v7);
        return 0;
      }
      else
      {
        v17[0] = 0;
        v17[1] = 0;
        v17[2] = 16;
        v18 = 0;
        if ( g_pRenderManager && *((_DWORD *)g_pRenderManager + 53) )
          RenderManager::SaveScreenshotToMemory(g_pRenderManager, 256, 192, v17, L"RGMH_Thumbnail_FreeCell.png");
        Str::Str((Str *)v21, 0x65u);
        *(__m128i *)Block = _mm_loadu_si128((const __m128i *)(*(__int64 (__fastcall **)(void *, _BYTE *))(*(_QWORD *)g_pInterface + 16LL))(
                                                               g_pInterface,
                                                               v23));
        v11 = (unsigned int)WriteSpecialFolderFileRichGameHeader(SpecialFolderFile, Source) == 0;
        operator delete(v22);
        if ( v11 )
        {
          Log(0x80u, L"Stash::SaveXMLFile(): Unable to write Rich Game Media header to %s", Source);
          operator delete(v7);
          CloseSpecialFolderFile((__int64)SpecialFolderFile, v5, 1);
          if ( v18 )
            free(v18);
          return 0;
        }
        else
        {
          Buffer = 2 * v8 + 2;
          NumberOfBytesWritten = 0;
          if ( WriteFile(SpecialFolderFile, &Buffer, 4u, &NumberOfBytesWritten, 0) )
          {
            v12 = 0;
            v24 = -1;
            v25 = -2;
            if ( WriteFile(SpecialFolderFile, &v24, 2u, &v12, 0) && v12 == 2 )
            {
              v14 = 0;
              if ( WriteFile(SpecialFolderFile, v7, 2 * v8, &v14, 0) && v14 == 2 * v8 )
              {
                operator delete(v7);
                CloseSpecialFolderFile((__int64)SpecialFolderFile, v5, a4);
                if ( v18 )
                  free(v18);
                return 1;
              }
              else
              {
                Log(0x80u, L"Stash::SaveXMLFile(): Unable to write xml buffer to %s", Source);
                operator delete(v7);
                CloseSpecialFolderFile((__int64)SpecialFolderFile, v5, 1);
                if ( v18 )
                  free(v18);
                return 0;
              }
            }
            else
            {
              Log(0x80u, L"Stash::SaveXMLFile(): Unable to write UTF16 LE prefix to %s", Source);
              operator delete(v7);
              CloseSpecialFolderFile((__int64)SpecialFolderFile, v5, 1);
              if ( v18 )
                free(v18);
              return 0;
            }
          }
          else
          {
            Log(0x80u, L"Stash::SaveXMLFile(): Unable to write XML data size value to %s", Source);
            operator delete(v7);
            CloseSpecialFolderFile((__int64)SpecialFolderFile, v5, 1);
            if ( v18 )
              free(v18);
            return 0;
          }
        }
      }
    }
    else
    {
      Log(0x10000001u, L"Stash::SaveXMLFile(): Malformed xml string generated for file %s", Source);
      return 0;
    }
  }
  else
  {
    Log(
      0x80u,
      L"Stash::SaveXMLFile(wszFileName=%u, pSource=%u, dwFlags=%u): Malformed parameters",
      Source,
      this,
      (_DWORD)a3);
    return 0;
  }
}
