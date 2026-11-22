/**
 *  Morsel - Morse code reader.
 *  Created by Jan on 22 Nov 2026
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PrintHelp(const char* prog)
{
    printf("Morsel - Morse code reader.\nUsage:\n  %s <text>\n" \
           "  %s -d <morse>\n  %s -e <text>\n  %s -h or %s --help\n", prog, prog, prog, prog, prog);

    return;
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 3)
    {
        fprintf(stderr, "%s: Invalid number of arguments.\nUsage: '-h' or '--help' to show help.\n", argv[0]);
        return EXIT_FAILURE;
    }

    else if (argc == 2)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            PrintHelp(argv[0]);
            return EXIT_SUCCESS;
        }

        else
        {
            // encode the text (arg1) to morse
            return EXIT_SUCCESS;
        }
    }

    else // app + 2 args
    {
        if (strcmp(argv[1], "-d") == 0)
        {
            // decode morse code
            return EXIT_SUCCESS;
        }

        else if (strcmp(argv[1], "-e") == 0)
        {
            // encode plain text
            return EXIT_SUCCESS;
        }

        else
        {
            // invalid arguments
            fprintf(stderr, "%s: Invalid argument '%s'.\nExpected '-d' or '-e'.\n", argv[0], argv[1]);
            return EXIT_FAILURE;
        }
    }

    // redundant return statement just in case
    return EXIT_SUCCESS;
}