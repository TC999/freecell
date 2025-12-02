void __fastcall UserInterface::UpdateMouseOverFocus(UserInterface *this)
{
  UserInterface *v1; // rbx
  struct NodeBase *v2; // rax
  int v3; // [rsp+48h] [rbp+10h] BYREF
  int v4; // [rsp+50h] [rbp+18h] BYREF
  struct tagPOINT Point; // [rsp+58h] [rbp+20h] BYREF

  v1 = g_pUserInterface;
  if ( !g_bMouseHidden && !*((_BYTE *)g_pUserInterface + 300) )
  {
    UserInterface::UpdateLayout(g_pUserInterface);
    GetCursorPos(&Point);
    UserInterface::ScreenToLayout(v1, Point.x, Point.y, &v4, &v3);
    v2 = RenderManager::HitTestTopLevel(g_pRenderManager, v4, v3, 0);
    if ( !v2 )
      v2 = (struct NodeBase *)(*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD))(**((_QWORD **)g_pRenderManager
                                                                                           + 15)
                                                                                        + 80LL))(
                                *((_QWORD *)g_pRenderManager + 15),
                                (unsigned int)v4,
                                (unsigned int)v3,
                                0);
    UserInterface::SetFocus(v1, v2);
  }
}
