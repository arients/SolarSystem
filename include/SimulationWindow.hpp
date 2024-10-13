#ifndef SIMULATIONWINDOW_HPP
#define SIMULATIONWINDOW_HPP

#include <Date.hpp>
#include <SFML/Graphics.hpp>
#include <PlanetarySystem.hpp>

/**
 * @class SimulationWindow
 * @brief Handles the simulation window and main loop.
 */
class SimulationWindow {
public:
    /**
     * @brief Constructs the simulation window.
     */
    SimulationWindow();

    /**
     * @brief Runs the simulation loop.
     */
    void run();

private:
    /**
     * @brief Handles user input and events.
     */
    void handleEvents();

    /**
     * @brief Updates the simulation state.
     */
    void updateSimulation();

    /**
     * @brief Renders content to the window.
     */
    void render();

private:
    Date date;                       /**< Simulation date and time. */
    sf::RenderWindow window;         /**< The main SFML window. */
    sf::View view;                   /**< View for rendering the simulation. */
    sf::View hudView;                /**< View for HUD elements. */
    sf::Font font;                   /**< Font used for text rendering. */
    sf::Text text;                   /**< Text object for displaying information. */
    PlanetarySystem planetarySystem; /**< The planetary system being simulated. */
    float current_zoom = 1.0f;       /**< Current zoom level (1.0 means no zoom). */
};

#endif // SIMULATIONWINDOW_HPP
