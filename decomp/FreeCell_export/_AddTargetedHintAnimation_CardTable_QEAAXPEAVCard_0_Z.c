void __fastcall CardTable::AddTargetedHintAnimation(CardTable *this, struct Card *a2, struct Card *a3)
{
  CardStack *CardStackWithCard; // r13
  struct CardStack *v7; // rax
  CardStack *v8; // rsi

  if ( g_bWindowActive )
  {
    CardTable::ClearHintAnimations(this);
    CardStackWithCard = CardTable::GetCardStackWithCard(this, a2);
    v7 = CardTable::GetCardStackWithCard(this, a3);
    v8 = v7;
    if ( CardStackWithCard && v7 )
    {
      CardStack::StartHintAnimation(CardStackWithCard, *((_DWORD *)this + 42), a2);
      Array<IEventListener *>::Add((__int64)this + 216, (__int64)CardStackWithCard);
      CardStack::StartHintAnimation(v8, *((_DWORD *)this + 43), a3);
      Array<IEventListener *>::Add((__int64)this + 216, (__int64)v8);
      *((_QWORD *)this + 23) = a3;
      *((_QWORD *)this + 22) = a2;
    }
    else
    {
      Log(0x10001u, L"Couldn't find cards for targeted hint animation");
    }
  }
}
