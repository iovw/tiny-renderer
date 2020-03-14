//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_LIB_HPP
#define TINYRENDERER_INCLUDE_LIB_HPP

#include <cstdint>
#include "Matrix.hpp"
#include "Type.h"

using Mat = Matrix<Vector3<uint8_t>>;
using RGB = Vector3<uint8_t>;
using P = Vector2<uint32_t>;

void line(Mat &mat, const P &a, const P &b, const RGB &c) {
  float dx = static_cast<float>(b.x() - a.x()) / static_cast<float>(b.y() - a.y());
  for (uint32_t y = a.y(), x = a.x(); y < b.y(); ++y, x += dx) {
	mat.setColor(P{x, y}, c);
  }
}

#endif //TINYRENDERER_INCLUDE_LIB_HPP
