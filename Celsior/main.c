/*
 *  Created by Jan on 22 Nov 2026
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "temperature.h"

void PrintHelp(char* prog)
{
    printf("%s: Invalid arguments.\n\nUsage: %s <value> <from> <to>, where:" \
           "\n  <value> - Temperature in the source unit\n  <from>  - Source unit" \
           "\n  <to>    - Target unit\n", prog, prog);
}

char* unit_names[TEMP_INVALID] = {
    "degrees Celsius", "Fahrenheit", "Kelvin"
};

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "%s: No arguments passed.\nUse '-h' or '--help' to show help.\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        // show help (on purpose)
        PrintHelp(argv[0]);
        return EXIT_SUCCESS;
    }

    if (argc != 4)
    {
        fprintf(stderr, "%s: Not enough arguments have been passed.\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strlen(argv[2]) < 1 || strlen(argv[3]) < 1)
    {
        PrintHelp(argv[0]);
        return EXIT_FAILURE;
    }

    double value = strtod(argv[1], NULL);
    char source = argv[2][0];
    char target = argv[3][0];

    int temp_src = GetTempUnit(source);
    int temp_dst = GetTempUnit(target);

    double output = TempConvert(temp_src, temp_dst, value);
    if (output == TEMP_ERROR)
    {
        fprintf(stderr, "%s: Conversion error.\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("%.2lf %s is equal to %.2lf %s\n", value, unit_names[temp_src], output, unit_names[temp_dst]);
    return EXIT_SUCCESS;
}