char __fastcall AnimationDescriptor::ParseXml(AnimationDescriptor *this, const unsigned __int16 *a2)
{
  AnimationDescriptor *v2; // rdi
  struct XmlNode *Xml; // rax
  struct XmlNode *v5; // rcx
  unsigned int v7; // eax
  unsigned int v8; // edx
  __int64 v9; // r8
  XmlNode *v10; // r15
  XmlNode *v11; // rax
  unsigned __int16 *NodeValue; // rbp
  bool v13; // zf
  _DWORD *v14; // rbx
  const wchar_t *v15; // rdi
  unsigned __int16 *v16; // rsi
  __int64 v17; // rcx
  __int64 v18; // r13
  __int64 v19; // r12
  int v20; // esi
  _DWORD *v21; // rax
  _DWORD *v22; // rdi
  const struct XmlNode **v23; // rax
  const struct XmlNode **v24; // r14
  XmlNode **v25; // r12
  int XmlInt; // eax
  unsigned int v27; // edx
  int v28; // r15d
  __int64 v29; // rdx
  void *v30; // rcx
  void *v31; // rax
  const wchar_t *v32; // rdi
  unsigned __int16 *v33; // rsi
  __int64 v34; // rcx
  _DWORD *v35; // rax
  _DWORD *v36; // rax
  const wchar_t *v37; // rdi
  unsigned __int16 *v38; // rsi
  __int64 v39; // rcx
  _DWORD *v40; // rax
  void **v41; // rax
  const wchar_t *v42; // rdi
  unsigned __int16 *v43; // rsi
  __int64 v44; // rcx
  _DWORD *v45; // rax
  const wchar_t *v46; // rdi
  unsigned __int16 *v47; // rsi
  __int64 v48; // rcx
  _DWORD *v49; // rax
  const wchar_t *v50; // rdi
  unsigned __int16 *v51; // rsi
  __int64 v52; // rcx
  _DWORD *v53; // rax
  const wchar_t *v54; // rdi
  unsigned __int16 *v55; // rsi
  __int64 v56; // rcx
  _DWORD *v57; // rax
  const wchar_t *v58; // rdi
  unsigned __int16 *v59; // rsi
  __int64 v60; // rcx
  _DWORD *v61; // rax
  const struct XmlNode **v62; // rax
  const struct XmlNode **v63; // r14
  _QWORD *v64; // r15
  unsigned int v65; // ebx
  XmlNode **v66; // r13
  const wchar_t *v67; // rdi
  bool v68; // zf
  unsigned __int16 *v69; // rsi
  unsigned __int16 *v70; // r12
  __int64 v71; // rcx
  _QWORD *v72; // rax
  _QWORD *v73; // rdi
  const unsigned __int16 *v74; // rdx
  const wchar_t *v75; // rdi
  unsigned __int16 *v76; // rsi
  __int64 v77; // rcx
  _QWORD *v78; // rax
  const wchar_t *v79; // rdi
  unsigned __int16 *v80; // rsi
  __int64 v81; // rcx
  _QWORD *v82; // rax
  XmlNode *v83; // rax
  unsigned __int16 *v84; // rsi
  __int64 v85; // rcx
  unsigned __int16 *v86; // rdi
  unsigned __int64 v87; // rdi
  void *v88; // rax
  _QWORD *v89; // rdi
  __int64 v90; // rsi
  unsigned int v91; // [rsp+40h] [rbp-98h]
  char *v92; // [rsp+48h] [rbp-90h]
  XmlNode *v93; // [rsp+50h] [rbp-88h]
  __int64 i; // [rsp+58h] [rbp-80h]
  struct XmlNode *v95; // [rsp+60h] [rbp-78h]
  _DWORD *v96; // [rsp+68h] [rbp-70h] BYREF
  _DWORD *v97; // [rsp+70h] [rbp-68h]
  __int64 v98; // [rsp+78h] [rbp-60h]
  __int64 v99; // [rsp+80h] [rbp-58h]
  unsigned int v102; // [rsp+F0h] [rbp+18h] BYREF
  unsigned int v103; // [rsp+F8h] [rbp+20h] BYREF

  v2 = this;
  Xml = XmlManager::GetXml(g_pXmlManager, a2);
  v5 = Xml;
  v95 = Xml;
  if ( !Xml )
  {
    Log(0x200u, 398, "AnimationDescriptor.cpp", L"Invalid Xml: %s", a2);
    return 0;
  }
  v7 = *((_DWORD *)Xml + 6);
  v8 = 0;
  v91 = 0;
  if ( !v7 )
    return 1;
  v9 = 0;
  for ( i = 0; ; i += 8 )
  {
    if ( v8 < v7 )
      v10 = *(XmlNode **)(v9 + *((_QWORD *)v5 + 5));
    else
      v10 = 0;
    v93 = v10;
    if ( !XmlNode::MatchName(v10, L"Animation") )
    {
      if ( XmlNode::MatchName(v10, L"WaitForComplete") )
      {
        AnimationDescriptor::AddAnimator(v2, 0, 0);
      }
      else if ( XmlNode::MatchName(v10, L"SendAnimationComplete") )
      {
        *(_BYTE *)v2 = 1;
      }
      goto LABEL_121;
    }
    v11 = XmlNode::XPathElementSearchSingle(v10, L"/Affects");
    if ( v11 )
      NodeValue = XmlNode::GetNodeValue(v11);
    else
      NodeValue = 0;
    if ( !NodeValue )
    {
      Log(0x200u, 419, "AnimationDescriptor.cpp", L"Malformed animation file, no Affects tag (%s)", a2);
      return 0;
    }
    v13 = 1;
    v14 = 0;
    v15 = L"CurrentFrame";
    v16 = NodeValue;
    v17 = 13;
    v96 = 0;
    v97 = 0;
    do
    {
      if ( !v17 )
        break;
      v13 = *v16++ == *v15++;
      --v17;
    }
    while ( v13 );
    v18 = 0;
    v98 = 0;
    v19 = 0;
    v99 = 0;
    if ( v13 )
    {
      v20 = 1;
      v21 = operator new(0x38u);
      v22 = v21;
      if ( v21 )
      {
        v21[8] = 0;
        v21[9] = 0;
        v21[10] = 16;
        *((_QWORD *)v21 + 6) = 0;
        v21[6] = 0;
        *(_QWORD *)v21 = &Affector_CurrentFrame::`vftable';
      }
      else
      {
        v22 = 0;
      }
      v96 = v22;
      v23 = XmlNode::XPathElementSearch(v10, L"/IntMessage", &v103);
      v24 = v23;
      if ( v103 )
      {
        v25 = v23;
        while ( 1 )
        {
          XmlInt = XmlNode::GetXmlInt(*v25, L"/", 0);
          v27 = v22[9];
          ++v22[8];
          v28 = XmlInt;
          if ( v22[8] <= v27 )
            goto LABEL_27;
          v29 = v22[10] + v27;
          v30 = (void *)*((_QWORD *)v22 + 6);
          v22[9] = v29;
          v31 = realloc(v30, 4 * v29);
          if ( v31 )
            break;
          CheckAllocation(0);
LABEL_28:
          LODWORD(v18) = v18 + 1;
          ++v25;
          if ( (unsigned int)v18 >= v103 )
          {
            v19 = v99;
            v10 = v93;
            goto LABEL_30;
          }
        }
        *((_QWORD *)v22 + 6) = v31;
LABEL_27:
        *(_DWORD *)(*((_QWORD *)v22 + 6) + 4LL * (unsigned int)(v22[8] - 1)) = v28;
        goto LABEL_28;
      }
LABEL_30:
      operator delete(v24);
      v18 = v98;
    }
    else
    {
      v32 = L"Position";
      v33 = NodeValue;
      v34 = 9;
      do
      {
        if ( !v34 )
          break;
        v13 = *v33++ == *v32++;
        --v34;
      }
      while ( v13 );
      if ( !v13 )
      {
        v37 = L"XPosition";
        v38 = NodeValue;
        v39 = 10;
        do
        {
          if ( !v39 )
            break;
          v13 = *v38++ == *v37++;
          --v39;
        }
        while ( v13 );
        if ( v13 )
        {
          v20 = 1;
          v40 = operator new(0x38u);
          v22 = v40;
          if ( v40 )
          {
            v40[8] = 0;
            v40[9] = 0;
            v40[10] = 16;
            *((_QWORD *)v40 + 6) = 0;
            v40[6] = 0;
            v41 = &Affector_XPosition::`vftable';
            goto LABEL_78;
          }
LABEL_79:
          v22 = 0;
        }
        else
        {
          v42 = L"YPosition";
          v43 = NodeValue;
          v44 = 10;
          do
          {
            if ( !v44 )
              break;
            v13 = *v43++ == *v42++;
            --v44;
          }
          while ( v13 );
          if ( v13 )
          {
            v20 = 1;
            v45 = operator new(0x38u);
            v22 = v45;
            if ( !v45 )
              goto LABEL_79;
            v45[8] = 0;
            v45[9] = 0;
            v45[10] = 16;
            *((_QWORD *)v45 + 6) = 0;
            v45[6] = 0;
            v41 = &Affector_YPosition::`vftable';
          }
          else
          {
            v46 = L"Scale";
            v47 = NodeValue;
            v48 = 6;
            do
            {
              if ( !v48 )
                break;
              v13 = *v47++ == *v46++;
              --v48;
            }
            while ( v13 );
            if ( v13 )
            {
              v20 = 1;
              v49 = operator new(0x38u);
              v22 = v49;
              if ( !v49 )
                goto LABEL_79;
              v49[8] = 0;
              v49[9] = 0;
              v49[10] = 16;
              *((_QWORD *)v49 + 6) = 0;
              v49[6] = 0;
              v41 = &Affector_Scale::`vftable';
            }
            else
            {
              v50 = L"XScale";
              v51 = NodeValue;
              v52 = 7;
              do
              {
                if ( !v52 )
                  break;
                v13 = *v51++ == *v50++;
                --v52;
              }
              while ( v13 );
              if ( v13 )
              {
                v20 = 1;
                v53 = operator new(0x38u);
                v22 = v53;
                if ( !v53 )
                  goto LABEL_79;
                v53[8] = 0;
                v53[9] = 0;
                v53[10] = 16;
                *((_QWORD *)v53 + 6) = 0;
                v53[6] = 0;
                v41 = &Affector_XScale::`vftable';
              }
              else
              {
                v54 = L"YScale";
                v55 = NodeValue;
                v56 = 7;
                do
                {
                  if ( !v56 )
                    break;
                  v13 = *v55++ == *v54++;
                  --v56;
                }
                while ( v13 );
                if ( v13 )
                {
                  v20 = 1;
                  v57 = operator new(0x38u);
                  v22 = v57;
                  if ( !v57 )
                    goto LABEL_79;
                  v57[8] = 0;
                  v57[9] = 0;
                  v57[10] = 16;
                  *((_QWORD *)v57 + 6) = 0;
                  v57[6] = 0;
                  v41 = &Affector_YScale::`vftable';
                }
                else
                {
                  v58 = L"Alpha";
                  v59 = NodeValue;
                  v60 = 6;
                  do
                  {
                    if ( !v60 )
                      break;
                    v13 = *v59++ == *v58++;
                    --v60;
                  }
                  while ( v13 );
                  if ( !v13 )
                  {
                    Log(0x200u, 488, "AnimationDescriptor.cpp", L"Invalid affector %s in file %s", NodeValue, a2);
                    operator delete(NodeValue);
                    return 0;
                  }
                  v20 = 1;
                  v61 = operator new(0x38u);
                  v22 = v61;
                  if ( !v61 )
                    goto LABEL_79;
                  v61[8] = 0;
                  v61[9] = 0;
                  v61[10] = 16;
                  *((_QWORD *)v61 + 6) = 0;
                  v61[6] = 0;
                  v41 = &Affector_Alpha::`vftable';
                }
              }
            }
          }
LABEL_78:
          *(_QWORD *)v22 = v41;
        }
        v96 = v22;
        goto LABEL_81;
      }
      v20 = 2;
      v35 = operator new(0x38u);
      v22 = v35;
      if ( v35 )
      {
        v35[8] = 0;
        v35[9] = 0;
        v35[10] = 16;
        *((_QWORD *)v35 + 6) = 0;
        v35[6] = 0;
        *(_QWORD *)v35 = &Affector_XPosition::`vftable';
      }
      else
      {
        v22 = 0;
      }
      v96 = v22;
      v36 = operator new(0x38u);
      v14 = v36;
      if ( v36 )
      {
        v36[8] = 0;
        v36[9] = 0;
        v36[10] = 16;
        *((_QWORD *)v36 + 6) = 0;
        v36[6] = 0;
        *(_QWORD *)v36 = &Affector_YPosition::`vftable';
      }
      else
      {
        v14 = 0;
      }
      v97 = v14;
    }
LABEL_81:
    v102 = 0;
    v62 = XmlNode::XPathElementSearch(v10, L"/Type", &v102);
    v63 = v62;
    if ( v102 != v20 )
      break;
    v64 = 0;
    v65 = 0;
    if ( v102 )
    {
      v66 = v62;
      v92 = (char *)((char *)&v96 - (char *)v62);
      do
      {
        v67 = L"LinearRelative";
        v69 = XmlNode::XPathAttributeSearchSingle(*v66, L"/@Name");
        v70 = v69;
        v71 = 15;
        do
        {
          if ( !v71 )
            break;
          v68 = *v69++ == *v67++;
          --v71;
        }
        while ( v68 );
        if ( v68 )
        {
          v72 = operator new(0x18u);
          v73 = v72;
          if ( v72 )
          {
            v72[1] = 0;
            *v72 = &Animator_LinearRelative::`vftable';
          }
          else
          {
            v73 = 0;
          }
          v74 = L"/Count";
        }
        else
        {
          v75 = L"LinearAbsolute";
          v76 = v70;
          v77 = 15;
          do
          {
            if ( !v77 )
              break;
            v68 = *v76++ == *v75++;
            --v77;
          }
          while ( v68 );
          if ( v68 )
          {
            v78 = operator new(0x20u);
            v73 = v78;
            if ( v78 )
            {
              v78[1] = 0;
              *v78 = &Animator_LinearAbsolute::`vftable';
            }
            else
            {
              v73 = 0;
            }
            *((_DWORD *)v73 + 4) = XmlNode::GetXmlInt(*v66, L"/Start", 0);
            *((_DWORD *)v73 + 5) = XmlNode::GetXmlInt(*v66, L"/End", 0);
            *((float *)v73 + 6) = XmlNode::GetXmlFloat(*v66, L"/Time", 0.0);
            goto LABEL_109;
          }
          v79 = L"LinearTargeted";
          v80 = v70;
          v81 = 15;
          do
          {
            if ( !v81 )
              break;
            v68 = *v80++ == *v79++;
            --v81;
          }
          while ( v68 );
          if ( !v68 )
          {
            Log(
              0x200u,
              571,
              "AnimationDescriptor.cpp",
              L"Invalid type %s for affector %s in file %s",
              v70,
              NodeValue,
              a2);
            operator delete(NodeValue);
            operator delete(v63);
            operator delete(v70);
            if ( v65 < 4 )
            {
              v89 = &(&v96)[v65];
              v90 = 4 - v65;
              do
              {
                if ( *v89 )
                  (*(void (__fastcall **)(_QWORD, __int64))(*(_QWORD *)*v89 + 8LL))(*v89, 1);
                ++v89;
                --v90;
              }
              while ( v90 );
            }
            return 0;
          }
          v82 = operator new(0x18u);
          v73 = v82;
          if ( v82 )
          {
            v82[1] = 0;
            *v82 = &Animator_LinearTargeted::`vftable';
          }
          else
          {
            v73 = 0;
          }
          v74 = L"/Target";
        }
        *((_DWORD *)v73 + 4) = XmlNode::GetXmlInt(*v66, v74, 0);
        *((float *)v73 + 5) = XmlNode::GetXmlFloat(*v66, L"/Time", 0.0);
LABEL_109:
        if ( !v64 )
          v64 = v73;
        AnimationDescriptor::AddAnimator(
          this,
          (const struct Animator_Base *)v73,
          *(const struct Affector_Base **)((char *)v66 + (_QWORD)v92));
        operator delete(v70);
        ++v65;
        ++v66;
      }
      while ( v65 < v102 );
    }
    operator delete(v63);
    operator delete(NodeValue);
    v83 = XmlNode::XPathElementSearchSingle(v93, L"/SendComplete");
    if ( v83 )
      v84 = XmlNode::GetNodeValue(v83);
    else
      v84 = 0;
    if ( v84 )
    {
      operator delete((void *)v64[1]);
      v85 = -1;
      v86 = v84;
      do
      {
        if ( !v85 )
          break;
        v13 = *v86++ == 0;
        --v85;
      }
      while ( !v13 );
      v87 = (unsigned int)~(_DWORD)v85;
      v88 = operator new[](saturated_mul(v87, 2u));
      v64[1] = v88;
      memcpy(v88, v84, 2 * v87);
      operator delete(v84);
    }
    v2 = this;
LABEL_121:
    v5 = v95;
    v7 = *((_DWORD *)v95 + 6);
    v8 = v91 + 1;
    v9 = i + 8;
    v91 = v8;
    if ( v8 >= v7 )
      return 1;
  }
  Log(0x200u, 503, "AnimationDescriptor.cpp", L"Invalid type count(%d) for affector %s in file %s", v102, NodeValue, a2);
  operator delete(NodeValue);
  operator delete(v63);
  if ( v22 )
    (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)v22 + 8LL))(v22, 1);
  if ( v14 )
    (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)v14 + 8LL))(v14, 1);
  if ( v18 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v18 + 8LL))(v18, 1);
  if ( v19 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 8LL))(v19, 1);
  return 0;
}
