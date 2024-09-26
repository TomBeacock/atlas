#pragma once

#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

#include <format>
#include <ostream>
#include <string>

namespace Atlas::Math {
template<Size L, typename T>
struct VectorT;
}  // namespace Atlas::Math

namespace Atlas::Math {
/**
 * @brief Calculates the magnitude of a vector.
 * @tparam T Value type of the vector.
 * @tparam L Number of dimensions of the vector.
 * @param v The vector.
 * @return The magnitude.
 */
template<Size L, typename T>
constexpr T magnitude(const VectorT<L, T> &v);

/**
 * @brief Calculates the square magnitude of a vector.
 *
 * Useful for more cheaply comparing magnitudes.
 *
 * @tparam T Value type of the vector.
 * @tparam L Number of dimensions of the vector.
 * @param v The vector.
 * @return The magnitude squared.
 */
template<Size L, typename T>
constexpr T sqr_magnitude(const VectorT<L, T> &v);

/**
 * @brief Calculate the normalization of a vector.
 * @tparam T Value type of the vector.
 * @tparam L Number of dimensions of the vector.
 * @param v The vector.
 * @return The normalized vector.
 */
template<Size L, typename T>
constexpr VectorT<L, T> normalize(const VectorT<L, T> &v);

/**
 * @brief Calculates the reflection of a vector.
 * @tparam T Value type of the vector.
 * @tparam L Number of dimensions of the vector.
 * @param v The vector.
 * @param normal The normal of the reflection plane.
 * @return The reflected vector.
 */
template<Size L, typename T>
constexpr VectorT<L, T> reflect(
    const VectorT<L, T> &v, const VectorT<L, T> &normal);

/**
 * @brief Calculates the angle between two vectors.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The angle in radians.
 */
template<Size L, typename T>
constexpr T angle(const VectorT<L, T> &v1, const VectorT<L, T> &v2);

/**
 * @brief Calculates the distance between two vectors.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The distance.
 */
template<Size L, typename T>
constexpr T distance(const VectorT<L, T> &v1, const VectorT<L, T> &v2);

/**
 * @brief Calculates the dot product between two vectors.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The dot product.
 */
template<Size L, typename T>
constexpr T dot(const VectorT<L, T> &v1, const VectorT<L, T> &v2);

/**
 * @brief Calculates the linear interpolation between two vectors.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @param t The interpolation value.
 * @return The interpolated vector.
 */
template<Size L, typename T>
constexpr VectorT<L, T> lerp(
    const VectorT<L, T> &v1, const VectorT<L, T> &v2, float t);

/**
 * @brief Convert vector to string.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param v The vector.
 * @return The string representation.
 */
template<Size L, typename T>
constexpr std::string to_string(const VectorT<L, T> &v);

/**
 * @brief Outputs vector to a stream as a string.
 * @tparam T Value type of the vectors.
 * @tparam L Number of dimensions of the vectors.
 * @param os The output stream.
 * @param v The vector.
 * @return The resulting output stream.
 */
template<Size L, typename T>
inline std::ostream &operator<<(std::ostream &os, const VectorT<L, T> &v);
}  // namespace Atlas::Math

template<typename T>
struct std::formatter<Atlas::Math::VectorT<2, T>> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::Math::VectorT<2, T> &v, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "[{},{}]", v.x, v.y);
    }
};

template<typename T>
struct std::formatter<Atlas::Math::VectorT<3, T>> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::Math::VectorT<3, T> &v, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "[{},{},{}]", v.x, v.y, v.z);
    }
};

template<typename T>
struct std::formatter<Atlas::Math::VectorT<4, T>> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::Math::VectorT<4, T> &v, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "[{},{},{},{}]", v.x, v.y, v.z, v.w);
    }
};

#include "vector_func.inl"
