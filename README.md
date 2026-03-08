# so_long

A small **2D game project written in C** using the **MiniLibX graphics library**, developed as part of the **42 curriculum**.

The goal of the project is to build a simple tile-based game while learning the basics of **graphics programming, event handling, and game loops** in C.

---

## Overview

`so_long` is a minimal 2D game where the player navigates through a map, collects items, and reaches the exit.

The project focuses on implementing the core components of a simple game engine:

* Map parsing and validation
* Window rendering
* Keyboard input handling
* Player movement logic
* Basic game state management

---

## Gameplay

The player moves around a tile-based map with the objective of:

1. Collecting all collectibles on the map
2. Reaching the exit tile

The player cannot exit the level until **all collectibles have been gathered**.

Every movement made by the player is counted and printed to the terminal.

---

## Controls

```id="1d93s9"
W  Move up
A  Move left
S  Move down
D  Move right
ESC  Exit the game
```

---

## Map Format

The game loads maps from `.ber` files.

Example map:

```id="u8ng1s"
1111111
1P000C1
1000101
1C00E01
1111111
```

### Map Elements

```id="jkt8p9"
1  Wall
0  Empty space
P  Player starting position
C  Collectible
E  Exit
```

---

## Map Validation

Before the game starts, the map is validated to ensure:

* The map is rectangular
* It is surrounded by walls
* It contains exactly **one player**
* It contains at least **one collectible**
* It contains **one exit**
* All collectibles and the exit are reachable

---

## Rendering

The game uses **MiniLibX** to:

* Create a window
* Render tiles and sprites
* Update the scene based on player movement

Each tile on the map is drawn based on its type (wall, floor, collectible, etc.).

---

## Example Run

```id="v3b6r8"
./so_long maps/map.ber
```

This launches the game and loads the specified map.

---

## Build

Compile the project using:

```id="7kgn1k"
make
```

This will generate the executable:

```id="w2qhsx"
so_long
```

---

## Project Structure

```id="8d5wju"
so_long/
│
├── src/        source files
├── includes/   header files
├── map/       example maps
├── textures/   game textures
└── Makefile
```

---

## What This Project Demonstrates

* Basic game loop architecture
* Event-driven programming
* 2D rendering with MiniLibX
* Map parsing and validation
* Memory management in C
* Simple gameplay system implementation

---

## Notes

This project was implemented as part of the **42 School curriculum**, which focuses on learning low-level programming and building practical software projects from scratch.
