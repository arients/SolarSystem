#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <Vector3ld.hpp>

/**
 * @class Tools
 * @brief Provides utility functions for unit conversions.
 */
class Tools{
public:
    /**
     * @brief Converts astronomical units (AU) to pixels.
     * @param p Position in AU.
     * @return Position in pixels.
     */
    static Vector3ld AU_to_pixels(const Vector3ld& p);

    /**
     * @brief Converts pixels to astronomical units (AU).
     * @param p Position in pixels.
     * @return Position in AU.
     */
    static Vector3ld pixels_to_AU(const Vector3ld& p);
};

#endif // TOOLS_HPP
