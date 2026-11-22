# Thimble

A collection of small, practical command-line tools written in C. Each tool takes its input as arguments, so it works directly from the terminal and in scripts.

## Tools

| Tool | Description | Usage |
|------|-------------|-------|
| [Celsior](Celsior/README.md) | Converts temperatures between Celsius, Fahrenheit, and Kelvin | `temp <value> <from> <to>` |

More tools will be added over time.

## Structure

Each tool lives in its own PascalCase folder with a single source file. Compiled binaries go in a `bin/` folder inside that tool's folder.

```
Thimble/
├── README.md
├── LICENSE.md
├── Celsior/
│   ├── Celsior.c
│   ├── README.md
│   └── bin/
│       └── temp
└── ...
```

## Building

Each tool is built on its own. From inside a tool's folder:

```sh
mkdir -p bin
gcc -Wall -Wextra -o bin/<name> <Source>.c
```

See each tool's README for its exact build and usage instructions.

## License

This project is licensed under the MIT License. See [LICENSE.md](LICENSE.md) for details.