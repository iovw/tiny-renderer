#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <cmath>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct Vec2
{
    union
    {
        struct
        {
            T U, V;
        };

        struct
        {
            T X, Y;
        };

        T Raw[2];
    };

    Vec2() :
        U(0), V(0)
    {
    }

    Vec2(T u, T v) :
        U(u), V(v)
    {
    }

    inline Vec2<T> operator +(const Vec2<T> &V) const { return Vec2<T>(U + V.U, V + V.V); }
    inline Vec2<T> operator -(const Vec2<T> &V) const { return Vec2<T>(U - V.U, V - V.V); }
    inline Vec2<T> operator *(float f) const { return Vec2<T>(U * f, V * f); }
    template <class>
    friend std::ostream &operator<<(std::ostream &s, Vec2<T> &v);
};

template <class T>
struct Vec3
{
    union
    {
        struct
        {
            T X, Y, Z;
        };

        struct
        {
            T IVert, Iuv, INorm;
        };

        T Raw[3];
    };

    Vec3() :
        X(0), Y(0), Z(0)
    {
    }

    Vec3(T x, T y, T z) :
        X(x), Y(y), Z(z)
    {
    }

    inline Vec3<T> operator ^(const Vec3<T> &v) const
    {
        return Vec3<T>(Y * v.Z - Z * v.Y, Z * v.X - X * v.Z, X * v.Y - Y * v.X);
    }

    inline Vec3<T> operator +(const Vec3<T> &v) const { return Vec3<T>(X + v.X, Y + v.Y, Z + v.Z); }
    inline Vec3<T> operator -(const Vec3<T> &v) const { return Vec3<T>(X - v.X, Y - v.Y, Z - v.Z); }
    inline Vec3<T> operator *(float f) const { return Vec3<T>(X * f, Y * f, Z * f); }
    inline T operator *(const Vec3<T> &v) const { return X * v.X + Y * v.Y + Z * v.Z; }
    [[nodiscard]] float Norm() const { return std::sqrt(X * X + Y * Y + Z * Z); }

    Vec3<T> &Normalize(T l = 1)
    {
        *this = (*this) * (l / Norm());
        return *this;
    }

    template <class>
    friend std::ostream &operator<<(std::ostream &s, Vec3<T> &v);
};

typedef Vec2<float> Vec2F;
typedef Vec2<int> Vec2I;
typedef Vec3<float> Vec3F;
typedef Vec3<int> Vec3I;

template <class T>
std::ostream &operator<<(std::ostream &s, Vec2<T> &v)
{
    s << "(" << v.x << ", " << v.y << ")\n";
    return s;
}

template <class T>
std::ostream &operator<<(std::ostream &s, Vec3<T> &v)
{
    s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return s;
}

#endif //__GEOMETRY_H__
