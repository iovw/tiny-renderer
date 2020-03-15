#include <cstdio>
#include <iostream>

#include "svpng.inc"
#include "Lib.hpp"
#include "model.h"

using namespace TR::ColorRGB;
using namespace TR;

int main(int argc, char *argv[])
{
    const uint32_t w = 512, h = 512;
    TR::Mat image{w, h};

    auto model = Model{"C:/Users/i/Source/tiny-renderer/resource/obj/african_head.obj"};
    for (const auto &face : model.GetFaces())
    {
        for (auto i = 0; i < face.size(); ++i)
        {
            const auto v0 = model.Vert(face[i]);
            const auto v1 = model.Vert(face[(i + 1) % 3]);
            int x0 = (v0.X + 1.) / 2. * (w - 1);
            int y0 = (v0.Y + 1.) / 2. * (h - 1);
            int x1 = (v1.X + 1.) / 2. * (w - 1);
            int y1 = (v1.Y + 1.) / 2. * (h - 1);
            TR::Line(x0, y0, x1, y1, image, WHITE);
        }
    }

    const auto fp = fopen("out.png", "wb");
    svpng(fp, w, h, image.GetData(), 0);
    return 0;
}
