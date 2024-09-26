#pragma once

#include "matrix4x4.hpp"
#include "vector4.hpp"

#include <format>
#include <ostream>

namespace Atlas::Math {
/**
 * @brief Calculates the transposition of a matrix.
 * @tparam T Value type of the matrix.
 * @tparam R Number of rows in the matrix.
 * @tparam C Number of columns in the matrix.
 * @param m Input matrix.
 * @return The transposed matrix.
 */
template<Size R, Size C, typename T>
constexpr MatrixT<C, R, T> transpose(const MatrixT<R, C, T> &m);

/**
 * @brief Calculates the determinant of a matrix.
 * @tparam T Value type of the matrix.
 * @tparam R Number of rows in the matrix.
 * @tparam C Number of columns in the matrix.
 * @param m The matrix.
 * @return The determinant.
 */
template<Size R, Size C, typename T>
constexpr T determinant(const MatrixT<R, C, T> &m);

/**
 * @brief Calculates the inversion of a matrix.
 * @tparam T Value type of the matrix.
 * @tparam R Number of rows in the matrix.
 * @tparam C Number of columns in the matrix.
 * @param m The matrix.
 * @return The inverted matrix.
 */
template<Size R, Size C, typename T>
constexpr MatrixT<R, C, T> inverse(const MatrixT<R, C, T> &m);

/**
 * @brief Convert matrix to string.
 * @tparam T Value type of the matrix.
 * @tparam R Number of rows in the matrix.
 * @tparam C Number of columns in the matrix.
 * @param m The matrix.
 * @return The string representation.
 */
template<Size R, Size C, typename T>
constexpr std::string to_string(const MatrixT<R, C, T> &m);

/**
 * @brief Outputs matrix to a stream as a string.
 * @tparam T Value type of the matrix.
 * @tparam R Number of rows in the matrix.
 * @tparam C Number of columns in the matrix.
 * @param os The output stream.
 * @param m The matrix.
 * @return The resulting output stream.
 */
template<Size R, Size C, typename T>
inline std::ostream &operator<<(std::ostream &os, const MatrixT<R, C, T> &m);
}  // namespace Atlas::Math

template<typename T>
struct std::formatter<Atlas::Math::MatrixT<4, 4, T>> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::Math::MatrixT<4, 4, T> &m, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(),
            "|{},{},{},{}|\n|{},{},{},{}|\n|{},{},{},{}|\n|{},{},{},{}|",
            m[0][0], m[1][0], m[2][0], m[3][0], m[0][1], m[1][1], m[2][1],
            m[3][1], m[0][2], m[1][2], m[2][2], m[3][2], m[0][3], m[1][3],
            m[2][3], m[3][3]);
    }
};

#include "matrix_func.inl"
