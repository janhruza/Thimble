# Numerous

A small command-line calculator written in C. The first argument selects the calculation, and the remaining arguments are passed to it. It works directly from the terminal and in scripts.

## Structure

```
Numerous/
├── Numerous.c
├── README.md
├── LICENSE.md
├── inc /
│   ├── macros.h
│   ├── dist.c
│   ├── dist.h
│   └── ...
└── bin/
    └── calc
```

The source file is `Numerous.c`, and the compiled executable is `bin/calc`.

## Build

From inside the `Numerous/` folder:

```sh
mkdir -p bin
gcc -Wall -Wextra -o bin/calc Numerous.c -lm
```

The `-lm` flag links the math library, which provides functions like `sqrt()` and `pow()`. It must come after the source file, because the linker reads libraries in order.

## Usage

```sh
calc <command> [arguments...]
```

Subcommands will be documented here as they are added.

## Run

```sh
./bin/calc
```

## License

This project is licensed under the MIT License.