//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_MATRIX_HPP
#define TINYRENDERER_INCLUDE_MATRIX_HPP
#include <ostream>
#include "Type.h"

template<typename T, u8 N = sizeof(T)>
class Matrix {
  std::vector<T> data{};
  u32 width;
  u32 height;

  [[nodiscard]] inline u64 getOffset(Point p) const {
	return p.y() * width + p.x();
  }

public:
  Matrix(u32 Width, u32 Height) : width(Width), height(Height) {
	data.reserve(width * height);
  }
  [[nodiscard]] const u8 *getData() const {
	u8 *p = new u8[data.size() * sizeof(T)], *ph = p;
	for (auto i:data) {
	  auto flatten = i.flat();
	  for (u8 j = 0; j < N; ++j) {
		*p++ = flatten[j];
	  }
	}
	return ph;
  }
  [[nodiscard]] u32 getWidth() const {
	return width;
  }
  [[nodiscard]] u32 getHeight() const {
	return height;
  }

  void setColor(Point p, T c) {
	data[getOffset(p)] = c;
  }

  T getColor(Point p) const {
	return data[getOffset(p)];
  }
};

using Mat = Matrix<ColorRGB>;

#endif //TINYRENDERER_INCLUDE_MATRIX_HPP
