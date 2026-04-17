# so_long — 2D Game

A small 2D game built in C using the **MiniLibX** graphics library, created as part of the 42 school curriculum.

## Overview

The player navigates a character through a tile-based map, collecting all items before reaching the exit. The move counter is printed to the terminal after each step.

## Map Legend

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty floor |
| `P` | Player starting position (exactly 1 required) |
| `C` | Collectible (at least 1 required) |
| `E` | Exit (exactly 1 required) |

Maps must use the `.ber` extension and be fully enclosed by walls (`1`).

## Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` | Quit |

## Requirements

- **macOS** (uses the MiniLibX macOS library with OpenGL + AppKit frameworks)
- **MiniLibX** — the `mlx` library must be present and reachable via `-Imlx -lmlx`
- C compiler (`cc`) with `-Wall -Wextra -Werror`

## Building

```bash
make
```

Additional targets:

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full rebuild
```

## Running

```bash
./so_long maps/map.ber
```

Pass any valid `.ber` map file as the sole argument.

## Map Validation

The parser enforces the following rules and exits with an error message if any are violated:

- File must have the `.ber` extension.
- Map must be rectangular and fully surrounded by walls.
- Exactly one player (`P`) and one exit (`E`) must be present.
- At least one collectible (`C`) must be present.
- Only the characters `0`, `1`, `P`, `C`, and `E` are allowed.
- A valid path from `P` to all `C`s and the exit must exist (flood-fill check).

## Project Structure

```
so_long-2D-Game-/
├── Makefile
├── so_long.h           # Header — structs and function prototypes
├── maps/
│   └── map.ber         # Example map
├── assets/             # XPM sprite images
│   ├── hero1.xpm
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── collective.xpm
│   ├── portal_closed.xpm
│   ├── portal_open.xpm
│   └── AnyConv.com__patrols.xpm
└── srcs/
    ├── main.c          # Entry point, render loop
    ├── parsing.c       # Map loading and validation
    ├── flood_fill.c    # Path reachability check
    ├── move.c          # Player movement and key handling
    ├── mlx_function.c  # Sprite loading and drawing helpers
    ├── get_next_line.c # Read map file line by line
    ├── get_next_line_utils.c
    ├── ft_split.c
    ├── ft_strncmp.c
    ├── ft_strdup.c
    ├── ft_strlen.c
    ├── ft_itoa.c
    ├── ft_putchar_fd.c
    ├── ft_putnbr_fd.c
    └── ft_putstr_fd.c
```

## Author

**sbadr** — 42 student
