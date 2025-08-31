# Cub3D

Cub3D is a 3D game engine inspired by the classic Wolfenstein 3D. It is developed as part of the 42 curriculum to demonstrate mastery of raycasting, file parsing, and low-level graphics programming. The project adheres to the constraints of the 42 coding standards and uses the MinilibX library for rendering.

---

## Features

- **Raycasting**: Implements a 2D raycasting algorithm to render a 3D perspective from a 2D map.
- **Texture Mapping**: Supports `.xpm` textures for walls and customizable floor/ceiling colors.
- **Map Parsing**: Reads and validates `.cub` map files to ensure proper configuration.
- **Player Controls**: Allows movement and rotation within the map.
- **Error Handling**: Provides detailed error messages for invalid configurations or files.

---

## Project Structure

```
.vscode/              # VSCode configuration files
includes/             # Header files
lib/                  # External libraries (ft_printf, libft, get_next_line)
maps/                 # Sample map files (.cub)
mlx_linux/            # MinilibX library for Linux
srcs/                 # Source code
Makefile              # Build system
```

### Key Directories

- **

includes

**: Contains header files such as `cub3d.h` and 

parsing.h

.
- **

srcs

**: Contains the main source code, including parsing, raycasting, and initialization logic.
- **

maps

**: Contains `.cub` map files used to define the game environment.
- **

mlx_linux

**: MinilibX library for rendering graphics.

---

## Dependencies

- **MinilibX**: A lightweight graphics library for rendering.
- **libft**: A custom C library for utility functions.
- **ft_printf**: A custom implementation of `printf`.
- **get_next_line**: A utility for reading files line by line.

---

## Installation

1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd cub3d
   ```

2. Extract the MinilibX library:
   ```sh
   tar -xzf minilibx-linux.tgz
   ```

3. Build the project:
   ```sh
   make
   ```

---

## Usage

1. Run the program with a `.cub` map file:
   ```sh
   ./cub3d maps/map.cub
   ```

2. Use the following controls:
   - **W/A/S/D**: Move forward, left, backward, right.
   - **Arrow Keys**: Rotate the camera.
   - **ESC**: Exit the game.

---

## Map File Format

Map files (`.cub`) define the game environment and must follow these rules:

- **Textures**: Specify paths to `.xpm` files for walls:
  ```
  NO ./path_to_north_texture.xpm
  SO ./path_to_south_texture.xpm
  WE ./path_to_west_texture.xpm
  EA ./path_to_east_texture.xpm
  ```

- **Colors**: Define RGB values for the floor and ceiling:
  ```
  F 220,100,0
  C 225,30,0
  ```

- **Map Layout**: Use `1` for walls, `0` for empty spaces, and `N/S/E/W` for the player's spawn point.

---

## Error Handling

The program validates the following:

- File extensions (`.cub` for maps, `.xpm` for textures).
- Map structure (closed walls, valid characters).
- Texture paths and file readability.
- Floor and ceiling color values (RGB between 0-255).

## Authors

- **fduzant**: Majority of parsing and project structure/organization.
- **tmalless**: Majority of raycasting.