# Morsel

A small command-line Morse code translator written in C. It encodes text to Morse code, and with `-d` it decodes Morse code back to text. It takes its input as arguments, so it works directly from the terminal or in scripts.

## Structure

The source file is `Morsel.c`, and the compiled executable is `bin/morse`.

## Usage

```sh
morse <text> # equivalent to morse -e <text>
morse -d <morse>
morse -e <text>
morse -h
morse --help
```

- `text`: the text to encode. Letters, digits, and spaces are supported, and letters are case-insensitive.
- `-d <morse>`: decodes Morse code back to text. Letters are separated by a single space and words by `/`.
- `-h` or `--help`: prints a short usage message

## Examples

```sh
morse "SOS"
# ... --- ...

morse "Hello World"
# .... . .-.. .-.. --- / .-- --- .-. .-.. -..

morse -d "... --- ..."
# SOS
```

## Build

From inside the `Morsel/` folder:

```sh
mkdir -p bin
gcc -Wall -Wextra -o bin/morse Morsel.c
```

## Run

```sh
./bin/morse "SOS"
```

## License

This project is licensed under the MIT License.