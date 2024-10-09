---

# Game of Life Simulation

This project is a simple implementation of **Conway's Game of Life** in C++. It simulates a 2D grid of cells that evolve according to specific rules over time. The grid supports different initial patterns, such as the **Lightweight Spaceship (LWSS)**, **Glider**, and **Penta Decathalon**.

## Table of Contents

- [Introduction](#introduction)
- [Game Rules](#game-rules)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Patterns](#patterns)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The **Game of Life** is a cellular automaton devised by mathematician John Conway. It simulates the life and death of cells on a grid based on simple rules. Despite its simplicity, the game can generate complex and dynamic patterns.

## Game Rules

Each cell in the grid has two possible states:
1. **Alive**
2. **Dead**

The following rules determine how the grid evolves from one generation to the next:

1. **Underpopulation**: A live cell with fewer than 2 live neighbors dies.
2. **Overcrowding**: A live cell with more than 3 live neighbors dies.
3. **Survival**: A live cell with 2 or 3 live neighbors remains alive.
4. **Reproduction**: A dead cell with exactly 3 live neighbors becomes a live cell.

## Features

- Simulates the Game of Life on a 20x20 grid.
- Offers three initial patterns:
  1. **LWSS (Lightweight Spaceship)**: A common pattern that moves across the grid.
  2. **Glider**: A pattern that travels diagonally.
  3. **Penta Decathalon**: An oscillator pattern.
- Displays the evolving grid in real-time.
- Supports continuous simulation with automatic grid updates.

## Installation

To use this project on your local machine, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/game-of-life-simulation.git
   cd game-of-life-simulation
   ```

2. Compile the C++ code:
   ```bash
   g++ -o game_of_life game_of_life.cpp
   ```

3. Run the program:
   ```bash
   ./game_of_life
   ```

## Usage

Upon running the program, you'll be prompted to select one of the initial patterns:

```
ENTER CHOICE 
1. LWSS :
2. Glider :
3. Penta Decathalon :
```

Choose one of the options by entering the corresponding number.

The simulation will then run continuously, updating the grid based on the rules of the Game of Life. The grid is displayed in the terminal, with `o` representing live cells and spaces representing dead cells.

Press `Ctrl + C` to stop the simulation.

## Patterns

Here are the details of the three available patterns:

- **LWSS (Lightweight Spaceship)**: A moving spaceship pattern that repeats itself and travels across the grid.
- **Glider**: A small pattern that moves diagonally across the grid.
- **Penta Decathalon**: An oscillator pattern that repeats after a fixed number of generations.

## Dependencies

This project requires the following:
- A C++ compiler (such as `g++`).
- **unistd.h** for `usleep` (Linux/Mac). On Windows, you may need to adapt or replace `usleep` with a suitable alternative like `Sleep` from **windows.h**.
- **system("cls")** for clearing the console. On Linux/Mac, replace it with `system("clear")`.

## Contributing

Feel free to contribute to this project by opening an issue or submitting a pull request. Contributions for new patterns, optimizations, or improvements are welcome!

---

### Notes:
1. You may need to replace or adapt `system("cls")` and `usleep()` based on the operating system.
