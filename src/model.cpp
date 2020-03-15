#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include "model.h"

Model::Model(const char *filename) :
    Verts(), Faces()
{
    namespace Fs = std::filesystem;
    auto filePath = absolute(Fs::path(filename));
    std::ifstream in;
    in.open(filePath, std::ifstream::in);
    if (in.fail())
    {
        std::cout << filePath << + " File Not Found" << std::endl;
        // throw std::exception("File Not Found");
        return;
    }
    std::string line;
    while (!in.eof())
    {
        std::getline(in, line);
        std::istringstream iss(line);
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            iss >> trash;
            Vec3F v;
            for (auto &i : v.Raw)
                iss >> i;
            Verts.push_back(v);
        }
        else if (!line.compare(0, 2, "f "))
        {
            std::vector<int> f;
            int itrash, idx;
            iss >> trash;
            while (iss >> idx >> trash >> itrash >> trash >> itrash)
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
            }
            Faces.push_back(f);
        }
    }
    std::cerr << "# v# " << Verts.size() << " f# " << Faces.size() << std::endl;
}

Model::~Model() = default;

int Model::NVerts() const
{
    return static_cast<int>(Verts.size());
}

int Model::NFaces() const
{
    return static_cast<int>(Faces.size());
}

std::vector<int> Model::Face(const int idx)
{
    return Faces[idx];
}

std::vector<std::vector<int>> Model::GetFaces() const
{
    return Faces;
}

Vec3F Model::Vert(const int i)
{
    return Verts[i];
}
