//
// Created by iov on 3/13/20.
//

#ifndef TINYRENDERER_INCLUDE_VECTOR3_H
#define TINYRENDERER_INCLUDE_VECTOR3_H

template<typename T>
class Vector3 {
  T _x, _y, _z;

public:
  Vector3(T X, T Y, T Z) : _x(X), _y(Y), _z(Z) {}
  Vector3() : Vector3(0, 0, 0) {}
  bool operator==(const Vector3 &Rhs) const {
	return _x == Rhs._x &&
		_y == Rhs._y &&
		_z == Rhs._z;
  }
  bool operator!=(const Vector3 &Rhs) const {
	return !(Rhs == *this);
  }
  T x() const {
	return _x;
  }
  T y() const {
	return _y;
  }
  T z() const {
	return _z;
  }
  void setX(T X) {
	_x = X;
  }
  void setY(T Y) {
	_y = Y;
  }
  void setZ(T Z) {
	_z = Z;
  }
};

#endif //TINYRENDERER_INCLUDE_VECTOR3_H
