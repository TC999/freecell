struct XmlNode *__fastcall Stash::LoadXMLFile(Stash *this, const unsigned __int16 *a2)
{
  unsigned int v2; // esi
  HANDLE FileW; // rax
  void *v5; // rbx
  CHAR *v6; // rax
  unsigned int v7; // esi
  CHAR *v8; // rbp
  void *SpecialFolderFile; // rax
  void *v10; // rbx
  CHAR *v11; // rax
  unsigned int v12; // r12d
  XmlNode *v13; // rax
  XmlNode *v14; // rsi
  bool XmlRaw; // bl
  DWORD v17; // [rsp+40h] [rbp-38h] BYREF
  unsigned int Buffer; // [rsp+88h] [rbp+10h] BYREF
  DWORD NumberOfBytesRead; // [rsp+90h] [rbp+18h] BYREF
  DWORD v20; // [rsp+98h] [rbp+20h] BYREF

  Buffer = 0;
  v2 = (unsigned int)a2;
  if ( (_DWORD)a2 )
  {
    SpecialFolderFile = (void *)CreateSpecialFolderFile((wchar_t *)this, 1, (unsigned int)a2, 1, 101);
    v10 = SpecialFolderFile;
    if ( SpecialFolderFile == (void *)-1LL )
      goto LABEL_3;
    if ( (unsigned int)ReadSpecialFolderFileRichGameHeader(SpecialFolderFile) )
    {
      NumberOfBytesRead = 0;
      if ( ReadFile(v10, &Buffer, 4u, &NumberOfBytesRead, 0) && NumberOfBytesRead == 4 )
      {
        v11 = (CHAR *)operator new[](Buffer);
        v12 = Buffer;
        v8 = v11;
        if ( ReadFile(v10, v11, Buffer, &v17, 0) && v17 == v12 )
        {
          CloseSpecialFolderFile((__int64)v10, v2, 1);
          goto LABEL_23;
        }
LABEL_13:
        Log(0x10000001u, L"Stash::LoadXMLFile(): Unable to read data from %s", this);
        return 0;
      }
      Log(0x80u, L"Stash::LoadXMLFile(): Unable to read XML data size value from %s", this);
    }
    else
    {
      Log(0x80u, L"Stash::LoadXMLFile(): Unable to read Rich Game Media header from %s", this);
    }
    CloseSpecialFolderFile((__int64)v10, v2, 1);
    return 0;
  }
  FileW = CreateFileW((LPCWSTR)this, 0x80000000, 0, 0, 3u, 0x80u, 0);
  v5 = FileW;
  if ( FileW == (HANDLE)-1LL )
  {
LABEL_3:
    Log(0x10000001u, L"Stash::LoadXMLFile(): Unable to open %s", this);
    return 0;
  }
  if ( !(unsigned int)ReadSpecialFolderFileRichGameHeader(FileW) )
  {
    Log(0x80u, L"Stash::LoadXMLFile(): Unable to read Rich Game Media header from %s", this);
LABEL_7:
    CloseHandle(v5);
    return 0;
  }
  NumberOfBytesRead = 0;
  if ( !ReadFile(v5, &Buffer, 4u, &NumberOfBytesRead, 0) || NumberOfBytesRead != 4 )
  {
    Log(0x80u, L"Stash::LoadXMLFile(): Unable to read XML data size value from %s", this);
    goto LABEL_7;
  }
  v6 = (CHAR *)operator new[](Buffer);
  v7 = Buffer;
  v8 = v6;
  if ( !ReadFile(v5, v6, Buffer, &v20, 0) || v20 != v7 )
    goto LABEL_13;
  CloseHandle(v5);
LABEL_23:
  v13 = (XmlNode *)operator new(0x98u);
  if ( v13 )
    v14 = XmlNode::XmlNode(v13);
  else
    v14 = 0;
  XmlRaw = XmlNode::LoadXmlRaw(v14, v8, Buffer);
  operator delete(v8);
  if ( XmlRaw )
    return v14;
  Log(0x10000001u, L"Stash::LoadXMLFile(): Error parsing xml file %s", this);
  if ( v14 )
  {
    XmlNode::~XmlNode(v14);
    operator delete(v14);
  }
  return 0;
}
