/**
 *  Numerous
 *  Created by Jan on 24 Nov 2026
*/

#include <stdlib.h>
#include <stdio.h>

#include "inc/macros.h"

void PrintHelp(const char *prog)
{
    fprintf(stderr, "%s: No arguments passed.\nUse %s -h or --help for help.\n", prog, prog);
    return;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        PrintHelp(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}