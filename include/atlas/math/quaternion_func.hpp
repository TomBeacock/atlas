#pragma once

#include "vector3.hpp"

#include <format>
#include <ostream>

namespace Atlas::Math {
template<typename T>
struct QuaternionT;
}  // namespace Atlas::Math

namespace Atlas::Math {
/**
 * @brief Calculate euler roll (Z-axis) of a quaternion
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @return The roll.
 */
template<typename T>
T roll(const QuaternionT<T> &q);

/**
 * @brief Calculate euler pitch (X-axis) of a quaternion
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @return The pitch.
 */
template<typename T>
T pitch(const QuaternionT<T> &q);

/**
 * @brief Calculate euler yaw (Y-axis) of a quaternion
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @return The yaw.
 */
template<typename T>
T yaw(const QuaternionT<T> &q);

/**
 * @brief Convert quaternion to euler angles [pitch, yaw, roll]
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @return The euler angles as a 3d vector.
 */
template<typename T>
VectorT<3, T> to_euler_angles(const QuaternionT<T> &q);

/**
 * @brief Rotate a quaternion around a given axis.
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @param angle The angle of rotation.
 * @param axis The axis of rotationi.
 * @return The new quaternion after rotation has been applied.
 */
template<typename T>
QuaternionT<T> rotate(
    const QuaternionT<T> &q, const T &angle, const VectorT<3, T> &axis);

/**
 * @brief Convert quaternion to string.
 * @tparam T Value type of the quaternion.
 * @param q The quaternion.
 * @return The string representation.
 */
template<typename T>
constexpr std::string to_string(const QuaternionT<T> &q);

/**
 * @brief Outputs quaternion to a stream as a string.
 * @tparam T Value type of the quaternion.
 * @param os The output stream.
 * @param q The quaternion.
 * @return The resulting output stream.
 */
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const QuaternionT<T> &q);
}  // namespace Atlas::Math

template<typename T>
struct std::formatter<Atlas::Math::QuaternionT<T>> {
    constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

    auto format(
        const Atlas::Math::QuaternionT<T> &q, std::format_context &ctx) const
    {
        return std::format_to(ctx.out(), "[{},{},{},{}]", q.x, q.y, q.z, q.w);
    }
};

#include "quaternion_func.inl"
