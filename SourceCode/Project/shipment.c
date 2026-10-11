#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <string.h>
#include "shipment.h"

// Water Fill Algorithm Map for route finding 
const struct Map waterFill = {
	//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
	//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//0
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//1
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//2
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//3
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//4
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//5
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//6
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//7
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//8
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//9
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//10
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//11
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//12
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//13
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//14
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//15
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//16
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//17
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//19
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//20
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//21
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//22
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//23
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}		//24
	},
	MAP_ROWS, MAP_COLS
};

/* Validation functions */
int isValidWeight(int weight)
{
	return (weight >= 1 && weight <= MAX_WEIGHT);
}

int isValidSize(double boxSize)
{
	return (boxSize == 0.5 || boxSize == 1 || boxSize == 2);
}

int isValidDestination(struct Point* dest)
{
	if (dest == NULL)
	{
		return 0;
	}
	return (dest->row >= 0 && dest->row < MAP_ROWS && dest->col >= 0 && dest->col < MAP_COLS);
}

int checkCurrentWeight(struct Truck* truck, int weight)
{
	return (truck->m_currentWeight + weight <= MAX_WEIGHT);
}

int checkCurrentVolume(struct Truck* truck, double boxSize)
{
	if ((truck == NULL) || (!isValidSize(boxSize)))
	{
		return 0;
	}
	return (truck->m_currentVolume + boxSize <= MAX_VOLUME);
}

int isTruckAvailable(struct Truck* truck, const struct Shipment* shipment)
{
	if ((truck == NULL) || (shipment == NULL))
	{
		return 0;
	}
	return (checkCurrentWeight(truck, shipment->m_weight) && checkCurrentVolume(truck, shipment->m_size));
}


/* Core Functions */
double findLimitingPercentage(struct Truck* truck, struct Shipment* shipment)
{
	if (!isTruckAvailable(truck,shipment))
	{
		return -1.0;
	}
	// Calculate the percentage
	double PerWeight = (double)(truck->m_currentWeight + shipment->m_weight) / MAX_WEIGHT;
	double PerVolume = (double)(truck->m_currentVolume + shipment->m_size) / MAX_VOLUME;

	// Return the higher percentage
	return (PerWeight > PerVolume) ? PerWeight : PerVolume;
}

int findTruckForShipment(struct Map* map, struct Truck truckList[], int numTrucks, struct Shipment* shipment)
{
	int selectedTruckIdx = -1;
	double shortestDist = MAX_MOVEMENTS;

	if (map == NULL || shipment == NULL)
	{
		return -1;
	}

	// Validate shipment destination
	if (!isValidDestination(&shipment->m_dest))
	{
		printf("Invalid destination\n");
		return -5;
	}

	// Validate shipment weight
	if (!isValidWeight(shipment->m_weight))
	{
		printf("Invalid weight (must be 1-2000 Kg.)\n");
		return -4;
	}

	// Validate shipment size
	if (!isValidSize(shipment->m_size))
	{
		printf("Invalid size (must be 0.5, 1, or 2)\n");
		return -3;
	}


	for (int i = 0; i < numTrucks; ++i)
	{
		// Check if the truck is available for the shipment
		if (!isTruckAvailable(&truckList[i], shipment))
		{
			continue;
		}

		// Get the closest point to the shipment destination
		int closestPointIdx = findStartPoint(map, &truckList[i].m_route, &(shipment->m_dest));
		if (closestPointIdx == -1)
		{
			continue;
		}
		struct Point closestPoint = truckList[i].m_route.points[closestPointIdx];
		struct Route currentRoute = { {{0, 0}}, 0, DIVERSION };

		// Get the route
		getFinalPath(map, &closestPoint, &shipment->m_dest, &currentRoute);

		// Calculate the distance from the closest point to the shipment destination
		int truckDist = currentRoute.numPoints;

		// Compare the current truck's distance to the closest distance
		// If the current truck's distance is shorter
		if (truckDist < shortestDist)
		{
			selectedTruckIdx = i;
			shortestDist = truckDist;
		}
		// If the current truck's distance is equal to the closest distance
		else if (truckDist == shortestDist)
		{
			// Compare the limiting percetage of the two trucks
			double preTruckPer = findLimitingPercentage(&truckList[selectedTruckIdx], shipment);
			double curTruckPer = findLimitingPercentage(&truckList[i], shipment);

			// Check if the current truck has more space/weight available than the selected truck
			if (curTruckPer < preTruckPer)
			{
				selectedTruckIdx = i;
			}
		}
	}

	// Check if a truck is selected
	if (selectedTruckIdx == -1)
	{
		printf("No truck is available for the shipment. Item will be shipped tomorrow.\n");
		return -1;
	}
	else
	{
		// Add the shipment to the selected truck
		addShipmentToTruck(&truckList[selectedTruckIdx], shipment);
	}

	return selectedTruckIdx;
}

