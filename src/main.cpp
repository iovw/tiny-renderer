#include <algorithm>
#include <iostream>
#include <cstdio>
#include "svpng.inc"
#include "Lib.hpp"

using namespace tr::rgb;

int main(int argc, char *argv[]) {
  const uint32_t w = 128, h = 128;
  tr::Mat image{w, h};

  tr::line(0, 0, w, h, image, Red);
  tr::line(w, h, 0, 0, image, White);
  line(13, 20, 80, 40, image, White);
  line(20, 13, 40, 80, image, Red);
  line(80, 40, 13, 20, image, Red);

  FILE *fp = fopen("out.png", "wb");
  svpng(fp, w, h, image.getData(), 0);
  return 0;
}