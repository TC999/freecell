void __fastcall CardTable::AddTargetedHintAnimation(CardTable *this, struct Card *a2, struct CardStack *a3)
{
  CardStack *CardStackWithCard; // rax
  __int64 v7; // r12

  if ( g_bWindowActive )
  {
    CardTable::ClearHintAnimations(this);
    CardStackWithCard = CardTable::GetCardStackWithCard(this, a2);
    v7 = (__int64)CardStackWithCard;
    if ( CardStackWithCard && a3 )
    {
      CardStack::StartHintAnimation(CardStackWithCard, *((_DWORD *)this + 42), a2);
      Array<IEventListener *>::Add((__int64)this + 216, v7);
      CardStack::StartHintAnimation(a3, *((_DWORD *)this + 43), 0);
      Array<IEventListener *>::Add((__int64)this + 216, (__int64)a3);
      *((_QWORD *)this + 22) = a2;
      *((_QWORD *)this + 24) = a3;
    }
    else
    {
      Log(0x10001u, L"Couldn't find cards for targeted hint animation");
    }
  }
}
