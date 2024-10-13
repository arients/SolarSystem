#ifndef VECTOR3LD_HPP
#define VECTOR3LD_HPP

#include <iostream>
#include <cmath>

/**
 * @class Vector3ld
 * @brief Represents a 3-dimensional vector using long doubles.
 */
class Vector3ld {
public:
    /**
     * @brief Default constructor initializes vector components to zero.
     */
    Vector3ld();

    /**
     * @brief Constructs a vector with specified x, y, and z components.
     * @param x The x-component.
     * @param y The y-component.
     * @param z The z-component.
     */
    Vector3ld(long double x, long double y, long double z);

    /**
     * @brief Adds two vectors.
     * @param v The vector to add.
     * @return Resulting vector after addition.
     */
    Vector3ld operator+(const Vector3ld& v) const;

    /**
     * @brief Subtracts a vector from this vector.
     * @param v The vector to subtract.
     * @return Resulting vector after subtraction.
     */
    Vector3ld operator-(const Vector3ld& v) const;

    /**
     * @brief Multiplies the vector by a scalar.
     * @param scalar The scalar value.
     * @return Scaled vector.
     */
    Vector3ld operator*(double scalar) const;

    /**
     * @brief Multiplies a scalar by a vector (friend function).
     * @param scalar The scalar value.
     * @param v The vector.
     * @return Scaled vector.
     */
    friend Vector3ld operator*(double scalar, const Vector3ld& v);

    /**
     * @brief Overloads the insertion operator for output.
     * @param os Output stream.
     * @param v Vector to output.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Vector3ld &v);

    /**
     * @brief Calculates the Euclidean norm (magnitude) of the vector.
     * @return The norm of the vector.
     */
    long double norm() const;

public:
    long double x; /**< X-component of the vector. */
    long double y; /**< Y-component of the vector. */
    long double z; /**< Z-component of the vector. */
};

#endif //VECTOR3LD_HPP
