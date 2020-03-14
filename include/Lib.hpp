//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_LIB_HPP
#define TINYRENDERER_INCLUDE_LIB_HPP

#include <cstdint>
#include "Matrix.hpp"
#include "Typedef.h"

namespace tr {
using Mat = Matrix<RGB>;

void line(int32_t x0, int32_t y0, int32_t x1, int32_t y1, Mat &m, const RGB &c) {
  int32_t xx = x1 - x0,
	  yy = y1 - y0;
  if (std::abs(xx) >= std::abs(yy)) {
	if (x0 > x1) {
	  std::swap(x0, x1);
	}
	float dy = static_cast<float>(yy) / static_cast<float>(std::abs(xx)),
		y = y0;
	for (float x = x0; x < x1;) {
	  m.setColor(x, y, c);
	  y += dy;
	  x++;
	}
  } else {
	if (y0 > y1) {
	  std::swap(y0, y1);
	}
	float dx = static_cast<float>(xx) / static_cast<float>(std::abs(yy)),
		x = x0;
	for (float y = y0; y < y1;) {
	  m.setColor(x, y, c);
	  x += dx;
	  y++;
	}
  }
}

}

#endif //TINYRENDERER_INCLUDE_LIB_HPP
