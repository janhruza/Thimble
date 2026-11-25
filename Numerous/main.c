/**
 *  Numerous
 *  Created by Jan on 24 Nov 2026
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PrintHelp(const char *prog)
{
    fprintf(stderr, "%s: No arguments passed.\nUse %s -h or --help for help.\n", prog, prog);
    return;
}

void InvalidSwitch(const char *prog, const char *arg)
{
    fprintf(stderr, "%s: Invalid argument: '%s'\n", prog, arg);
    return;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        PrintHelp(argv[0]);
        return EXIT_FAILURE;
    }

    switch (argc)
    {
        case 2:
        {
            if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
            {
                PrintHelp(argv[0]);
                return EXIT_SUCCESS;
            }

            else
            {
                InvalidSwitch(argv[0], argv[1]);
                return EXIT_FAILURE;
            }
        }

        default:
        {
            // any other argument count
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}