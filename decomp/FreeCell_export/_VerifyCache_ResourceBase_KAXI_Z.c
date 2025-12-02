void __fastcall ResourceBase::VerifyCache(unsigned int a1)
{
  unsigned int v2; // ebx
  wchar_t *v3; // rax

  if ( (unsigned int)ResourceBase::CacheCch < a1 )
  {
    operator delete(ResourceBase::wszCache);
    v2 = a1 + 1;
    v3 = (wchar_t *)operator new[](saturated_mul(v2, 2u));
    LODWORD(ResourceBase::CacheCch) = v2;
    ResourceBase::wszCache = v3;
  }
}
