//
// Created by Jan on 24 Nov 2026
//

#ifndef DIST_H
#define DIST_H

/**
 * @brief Calculates the distance between two points in a 2D space.
 * @param p1x The X coordinate of the first point.
 * @param p1y The Y coordinate of the first point.
 * @param p2x The X coordinate of the second point.
 * @param p2y The Y coordinate of the second point.
 * @return The distance between these two points.
 */
double dist(int p1x, int p1y, int p2x, int p2y);

/**
 * @brief Calculates the distance between two points in a 2D space.
 * @param p1x The X coordinate of the first point.
 * @param p1y The Y coordinate of the first point.
 * @param p2x The X coordinate of the second point.
 * @param p2y The Y coordinate of the second point.
 * @param p1z The Z coordinate of the first point.
 * @param p2z The Z coordinate of the second point.
 * @return The distance between these two points.
 */
double dist3(int p1x, int p1y, int p1z, int p2x, int p2y, int p2z);

void dist_help(void);

#endif