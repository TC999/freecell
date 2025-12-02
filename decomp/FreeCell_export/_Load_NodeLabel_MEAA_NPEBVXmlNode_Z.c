// Hidden C++ exception states: #wind=2
char __fastcall NodeLabel::Load(NodeLabel *this, const struct XmlNode *a2)
{
  _DWORD *v4; // rax
  _DWORD *v5; // rbx
  XmlNode *v6; // rax
  unsigned __int16 *NodeValue; // rbp
  wchar_t *v8; // rbx
  HMODULE ModuleHandleW; // rax
  wchar_t *v10; // rbx
  unsigned int v11; // eax
  int v12; // ebx
  unsigned int XmlHex; // eax
  RenderManager *v14; // rax
  int XmlInt; // eax
  int v16; // eax
  int XmlUInt; // eax
  int v18; // eax
  RenderManager *v19; // rdx
  __int64 v20; // r8
  unsigned int v21; // eax
  _QWORD *v22; // rcx
  int v23; // edx
  int v24; // eax
  RenderManager *v25; // rax
  char XmlBool; // al
  RenderManager *v27; // rax
  int v28; // eax
  RenderManager *v29; // rax
  XmlNode *v30; // rax
  unsigned __int16 *v31; // r13
  XmlNode *v32; // rax
  unsigned __int16 *v33; // r12
  XmlNode *v34; // rax
  unsigned __int16 *v35; // r14
  XmlNode *v36; // rax
  unsigned __int16 *v37; // rbp
  XmlNode *v38; // rax
  unsigned __int16 *v39; // rbx
  int v41; // [rsp+20h] [rbp-1B8h]
  _DWORD *v42; // [rsp+40h] [rbp-198h] BYREF
  _DWORD v43[4]; // [rsp+48h] [rbp-190h] BYREF
  void *Block; // [rsp+58h] [rbp-180h]
  __int64 v45; // [rsp+60h] [rbp-178h]
  wchar_t String1; // [rsp+68h] [rbp-170h] BYREF
  __int64 v47; // [rsp+6Ah] [rbp-16Eh]
  __int64 v48; // [rsp+72h] [rbp-166h]
  __int64 v49; // [rsp+7Ah] [rbp-15Eh]
  int v50; // [rsp+82h] [rbp-156h]
  __int16 v51; // [rsp+86h] [rbp-152h]
  wchar_t Destination[64]; // [rsp+90h] [rbp-148h] BYREF
  unsigned __int16 v53[64]; // [rsp+110h] [rbp-C8h] BYREF

  v45 = -2;
  v4 = operator new[](0x24u);
  v42 = v4;
  if ( v4 )
  {
    *v4 = 1;
    v5 = v4 + 1;
    `eh vector constructor iterator'(
      v4 + 1,
      0x20u,
      1,
      (void (*)(void *))NodeSprite::Source::Source,
      (void (*)(void *))NodeSprite::Source::~Source);
  }
  else
  {
    v5 = 0;
  }
  *((_QWORD *)this + 52) = v5;
  v5[3] = 1;
  *((_BYTE *)this + 413) = 0;
  *((_DWORD *)this + 106) = 1;
  if ( a2 )
  {
    memset(Destination, 0, sizeof(Destination));
    *(_DWORD *)v53 = *(_DWORD *)L"20";
    memset(&v53[2], 0, 124);
    v6 = XmlNode::XPathElementSearchSingle(a2, L"/Text");
    if ( v6 )
      NodeValue = XmlNode::GetNodeValue(v6);
    else
      NodeValue = 0;
    if ( XmlNode::GetXmlString(a2, Destination, 0x40u, L"/FontName") )
    {
      v8 = LocalizeMessage(Destination);
      wcscpy_s(Destination, 0x40u, v8);
      LocalFree(v8);
    }
    else
    {
      ModuleHandleW = GetModuleHandleW(0);
      LoadStringW(ModuleHandleW, 0x3E9u, Destination, 64);
    }
    XmlNode::GetXmlString(a2, v53, 0x40u, L"/FontSize");
    v10 = LocalizeMessage(v53);
    v11 = wcstol(v10, 0, 10);
    LOBYTE(v41) = 0;
    (*(void (__fastcall **)(TextRenderer *, _DWORD **, _QWORD, wchar_t *, int, _BYTE, _BYTE))(*(_QWORD *)g_pTextRenderer
                                                                                            + 8LL))(
      g_pTextRenderer,
      &v42,
      v11,
      Destination,
      v41,
      0,
      0);
    LocalFree(v10);
    v12 = 0;
    String1 = 0;
    v47 = 0;
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v51 = 0;
    if ( XmlNode::GetXmlString(a2, &String1, 0x10u, L"/Material") )
    {
      if ( !wcsncmp(&String1, L"alpha", 0x10u) )
      {
        v12 = 1;
      }
      else if ( !wcsncmp(&String1, L"additive", 0x10u) )
      {
        v12 = 2;
      }
    }
    XmlHex = XmlNode::GetXmlHex(a2, L"/Color", 0xFFFFFFFF);
    if ( XmlHex != *((_DWORD *)this + 101) )
    {
      *((_DWORD *)this + 101) = XmlHex;
      v14 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v14 + 88) = 1;
    }
    XmlInt = XmlNode::GetXmlInt(a2, L"/X", 0);
    NodeBase::SetPosition(this, XmlInt, *((_DWORD *)this + 3));
    v16 = XmlNode::GetXmlInt(a2, L"/Y", 0);
    NodeBase::SetPosition(this, *((_DWORD *)this + 2), v16);
    XmlUInt = XmlNode::GetXmlUInt(a2, L"/W", 0x64u);
    NodeBase::SetSize(this, XmlUInt, *((_DWORD *)this + 5));
    v18 = XmlNode::GetXmlUInt(a2, L"/H", 0x64u);
    NodeBase::SetSize(this, *((_DWORD *)this + 4), v18);
    v19 = g_pRenderManager;
    if ( *((_DWORD *)this + 118) != (_DWORD)v42 )
    {
      *((_DWORD *)this + 118) = (_DWORD)v42;
      *((_BYTE *)v19 + 20) = 1;
      *((_BYTE *)v19 + 88) = 1;
    }
    if ( !v12 )
      v12 = 1;
    v20 = *(_QWORD *)(*((_QWORD *)v19 + 7) + 8LL * v12);
    v21 = 0;
    v22 = (_QWORD *)((char *)v19 + 96);
    v23 = 3;
    while ( *v22 != v20 )
    {
      ++v21;
      ++v22;
      if ( v21 >= 3 )
        goto LABEL_27;
    }
    v23 = v21;
LABEL_27:
    *((_DWORD *)this + 90) = v23;
    v24 = XmlNode::GetXmlInt(a2, L"/Justify", 2);
    if ( v24 != *((_DWORD *)this + 119) )
    {
      *((_DWORD *)this + 119) = v24;
      v25 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v25 + 88) = 1;
    }
    (**(void (__fastcall ***)(NodeLabel *))this)(this);
    XmlBool = XmlNode::GetXmlBool(a2, L"/Visible", 1);
    if ( *((_BYTE *)this + 41) != XmlBool )
    {
      *((_BYTE *)this + 41) = XmlBool;
      v27 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v27 + 88) = 1;
    }
    v28 = XmlNode::GetXmlInt(a2, L"/Alpha", 255);
    if ( v28 != *((_DWORD *)this + 99) )
    {
      *((_DWORD *)this + 99) = v28;
      v29 = g_pRenderManager;
      *((_BYTE *)g_pRenderManager + 20) = 1;
      *((_BYTE *)v29 + 88) = 1;
    }
    *((_BYTE *)this + 72) = 0;
    if ( NodeValue )
    {
      Str::Str((Str *)v43, NodeValue);
      (*(void (__fastcall **)(NodeLabel *, void *, _QWORD))(*(_QWORD *)this + 120LL))(
        this,
        Block,
        (unsigned int)(v43[0] + 1));
      operator delete(NodeValue);
      operator delete(Block);
    }
    v30 = XmlNode::XPathElementSearchSingle(a2, L"/AccessName");
    if ( v30 )
      v31 = XmlNode::GetNodeValue(v30);
    else
      v31 = 0;
    v32 = XmlNode::XPathElementSearchSingle(a2, L"/AccessDesc");
    if ( v32 )
      v33 = XmlNode::GetNodeValue(v32);
    else
      v33 = 0;
    v34 = XmlNode::XPathElementSearchSingle(a2, L"/AccessValue");
    if ( v34 )
      v35 = XmlNode::GetNodeValue(v34);
    else
      v35 = 0;
    v36 = XmlNode::XPathElementSearchSingle(a2, L"/AccessDefAction");
    if ( v36 )
      v37 = XmlNode::GetNodeValue(v36);
    else
      v37 = 0;
    v38 = XmlNode::XPathElementSearchSingle(a2, L"/AccessKeyShort");
    if ( v38 )
      v39 = XmlNode::GetNodeValue(v38);
    else
      v39 = 0;
    if ( v31 )
    {
      NodeBase::SetAccessName((HLOCAL *)this, v31);
      operator delete(v31);
    }
    if ( v33 )
    {
      NodeBase::SetAccessDescription((HLOCAL *)this, v33);
      operator delete(v33);
    }
    if ( v35 )
    {
      LocalFree(*((HLOCAL *)this + 23));
      *((_QWORD *)this + 23) = LocalizeMessage(v35);
      operator delete(v35);
    }
    if ( v37 )
    {
      NodeBase::SetAccessDefaultAction((HLOCAL *)this, v37);
      operator delete(v37);
    }
    if ( v39 )
    {
      LocalFree(*((HLOCAL *)this + 21));
      *((_QWORD *)this + 21) = LocalizeMessage(v39);
      operator delete(v39);
    }
  }
  return 1;
}
