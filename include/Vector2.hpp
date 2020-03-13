//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_VECTOR2_HPP
#define TINYRENDERER_INCLUDE_VECTOR2_HPP

template<typename T>
class Vector2 {
  T _x, _y;

public:
  Vector2(T X, T Y) : _x(X), _y(Y) {}
  bool operator==(const Vector2 &Rhs) const {
	return _x == Rhs._x &&
		_y == Rhs._y;
  }
  bool operator!=(const Vector2 &Rhs) const {
	return !(Rhs == *this);
  }
  T x() const {
	return _x;
  }
  T y() const {
	return _y;
  }
  void setX(T X) {
	_x = X;
  }
  void setY(T Y) {
	_y = Y;
  }
};

#endif //TINYRENDERER_INCLUDE_VECTOR2_HPP
