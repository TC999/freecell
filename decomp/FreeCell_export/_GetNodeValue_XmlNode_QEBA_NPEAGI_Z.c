bool __fastcall XmlNode::GetNodeValue(XmlNode *this, unsigned __int16 *a2, unsigned int a3)
{
  if ( a3 )
    *a2 = 0;
  return *((_QWORD *)this + 15)
      && a3 >= *((_DWORD *)this + 32) + 1
      && wcsncpy_s(a2, a3, *((const wchar_t **)this + 15), *((unsigned int *)this + 32)) == 0;
}
