# Bodymetric

A small command-line tool written in C that calculates body mass index (BMI) from weight and height and shows the matching category. It takes its input as arguments, so it works directly from the terminal or in scripts.

## Structure

```
Bodymetric/
├── Bodymetric.c
├── README.md
├── LICENSE.md
└── bin/
    └── bmi
```

The source file is `Bodymetric.c`, and the compiled executable is `bin/bmi`.

## Usage

```sh
bmi <weight_kg> <height_cm>
```

- `weight_kg`: body weight in kilograms, as a number
- `height_cm`: height in meters, as a number (for example, `175`)

## Examples

```sh
bmi 70 175    # BMI: 22.86 (Normal weight)
bmi 90 170    # BMI: 31.14 (Obese)
```

## Categories

| BMI | Category |
|-----|----------|
| Below 16 | Heavy underweight |
| 16.0 to 16.9 | Medium underweight |
| Below 18.5 | Underweight |
| 18.5 to 24.9 | Normal weight |
| 25.0 to 29.9 | Overweight |
| 30.0 to 34.9 | Obesity (type 1) |
| 35.0 to 39.9 | Obesity (type 2) |
| Above 40 | Morbid obesity |

These categories follow the WHO adult classification. BMI is a rough screening measure and doesn't account for muscle mass, age, or body composition.

## Build

Bodymetric uses the standard math library. From inside the `Bodymetric/` folder:

```sh
mkdir -p bin
gcc -Wall -Wextra -lm -o bin/bmi Bodymetric.c
```

## Run

```sh
./bin/bmi 70 175
```

## License

This project is licensed under the MIT License.