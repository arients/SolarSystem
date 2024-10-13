#include "PlanetarySystem.hpp"

// Adds an object and its orbit trail to the system
void PlanetarySystem::addObject(Object& object) {
    auto obj = std::make_unique<Object>(object);
    auto orbitTrail = std::make_unique<sf::VertexArray>(sf::LinesStrip);
    objects.emplace_back(std::move(obj), std::move(orbitTrail));
}

// Updates all objects in the system
void PlanetarySystem::update(double dt) {
    for (auto& obj_pair : objects) {
        obj_pair.first->runge_kutta_step(dt, getAllObjects());
        updateOrbitTrail(obj_pair);
    }
}

// Draws objects and their orbit trails
void PlanetarySystem::draw(sf::RenderWindow& window) const {
    for (const auto& obj_pair : objects) {
        window.draw(*obj_pair.second); // Draw orbit trail
    }

    for (const auto& obj_pair : objects) {
        window.draw(obj_pair.first->shape); // Draw object
    }
}

// Updates the orbit trail of an object
void PlanetarySystem::updateOrbitTrail(std::pair<std::unique_ptr<Object>, std::unique_ptr<sf::VertexArray>>& obj_pair) const {
    auto& object = obj_pair.first;
    auto& trail = *obj_pair.second;

    // Add new point to the trail
    sf::Vertex new_point;
    new_point.position = sf::Vector2f(WINDOW_CENTER.x + static_cast<float>(object->positionShape.x),
                                      WINDOW_CENTER.y + static_cast<float>(object->positionShape.y));
    new_point.color = sf::Color::White;

    trail.append(new_point);

    // Limit the trail length
    if (trail.getVertexCount() > max_trail_length) {
        for (std::size_t i = 0; i < trail.getVertexCount() - 1; ++i) {
            trail[i] = trail[i + 1];
        }
        trail.resize(max_trail_length);
    }
}

// Retrieves pointers to all objects in the system
std::vector<Object*> PlanetarySystem::getAllObjects() const {
    std::vector<Object*> object_ptrs;
    for (const auto& obj_pair : objects) {
        object_ptrs.push_back(obj_pair.first.get());
    }
    return object_ptrs;
}
