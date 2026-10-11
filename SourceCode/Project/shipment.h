#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <stdio.h>
#include "mapping.h"

#define NUM_TRUCKS 3
#define MAX_WEIGHT 2000
#define MAX_VOLUME 20

/**
* ENUM NAME: Color
* -- A enum type to identify the truck color(id)
*/
enum Color
{
	blue, green, yellow
};

/**
 * STRUCT NAME: Truck
 * -- Truck structure to store the truck information
 * @param m_color - truck color used as ID to identify the truck (blue, green, yellow);
 * @param m_weight - truck capacity;
 * @param m_volume - truck volume;
 * @param m_route - truck route;
 */
struct Truck
{
	enum Color m_color;
	int m_currentWeight;
	double m_currentVolume;
	struct Route m_route;
};

/**
 * STRUCT NAME: Shipment
 * -- Shipment structure to store the shipment information
 * @param m_weight - shipment weight;
 * @param m_size - shipment size;
 * @param m_dest - destination point;
 */
struct Shipment
{
	int m_weight;
	double m_size;
	struct Point m_dest;
	struct Route diversionPath;
};


/**
 * NAME: isValidWeight
 * -- Check if the input weight for shipment is valid
 * @param weight - shipment weight
 * @return 1 if the weight is valid, 0 otherwise
 */
int isValidWeight(int weight);

/**
 * NAME: isValidSize
 * -- Check if the input size for shipment is valid
 * @param size - shipment size
 * @return 1 if the size is valid, 0 otherwise
 */
int isValidSize(double boxSize);

/**
 * NAME: isValidDestination
 * -- Check if the input destination for shipment is valid
 * @param *dest - a pointer that points to a shipment destination coordinate
 * @return 1 if the destination is valid, 0 otherwise
 */
int isValidDestination(struct Point* dest);

/**
 * NAME: checkCurrentWeight
 * -- Check if a truck has enough capacity to carry the shipment
 * @param *truck - a pointer that points to a truck struct
 * @param weight - shipment weight
 * @return 1 if the current capacity plus the weight of the shipment is less than
 *	or equal to the maximum capacity of the truck, 0 otherwise
 */
int checkCurrentWeight(struct Truck* truck, int weight);

/**
 * NAME: checkCurrentVolume
 * -- Check if a truck has enough volume to carry the shipment
 * @param *truck - a pointer that points to a truck struct
 * @param boxSize - shipment size
 * @return 1 if the current volume plus the size of the shipment is less than
 *	or equal to the maximum volume of the truck, 0 otherwise
 */
int checkCurrentVolume(struct Truck* truck, double boxSize);

/**
 * NAME: isTruckAvailable
 * -- Check if a truck is available to carry the shipment
 * @param *truck - a pointer that points to a truck struct
 * @param *shipment - a pointer that points to a shipment struct
 * @return 1 if the truck is available to carry the shipment, 0 otherwise
 */
int isTruckAvailable(struct Truck* truck, const struct Shipment* shipment);

/**
 * NAME: determineLimitingFactor
 * -- determine if the limiting factor for the truck is weight or volume
 * @param *truck - a pointer that points to a truck
 * @param *shipment - a pointer that points to a shipment
 * @return the percentage of the determined limiting factor
 */
double findLimitingPercentage(struct Truck* truck, struct Shipment* shipment);

/**
 * NAME: findTruckForShipment
 * -- Find the appropriate truck for the shipment
 * @param *map - a pointer that points to the map, where points and buildings are stored
 * @param truckList[] - an array of trucks
 * @param numTrucks - the number of trucks in the truckList array
 * @param *shipment - a pointer that points to the shipment struct
 * @return the index of the truck in the truckList that is appropriate for the shipment
 *	if no truck can take the shipment, return -1
 */
int findTruckForShipment(struct Map* map, struct Truck truckList[], int numTrucks, struct Shipment* shipment);

/**
 * NAME: addShipmentToTruck
 * -- Add a shipment to a truck
 * @param *truck - a pointer that points to a truck
 * @param *shipment - a pointer that points to a shipment
 * @return 1 for success, 0 for fail
 */
int addShipmentToTruck(struct Truck* truck, const struct Shipment* shipment);

/**
<<<<<<< HEAD
 * NAME: findStartPoint
 * -- Find the start point for the truck to reach the destination
 * @param *map - a pointer that points to the map struct
 * @param *route - a pointer that points to the route struct
 * @param *dest - a pointer that points to the destination point
 * @return the start point for the truck to reach the destination
 */
int findStartPoint(const struct Map* map, struct Route* route, const struct Point* dest);

/**
 * NAME: getFinalPath
 * -- Get the final path for the truck to reach the destination
 * @param *map - a pointer that points to the map struct
 * @param *start - a pointer that points to the start point
 * @param *dest - a pointer that points to the destination point
 * @param *route - a pointer that points to the route struct
 * @return 1 if the final path is found, 0 otherwise
 */
int getFinalPath(const struct Map* map, const struct Point* start, const struct Point* dest, struct Route* route);

/** NAME: printRoute
 * -- Print the route
 * @param *route - a pointer that points to the route struct
 * @param *dest - a pointer that points to the destination point
 * @param *map - a pointer that points to the map struct
 */
void printRoute(const struct Map* map, struct Truck* truck, struct Shipment shipment);


#endif // SHIPMENT_H
