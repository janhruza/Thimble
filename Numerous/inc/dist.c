#include "dist.h"

#include <math.h>
#include <stdio.h>

double dist(int p1x, int p1y, int p2x, int p2y)
{
    // vector distance
    return sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2));
}

double dist3(int p1x, int p1y, int p1z, int p2x, int p2y, int p2z)
{
    return sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2) + pow(p2z - p1z, 2));
} 

void dist_help(void)
{
    printf("2D vector distance calculator\nUsage: 'dist [p1x] [p1y] [p2x] [p2y]' where\n" \
           "  p1x: The X coordinate of the first point.\n" \
           "  p1y: The Y coordinate of the first point.\n" \
           "  p2x: The X coordinate of the second point.\n" \
           "  p2y: The Y coordinate of the second point.\n\n" \
        "Example: 'dist 5 2 3 4' -> 2.828427\n");
    return;
}