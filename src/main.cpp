#include <algorithm>
#include <cstdio>
#include "svpng.inc"
#include "Lib.hpp"

int main(int argc, char *argv[]) {
  const uint32_t w = 128, h = 128;
  Mat mat{w, h};
  line(mat, P{0, 0}, P{w, h}, RGB{255, 0, 0});
  FILE *fp = fopen("out.png", "wb");
  svpng(fp, w, h, mat.getData(), 0);
  return 0;
}