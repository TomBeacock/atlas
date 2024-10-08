namespace Atlas::Math {
template<typename T>
constexpr MatrixT<4, 4, T> transpose(const MatrixT<4, 4, T> &m)
{
    return MatrixT<4, 4, T>(VectorT<4, T>(m[0][0], m[1][0], m[2][0], m[3][0]),
        VectorT<4, T>(m[0][1], m[1][1], m[2][1], m[3][1]),
        VectorT<4, T>(m[0][2], m[1][2], m[2][2], m[3][2]),
        VectorT<4, T>(m[0][3], m[1][3], m[2][3], m[3][3]));
}

template<typename T>
constexpr T determinant(const MatrixT<4, 4, T> &m)
{
    T sub_factor0 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    T sub_factor1 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    T sub_factor2 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    T sub_factor3 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    T sub_factor4 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    T sub_factor5 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

    VectorT<4, T> coef(+(m[1][1] * sub_factor0 - m[1][2] * sub_factor1
                           + m[1][3] * sub_factor2),
        -(m[1][0] * sub_factor0 - m[1][2] * sub_factor3
            + m[1][3] * sub_factor4),
        +(m[1][0] * sub_factor1 - m[1][1] * sub_factor3
            + m[1][3] * sub_factor5),
        -(m[1][0] * sub_factor2 - m[1][1] * sub_factor4
            + m[1][2] * sub_factor5));

    return m[0][0] * coef[0] + m[0][1] * coef[1] + m[0][2] * coef[2]
           + m[0][3] * coef[3];
}

template<Size R, Size C, typename T>
constexpr MatrixT<R, C, T> inverse(const MatrixT<R, C, T> &m)
{
    T coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    T coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    T coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

    T coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    T coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    T coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

    T coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    T coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    T coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

    T coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    T coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    T coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

    T coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    T coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    T coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

    T coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    T coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    T coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    VectorT<4, T> fac0(coef00, coef00, coef02, coef03);
    VectorT<4, T> fac1(coef04, coef04, coef06, coef07);
    VectorT<4, T> fac2(coef08, coef08, coef10, coef11);
    VectorT<4, T> fac3(coef12, coef12, coef14, coef15);
    VectorT<4, T> fac4(coef16, coef16, coef18, coef19);
    VectorT<4, T> fac5(coef20, coef20, coef22, coef23);

    VectorT<4, T> vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
    VectorT<4, T> vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
    VectorT<4, T> vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
    VectorT<4, T> vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

    VectorT<4, T> inv0(vec1 * fac0 - vec2 * fac1 + vec3 * fac2);
    VectorT<4, T> inv1(vec0 * fac0 - vec2 * fac3 + vec3 * fac4);
    VectorT<4, T> inv2(vec0 * fac1 - vec1 * fac3 + vec3 * fac5);
    VectorT<4, T> inv3(vec0 * fac2 - vec1 * fac4 + vec2 * fac5);

    VectorT<4, T> signA(+1, -1, +1, -1);
    VectorT<4, T> signB(-1, +1, -1, +1);
    MatrixT<4, 4, T> inverse(
        inv0 * signA, inv1 * signB, inv2 * signA, inv3 * signB);

    VectorT<4, T> row(
        inverse[0][0], inverse[1][0], inverse[2][0], inverse[3][0]);

    VectorT<4, T> dot0(m[0] * row);
    T dot1 = (dot0.x + dot0.y) + (dot0.z + dot0.w);

    T one_over_det = static_cast<T>(1) / dot1;

    return inverse * one_over_det;
}

template<Size R, Size C, typename T>
constexpr std::string to_string(const MatrixT<R, C, T> &m)
{
    return std::format("{}", m);
}

template<Size R, Size C, typename T>
inline std::ostream &operator<<(std::ostream &os, const MatrixT<R, C, T> &m)
{
    return os << to_string(m);
}
}  // namespace Atlas::Math