int addShipmentToTruck(struct Truck* truck, const struct Shipment* shipment)
{
	if (!isTruckAvailable(truck,shipment))
	{
		return 0;
	}

	truck->m_currentWeight += shipment->m_weight;
	truck->m_currentVolume += shipment->m_size;
	return 1;
}

int findStartPoint(const struct Map* map, struct Route* route, const struct Point* dest)
{
	int closestIdx = -1;
	int closestDist = MAX_MOVEMENTS;

	if (map == NULL || route == NULL || dest == NULL)
	{
		return -1;
	}

	for (int i = 0; i < route->numPoints; ++i)
	{
		struct Route diversionRoute = { {{0, 0}}, 0, DIVERSION };
		if (getFinalPath(map, &(route->points[i]), dest, &diversionRoute))
		{
			if (diversionRoute.numPoints < closestDist)
			{
				closestDist = diversionRoute.numPoints;
				closestIdx = i;
			}
		}
	}

	return closestIdx;
}

int getFinalPath(const struct Map* map, const struct Point* start, const struct Point* dest, struct Route* route)
{
	struct Route possible = { {{0, 0}}, 0, DIVERSION };
	struct Map newMap = waterFill;
	struct Map* pNewMap = &newMap;
	int isArrived = 0;

	if (map == NULL || start == NULL || dest == NULL || route == NULL)
	{
		return 0;
	}
	// Set the current route to empty
	*route = possible;

	// Check if there is an available path from the start point to the destination
	isArrived = searchPath(start->row, start->col, dest->row, dest->col, map, pNewMap);

	// Find the shortest path from the start point to the destination on the water fill map if there
	// is an available path
	if (isArrived)
	{
		if (getShortestPath(pNewMap, *start, *dest, route) == 0)
		{
			isArrived = 0;
		}
	}

	return isArrived;
}

/* Print functions */
void printRoute(const struct Map* map, struct Truck* truck, struct Shipment shipment)
{
	struct Route diversionPath = { {{0, 0}}, 0, DIVERSION };

	if (map == NULL || truck == NULL)
	{
		return ;
	}


	int closesetIdx = findStartPoint(map, &truck->m_route, &(shipment.m_dest));
	if (closesetIdx != -1)
	{
		if (distance(&truck->m_route.points[closesetIdx], &shipment.m_dest) == 1)
		{
			printf("no diversion\n");
		}
		else if (getFinalPath(map, &truck->m_route.points[closesetIdx], &shipment.m_dest, &diversionPath))
		{
			printf("divert: %d%c, ", truck->m_route.points[closesetIdx].row + 1, 'A' + truck->m_route.points[closesetIdx].col);
			for (int i = 0; i < diversionPath.numPoints; ++i)
			{
				printf("%d%c", diversionPath.points[i].row + 1, 'A' + diversionPath.points[i].col);
				if (i < diversionPath.numPoints - 1)
				{
					printf(", ");
				}
			}
			putchar('\n');
		}
	}
}
