
# Cub3D Raycasting Project

## Table of Contents
- [Preview](#preview)
- [Intro](#intro)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Controls](#controls)
- [Technical Details](#technical-details)
- [Credits](#credits)

## Preview
![Screenshot from 2024-10-05 18-55-00](https://github.com/user-attachments/assets/d1b3622f-3a0f-49e4-af47-6d35cd70d1d3)

[Game play](https://github.com/user-attachments/assets/a4526cd7-8b1e-4c9f-9041-3cfac03ad381)

## Intro
Cub3D is a raycasting-based 3D game engine developed as part of the 42 School curriculum. The goal is to simulate a 3D environment in a 2D grid world by calculating the intersections of rays with walls and projecting them to create a first-person view. This project focuses on concepts like raycasting, texture mapping, collision detection, and efficient rendering using the **MiniLibX** library.

## Features
- **Raycasting Engine:** Renders a 3D perspective from a 2D map using raycasting.
- **Texture Mapping:** Textures are applied to walls to enhance visual realism.
- **Dynamic Player Movement:** The player can move in all directions using the keyboard, and rotate the the point of view with arrows/mouse.
- **Collision Detection:** Ensures that the player cannot walk through walls.
- **Doors:** Doors behave like walls but use a different texture and are rendered conditionally.
- **Gun animation:** The player holds a gun that can shoot the shooting boards.
- **Minimap:** Yes, a minimap

## Requirements
To compile and run Cub3D, you will need:
- **Linux machine** (cuz MacOs is bad)**
- **MiniLibX** (included with the project for 42's student)
```bash
  sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/SOHAIBALOUSSI/Cub3D.git cub3d
   cd cub3d
   ```

2. Compile the project:
   ```bash
   make bonus
   ```

3. Run the game and Enjoy:
   ```bash
   ./cub3d_bonus maps/shooting_range.cub
   ```

## Controls
- **W / A / S / D:** Move the player (forward, left, backward, right).
- **Left / Right Arrow:** Rotate the camera view left and right.
- **E:** Open/Close Doors.
- **Mouse:** Control the camera view freely in any direction.
- **Left mouse click:** Shoot 🔫.
- **LCRTL:** Show/Hide the mouse cursor.
- **ESC:** Exit the game.

## Technical Details

1. **Raycasting Algorithm:**  
   The engine uses a modified version of the Digital Differential Analysis (DDA) algorithm for raycasting. It casts rays from the player’s position and calculates intersections with grid lines, determining the distance to walls and projecting them on the screen.

2. **Projection and Wall Rendering:**  
   Wall height is calculated based on the distance from the player, and the appropriate texture is scaled and drawn vertically for each ray. This creates the illusion of depth in a 3D environment.

3. **Player Movement and Collision Detection:**  
   The player’s position is updated based on key hooks, with collision detection ensuring that the player cannot pass through walls. Movements are based on a grid defined in the `.cub` map file.

4. **Textures:**  
   Textures are stored as images and mapped onto walls using the pixel's horizontal and vertical position. The MiniLibX library handles loading `.xpm` texture files and drawing them to the screen.

5. **Doors:**  
   Doors (represented by 'D' in the map file) behave like walls but with diffrent textures and can be opened with 'E'.

## Credits
- [**Cute Sound Library**](https://github.com/RandyGaul/cute_headers/blob/master/cute_sound.h): for managing sound effects in the project. Thanks to [@Randy](https://github.com/RandyGaul).
