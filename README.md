# Mystersy - A SDL2 C++ Game

## Introduction

A game project made with SDL2 C++.

## Technologies

Project uses:

- Visual Studio Code (VSCode).
- SDL2 image devel 2.0.5 mingw.
- SDL2 ttf devel 2.0.18 mingw.
- SDL2 mixer devel 2.0.4 mingw.
- SDL2 devel 2.0.20 mingw.

## How to compile and play

- **Windows 64bit**:

  - Requirements:
    - VSCode.
    - MinGW-w64.
  - Clone this repository to your computer.
  - Open command line inside the cloned folder.
  - Build `main.exe`

  ```
  g++ -std=c++17 -static-libstdc++ -Iinclude -Iinclude/sdl2 -Iinclude/headers -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
  ```

  - `main.exe` file will be generated. Open the file to run the game (Double click or run `.\main.exe` in the cmd).

- **MacOS**:
  - Requirements:
    - VSCode.
    - Clang- arm64.
  - Clone this repository to your computer.
    #Step by step to run

1. Change SDL_stdinc.h

- Inside include/sdl2/SDL*stdinc.h: (notice from line 479 to 487)
  SDL_FORCE_INLINE void SDL_memset4(void \_dst, Uint32 val, size_t dwords)
  {
  #ifdef **APPLE**
  // memset_pattern4(dst, &val, dwords * 4);
  Uint32 _dst32 = SDL_static_cast(Uint32 _, dst);
  for (size_t i = 0; i < dwords; ++i)
  {
  dst32[i] = val;
  }

- Change: memset_pattern4(dst, &val, dwords \* 4);
- To:
  Uint32 \*dst32 = SDL_static_cast(Uint32 \*, dst);
  for (size_t i = 0; i < dwords; ++i)
  {
  dst32[i] = val;
  }

2. Change launch.json:
   Change:
   "cwd": "${workspaceFolder}",
      "program": "${workspaceFolder}/main",

To:
"cwd": "${workspaceFolder}/src",
      "program": "${workspaceFolder}/src/main",

3. Compile and run

- Open command line inside the cloned folder.
- Build `main.exe` by this command:
  _(Notice that /opt/homebrew/include/SDL2 need to be replace by link to SDL2 include folder on your computer)_

```
clang++ -std=c++17 src/*.cpp -o main $(sdl2-config --cflags --libs) -Iinclude -Iinclude/sdl2 -Iinclude/headers -I/opt/homebrew/include/SDL2 -Llib_mac -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
```

- `main.exe` is created inside working directory, type `./main` on terminal to run

## Contents

#### How to play

You got reincarnated as a fearsome warrior living in the open world Mystersy - a dangerous place filled with skeletons .

Try to survive, level up and win the game.

**Controls**:

- 4 arrow keys : Move around.
- SPACE : Slash with sword (bats can't be slashed).
- E : Create a shield, block every attack of monsters.
- A : Show where to find the Mega Boss.
- S : Turn on/off background music.
- D : Turn on/off sound effects.

**Notes**:

- Killing skeletons will grant you 1 star.
Reach a certain number of stars to **level up** (heal to full health and increase player's stats).

- To win the game, get your level to level 5 .

#### Note on game's algorithm:

- **Map**: the map is endless and generated using Perlin Noise (to specify what type of tile will be (deep water, water, grass, grass mushroom and tree)). Each time, there will be a completely different generated map, based on the random seed.
  Referenced: https://rtouti.github.io/graphics/perlin-noise-algorithm and https://en.wikipedia.org/wiki/Perlin_noise.
