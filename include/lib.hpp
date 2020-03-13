//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_LIB_HPP
#define TINYRENDERER_INCLUDE_LIB_HPP

#include <cstdint>
#include "Matrix.hpp"
#include "type.h"

void line(Mat &mat, Point &a, Point &b, ColorRGB &c) {
  for (u32 y = a.y(); y < b.y(); ++y) {
	for (u32 x = a.x(); x < b.x(); ++x) {
	  mat.setColor(Point{x, y}, c);
	}
  }
}

#endif //TINYRENDERER_INCLUDE_LIB_HPP
