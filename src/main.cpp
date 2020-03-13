#include <algorithm>
#include <cstdio>
#include "svpng.inc"
#include "Lib.hpp"

int main(int argc, char *argv[]) {
  const u32 w = 1024, h = 1024;
  Mat mat{w, h};

  FILE *fp = fopen("out.png", "wb");
  svpng(fp, w, h, mat.getData(), 0);
  return 0;
}