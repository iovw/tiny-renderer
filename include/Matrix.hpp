//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_MATRIX_HPP
#define TINYRENDERER_INCLUDE_MATRIX_HPP
#include <ostream>
#include "Type.h"

template<typename T>
std::vector<T> flat(Vector3<T> v) {
  return std::vector<T>{v.x(), v.y(), v.z()};
}

template<typename T>
class Matrix {
  std::vector<T> data{};
  uint32_t width;
  uint32_t height;

  [[nodiscard]] inline uint64_t getOffset(Vector2<uint32_t> p) const {
	return p.y() * width + p.x();
  }

public:
  Matrix(uint32_t Width, uint32_t Height) : width(Width), height(Height) {
	data.resize(width * height);
  }
  [[nodiscard]] const uint8_t *getData() const {
	uint8_t *p = new uint8_t[data.size() * sizeof(T)], *ph = p;
	for (auto i:data) {
	  auto flatten = flat(i);
	  for (uint8_t j = 0; j < flatten.size(); ++j) {
		*p++ = flatten[j];
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

  void setColor(Vector2<uint32_t> p, T c) {
	data[getOffset(p)] = c;
  }

  T getColor(Vector2<uint32_t> p) const {
	return data[getOffset(p)];
  }
};

#endif //TINYRENDERER_INCLUDE_MATRIX_HPP
