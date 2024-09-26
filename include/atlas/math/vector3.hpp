#pragma once

#include "atlas/types.hpp"

namespace Atlas::Math {
template<Size L, typename T>
struct VectorT;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
using Vector3 = VectorT<3, T>;
using Nat3 = Vector3<Nat>;
using Int3 = Vector3<Int>;
using Float3 = Vector3<Float>;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
struct VectorT<3, T> {
    T x, y, z;

    static const VectorT<3, T> zero;
    static const VectorT<3, T> one;
    static const VectorT<3, T> left;
    static const VectorT<3, T> right;
    static const VectorT<3, T> up;
    static const VectorT<3, T> down;
    static const VectorT<3, T> forward;
    static const VectorT<3, T> back;

    constexpr VectorT() = default;
    template<typename TX, typename TY, typename TZ>
    constexpr VectorT(TX x, TY y, TZ z);
    template<typename U>
    constexpr explicit VectorT(U scalar);
    template<typename U>
    constexpr VectorT(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<4, U> &v);

    template<typename U>
    constexpr VectorT<3, T> &operator=(U scalar);
    template<typename U>
    constexpr VectorT<3, T> &operator=(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT<3, T> &operator+=(U scalar);
    template<typename U>
    constexpr VectorT<3, T> &operator+=(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT<3, T> &operator-=(U scalar);
    template<typename U>
    constexpr VectorT<3, T> &operator-=(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT<3, T> &operator*=(U scalar);
    template<typename U>
    constexpr VectorT<3, T> &operator*=(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT<3, T> &operator/=(U scalar);
    template<typename U>
    constexpr VectorT<3, T> &operator/=(const VectorT<3, U> &v);

    constexpr T &operator[](Size i);
    constexpr const T &operator[](Size i) const;
};

template<typename T>
constexpr VectorT<3, T> operator+(const VectorT<3, T> &v);
template<typename T>
constexpr VectorT<3, T> operator-(const VectorT<3, T> &v);

template<typename T>
constexpr VectorT<3, T> operator+(const VectorT<3, T> &v, T scalar);
template<typename T>
constexpr VectorT<3, T> operator+(T scalar, const VectorT<3, T> &v);
template<typename T>
constexpr VectorT<3, T> operator+(
    const VectorT<3, T> &v1, const VectorT<3, T> &v2);
template<typename T>
constexpr VectorT<3, T> operator-(const VectorT<3, T> &v, T scalar);
template<typename T>
constexpr VectorT<3, T> operator-(T scalar, const VectorT<3, T> &v);
template<typename T>
constexpr VectorT<3, T> operator-(
    const VectorT<3, T> &v1, const VectorT<3, T> &v2);
template<typename T>
constexpr VectorT<3, T> operator*(const VectorT<3, T> &v, T scalar);
template<typename T>
constexpr VectorT<3, T> operator*(T scalar, const VectorT<3, T> &v);
template<typename T>
constexpr VectorT<3, T> operator*(
    const VectorT<3, T> &v1, const VectorT<3, T> &v2);
template<typename T>
constexpr VectorT<3, T> operator/(const VectorT<3, T> &v, T scalar);
template<typename T>
constexpr VectorT<3, T> operator/(T scalar, const VectorT<3, T> &v);
template<typename T>
constexpr VectorT<3, T> operator/(
    const VectorT<3, T> &v1, const VectorT<3, T> &v2);

template<typename T>
constexpr bool operator==(const VectorT<3, T> &v1, const VectorT<3, T> &v2);
template<typename T>
constexpr bool operator!=(const VectorT<3, T> &v1, const VectorT<3, T> &v2);
}  // namespace Atlas::Math

#include "vector3.inl"
