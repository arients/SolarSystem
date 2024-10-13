#ifndef PLANETARYSYSTEM_HPP
#define PLANETARYSYSTEM_HPP

#include <vector>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

/**
 * @class PlanetarySystem
 * @brief Manages a collection of celestial objects and their interactions.
 */
class PlanetarySystem {
public:
    PlanetarySystem() = default;

    /**
     * @brief Adds an object to the planetary system.
     * @param object The object to add.
     */
    void addObject(Object& object);

    /**
     * @brief Updates the state of the system over time.
     * @param dt Time step for the update.
     */
    void update(double dt);

    /**
     * @brief Renders the planetary system onto the window.
     * @param window The SFML render window.
     */
    void draw(sf::RenderWindow& window) const;

private:
    /**
     * @brief Updates the orbit trail of a celestial object.
     * @param obj_pair Pair containing the object and its orbit trail.
     */
    void updateOrbitTrail(std::pair<std::unique_ptr<Object>, std::unique_ptr<sf::VertexArray>>& obj_pair) const;

    /**
     * @brief Retrieves all objects in the system.
     * @return Vector of pointers to objects.
     */
    std::vector<Object*> getAllObjects() const;

private:
    std::vector<std::pair<std::unique_ptr<Object>, std::unique_ptr<sf::VertexArray>>> objects; /**< Celestial objects and their orbit trails. */
    const std::size_t max_trail_length = 10000; /**< Maximum length of the orbit trail. */
};

#endif // PLANETARYSYSTEM_HPP
