#include "Vector3ld.hpp"

// Default constructor initializes vector to zero
Vector3ld::Vector3ld() : x(0), y(0), z(0) { }

// Constructor initializes vector with given components
Vector3ld::Vector3ld(const long double x, const long double y, const long double z) : x(x), y(y), z(z) { }

// Vector addition
Vector3ld Vector3ld::operator+(const Vector3ld& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

// Vector subtraction
Vector3ld Vector3ld::operator-(const Vector3ld& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

// Scalar multiplication
Vector3ld Vector3ld::operator*(double scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

// Scalar multiplication (friend function)
Vector3ld operator*(double scalar, const Vector3ld& v) {
    return {v.x * scalar, v.y * scalar, v.z * scalar};
}

// Overloads the << operator for output
std::ostream &operator<<(std::ostream &os, const Vector3ld &v) {
    os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return os;
}

// Calculates the norm (magnitude) of the vector
long double Vector3ld::norm() const {
    return std::sqrt(x * x + y * y + z * z);
}
