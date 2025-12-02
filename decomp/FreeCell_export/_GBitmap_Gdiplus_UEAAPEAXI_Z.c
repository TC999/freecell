Gdiplus::Bitmap *__fastcall Gdiplus::Bitmap::`scalar deleting destructor'(Gdiplus::Bitmap *this, char a2)
{
  *(_QWORD *)this = &Gdiplus::Image::`vftable';
  GdipDisposeImage(*((_QWORD *)this + 1));
  if ( (a2 & 1) != 0 )
    GdipFree(this);
  return this;
}
