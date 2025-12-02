void __fastcall CardAnimationManager::Update(CardAnimationManager *this, float a2)
{
  float v3; // xmm7_4
  unsigned int v4; // r13d
  RenderManager *v5; // r10
  UserInterface *v6; // rbp
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rcx
  float v10; // xmm0_4
  float v11; // xmm0_4
  __int64 v12; // rcx
  bool v13; // cc
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  float v19; // xmm1_4
  float v20; // xmm0_4
  Card *v21; // rcx
  __int64 v22; // r10
  __int64 v23; // rdx
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rdx
  char v28; // cl
  __int64 v29; // rcx
  __int64 v30; // rcx
  __int64 v31; // rcx
  __int64 v32; // r10
  __int64 v33; // rax
  __int64 v34; // rcx
  __int64 v35; // r10
  __int64 v36; // rax
  __int64 v37; // rcx
  int *v38; // rcx
  double v39; // xmm14_8
  double v40; // xmm13_8
  double v41; // xmm8_8
  double v42; // xmm14_8
  unsigned int v43; // eax
  double v44; // xmm6_8
  double v45; // xmm10_8
  double i; // xmm0_8
  double v47; // xmm1_8
  unsigned int v48; // eax
  double v49; // xmm7_8
  double v50; // xmm0_8
  unsigned int v51; // eax
  double v52; // xmm5_8
  double v53; // xmm1_8
  unsigned int v54; // eax
  double v55; // xmm4_8
  double v56; // xmm0_8
  unsigned int v57; // eax
  double v58; // xmm3_8
  double v59; // xmm1_8
  unsigned int v60; // eax
  double v61; // xmm2_8
  double v62; // xmm0_8
  unsigned int v63; // eax
  double v64; // xmm1_8
  unsigned int v65; // eax
  double v66; // xmm12_8
  double v67; // xmm0_8
  double v68; // xmm7_8
  double v69; // xmm0_8
  unsigned int v70; // eax
  double v71; // xmm11_8
  double v72; // xmm1_8
  unsigned int v73; // eax
  double v74; // xmm6_8
  double v75; // xmm0_8
  unsigned int v76; // eax
  double v77; // xmm5_8
  double v78; // xmm1_8
  unsigned int v79; // eax
  double v80; // xmm4_8
  double v81; // xmm0_8
  unsigned int v82; // eax
  double v83; // xmm3_8
  double v84; // xmm1_8
  unsigned int v85; // eax
  double v86; // xmm2_8
  unsigned int v87; // eax
  double v88; // xmm11_8
  double v89; // xmm7_8
  double v90; // xmm0_8
  double v91; // xmm11_8
  double v92; // xmm0_8
  unsigned int v93; // eax
  double v94; // xmm9_8
  double v95; // xmm1_8
  unsigned int v96; // eax
  double v97; // xmm6_8
  double v98; // xmm0_8
  unsigned int v99; // eax
  double v100; // xmm5_8
  double v101; // xmm1_8
  unsigned int v102; // eax
  double v103; // xmm4_8
  double v104; // xmm0_8
  unsigned int v105; // eax
  double v106; // xmm3_8
  double v107; // xmm1_8
  unsigned int v108; // eax
  double v109; // xmm2_8
  unsigned int v110; // eax
  double v111; // xmm9_8
  double v112; // xmm7_8
  double v113; // xmm0_8
  double v114; // xmm9_8
  double v115; // xmm0_8
  unsigned int v116; // eax
  double v117; // xmm5_8
  double v118; // xmm1_8
  unsigned int v119; // eax
  double v120; // xmm6_8
  unsigned int v121; // eax
  double v122; // xmm3_8
  double v123; // xmm0_8
  unsigned int v124; // eax
  double v125; // xmm4_8
  double v126; // xmm1_8
  unsigned int v127; // eax
  double v128; // xmm2_8
  unsigned int v129; // eax
  double v130; // xmm0_8
  double v131; // xmm0_8
  int v132; // r11d
  int v133; // r9d
  __int64 v134; // rcx
  __int64 v135; // rcx
  __int64 v136; // rcx
  double v137; // xmm5_8
  int v138; // esi
  int v139; // r9d
  int v140; // r11d
  __int64 v141; // rax
  __int64 v142; // rcx
  __int64 v143; // rcx
  Card *v144; // rcx
  _QWORD *v145; // r11
  int v146; // edi
  __int64 v147; // rcx
  RenderManager *v148; // r10
  int v149; // eax
  __int64 v150; // rcx
  float v151; // xmm2_4
  __int64 v152; // rcx
  __int64 v153; // r10
  __int64 v154; // rcx
  __int64 v155; // rdx
  char v156; // al
  __int64 v157; // rax
  __int64 v158; // rdi
  int v159; // ecx
  float v160; // xmm1_4
  int v161; // eax
  int v162; // ecx
  float v163; // xmm2_4
  float v164; // xmm2_4
  __int64 v165; // rcx
  int v166; // r9d
  double v168; // [rsp+110h] [rbp+18h]

  v3 = a2;
  if ( !*(_BYTE *)this )
  {
    CardAnimationManager::FinishAllAnimations(this);
    return;
  }
  v4 = 0;
  if ( *((_DWORD *)this + 10) )
  {
    v5 = g_pRenderManager;
    v6 = g_pUserInterface;
    do
    {
      v7 = *(_QWORD *)(*((_QWORD *)this + 7) + 8LL * v4);
      v8 = *(_QWORD *)(v7 + 8);
      if ( v8 )
      {
        v9 = *(_QWORD *)(v8 + 64);
        if ( *(_BYTE *)(v9 + 41) != 1 )
        {
          *(_BYTE *)(v9 + 41) = 1;
          *((_BYTE *)v5 + 88) = 1;
          *((_BYTE *)v5 + 20) = 1;
        }
      }
      v10 = *(float *)(v7 + 32);
      if ( v10 > 0.0 )
      {
        v11 = v10 - v3;
        *(float *)(v7 + 32) = v11;
        if ( v11 > 0.0 )
          goto LABEL_218;
        if ( *(_DWORD *)(v7 + 76) == 1 )
        {
          if ( rand() % 2 && (unsigned int)GameAudio::aSoundEffects > 0x16 )
            Audio::StartEffect(g_pAudio, **((_DWORD **)qword_1000ACE60 + 22), 0, 0);
          v6 = g_pUserInterface;
          v5 = g_pRenderManager;
        }
      }
      if ( !*(_BYTE *)(v7 + 68) )
      {
        *(_BYTE *)(v7 + 68) = 1;
        if ( *(_BYTE *)(v7 + 69) )
        {
          v12 = *(_QWORD *)(v7 + 8);
          if ( v12 )
          {
            NodeBase::MoveToFront(*(NodeBase **)(v12 + 64));
            v5 = g_pRenderManager;
            v6 = g_pUserInterface;
          }
        }
      }
      v13 = *(float *)(v7 + 32) >= 0.0;
      v14 = v3 + *(float *)(v7 + 40);
      *(float *)(v7 + 40) = v14;
      if ( !v13 )
      {
        v15 = v14 - *(float *)(v7 + 32);
        *(_DWORD *)(v7 + 32) = 0;
        *(float *)(v7 + 40) = v15;
      }
      v16 = *(_DWORD *)(v7 + 76);
      if ( !v16 )
      {
        v151 = *(float *)(v7 + 40);
        if ( v151 < *(float *)(v7 + 36) )
        {
          v163 = v151 / *(float *)(v7 + 36);
          if ( v163 >= 0.5 )
            v164 = 1.0
                 - (float)((float)((float)(1.0 - v163) * CardAnimationManager::DEF_BASE_ANIM_SPEED) * (float)(1.0 - v163));
          else
            v164 = v163 * (float)(v163 * CardAnimationManager::DEF_BASE_ANIM_SPEED);
          v165 = *(_QWORD *)(v7 + 8);
          if ( !v165 )
            goto LABEL_218;
          NodeBase::SetPosition(
            *(NodeBase **)(v165 + 64),
            *(_DWORD *)(v7 + 44) + (int)(float)((float)(*(_DWORD *)(v7 + 52) - *(_DWORD *)(v7 + 44)) * v164),
            *(_DWORD *)(*(_QWORD *)(v165 + 64) + 12LL));
          NodeBase::SetPosition(
            *(NodeBase **)(*(_QWORD *)(v7 + 8) + 64LL),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 64LL) + 8LL),
            *(_DWORD *)(v7 + 48) + (int)(float)((float)v166 * v164));
          if ( *(_BYTE *)(v7 + 72) )
            goto LABEL_218;
          v144 = *(Card **)(v7 + 8);
LABEL_232:
          Card::SetShadow(v144, 1, 0, 0);
        }
        else
        {
          v152 = *(_QWORD *)(v7 + 8);
          if ( v152 )
          {
            NodeBase::SetPosition(
              *(NodeBase **)(v152 + 64),
              *(_DWORD *)(v7 + 52),
              *(_DWORD *)(*(_QWORD *)(v152 + 64) + 12LL));
            NodeBase::SetPosition(
              *(NodeBase **)(*(_QWORD *)(v7 + 8) + 64LL),
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 64LL) + 8LL),
              *(_DWORD *)(v7 + 56));
            v154 = *(_QWORD *)(v7 + 8);
            if ( *(_BYTE *)(v154 + 16) )
            {
              v157 = *(_QWORD *)(v154 + 64);
              if ( *(_BYTE *)(v157 + 41) != 1 )
              {
                *(_BYTE *)(v157 + 41) = 1;
LABEL_240:
                *(_BYTE *)(v153 + 88) = 1;
                *(_BYTE *)(v153 + 20) = 1;
              }
            }
            else
            {
              v155 = *(_QWORD *)(v154 + 64);
              v156 = *(_BYTE *)(v7 + 71) == 0;
              if ( *(_BYTE *)(v155 + 41) != v156 )
              {
                *(_BYTE *)(v155 + 41) = v156;
                goto LABEL_240;
              }
            }
            Card::SetShadow(*(Card **)(v7 + 8), 0, 0, 0);
          }
          v158 = *(_QWORD *)(v7 + 24);
          if ( v158 )
          {
            v159 = *(_DWORD *)(v7 + 52);
            v160 = CardAnimationManager::ANIM_DUR_EXP;
            *(_DWORD *)(v158 + 44) = v159;
            v161 = *(_DWORD *)(v7 + 56);
            v162 = v159 - *(_DWORD *)(v158 + 52);
            *(_DWORD *)(v158 + 48) = v161;
            *(float *)(v158 + 36) = (float)(powf(
                                              (float)((v161 - *(_DWORD *)(v158 + 56)) * (v161 - *(_DWORD *)(v158 + 56))
                                                    + v162 * v162),
                                              v160)
                                          * CardAnimationManager::ANIM_DUR_MULT)
                                  + CardAnimationManager::ANIM_DUR_BASE;
            if ( *(_BYTE *)(v158 + 69) && *(float *)(v158 + 32) == 0.0 )
              NodeBase::MoveToFront(*(NodeBase **)(*(_QWORD *)(v158 + 8) + 64LL));
            Array<Access_Node *>::FindRemove((__int64)this + 64, *(_QWORD *)(*((_QWORD *)this + 7) + 8LL * v4));
            operator delete(*(void **)(*((_QWORD *)this + 7) + 8LL * v4));
            *(_QWORD *)(*((_QWORD *)this + 7) + 8LL * v4) = v158;
            goto LABEL_247;
          }
LABEL_221:
          CardAnimationManager::RemoveAnimation(this, (struct CardAnimationManager::CardAnimation *)v7, 1);
          --v4;
        }
