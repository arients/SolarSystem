#include "Object.hpp"

// Constructor initializes the celestial object with given parameters
Object::Object(const long double m, const long double r, const Vector3ld& v, const Vector3ld& p, const sf::Color c, const bool isStatic_) :
    mass(m), radius(r), velocity(v), positionReal(p), shape(static_cast<float>(r)), isStatic(isStatic_) {
    positionShape = Tools::AU_to_pixels(positionReal);
    shape.setPosition(WINDOW_CENTER.x + static_cast<float>(positionShape.x),
                      WINDOW_CENTER.y + static_cast<float>(positionShape.y));
    shape.setFillColor(c);
    shape.setOrigin(static_cast<float>(r), static_cast<float>(r));
}

// Calculates gravitational acceleration due to other objects
Vector3ld Object::gravitational_acceleration(const std::vector<Object*>& objects) const {
    Vector3ld acceleration = {0.0, 0.0, 0.0};
    const long double epsilon = 1e-10;  // Avoid too small distances
    for (const auto& obj : objects) {
        if (obj == this) continue; // Skip self-interaction
        Vector3ld r = obj->positionReal - this->positionReal;
        long double distance = r.norm();
        if (distance < epsilon) continue; // Avoid division by zero
        long double factor = G * obj->mass / (distance * distance * distance);
        acceleration.x += factor * r.x;
        acceleration.y += factor * r.y;
        acceleration.z += factor * r.z;
    }
    return acceleration;
}

// Performs a Runge-Kutta integration step
void Object::runge_kutta_step(double dt, const std::vector<Object*>& objects) {
    if (isStatic) return;

    // Compute acceleration and intermediate steps for Runge-Kutta integration
    Vector3ld a1 = gravitational_acceleration(objects);
    Vector3ld k1_v = a1 * dt;
    Vector3ld k1_r = velocity * dt;

    Vector3ld temp_pos = positionReal + k1_r * 0.5;
    Vector3ld temp_vel = velocity + k1_v * 0.5;
    Vector3ld a2 = compute_acceleration_at(temp_pos, objects);
    Vector3ld k2_v = a2 * dt;
    Vector3ld k2_r = temp_vel * dt;

    temp_pos = positionReal + k2_r * 0.5;
    temp_vel = velocity + k2_v * 0.5;
    Vector3ld a3 = compute_acceleration_at(temp_pos, objects);
    Vector3ld k3_v = a3 * dt;
    Vector3ld k3_r = temp_vel * dt;

    Vector3ld temp_pos_end = positionReal + k3_r;
    Vector3ld temp_vel_end = velocity + k3_v;
    Vector3ld a4 = compute_acceleration_at(temp_pos_end, objects);
    Vector3ld k4_v = a4 * dt;
    Vector3ld k4_r = temp_vel_end * dt;

    // Update position and velocity using Runge-Kutta 4th order method
    positionReal = positionReal + (k1_r + 2.0 * (k2_r + k3_r) + k4_r) * (1.0 / 6.0);
    velocity = velocity + (k1_v + 2.0 * (k2_v + k3_v) + k4_v) * (1.0 / 6.0);

    // Update shape position for rendering
    positionShape = Tools::AU_to_pixels(positionReal);
    shape.setPosition(WINDOW_CENTER.x + static_cast<float>(positionShape.x),
                      WINDOW_CENTER.y + static_cast<float>(positionShape.y));
}

// Moves the object's graphical representation
void Object::move(sf::Vector2f offset) {
    shape.move(offset);
}

// Returns the real position of the object
Vector3ld Object::getPosition() const {
    return positionReal;
}

// Computes acceleration at a given position due to other objects
Vector3ld Object::compute_acceleration_at(const Vector3ld& pos, const std::vector<Object*>& objects) const {
    Vector3ld acceleration = {0.0, 0.0, 0.0};
    const long double epsilon = 1e-10;
    for (const auto& obj : objects) {
        if (obj == this) continue;
        Vector3ld r = obj->positionReal - pos;
        long double distance = r.norm();
        if (distance < epsilon) continue;
        long double factor = G * obj->mass / (distance * distance * distance);
        acceleration.x += factor * r.x;
        acceleration.y += factor * r.y;
        acceleration.z += factor * r.z;
    }
    return acceleration;
}
