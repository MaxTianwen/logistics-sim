#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mapping.h"

#define LIST_CAPACITY 4

/**
* Node in the A* algorithm.
* @param point - the point in the map
* @param parent - the parent node
* @param f - total cost
* @param g - cost from start to current point
* @param h - cost from current point to destination
*/
typedef struct Node
{
	struct Point point;
	struct Node* parent;
	double f;
	double g;
	double h;
} Node, *pNode;

/**
* A list of points that are open for consideration in the A* algorithm.
* @param points - the list of points
* @param numPoints - the number of points in the list
* @param capacity - the maximum number of points that can be stored in the list
*/
typedef struct OpenList
{
	struct Point points[LIST_CAPACITY];
	int numPoints;
	int capacity;
} OpenList, *pOpenList;




#endif // !UTILS_H

