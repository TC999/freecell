void __fastcall RenderManager::SetBack(RenderManager *this, const unsigned __int16 *a2)
{
  RenderManager *v2; // rbx
  NodeBase *v4; // rcx
  const struct XmlNode *Xml; // rax
  struct NodeBase *v6; // rax
  RenderManager *v7; // rax
  XmlManager *v8; // rcx
  XmlNode *v9; // rax
  XmlNode *v10; // rax
  wchar_t *NodeValue; // rdi

  v2 = g_pRenderManager;
  v4 = (NodeBase *)*((_QWORD *)g_pRenderManager + 19);
  if ( v4 )
    NodeBase::DeleteSelf(v4);
  if ( a2 )
  {
    Xml = XmlManager::GetXml(g_pXmlManager, a2);
    v6 = NodeBase::CreateFromXmlNode(Xml, 0);
    *((_QWORD *)v2 + 19) = v6;
    if ( v6 )
    {
      if ( *((_BYTE *)v6 + 41) )
      {
        *((_BYTE *)v6 + 41) = 0;
        v7 = g_pRenderManager;
        *((_BYTE *)g_pRenderManager + 20) = 1;
        *((_BYTE *)v7 + 88) = 1;
      }
      v8 = g_pXmlManager;
      *(_BYTE *)(*((_QWORD *)v2 + 19) + 72LL) = 0;
      v9 = XmlManager::GetXml(v8, a2);
      if ( v9 )
      {
        v10 = XmlNode::XPathElementSearchSingle(v9, L"/Anchor");
        if ( v10 )
          NodeValue = XmlNode::GetNodeValue(v10);
        else
          NodeValue = 0;
        if ( NodeValue )
        {
          if ( _wcsicmp(NodeValue, L"center") )
          {
            if ( _wcsicmp(NodeValue, L"lowerleft") )
              *((_DWORD *)v2 + 40) = _wcsicmp(NodeValue, L"upperleft") == 0 ? 2 : 0;
            else
              *((_DWORD *)v2 + 40) = 1;
          }
          else
          {
            *((_DWORD *)v2 + 40) = 0;
          }
          operator delete(NodeValue);
        }
        else
        {
          *((_DWORD *)v2 + 40) = 0;
        }
      }
    }
    else
    {
      Log(2u, 2429, "RenderManager.cpp", L"Couldn't create the background sprite");
    }
  }
  else
  {
    *((_QWORD *)v2 + 19) = 0;
  }
}
