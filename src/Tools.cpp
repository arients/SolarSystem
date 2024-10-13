#include "Tools.hpp"
#include <Parameters.hpp>

// Converts astronomical units to pixels
Vector3ld Tools::AU_to_pixels(const Vector3ld& p) {
    return {p.x / AU_TO_PIXELS, p.y / AU_TO_PIXELS, p.z / AU_TO_PIXELS};
}

// Converts pixels to astronomical units
Vector3ld Tools::pixels_to_AU(const Vector3ld& p) {
    return {p.x * AU_TO_PIXELS, p.y * AU_TO_PIXELS, p.z * AU_TO_PIXELS};
}