LABEL_247:
        v5 = g_pRenderManager;
        v6 = g_pUserInterface;
        goto LABEL_218;
      }
      v17 = v16 - 1;
      if ( v17 )
      {
        v18 = v17 - 1;
        if ( v18 )
        {
          if ( v18 == 1 )
          {
            v19 = *(float *)(v7 + 40);
            v20 = *(float *)(v7 + 36);
            v21 = *(Card **)(v7 + 8);
            if ( v19 < v20 )
            {
              if ( !v21 )
                return;
              if ( v19 > (float)(v20 * 0.5) && !*((_BYTE *)v21 + 17) )
              {
                Card::SetFaceUp(v21, 1, 1);
                v5 = g_pRenderManager;
                v6 = g_pUserInterface;
              }
              v38 = *(int **)(*(_QWORD *)(v7 + 8) + 104LL);
              v39 = (double)v38[4] * (double)(v38[6] / 0x64u);
              v40 = v39 * 450.0 / 100.0 * 0.5;
              v41 = *(float *)(v7 + 40) / *(float *)(v7 + 36);
              v42 = v39 * 150.0 / 100.0 * 0.5 * -1.0;
              if ( v41 < 0.0 )
                v41 = 0.0;
              if ( v41 > 1.0 )
                v41 = DOUBLE_1_0;
              v43 = 4;
              v44 = DOUBLE_1_0;
              v45 = 1.0 - v41;
              for ( i = 1.0 - v41; ; i = i * i )
              {
                if ( (v43 & 1) != 0 )
                  v44 = v44 * i;
                v43 >>= 1;
                if ( !v43 )
                  break;
              }
              v47 = 1.0 - v41;
              v48 = 3;
              v49 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v48 & 1) != 0 )
                  v49 = v49 * v47;
                v48 >>= 1;
                if ( !v48 )
                  break;
                v47 = v47 * v47;
              }
              v50 = v41;
              v51 = 1;
              v52 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v51 & 1) != 0 )
                  v52 = v52 * v50;
                v51 >>= 1;
                if ( !v51 )
                  break;
                v50 = v50 * v50;
              }
              v53 = 1.0 - v41;
              v54 = 2;
              v55 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v54 & 1) != 0 )
                  v55 = v55 * v53;
                v54 >>= 1;
                if ( !v54 )
                  break;
                v53 = v53 * v53;
              }
              v56 = v41;
              v57 = 2;
              v58 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v57 & 1) != 0 )
                  v58 = v58 * v56;
                v57 >>= 1;
                if ( !v57 )
                  break;
                v56 = v56 * v56;
              }
              v59 = v41;
              v60 = 3;
              v61 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v60 & 1) != 0 )
                  v61 = v61 * v59;
                v60 >>= 1;
                if ( !v60 )
                  break;
                v59 = v59 * v59;
              }
              v62 = v41;
              v63 = 4;
              v64 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v63 & 1) != 0 )
                  v64 = v64 * v62;
                v63 >>= 1;
                if ( !v63 )
                  break;
                v62 = v62 * v62;
              }
              v65 = 4;
              v66 = v45 * 4.0;
              v67 = 1.0 - v41;
              v168 = v49 * 4.0 * v52 * 250.0
                   + v44 * 105.0
                   - v55 * 6.0 * v58 * 350.0
                   + v45 * 4.0 * v61 * 250.0
                   + v64 * 100.0;
              v68 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v65 & 1) != 0 )
                  v68 = v68 * v67;
                v65 >>= 1;
                if ( !v65 )
                  break;
                v67 = v67 * v67;
              }
              v69 = 1.0 - v41;
              v70 = 3;
              v71 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v70 & 1) != 0 )
                  v71 = v71 * v69;
                v70 >>= 1;
                if ( !v70 )
                  break;
                v69 = v69 * v69;
              }
              v72 = v41;
              v73 = 1;
              v74 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v73 & 1) != 0 )
                  v74 = v74 * v72;
                v73 >>= 1;
                if ( !v73 )
                  break;
                v72 = v72 * v72;
              }
              v75 = 1.0 - v41;
              v76 = 2;
              v77 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v76 & 1) != 0 )
                  v77 = v77 * v75;
                v76 >>= 1;
                if ( !v76 )
                  break;
                v75 = v75 * v75;
              }
              v78 = v41;
              v79 = 2;
              v80 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v79 & 1) != 0 )
                  v80 = v80 * v78;
                v79 >>= 1;
                if ( !v79 )
                  break;
                v78 = v78 * v78;
              }
              v81 = v41;
              v82 = 3;
              v83 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v82 & 1) != 0 )
                  v83 = v83 * v81;
                v82 >>= 1;
                if ( !v82 )
                  break;
                v81 = v81 * v81;
              }
              v84 = v41;
              v85 = 4;
              v86 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v85 & 1) != 0 )
                  v86 = v86 * v84;
                v85 >>= 1;
                if ( !v85 )
                  break;
                v84 = v84 * v84;
              }
              v87 = 4;
              v88 = v71 * 4.0 * v74 * 140.0 + v68 * 100.0;
              v89 = DOUBLE_1_0;
              v90 = 1.0 - v41;
              v91 = v88 + v77 * 6.0 * v80 * 140.0 + v66 * v83 * 140.0 + v86 * 100.0;
              while ( 1 )
              {
                if ( (v87 & 1) != 0 )
                  v89 = v89 * v90;
                v87 >>= 1;
                if ( !v87 )
                  break;
                v90 = v90 * v90;
              }
              v92 = 1.0 - v41;
              v93 = 3;
              v94 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v93 & 1) != 0 )
                  v94 = v94 * v92;
                v93 >>= 1;
                if ( !v93 )
                  break;
                v92 = v92 * v92;
              }
              v95 = v41;
              v96 = 1;
              v97 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v96 & 1) != 0 )
                  v97 = v97 * v95;
                v96 >>= 1;
                if ( !v96 )
                  break;
                v95 = v95 * v95;
              }
              v98 = 1.0 - v41;
              v99 = 2;
              v100 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v99 & 1) != 0 )
                  v100 = v100 * v98;
                v99 >>= 1;
                if ( !v99 )
                  break;
                v98 = v98 * v98;
              }
              v101 = v41;
              v102 = 2;
              v103 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v102 & 1) != 0 )
                  v103 = v103 * v101;
                v102 >>= 1;
                if ( !v102 )
                  break;
                v101 = v101 * v101;
              }
              v104 = v41;
              v105 = 3;
              v106 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v105 & 1) != 0 )
                  v106 = v106 * v104;
                v105 >>= 1;
                if ( !v105 )
                  break;
                v104 = v104 * v104;
              }
              v107 = v41;
              v108 = 4;
              v109 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v108 & 1) != 0 )
                  v109 = v109 * v107;
                v108 >>= 1;
                if ( !v108 )
                  break;
                v107 = v107 * v107;
              }
              v110 = 4;
              v111 = v94 * 4.0 * v97 * v42 + v89 * 0.0;
              v112 = DOUBLE_1_0;
              v113 = 1.0 - v41;
              v114 = v111 + v100 * 6.0 * v103 * v40 + v66 * v106 * v42 + v109 * 0.0;
              while ( 1 )
              {
                if ( (v110 & 1) != 0 )
                  v112 = v112 * v113;
                v110 >>= 1;
                if ( !v110 )
                  break;
                v113 = v113 * v113;
              }
              v115 = 1.0 - v41;
              v116 = 3;
              v117 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v116 & 1) != 0 )
                  v117 = v117 * v115;
                v116 >>= 1;
                if ( !v116 )
                  break;
                v115 = v115 * v115;
              }
              v118 = v41;
              v119 = 1;
              v120 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v119 & 1) != 0 )
                  v120 = v120 * v118;
                v119 >>= 1;
                if ( !v119 )
                  break;
                v118 = v118 * v118;
              }
              v121 = 2;
              v122 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v121 & 1) != 0 )
                  v122 = v122 * v45;
                v121 >>= 1;
                if ( !v121 )
                  break;
                v45 = v45 * v45;
              }
              v123 = v41;
              v124 = 2;
              v125 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v124 & 1) != 0 )
                  v125 = v125 * v123;
                v124 >>= 1;
                if ( !v124 )
                  break;
                v123 = v123 * v123;
              }
              v126 = v41;
              v127 = 3;
              v128 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v127 & 1) != 0 )
                  v128 = v128 * v126;
                v127 >>= 1;
                if ( !v127 )
                  break;
                v126 = v126 * v126;
              }
              v129 = 4;
              v130 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v129 & 1) != 0 )
                  v130 = v130 * v41;
                v129 >>= 1;
                if ( !v129 )
                  break;
                v41 = v41 * v41;
              }
              v131 = v168;
              if ( v168 < 0.0 )
                v131 = 0.0;
              v132 = (int)v131;
              if ( v38[7] != (int)v131 )
              {
                v38[7] = v132;
                *((_BYTE *)v5 + 20) = 1;
                *((_BYTE *)v5 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              v133 = (int)v91;
              v134 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL);
              if ( *(_DWORD *)(v134 + 32) != (int)v91 )
              {
                *(_DWORD *)(v134 + 32) = v133;
                *((_BYTE *)v5 + 20) = 1;
                *((_BYTE *)v5 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              v135 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL);
              if ( *(_DWORD *)(v135 + 28) != v132 )
              {
                *(_DWORD *)(v135 + 28) = v132;
                *((_BYTE *)v5 + 20) = 1;
                *((_BYTE *)v5 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              v136 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL);
              if ( *(_DWORD *)(v136 + 32) != v133 )
              {
                *(_DWORD *)(v136 + 32) = v133;
                *((_BYTE *)v5 + 20) = 1;
                *((_BYTE *)v5 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 104LL),
                (int)v114,
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL) + 12LL));
              v138 = (int)v137;
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 104LL),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL) + 8LL),
                (int)v137);
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 96LL),
                (int)v114,
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL) + 12LL));
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 96LL),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL) + 8LL),
                v138);
              v141 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL);
              if ( v141 )
              {
                if ( *(_DWORD *)(v141 + 28) != v140 )
                {
                  *(_DWORD *)(v141 + 28) = v140;
                  *((_BYTE *)v5 + 20) = 1;
                  *((_BYTE *)v5 + 88) = 1;
                  *((_BYTE *)v6 + 275) = 1;
                }
                v142 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL);
                if ( *(_DWORD *)(v142 + 32) != v139 )
                {
                  *(_DWORD *)(v142 + 32) = v139;
                  *((_BYTE *)v5 + 20) = 1;
                  *((_BYTE *)v5 + 88) = 1;
                  *((_BYTE *)v6 + 275) = 1;
                }
                NodeBase::SetPosition(
                  *(NodeBase **)(*(_QWORD *)(v7 + 8) + 80LL),
                  (int)v114,
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL) + 12LL));
                NodeBase::SetPosition(
                  *(NodeBase **)(*(_QWORD *)(v7 + 8) + 80LL),
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL) + 8LL),
                  v138);
              }
              if ( !*(_BYTE *)(v7 + 72) )
              {
                Card::SetShadow(*(Card **)(v7 + 8), 1, 0, 0);
                v5 = g_pRenderManager;
                v6 = g_pUserInterface;
              }
              v3 = a2;
              goto LABEL_218;
            }
            if ( !v21 )
              goto LABEL_221;
            Card::SetXScale(v21, 100);
            v23 = *(_QWORD *)(v7 + 8);
            v24 = *(_QWORD *)(v23 + 104);
            if ( *(_DWORD *)(v24 + 32) != 100 )
            {
              *(_DWORD *)(v24 + 32) = 100;
              *(_BYTE *)(v22 + 20) = 1;
              *(_BYTE *)(v22 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            v25 = *(_QWORD *)(v23 + 80);
            if ( *(_DWORD *)(v25 + 32) != 100 )
            {
              *(_DWORD *)(v25 + 32) = 100;
              *(_BYTE *)(v22 + 20) = 1;
              *(_BYTE *)(v22 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            v26 = *(_QWORD *)(v7 + 8);
            if ( *(_BYTE *)(v26 + 16) )
            {
              v29 = *(_QWORD *)(v26 + 64);
              if ( *(_BYTE *)(v29 + 41) != 1 )
              {
                *(_BYTE *)(v29 + 41) = 1;
LABEL_36:
                *(_BYTE *)(v22 + 88) = 1;
                *(_BYTE *)(v22 + 20) = 1;
              }
            }
            else
            {
              v27 = *(_QWORD *)(v26 + 64);
              v28 = *(_BYTE *)(v7 + 71) == 0;
              if ( *(_BYTE *)(v27 + 41) != v28 )
              {
                *(_BYTE *)(v27 + 41) = v28;
                goto LABEL_36;
              }
            }
            v30 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL);
            if ( *(_DWORD *)(v30 + 28) != 100 )
            {
              *(_DWORD *)(v30 + 28) = 100;
              *(_BYTE *)(v22 + 20) = 1;
              *(_BYTE *)(v22 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            v31 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL);
            if ( *(_DWORD *)(v31 + 32) != 100 )
            {
              *(_DWORD *)(v31 + 32) = 100;
              *(_BYTE *)(v22 + 20) = 1;
              *(_BYTE *)(v22 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            NodeBase::SetPosition(
              *(NodeBase **)(*(_QWORD *)(v7 + 8) + 96LL),
              0,
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL) + 12LL));
            NodeBase::SetPosition(
              *(NodeBase **)(*(_QWORD *)(v7 + 8) + 96LL),
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 96LL) + 8LL),
              0);
            v33 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL);
            if ( *(_DWORD *)(v33 + 28) != 100 )
            {
              *(_DWORD *)(v33 + 28) = 100;
              *(_BYTE *)(v32 + 20) = 1;
              *(_BYTE *)(v32 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            v34 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL);
            if ( *(_DWORD *)(v34 + 32) != 100 )
            {
              *(_DWORD *)(v34 + 32) = 100;
              *(_BYTE *)(v32 + 20) = 1;
              *(_BYTE *)(v32 + 88) = 1;
              *((_BYTE *)v6 + 275) = 1;
            }
            NodeBase::SetPosition(
              *(NodeBase **)(*(_QWORD *)(v7 + 8) + 104LL),
              0,
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL) + 12LL));
            NodeBase::SetPosition(
              *(NodeBase **)(*(_QWORD *)(v7 + 8) + 104LL),
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 104LL) + 8LL),
              0);
            v36 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL);
            if ( v36 )
            {
              if ( *(_DWORD *)(v36 + 28) != 100 )
              {
                *(_DWORD *)(v36 + 28) = 100;
                *(_BYTE *)(v35 + 20) = 1;
                *(_BYTE *)(v35 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              v37 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL);
              if ( *(_DWORD *)(v37 + 32) != 100 )
              {
                *(_DWORD *)(v37 + 32) = 100;
                *(_BYTE *)(v35 + 20) = 1;
                *(_BYTE *)(v35 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 80LL),
                0,
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL) + 12LL));
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 80LL),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL) + 8LL),
                0);
            }
            goto LABEL_221;
          }
        }
        else if ( *(float *)(v7 + 40) >= *(float *)(v7 + 36) )
        {
          goto LABEL_221;
        }
      }
      else
      {
        v143 = *(_QWORD *)(v7 + 8);
        if ( v143 )
        {
          NodeBase::SetPosition(
            *(NodeBase **)(v143 + 64),
            (int)(float)((float)(*(float *)(v7 + 60) * *(float *)(v7 + 40)) + (float)*(int *)(v7 + 44)),
            *(_DWORD *)(*(_QWORD *)(v143 + 64) + 12LL));
          NodeBase::SetPosition(
            *(NodeBase **)(*(_QWORD *)(v7 + 8) + 64LL),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 64LL) + 8LL),
            (int)(float)((float)((float)(*(float *)(v7 + 40) * *(float *)(v7 + 64)) + (float)*(int *)(v7 + 48))
                       + (float)((float)(*(float *)(v7 + 40) * CardAnimationManager::CARD_GRAVITY) * *(float *)(v7 + 40))));
          v144 = *(Card **)(v7 + 8);
          if ( *(int *)(*((_QWORD *)v144 + 8) + 12LL) > 400 )
          {
            Card::SetShadow(v144, 0, 0, 0);
            v145 = *(_QWORD **)(v7 + 8);
            v146 = (*(_DWORD *)(v145[8] + 12LL) - 400) / 2;
            if ( v146 <= 40 )
            {
              v147 = v145[13];
              v148 = g_pRenderManager;
              v6 = g_pUserInterface;
              v149 = 100 - v146;
              if ( *(_DWORD *)(v147 + 32) != 100 - v146 )
              {
                *(_DWORD *)(v147 + 32) = v149;
                *((_BYTE *)v148 + 20) = 1;
                *((_BYTE *)v148 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              v150 = v145[10];
              if ( *(_DWORD *)(v150 + 32) != v149 )
              {
                *(_DWORD *)(v150 + 32) = v149;
                *((_BYTE *)v148 + 20) = 1;
                *((_BYTE *)v148 + 88) = 1;
                *((_BYTE *)v6 + 275) = 1;
              }
              Card::SetXScale(*(Card **)(v7 + 8), 100 - (int)((double)v146 * -0.75));
              NodeBase::SetPosition(
                *(NodeBase **)(*(_QWORD *)(v7 + 8) + 64LL),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 64LL) + 8LL),
                v146 + 400);
              goto LABEL_218;
            }
            CardAnimationManager::PlayExplosionEffect(this, *(struct Card **)(v7 + 8));
            goto LABEL_221;
          }
          if ( !*(_BYTE *)(v7 + 72) )
            goto LABEL_232;
        }
      }
LABEL_218:
      ++v4;
    }
    while ( v4 < *((_DWORD *)this + 10) );
  }
}
