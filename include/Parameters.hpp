#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <SFML/Graphics.hpp>

/**
 * @file Parameters.hpp
 * @brief Defines global constants and parameters used throughout the simulation.
 */

// Base size for scaling (used for calculations involving size scaling)
const double Size = 4.0f; // 4.0f base size

// Gravitational constant in m^3 kg^-1 s^-2
const double G = 6.67430e-11;

// Astronomical unit (AU) in meters, average distance between Earth and the Sun
const double AU = 1.496e+11;

// Number of seconds in one hour
const double hour = 3600; // Time step

// Conversion factor from astronomical units (AU) to pixels (scaled by 'Size')
const double AU_TO_PIXELS = 2.493e8 / (Size / 4);

// Zoom settings
const float ZOOM_FACTOR = 1.1f;        // Zoom in/out factor per scroll or key press
const float ZOOM_MIN = 0.1f;           // Minimum zoom level allowed
const float ZOOM_MAX = 100.0f;         // Maximum zoom level allowed

const float movementSpeed = 5000.0f;   // Speed of camera movement

// Window dimensions (in pixels)
const int WINDOW_WIDTH = 1800;
const int WINDOW_HEIGHT = 1200;

// Center of the window in pixel coordinates (used for screen positioning)
const sf::Vector2f WINDOW_CENTER(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

// Mass of celestial bodies in kilograms
const double M_sun = 1.989e+30;        // Mass of the Sun
const double M_mercury = 3.3011e+23;   // Mass of Mercury
const double M_venus = 4.8675e+24;     // Mass of Venus
const double M_earth = 5.972e+24;      // Mass of Earth
const double M_mars = 6.4171e+23;      // Mass of Mars
const double M_jupiter = 1.8982e+27;   // Mass of Jupiter
const double M_saturn = 5.6834e+26;    // Mass of Saturn
const double M_uranus = 8.6810e+25;    // Mass of Uranus
const double M_neptune = 1.02413e+26;  // Mass of Neptune
const double M_pluto = 1.30900e+22;    // Mass of Pluto

#endif // PARAMETERS_HPP
