#include <cstdio>
#include "svpng.inc"
typedef unsigned char u8;
typedef unsigned u32;

int main(int argc, char *argv[]) {
  const u32 w = 256, h = 256;
  u8 rgb[w * h * 3], *p = rgb;
  for (int i = 0; i < h; ++i) {
	for (int j = 0; j < w; ++j) {
	  *p++ = i;
	  *p++ = j;
	  *p++ = 128;
	}
  }
  FILE *fp = fopen("out.png", "wb");
  svpng(fp, w, h, rgb, 0);
  return 0;
}