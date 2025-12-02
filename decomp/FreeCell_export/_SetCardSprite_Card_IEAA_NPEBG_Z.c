char __fastcall Card::SetCardSprite(Card *this, const unsigned __int16 *a2)
{
  NodeSprite *v3; // rcx
  NodeBase *v5; // rcx
  struct NodeBase *v6; // rbx
  const wchar_t **Xml; // rax
  struct NodeBase *v8; // rax
  const unsigned __int16 *v10; // rdx
  NodeBase *v11; // rcx

  v3 = (NodeSprite *)*((_QWORD *)this + 13);
  if ( v3 )
  {
    NodeSprite::Unpin(v3);
    v5 = (NodeBase *)*((_QWORD *)this + 13);
    if ( v5 )
    {
      NodeBase::DeleteSelf(v5);
      *((_QWORD *)this + 13) = 0;
    }
  }
  v6 = (struct NodeBase *)*((_QWORD *)this + 8);
  Xml = (const wchar_t **)XmlManager::GetXml(g_pXmlManager, a2);
  v8 = NodeBase::CreateFromXmlNode(Xml, v6);
  *((_QWORD *)this + 13) = v8;
  if ( v8 )
  {
    NodeSprite::Pin(v8);
    *(_BYTE *)(*((_QWORD *)this + 13) + 72LL) = 0;
    *(_DWORD *)(*((_QWORD *)this + 13) + 360LL) = 1;
    v10 = (const unsigned __int16 *)*((_QWORD *)this + 7);
    if ( v10 )
      NodeBase::SetName(*((void ***)this + 13), v10);
    *(_BYTE *)(*((_QWORD *)this + 13) + 413LL) = 0;
    v11 = (NodeBase *)*((_QWORD *)this + 12);
    if ( v11 )
      NodeBase::MoveToFront(v11);
    Card::UpdateCardFace(this);
    return 1;
  }
  else
  {
    Log(0x10001u, L"Card::SetGraphic() - Failed to create the card sprite.");
    return 0;
  }
}
