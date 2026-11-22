/*
 *  Bodymetric - Simple BMI calculator
 *  Created by Jan on 22 Nov 2026
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

enum
{
    BMI_HEAVY_UNDERWEIGHT,
    BMI_MEDIUM_UNDERWEIGHT,
    BMI_UNDERWEIGHT,
    BMI_NORMAL,
    BMI_OVERWEIGHT,
    BMI_OBESITY,
    BMI_OBESITY2,
    BMI_OBESITY3,
    BMI_LAST
};

char* bmi_str[BMI_LAST] = {
   "Heavy underweight", "Medium underweight", "Light underweight", "Normal",
   "Overweight", "Obesity (type 1)", "Obesity (type 2)", "Morbid obesity"
};

void PrintHelp(const char *prog)
{
   printf("Bodymetric - Simple BMI calculator\nUsage: '%s <weight> <height>', where\n" \
      "  <weight> - Weight in kilograms\n  <height> - Height in centimeters\n", prog);
}

double CalculateBMI(double weight, double height)
{
   return weight / pow((height / 100), 2);
}

int GetBMIClass(double bmi)
{
   if (bmi < 16.005)
   {
      return BMI_HEAVY_UNDERWEIGHT;
   }

   else if (bmi >= 16.005 && bmi < 17)
   {
      return BMI_MEDIUM_UNDERWEIGHT;
   }

   else if (bmi >= 17 && bmi < 18.5)
   {
      return BMI_UNDERWEIGHT;
   }

   else if (bmi >= 18.5 && bmi < 25)
   {
      return BMI_NORMAL;
   }

   else if (bmi >= 25 && bmi < 30)
   {
      return BMI_OVERWEIGHT;
   }

   else if (bmi >= 30 && bmi < 35)
   {
      return BMI_OBESITY;
   }

   else if (bmi >= 35 && bmi < 40)
   {
      return BMI_OBESITY2;
   }

   else if (bmi >= 40)
   {
      return BMI_OBESITY3;
   }

   else
   {
      // invalid
      return BMI_LAST;
   }
}

double ReadDoubleFromArg(const char* arg)
{
    char* end;

    errno = 0;
    double val = strtod(arg, &end);

    if (end == arg || *end != '\0') return -1;
    if (errno == ERANGE) return -1;
    if (!(val >= 0)) return -1;

    return val;
}

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      fprintf(stderr, "%s: No arguments passed.\nUse '-h' or '--help' to show help.\n", argv[0]);
      return EXIT_FAILURE;
   }

   if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
   {
      PrintHelp(argv[0]);
      return EXIT_SUCCESS;
   }

   if (argc != 3)
   {
      fprintf(stderr, "%s: Invalid number of arguments.\n", argv[0]);
      return EXIT_FAILURE;
   }

   // usage: bmi <weight> <height>
   double weight = ReadDoubleFromArg(argv[1]);
   double height = ReadDoubleFromArg(argv[2]);

   if (height == -1 || weight == -1)
   {
      fprintf(stderr, "%s: Invalid input.\n", argv[0]);
      return EXIT_FAILURE;
   }

   double bmi = CalculateBMI(weight, height);
   int bmi_class = GetBMIClass(bmi);
   if (bmi_class == BMI_LAST)
   {
      // internal conversion error
      fprintf(stderr, "%s: Value %lf is outside of any valid range.\n", argv[0], bmi);
      return EXIT_FAILURE;
   }

   printf("Your BMI is %.2lf which corresponds to the '%s' class.\n", bmi, bmi_str[bmi_class]);
   return EXIT_SUCCESS;
}