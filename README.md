# so_long

## Introduction
`so_long` is a small 2D game that utilizes textures, sprites, and basic gameplay mechanics. The goal is to guide a character through a map, collecting items and reaching the exit while avoiding obstacles.

usefull websites for the project:
https://lospec.com/pixel-art-scaler/
https://anyconv.com/png-to-xpm-converter/

## Features
- 2D top-down or side-scrolling view.
- Uses MiniLibX for graphical rendering.
- Simple movement controls using W, A, S, D.
- Displays movement count in the shell.
- Error handling for invalid maps and inputs.

## Usage
### Compilation
To compile the project, use the provided `Makefile`:
```sh
make
```
This will generate the `so_long` executable.

### Running the Game
To run the game, provide a valid map file in `.ber` format:
```sh
./so_long maps/example.ber
```

### Controls
- `W` / `Up Arrow` – Move up
- `A` / `Left Arrow` – Move left
- `S` / `Down Arrow` – Move down
- `D` / `Right Arrow` – Move right
- `ESC` – Exit the game

## Map Format
The map must be a `.ber` file and must contain:
- `0` - Empty space
- `1` - Wall
- `C` - Collectible
- `E` - Exit
- `P` - Player start position

Example:
```
111111
1P0C01
100001
1E0001
111111
```

## Error Handling
The program returns an `Error` message for the following cases:
- Invalid characters in the map.
- Incorrect map format (not rectangular, missing required elements, or open edges).
- Multiple player or exit positions.

## Bonus Features
- Animated sprites.
- Enemy patrols that end the game upon contact.
- On-screen movement counter.

## Makefile Targets
- `make`: Compile `so_long`.
- `make bonus`: Compile bonus features.
- `make clean`: Remove object files.
- `make fclean`: Remove executables and object files.
- `make re`: Recompile everything.
- `make play`: Compile and run the game with a default map.

## License
This project is developed for educational purposes as part of the 42 curriculum.
