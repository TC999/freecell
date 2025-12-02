const unsigned __int16 *__fastcall CardLibLogger::CardLibLogResolver(CardLibLogger *this)
{
  const unsigned __int16 *result; // rax

  result = 0;
  if ( (_DWORD)this == 0x10000 )
    return L"CardLibLogGeneral: ";
  if ( (_DWORD)this == 65537 )
    return L"ERROR_CARDLIB: ";
  if ( g_pCardGameLogResolver )
    return g_pCardGameLogResolver((unsigned int)this);
  return result;
}
