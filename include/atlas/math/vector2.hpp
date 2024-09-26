#pragma once

#include "atlas/types.hpp"

namespace Atlas::Math {
template<Size L, typename T>
struct VectorT;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
using Vector2 = VectorT<2, T>;
using Nat2 = Vector2<Nat>;
using Int2 = Vector2<Int>;
using Float2 = Vector2<Float>;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
struct VectorT<2, T> {
    T x, y;

    static const VectorT<2, T> zero;
    static const VectorT<2, T> one;
    static const VectorT<2, T> left;
    static const VectorT<2, T> right;
    static const VectorT<2, T> up;
    static const VectorT<2, T> down;

    constexpr VectorT() = default;
    template<typename TX, typename TY>
    constexpr VectorT(TX x, TY y);
    template<typename U>
    constexpr explicit VectorT(U scalar);
    template<typename U>
    constexpr VectorT(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<4, U> &v);

    template<typename U>
    constexpr VectorT<2, T> &operator=(U scalar);
    template<typename U>
    constexpr VectorT<2, T> &operator=(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT<2, T> &operator+=(U scalar);
    template<typename U>
    constexpr VectorT<2, T> &operator+=(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT<2, T> &operator-=(U scalar);
    template<typename U>
    constexpr VectorT<2, T> &operator-=(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT<2, T> &operator*=(U scalar);
    template<typename U>
    constexpr VectorT<2, T> &operator*=(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT<2, T> &operator/=(U scalar);
    template<typename U>
    constexpr VectorT<2, T> &operator/=(const VectorT<2, U> &v);

    constexpr T &operator[](Size i);
    constexpr const T &operator[](Size i) const;
};

template<typename T>
constexpr VectorT<2, T> operator+(const VectorT<2, T> &v);
template<typename T>
constexpr VectorT<2, T> operator-(const VectorT<2, T> &v);

template<typename T>
constexpr VectorT<2, T> operator+(const VectorT<2, T> &v, T scalar);
template<typename T>
constexpr VectorT<2, T> operator+(T scalar, const VectorT<2, T> &v);
template<typename T>
constexpr VectorT<2, T> operator+(
    const VectorT<2, T> &v1, const VectorT<2, T> &v2);
template<typename T>
constexpr VectorT<2, T> operator-(const VectorT<2, T> &v, T scalar);
template<typename T>
constexpr VectorT<2, T> operator-(T scalar, const VectorT<2, T> &v);
template<typename T>
constexpr VectorT<2, T> operator-(
    const VectorT<2, T> &v1, const VectorT<2, T> &v2);
template<typename T>
constexpr VectorT<2, T> operator*(const VectorT<2, T> &v, T scalar);
template<typename T>
constexpr VectorT<2, T> operator*(T scalar, const VectorT<2, T> &v);
template<typename T>
constexpr VectorT<2, T> operator*(
    const VectorT<2, T> &v1, const VectorT<2, T> &v2);
template<typename T>
constexpr VectorT<2, T> operator/(const VectorT<2, T> &v, T scalar);
template<typename T>
constexpr VectorT<2, T> operator/(T scalar, const VectorT<2, T> &v);
template<typename T>
constexpr VectorT<2, T> operator/(
    const VectorT<2, T> &v1, const VectorT<2, T> &v2);

template<typename T>
constexpr bool operator==(const VectorT<2, T> &v1, const VectorT<2, T> &v2);
template<typename T>
constexpr bool operator!=(const VectorT<2, T> &v1, const VectorT<2, T> &v2);
}  // namespace Atlas::Math

#include "vector2.inl"
