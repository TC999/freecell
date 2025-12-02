void __fastcall particlePaperCreation(struct NodeEmitter *this)
{
  XmlNode *v2; // rdi
  float XmlFloat; // xmm0_4
  int v4; // esi
  struct Particle *v5; // rdi
  float v6; // xmm9_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  int v9; // eax
  float v10; // xmm6_4
  int v11; // r11d
  float v12; // xmm0_4

  if ( !byte_1000B1CDB )
  {
    if ( !this )
      return;
    v2 = (XmlNode *)*((_QWORD *)this + 65);
    if ( !v2 )
      return;
    dword_1000B1E24 = XmlNode::GetXmlFloat(*((XmlNode **)this + 65), L"/rate", 0.0);
    XmlFloat = XmlNode::GetXmlFloat(v2, L"/life", 0.0);
    byte_1000B1CDB = 1;
    dword_1000B1E20 = LODWORD(XmlFloat);
  }
  if ( *((float *)this + 132) == 0.0 )
  {
    v4 = 0;
    if ( *(float *)&dword_1000B1E24 > 0.0 )
    {
      do
      {
        v5 = NodeEmitter::spawnParticle(this);
        if ( !v5 )
          break;
        v6 = (float)((10 - rand() % 20) / 100 + 1) * *(float *)&dword_1000B1E20;
        v7 = (float)(rand() % 20 - 10) + *((float *)v5 + 11);
        v8 = (float)(rand() % 80 - 40) + *((float *)v5 + 12);
        v9 = rand();
        v10 = (float)(90 * (v9 / 90) - v9) / 5.0;
        v11 = rand();
        *((_DWORD *)v5 + 13) = 0;
        *((_DWORD *)v5 + 16) = 0;
        ++v4;
        *((float *)v5 + 9) = (float)(v11 % 150 - 75) / 5.0;
        v12 = *(float *)&dword_1000B1E24;
        *((float *)v5 + 7) = v7;
        *((_DWORD *)v5 + 14) = 1097859072;
        *((_DWORD *)v5 + 15) = 1097859072;
        *((_BYTE *)v5 + 24) = 0;
        *((float *)v5 + 8) = v8;
        *((float *)v5 + 10) = v10;
        *((float *)v5 + 2) = v6;
        *((float *)v5 + 3) = v6;
      }
      while ( v12 > (float)v4 );
    }
  }
}
