#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>
#include "geometry.h"

class Model
{
private:
    std::vector<Vec3F> Verts;
    std::vector<std::vector<int>> Faces;
public:
    explicit Model(const char *filename);
    ~Model();
    [[nodiscard]] int NVerts() const;
    [[nodiscard]] int NFaces() const;
    Vec3F Vert(int i);
    std::vector<int> Face(int idx);
    [[nodiscard]] std::vector<std::vector<int>> GetFaces() const;
};

#endif //__MODEL_H__
