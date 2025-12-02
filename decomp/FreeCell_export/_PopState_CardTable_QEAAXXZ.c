// Hidden C++ exception states: #wind=2
void __fastcall CardTable::PopState(CardTable *this)
{
  __int64 v2; // rax
  void **v3; // rdi
  int v4; // eax
  __int64 v5; // rax
  __int64 v6; // rdi
  struct CardStack *v7; // rax
  struct CardStack *v8; // rdi
  CardStack *v9; // rax
  struct Card *v10; // rsi
  CardStack *v11; // rax
  CardStack *v12; // rdi
  CardStack *CardStack; // rax
  CardStack *v14; // rdi
  Card *v15; // rsi
  bool v16; // di
  Card *Card; // rsi
  bool v18; // di
  void **v19; // rdi
  int v20; // eax
  _BYTE v21[16]; // [rsp+28h] [rbp-50h] BYREF
  void *Block; // [rsp+38h] [rbp-40h]
  _BYTE v23[16]; // [rsp+40h] [rbp-38h] BYREF
  void *v24; // [rsp+50h] [rbp-28h]

  Log(0x10000u, L"CardTable::PopState()");
  if ( *((_DWORD *)this + 60) )
  {
    *((_BYTE *)this + 49) = 0;
    *((_BYTE *)this + 48) = 1;
    v2 = *((_QWORD *)this + 32);
    if ( !**(_DWORD **)(v2 + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1)) )
    {
      v3 = *(void ***)(v2 + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1));
      if ( v3 )
      {
        operator delete(v3[6]);
        operator delete(v3[3]);
        operator delete(v3);
      }
      v4 = *((_DWORD *)this + 60);
      if ( v4 )
        *((_DWORD *)this + 60) = v4 - 1;
    }
    if ( *((_DWORD *)this + 60) )
    {
      do
      {
        v5 = *((_QWORD *)this + 32);
        if ( !**(_DWORD **)(v5 + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1)) )
          break;
        v6 = *(_QWORD *)(v5 + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1));
        switch ( *(_DWORD *)v6 )
        {
          case 1:
            Card = CardTable::GetCard(this, *(const unsigned __int16 **)(v6 + 24));
            if ( Card )
            {
              Str::Str((Str *)v23, L"true");
              v18 = *(_QWORD *)(v6 + 48) && Str::Equals((Str *)(v6 + 32), (const struct Str *)v23);
              operator delete(v24);
              Card::SetEnabled(Card, !v18, 0);
            }
            else
            {
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the card to lock/unlock.");
            }
            break;
          case 3:
            v15 = CardTable::GetCard(this, *(const unsigned __int16 **)(v6 + 24));
            if ( v15 )
            {
              Str::Str((Str *)v21, L"true");
              v16 = *(_QWORD *)(v6 + 48) && Str::Equals((Str *)(v6 + 32), (const struct Str *)v21);
              operator delete(Block);
              Card::SetFaceUp(v15, !v16, 0);
            }
            else
            {
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the card to flip.");
            }
            break;
          case 4:
            CardStack = CardTable::GetCardStack(this, *(const unsigned __int16 **)(v6 + 48));
            v14 = CardStack;
            if ( CardStack )
            {
              CardStack::Pop(CardStack);
              CardStack::Arrange(v14, 1, 0);
            }
            else
            {
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the stack to pop.");
            }
            break;
          case 5:
            v10 = CardTable::GetCard(this, *(const unsigned __int16 **)(v6 + 24));
            if ( v10 )
            {
              v11 = CardTable::GetCardStack(this, *(const unsigned __int16 **)(v6 + 48));
              v12 = v11;
              if ( v11 )
              {
                CardStack::Push(v11, v10);
                CardStack::Arrange(v12, 1, 0);
              }
              else
              {
                Log(0x10001u, L"CardTable::PopState() - Couldn't find the stack to push to.");
              }
            }
            else
            {
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the card to push.");
            }
            break;
          case 6:
            v9 = CardTable::GetCardStack(this, *(const unsigned __int16 **)(v6 + 24));
            if ( v9 )
              CardStack::Reverse(v9);
            else
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the stack to reverse.");
            break;
          case 7:
            v7 = CardTable::GetCardStack(this, *(const unsigned __int16 **)(v6 + 48));
            v8 = v7;
            if ( v7 )
            {
              SortedListW<CardStack *>::Remove((char *)this + 144, *((_QWORD *)v7 + 36));
              (*(void (__fastcall **)(__int64, __int64))(*((_QWORD *)v8 + 1) + 8LL))((__int64)v8 + 8, 1);
            }
            else
            {
              Log(0x10001u, L"CardTable::PopState() - Couldn't find the stack to destroy.");
            }
            break;
          default:
            if ( *(_DWORD *)v6 == 8 && !CardTable::CreateCardStack(this, *(const unsigned __int16 **)(v6 + 48)) )
              Log(0x10001u, L"CardTable::PopState() - Failed to create a new stack.");
            break;
        }
        if ( *((_DWORD *)this + 60) )
        {
          v19 = *(void ***)(*((_QWORD *)this + 32) + 8LL * (unsigned int)(*((_DWORD *)this + 60) - 1));
          if ( v19 )
          {
            operator delete(v19[6]);
            operator delete(v19[3]);
            operator delete(v19);
          }
          v20 = *((_DWORD *)this + 60);
          if ( v20 )
            *((_DWORD *)this + 60) = v20 - 1;
        }
      }
      while ( *((_DWORD *)this + 60) );
      *((_BYTE *)this + 49) = 1;
      *((_BYTE *)this + 48) = 0;
    }
  }
}
