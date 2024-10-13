#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <Vector3ld.hpp>
#include <Parameters.hpp>
#include <Tools.hpp>

/**
 * @class Object
 * @brief Represents a celestial object in the simulation.
 */
class Object {
public:
    /**
     * @brief Constructs a new Object with specified properties.
     * @param m Mass of the object.
     * @param r Radius of the object.
     * @param v Initial velocity vector.
     * @param p Initial position vector.
     * @param c Color for rendering the object.
     * @param isStatic_ Indicates if the object is static (does not move).
     */
    Object(long double m, long double r, const Vector3ld& v, const Vector3ld& p, sf::Color c, bool isStatic_ = false);

    /**
     * @brief Calculates the gravitational acceleration due to other objects.
     * @param objects Vector of pointers to other objects.
     * @return Acceleration vector.
     */
    Vector3ld gravitational_acceleration(const std::vector<Object*>& objects) const;

    /**
     * @brief Performs a Runge-Kutta integration step.
     * @param dt Time step.
     * @param objects Vector of pointers to other objects.
     */
    void runge_kutta_step(double dt, const std::vector<Object*>& objects);

    /**
     * @brief Moves the object by a specified offset.
     * @param offset Offset vector.
     */
    void move(sf::Vector2f offset);

    /**
     * @brief Gets the current position of the object.
     * @return Position vector.
     */
    Vector3ld getPosition() const;

private:
    /**
     * @brief Computes acceleration at a given position.
     * @param pos Position at which to compute acceleration.
     * @param objects Vector of pointers to other objects.
     * @return Acceleration vector.
     */
    Vector3ld compute_acceleration_at(const Vector3ld& pos, const std::vector<Object*>& objects) const;

public:
    Vector3ld velocity;     /**< Current velocity of the object. */
    Vector3ld positionReal; /**< Actual position in the simulation space. */
    Vector3ld positionShape;/**< Position used for rendering the object. */
    long double mass;       /**< Mass of the object. */
    long double radius;     /**< Radius of the object. */
    sf::CircleShape shape;  /**< Graphical representation of the object. */
    bool isStatic;          /**< Indicates if the object is static. */
};

#endif //OBJECT_HPP
