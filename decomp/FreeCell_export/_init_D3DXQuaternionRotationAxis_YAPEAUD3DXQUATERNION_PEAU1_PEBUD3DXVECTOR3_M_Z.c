struct D3DXQUATERNION *__fastcall init_D3DXQuaternionRotationAxis(
        struct D3DXQUATERNION *a1,
        const struct D3DXVECTOR3 *a2,
        float a3)
{
  D3DXCheckNewDelete();
  D3DXCpuOptimizations(1);
  return off_1000AC570(a1, a2, a3);
}
