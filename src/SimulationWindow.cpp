#include <SimulationWindow.hpp>
#include <PlanetarySystem.hpp>
#include <Date.hpp>
#include <Object.hpp>
#include <Parameters.hpp>
#include <cmath>
#include <iostream>

SimulationWindow::SimulationWindow() {
    date.setDate(2023, 7, 6, 18);

    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Orbital Simulation");
    window.setFramerateLimit(60);

    if (!font.loadFromFile("assets/Geneva.ttf")) {
        std::cout << "Error loading font\n";
    }

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(5, 5);

    view = window.getDefaultView();
    hudView = window.getDefaultView();

    // Initialize and add celestial objects to the planetary system

    // Sun
    Object sun(M_sun, 30.0 * Size, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, sf::Color::Yellow);
    planetarySystem.addObject(sun);

    // Mercury
    double distance_mercury = 0.387 * AU;
    double v_mercury = std::sqrt(G * M_sun / distance_mercury);
    Object mercury(M_mercury, 5.0* Size, {0.0, v_mercury, 0.0}, {distance_mercury, 0.0, 0.0}, sf::Color::Cyan);
    planetarySystem.addObject(mercury);

    // Venus
    double distance_venus = 0.723 * AU;
    double v_venus = std::sqrt(G * M_sun / distance_venus);
    Object venus(M_venus, 8.0 * Size, {0.0, v_venus, 0.0}, {distance_venus, 0.0, 0.0}, sf::Color(255, 165, 0)); // Orange
    planetarySystem.addObject(venus);

    // Earth
    double distance_earth = 1.0 * AU;
    double v_earth_val = std::sqrt(G * M_sun / distance_earth);
    Object earth(M_earth, 6.0* Size, {0.0, v_earth_val, 0.0}, {distance_earth, 0.0, 0.0}, sf::Color::Blue);
    planetarySystem.addObject(earth);

    // Mars
    double distance_mars = 1.524 * AU;
    double v_mars = std::sqrt(G * M_sun / distance_mars);
    Object mars(M_mars, 7.0* Size, {0.0, v_mars, 0.0}, {distance_mars, 0.0, 0.0}, sf::Color::Red);
    planetarySystem.addObject(mars);

    // Jupiter
    double distance_jupiter = 5.204 * AU;
    double v_jupiter = std::sqrt(G * M_sun / distance_jupiter);
    Object jupiter(M_jupiter, 20.0* Size, {0.0, v_jupiter, 0.0}, {distance_jupiter, 0.0, 0.0}, sf::Color::Magenta);
    planetarySystem.addObject(jupiter);

    // Saturn
    double distance_saturn = 9.582 * AU;
    double v_saturn = std::sqrt(G * M_sun / distance_saturn);
    Object saturn(M_saturn, 18.0* Size, {0.0, v_saturn, 0.0}, {distance_saturn, 0.0, 0.0}, sf::Color(255, 215, 0)); // Gold
    planetarySystem.addObject(saturn);

    // Uranus
    double distance_uranus = 19.218 * AU;
    double v_uranus = std::sqrt(G * M_sun / distance_uranus);
    Object uranus(M_uranus, 16.0* Size, {0.0, v_uranus, 0.0}, {distance_uranus, 0.0, 0.0}, sf::Color::Green);
    planetarySystem.addObject(uranus);

    // Neptune
    double distance_neptune = 30.11 * AU;
    double v_neptune = std::sqrt(G * M_sun / distance_neptune);
    Object neptune(M_neptune, 16.0* Size, {0.0, v_neptune, 0.0}, {distance_neptune, 0.0, 0.0}, sf::Color::Blue);
    planetarySystem.addObject(neptune);

    // Pluto
    double distance_pluto = 39.5 * AU;
    double v_pluto = std::sqrt(G * M_sun / distance_pluto);
    Object pluto(M_pluto, 4.0* Size, {0.0, v_pluto, 0.0}, {distance_pluto, 0.0, 0.0}, sf::Color::White);
    planetarySystem.addObject(pluto);
}

// Main simulation loop
void SimulationWindow::run() {
    while (window.isOpen()) {
        handleEvents();
        updateSimulation();
        render();
    }
}

// Handles user input and events
void SimulationWindow::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Handle zooming with '+' and '-' keys
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Add || event.key.code == sf::Keyboard::Equal) { // '+' key
                if (current_zoom > ZOOM_MIN) {
                    view.zoom(1.0f / ZOOM_FACTOR);
                    current_zoom /= ZOOM_FACTOR;
                }
            }
            if (event.key.code == sf::Keyboard::Subtract || event.key.code == sf::Keyboard::Dash) { // '-' key
                if (current_zoom < ZOOM_MAX) {
                    view.zoom(ZOOM_FACTOR);
                    current_zoom *= ZOOM_FACTOR;
                }
            }
        }
    }

    // Handle camera movement with W/A/S/D keys or Up/Left/Down/Right arrows.
    static sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        view.move(0.0f, -movementSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        view.move(0.0f, movementSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        view.move(-movementSpeed * deltaTime, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        view.move(movementSpeed * deltaTime, 0.0f);
    }
}

// Updates the simulation state
void SimulationWindow::updateSimulation() {
    planetarySystem.update(hour);
}

// Renders the simulation to the window
void SimulationWindow::render() {
    window.clear(sf::Color::Black);

    window.setView(view);

    planetarySystem.draw(window);

    window.setView(hudView);
    text.setString("Current date: " + date.getDateString() + "\n"
        + "Scale: " + std::to_string(current_zoom));
    window.draw(text);
    date.addHours(hour/3600);
    window.display();
}
