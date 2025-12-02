struct D3DXCOLOR *__fastcall D3DXTex::CCodec::Convert(D3DXTex::CCodec *this, struct D3DXCOLOR *a2)
{
  unsigned int v4; // edx
  __int64 v5; // r10
  float *v6; // rcx
  float v7; // xmm2_4
  char *v8; // r9
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  unsigned int v12; // edx
  __int64 v13; // r10
  char *v14; // r9
  float v15; // xmm0_4
  unsigned int v16; // edx
  float v17; // xmm3_4
  __int64 v18; // rcx
  float *v19; // r9
  float v20; // xmm0_4
  unsigned int v21; // edx
  float *v22; // rcx
  __int64 v23; // r10
  float v24; // xmm1_4
  char *v25; // r9
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm1_4
  unsigned int v29; // edx
  __int64 v30; // r10
  char *v31; // r9
  float v32; // xmm0_4
  unsigned int v33; // edx
  float v34; // xmm3_4
  __int64 v35; // r10
  float *v36; // r9
  float v37; // xmm0_4
  unsigned int v38; // edx
  __int64 v39; // r10
  float *v40; // rcx
  float v41; // xmm2_4
  char *v42; // r9
  float v43; // xmm3_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  unsigned int v46; // edx
  __int64 v47; // rcx
  float *v48; // r9
  float v49; // xmm0_4
  unsigned int v50; // edx
  __int64 v51; // r10
  float *v52; // r9
  float v53; // xmm0_4

  switch ( *((_DWORD *)this + 3) )
  {
    case 1:
      switch ( *((_DWORD *)this + 26) )
      {
        case 2:
          v50 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v51 = 0;
            v52 = (float *)((char *)a2 + 8);
            do
            {
              ++v50;
              *(float *)(v51 + *((_QWORD *)this + 14)) = (float)(*(v52 - 2) * 0.5) + 0.5;
              v51 += 16;
              *(float *)(v51 + *((_QWORD *)this + 14) - 12) = (float)(*(v52 - 1) * 0.5) + 0.5;
              v53 = *v52;
              v52 += 4;
              *(float *)(v51 + *((_QWORD *)this + 14) - 8) = (float)(v53 * 0.5) + 0.5;
              *(float *)(v51 + *((_QWORD *)this + 14) - 4) = *(v52 - 3);
            }
            while ( v50 < *((_DWORD *)this + 34) );
          }
          break;
        case 3:
          v46 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v47 = 0;
            v48 = (float *)((char *)a2 + 8);
            do
            {
              ++v46;
              *(float *)(v47 + *((_QWORD *)this + 14)) = (float)(*(v48 - 2) * 0.5) + 0.5;
              v47 += 16;
              *(float *)(*((_QWORD *)this + 14) + v47 - 12) = (float)(*(v48 - 1) * 0.5) + 0.5;
              v49 = *v48;
              v48 += 4;
              *(float *)(*((_QWORD *)this + 14) + v47 - 8) = (float)(v49 * 0.5) + 0.5;
              *(float *)(*((_QWORD *)this + 14) + v47 - 4) = (float)(*(v48 - 3) * 0.5) + 0.5;
            }
            while ( v46 < *((_DWORD *)this + 34) );
          }
          break;
        case 4:
          v38 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v39 = -8LL - (_QWORD)a2;
            v40 = (float *)((char *)a2 + 8);
            do
            {
              v41 = *(v40 - 2);
              if ( v41 >= 0.0 )
              {
                if ( v41 >= 1.0 )
                  v41 = FLOAT_1_0;
              }
              else
              {
                v41 = 0.0;
              }
              v42 = (char *)v40 + v39;
              *(float *)((char *)v40 + v39 + *((_QWORD *)this + 14)) = v41;
              v43 = *(v40 - 1);
              if ( v43 >= 0.0 )
              {
                if ( v43 >= 1.0 )
                  v43 = FLOAT_1_0;
              }
              else
              {
                v43 = 0.0;
              }
              *(float *)&v42[*((_QWORD *)this + 14) + 4] = v43;
              v44 = *v40;
              if ( *v40 >= 0.0 )
              {
                if ( v44 >= 1.0 )
                  v44 = FLOAT_1_0;
              }
              else
              {
                v44 = 0.0;
              }
              *(float *)&v42[*((_QWORD *)this + 14) + 8] = v44;
              v45 = v40[1];
              if ( v45 >= 0.0 )
              {
                if ( v45 >= 1.0 )
                  v45 = FLOAT_1_0;
              }
              else
              {
                v45 = 0.0;
              }
              ++v38;
              v40 += 4;
              *(float *)&v42[*((_QWORD *)this + 14) + 12] = v45;
            }
            while ( v38 < *((_DWORD *)this + 34) );
          }
          break;
      }
      break;
    case 2:
      switch ( *((_DWORD *)this + 26) )
      {
        case 1:
          v33 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v34 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
            v35 = 0;
            v36 = (float *)((char *)a2 + 8);
            do
            {
              ++v33;
              *(float *)(v35 + *((_QWORD *)this + 14)) = (float)(*(v36 - 2) * v34) - 1.0;
              v35 += 16;
              *(float *)(v35 + *((_QWORD *)this + 14) - 12) = (float)(*(v36 - 1) * v34) - 1.0;
              v37 = *v36;
              v36 += 4;
              *(float *)(v35 + *((_QWORD *)this + 14) - 8) = (float)(v37 * v34) - 1.0;
              *(float *)(v35 + *((_QWORD *)this + 14) - 4) = *(v36 - 3);
            }
            while ( v33 < *((_DWORD *)this + 34) );
          }
          break;
        case 3:
          v29 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v30 = 0;
            v31 = (char *)a2 + 8;
            do
            {
              ++v29;
              *(_DWORD *)(v30 + *((_QWORD *)this + 14)) = *((_DWORD *)v31 - 2);
              *(_DWORD *)(v30 + *((_QWORD *)this + 14) + 4) = *((_DWORD *)v31 - 1);
              *(_DWORD *)(v30 + *((_QWORD *)this + 14) + 8) = *(_DWORD *)v31;
              v30 += 16;
              v32 = *((float *)v31 + 1);
              v31 += 16;
              *(float *)(v30 + *((_QWORD *)this + 14) - 4) = (float)(v32 * 0.5) + 0.5;
            }
            while ( v29 < *((_DWORD *)this + 34) );
          }
          break;
        case 4:
          v21 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v22 = (float *)((char *)a2 + 8);
            v23 = -8LL - (_QWORD)a2;
            do
            {
              v24 = *(v22 - 2);
              if ( v24 >= -1.0 )
              {
                if ( v24 >= 1.0 )
                  v24 = FLOAT_1_0;
              }
              else
              {
                v24 = FLOAT_N1_0;
              }
              v25 = (char *)v22 + v23;
              *(float *)((char *)v22 + v23 + *((_QWORD *)this + 14)) = v24;
              v26 = *(v22 - 1);
              if ( v26 >= -1.0 )
              {
                if ( v26 >= 1.0 )
                  v26 = FLOAT_1_0;
              }
              else
              {
                v26 = FLOAT_N1_0;
              }
              *(float *)&v25[*((_QWORD *)this + 14) + 4] = v26;
              v27 = *v22;
              if ( *v22 >= -1.0 )
              {
                if ( v27 >= 1.0 )
                  v27 = FLOAT_1_0;
              }
              else
              {
                v27 = FLOAT_N1_0;
              }
              *(float *)&v25[*((_QWORD *)this + 14) + 8] = v27;
              v28 = v22[1];
              if ( v28 >= 0.0 )
              {
                if ( v28 >= 1.0 )
                  v28 = FLOAT_1_0;
              }
              else
              {
                v28 = 0.0;
              }
              ++v21;
              v22 += 4;
              *(float *)&v25[*((_QWORD *)this + 14) + 12] = v28;
            }
            while ( v21 < *((_DWORD *)this + 34) );
          }
          break;
      }
      break;
    case 3:
      switch ( *((_DWORD *)this + 26) )
      {
        case 1:
          v16 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v17 = CardAnimationManager::DEF_BASE_ANIM_SPEED;
            v18 = 0;
            v19 = (float *)((char *)a2 + 8);
            do
            {
              ++v16;
              *(float *)(v18 + *((_QWORD *)this + 14)) = (float)(*(v19 - 2) * v17) - 1.0;
              v18 += 16;
              *(float *)(v18 + *((_QWORD *)this + 14) - 12) = (float)(*(v19 - 1) * v17) - 1.0;
              v20 = *v19;
              v19 += 4;
              *(float *)(v18 + *((_QWORD *)this + 14) - 8) = (float)(v20 * v17) - 1.0;
              *(float *)(v18 + *((_QWORD *)this + 14) - 4) = (float)(*(v19 - 3) * v17) - 1.0;
            }
            while ( v16 < *((_DWORD *)this + 34) );
          }
          break;
        case 2:
          v12 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v13 = 0;
            v14 = (char *)a2 + 8;
            do
            {
              ++v12;
              *(_DWORD *)(v13 + *((_QWORD *)this + 14)) = *((_DWORD *)v14 - 2);
              *(_DWORD *)(v13 + *((_QWORD *)this + 14) + 4) = *((_DWORD *)v14 - 1);
              *(_DWORD *)(v13 + *((_QWORD *)this + 14) + 8) = *(_DWORD *)v14;
              v13 += 16;
              v15 = *((float *)v14 + 1);
              v14 += 16;
              *(float *)(v13 + *((_QWORD *)this + 14) - 4) = (float)(v15 * CardAnimationManager::DEF_BASE_ANIM_SPEED)
                                                           - 1.0;
            }
            while ( v12 < *((_DWORD *)this + 34) );
          }
          break;
        case 4:
          v4 = 0;
          if ( *((_DWORD *)this + 34) )
          {
            v5 = -8LL - (_QWORD)a2;
            v6 = (float *)((char *)a2 + 8);
            do
            {
              v7 = *(v6 - 2);
              if ( v7 >= -1.0 )
              {
                if ( v7 >= 1.0 )
                  v7 = FLOAT_1_0;
              }
              else
              {
                v7 = FLOAT_N1_0;
              }
              v8 = (char *)v6 + v5;
              *(float *)((char *)v6 + v5 + *((_QWORD *)this + 14)) = v7;
              v9 = *(v6 - 1);
              if ( v9 >= -1.0 )
              {
                if ( v9 >= 1.0 )
                  v9 = FLOAT_1_0;
              }
              else
              {
                v9 = FLOAT_N1_0;
              }
              *(float *)&v8[*((_QWORD *)this + 14) + 4] = v9;
              v10 = *v6;
              if ( *v6 >= -1.0 )
              {
                if ( v10 >= 1.0 )
                  v10 = FLOAT_1_0;
              }
              else
              {
                v10 = FLOAT_N1_0;
              }
              *(float *)&v8[*((_QWORD *)this + 14) + 8] = v10;
              v11 = v6[1];
              if ( v11 >= -1.0 )
              {
                if ( v11 >= 1.0 )
                  v11 = FLOAT_1_0;
              }
              else
              {
                v11 = FLOAT_N1_0;
              }
              ++v4;
              v6 += 4;
              *(float *)&v8[*((_QWORD *)this + 14) + 12] = v11;
            }
            while ( v4 < *((_DWORD *)this + 34) );
          }
          break;
      }
      break;
  }
  return (struct D3DXCOLOR *)*((_QWORD *)this + 14);
}
