void __fastcall Card::SetFaceUp(Card *this, char a2, char a3)
{
  const unsigned __int16 *v6; // rsi

  if ( *((_BYTE *)this + 17) != a2 )
  {
    v6 = L"false";
    if ( a2 )
      v6 = L"true";
    Log(0x10000u, L"Card::SetFaceUp()::bVisibility == %s", v6);
    *((_BYTE *)this + 17) = a2;
    Card::RefreshAccessibility(this);
    if ( !a3 )
      CardTable::PushAction(*((CardTable **)this + 3), 3, *((const unsigned __int16 **)this + 7), v6);
    Card::UpdateCardFace(this);
  }
}
