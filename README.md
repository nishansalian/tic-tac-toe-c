# Tic-Tac-Toe in C

A two-player Tic-Tac-Toe game for the terminal. Players take turns choosing squares 1 through 9. The game detects a win or a draw and rejects invalid or already-taken squares.

## Build

You need a C compiler such as GCC or Clang and Make.

```sh
make
```

Or compile directly:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic -O2 -o tictactoe tictactoe.c
```

## Play

```sh
./tictactoe
```

Player X goes first. Enter a square number from 1 to 9, matching the positions shown on the board. Players share the keyboard and alternate turns.

## License

MIT. See [LICENSE](LICENSE).
