# Solar System Simulation

A C++ simulation of the solar system using SFML for graphical rendering. This project models the motion of celestial bodies using Newtonian physics and numerical integration methods.

## Features

- **Realistic Physics**: Implements gravitational interactions between celestial bodies using the Runge-Kutta 4th order method.
- **Graphical Visualization**: Uses SFML to render planets and their orbits in a 2D space.
- **User Interaction**: Allows zooming and panning of the view to explore the solar system.
- **Keyboard Controls**: Move around the simulation using arrow keys or W, A, S, D keys.
- **Scalable Design**: Easily add or modify celestial objects in the simulation.

## Demo

(Include screenshots or GIFs here to showcase your simulation.)

## Requirements

- C++17 or higher
- SFML 2.5 or later

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/arients/SolarSystem.git
   cd SolarSystem
   
2. Install SFML:
- Windows: Download the SFML SDK from SFML Downloads and follow the installation instructions.

- macOS: Install via Homebrew:
    ```bash
    brew install sfml
- Linux: Install via your package manager (e.g., for Ubuntu):
    ```bash
    sudo apt-get install libsfml-dev

### Controls:
- Zoom In: Press + or = 
- Zoom Out: Press - or _
- Move Up: Press W or Up Arrow ↑ 
- Move Down: Press S or Down Arrow ↓
- Move Left: Press A or Left Arrow ←
- Move Right: Press D or Right Arrow →

### Project Structure
- src/: Source code files. 
- include/: Header files. 
- assets/: Assets like fonts or images (if any). 
- CMakeLists.txt: Build configuration. 
- README.md: Project documentation.

![Solar System Simulation Screenshot](assets/screenshot.png)
