struct D3DXMATRIX *__fastcall init_D3DXMatrixTranspose(struct D3DXMATRIX *a1, const struct D3DXMATRIX *a2)
{
  D3DXCheckNewDelete();
  D3DXCpuOptimizations(1);
  return off_1000AC5B0(a1, a2);
}
