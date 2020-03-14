//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_MATRIX_HPP
#define TINYRENDERER_INCLUDE_MATRIX_HPP
#include <ostream>
#include "Typedef.h"

namespace tr {
template<typename T>
class Matrix {
  std::vector<T> data{};
  uint32_t width;
  uint32_t height;

  [[nodiscard]] inline uint64_t getOffset(uint32_t x, uint32_t y) const {
	return y * width + x;
  }

public:
  Matrix(uint32_t Width, uint32_t Height) : width(Width), height(Height) {
	data.resize(width * height);
  }
  [[nodiscard]] const uint8_t *getData() const {
	uint8_t *p = new uint8_t[data.size() * sizeof(T)], *ph = p;
	for (auto y:data) {
	  for (uint8_t x = 0; x < y.size(); ++x) {
		*p++ = y[x];
	  }
	}
	return ph;
  }
  [[nodiscard]] uint32_t getWidth() const {
	return width;
  }
  [[nodiscard]] uint32_t getHeight() const {
	return height;
  }

  void setColor(uint32_t x, uint32_t y, T c) {
	data[getOffset(x, y)] = c;
  }

  T getColor(uint32_t x, uint32_t y) const {
	return data[getOffset(x, y)];
  }
};
}

#endif //TINYRENDERER_INCLUDE_MATRIX_HPP
