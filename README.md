# Island with no name

**Island with no name** is a small 2D action-adventure prototype built with C++ and [raylib](https://www.raylib.com/). Explore a connected island, fight its creatures, and clear every room to win.

## Features

- Six connected rooms to explore
- Keyboard movement and a directional sword attack
- Enemies that pursue and attack the player
- Health display, healing, and restart after victory or defeat
- Pixel-art rendering with a CRT shader effect

## Controls

| Key | Action |
| --- | --- |
| Arrow keys | Move |
| Z | Attack in the direction you are facing |
| R | Restart after winning or dying |

## Requirements

- CMake 4.3 or newer
- A C++ compiler with C++20 support
- Git and an internet connection for CMake to fetch raylib during configuration

## Build and run

From the project root, configure and build:

```sh
cmake -S . -B build
cmake --build build
```

Run the game from the project root so it can find the files in `assets/`:

```sh
./build/bin/island_with_no_name
```

The game opens in a window. Close the window to exit.

## Credits

- [CRT shader](https://rickcarvalho.itch.io/crt-shader-for-raylib-go).
