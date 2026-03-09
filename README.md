# so_long

![Image](https://github.com/user-attachments/assets/304e482c-df1d-48dd-ada8-5ac9eee09078)

A small **2D game project written in C** using the **MiniLibX graphics library**, developed as part of the **42 curriculum**.

The goal of the project is to build a simple tile-based game while learning the basics of **graphics programming, event handling, and game loops** in C.

---

## Overview

`so_long` is a minimal 2D game where the player navigates through a map, collects items, and reaches the exit.

The project focuses on implementing the core components of a simple game structure:

* Map parsing and validation
* Window rendering
* Keyboard input handling
* Player movement logic
* Basic game state management

In this implementation, the game uses **different sprites for the map elements** (player, walls, collectibles, exit, and floor) so that each element is visually distinct.

---

## Gameplay

The player moves around a tile-based map with the objective of:

1. Collecting all collectibles on the map
2. Reaching the exit tile

The player cannot exit the level until **all collectibles have been gathered**.

Every movement made by the player is counted and printed to the terminal.

---

## Controls

```
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

```
1111111
1P000C1
1000101
1C00E01
1111111
```

### Map Elements

```
1  Wall
0  Empty space / floor
P  Player starting position
C  Collectible
E  Exit
```

Each element is rendered using **different textures/sprites**, allowing the player to clearly distinguish walls, collectibles, and the exit.

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
* Render the map grid
* Display different textures for each game element
* Update the scene after player movement

Each tile type (wall, floor, collectible, player, exit) is drawn with its **own sprite**, making the map visually readable during gameplay.

---

## Example Run

```
./so_long maps/map.ber
```

This launches the game and loads the specified map.

---

## Build

Compile the project using:

```
make
```

This will generate the executable:

```
so_long
```

---

## Project Structure

```
so_long/
│
├── src/        source files
├── includes/   header files
├── maps/       example maps
├── textures/   sprite images used in the game
└── Makefile
```

---

## What This Project Demonstrates

* Basic game loop architecture
* Event-driven programming
* 2D rendering using MiniLibX
* Map parsing and validation
* Texture/sprite based tile rendering
* Memory management in C

---

## Notes

This project was implemented as part of the **42 School curriculum**, which focuses on low-level programming and building software projects from scratch.
