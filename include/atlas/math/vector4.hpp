#pragma once

#include "atlas/types.hpp"

namespace Atlas::Math {
template<Size L, typename T>
struct VectorT;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
using Vector4 = VectorT<4, T>;
using Nat4 = Vector4<Nat>;
using Int4 = Vector4<Int>;
using Float4 = Vector4<Float>;
}  // namespace Atlas::Math

namespace Atlas::Math {
template<typename T>
struct VectorT<4, T> {
    T x, y, z, w;

    static const VectorT<4, T> zero;
    static const VectorT<4, T> one;

    constexpr VectorT() = default;
    template<typename TX, typename TY, typename TZ, typename TW>
    constexpr VectorT(TX x, TY y, TZ z, TW w);
    template<typename U>
    constexpr explicit VectorT(U scalar);
    template<typename U>
    constexpr VectorT(const VectorT<2, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<3, U> &v);
    template<typename U>
    constexpr VectorT(const VectorT<4, U> &v);

    template<typename U>
    constexpr VectorT<4, T> &operator=(U scalar);
    template<typename U>
    constexpr VectorT<4, T> &operator=(const VectorT<4, U> &v);
    template<typename U>
    constexpr VectorT<4, T> &operator+=(U scalar);
    template<typename U>
    constexpr VectorT<4, T> &operator+=(const VectorT<4, U> &v);
    template<typename U>
    constexpr VectorT<4, T> &operator-=(U scalar);
    template<typename U>
    constexpr VectorT<4, T> &operator-=(const VectorT<4, U> &v);
    template<typename U>
    constexpr VectorT<4, T> &operator*=(U scalar);
    template<typename U>
    constexpr VectorT<4, T> &operator*=(const VectorT<4, U> &v);
    template<typename U>
    constexpr VectorT<4, T> &operator/=(U scalar);
    template<typename U>
    constexpr VectorT<4, T> &operator/=(const VectorT<4, U> &v);

    constexpr T &operator[](Size i);
    constexpr const T &operator[](Size i) const;
};

template<typename T>
constexpr VectorT<4, T> operator+(const VectorT<4, T> &v);
template<typename T>
constexpr VectorT<4, T> operator-(const VectorT<4, T> &v);

template<typename T>
constexpr VectorT<4, T> operator+(const VectorT<4, T> &v, T scalar);
template<typename T>
constexpr VectorT<4, T> operator+(T scalar, const VectorT<4, T> &v);
template<typename T>
constexpr VectorT<4, T> operator+(
    const VectorT<4, T> &v1, const VectorT<4, T> &v2);
template<typename T>
constexpr VectorT<4, T> operator-(const VectorT<4, T> &v, T scalar);
template<typename T>
constexpr VectorT<4, T> operator-(T scalar, const VectorT<4, T> &v);
template<typename T>
constexpr VectorT<4, T> operator-(
    const VectorT<4, T> &v1, const VectorT<4, T> &v2);
template<typename T>
constexpr VectorT<4, T> operator*(const VectorT<4, T> &v, T scalar);
template<typename T>
constexpr VectorT<4, T> operator*(T scalar, const VectorT<4, T> &v);
template<typename T>
constexpr VectorT<4, T> operator*(
    const VectorT<4, T> &v1, const VectorT<4, T> &v2);
template<typename T>
constexpr VectorT<4, T> operator/(const VectorT<4, T> &v, T scalar);
template<typename T>
constexpr VectorT<4, T> operator/(T scalar, const VectorT<4, T> &v);
template<typename T>
constexpr VectorT<4, T> operator/(
    const VectorT<4, T> &v1, const VectorT<4, T> &v2);

template<typename T>
constexpr bool operator==(const VectorT<4, T> &v1, const VectorT<4, T> &v2);
template<typename T>
constexpr bool operator!=(const VectorT<4, T> &v1, const VectorT<4, T> &v2);
}  // namespace Atlas::Math

#include "vector4.inl"
