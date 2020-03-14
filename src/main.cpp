#include <cstdio>
#include "svpng.inc"
#include "Lib.hpp"

using namespace TR::ColorRGB;

int main(int argc, char *argv[])
{
    const uint32_t w = 128, h = 128;
    TR::Mat image{w, h};

    TR::Line(0, 0, w, h, image, RED);
    TR::Line(w - 1, h - 1, 0, 0, image, WHITE);
    TR::Line(13, 20, 80, 40, image, WHITE);
    TR::Line(20, 13, 40, 80, image, RED);
    TR::Line(80, 40, 13, 20, image, RED);

    FILE *fp = fopen("out.png", "wb");
    svpng(fp, w, h, image.GetData(), 0);
    return 0;
}
