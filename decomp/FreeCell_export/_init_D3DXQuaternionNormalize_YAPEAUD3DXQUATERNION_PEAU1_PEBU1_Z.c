struct D3DXQUATERNION *__fastcall init_D3DXQuaternionNormalize(
        struct D3DXQUATERNION *a1,
        const struct D3DXQUATERNION *a2)
{
  D3DXCheckNewDelete();
  D3DXCpuOptimizations(1);
  return off_1000AC528(a1, a2);
}
