# Flipside

A small command-line coin flipper written in C. Run it and it flips a coin, printing `Heads` or `Tails`. It takes no arguments, so it works directly from the terminal or in scripts.

## Structure

```
Flipside/
├── Flipside.c
├── README.md
├── LICENSE.md
└── bin/
    └── coin
```

The source file is `Flipside.c`, and the compiled executable is `bin/coin`.

## Usage

```sh
coin
coin -h
coin --help
```

- `coin`: flips the coin and prints the result
- `-h` or `--help`: prints a short usage message

## Examples

```sh
coin
# Heads
```

## Build

From inside the `Flipside/` folder:

```sh
mkdir -p bin
gcc -Wall -Wextra -o bin/coin Flipside.c
```

## Run

```sh
./bin/coin
```

## License

This project is licensed under the MIT License.