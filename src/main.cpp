#include <cstdio>
#include <iostream>
#include <boost/program_options.hpp>

#include "svpng.inc"
#include "Lib.hpp"
#include "model.h"

using namespace TR::ColorRGB;
using namespace TR;
using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    string inp, outp;
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "print help message")
        ("input,i", po::value<string>(&inp), "input file path")
        ("output,o", po::value<string>(&outp), "output file path");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << "\n";
        return 1;
    }
    if (inp.empty() || outp.empty())
    {
        cerr << "give a input and output path\n";
        return 1;
    }

    const uint32_t w = 1024, h = w;
    Mat image{w, h};

    auto model = Model{inp.c_str()};
    // auto model = Model{"C:/Users/i/Source/tiny-renderer/resource/obj/triangle.obj"};
    for (const auto &face : model.GetFaces())
    {
        for (auto i = 0ULL; i < face.size(); ++i)
        {
            const auto v0 = model.Vert(face[i]);
            const auto v1 = model.Vert(face[(i + 1) % face.size()]);
            int x0 = (v0.X + 1.) / 2. * (w - 1);
            int y0 = (v0.Y + 1.) / 2. * (h - 1);
            int x1 = (v1.X + 1.) / 2. * (w - 1);
            int y1 = (v1.Y + 1.) / 2. * (h - 1);
            Line(x0, y0, x1, y1, image, WHITE);
        }
    }

    image.FlipVertically();
    const auto fp = fopen(outp.c_str(), "wb");
    svpng(fp, w, h, image.GetData(), 0);
    return 0;
}
