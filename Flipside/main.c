/*
 *  Flipside - Simple coin flipper.
 *  Created by Jan on 22 Now 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum
{
    COIN_HEADS,
    COIN_TAILS
};

void PrintHelp(const char *prog)
{
    printf("Flipside - Simple coin flipper.\nUsage: '%s' without any arguments.\n", prog);
    return;
}

int CoinFlip(void)
{
    return rand() % 2;
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    if (argc == 1)
    {
        // flip a coin
        int result = CoinFlip();
        switch (result)
        {
            case COIN_HEADS:
                puts("Heads");
                break;

            case COIN_TAILS:
                puts("Tails");
                break;

            default:
                fprintf(stderr, "%s: Invalid pick: %d\n", argv[0], result);
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        PrintHelp(argv[0]);
        return EXIT_SUCCESS;
    }

    else
    {
        fprintf(stderr, "%s: Invalid arguments.\nOnly '-h' or '--help' is allowed.\n", argv[0]);
        return EXIT_FAILURE;
    }
}