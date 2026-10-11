#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "shipment.h"


int main(void)
{
	// Initialize the map
	struct Map map = populateMap();

	// Initialize the routes of the trucks
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	struct Map routeMap = addRoute(&map, &blueRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);
	routeMap = addRoute(&routeMap, &greenRoute);

	// Initialize the trucks
	struct Truck trucks[NUM_TRUCKS] =
	{
		{blue, 0, 0.0, blueRoute},
		{green, 0, 0.0, greenRoute},
		{yellow, 0, 0.0, yellowRoute}
	};

	// Variables for the input shipment
	int weight = -1;
	double size = -1;
	int row = -1;
	char colStr = 'Z';

	/* Output */
	// The header
	printf("=================\n");
	printf("Seneca Polytechnic Deliveries:\n");
	printf("=================\n");

	// The main loop
	while (1)
	{
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		if (scanf(" %d %lf %d%c", &weight, &size, &row, &colStr) != 4)
		{
			// Check if the input is 0 0 x
			if (weight == 0 && size == 0 && getchar() == 'x')
			{
				// Exit the loop
				break;
			}

			// Clear the buffer if the input is invalid
			while (getchar() != '\n');
			continue;
		}

		struct Shipment shipment = { weight, size, {row - 1, colStr - 'A'} };
		// Find the appropriate truck for the shipment
		int truckIdx = findTruckForShipment(&map, trucks, NUM_TRUCKS, &shipment);

		// Chek if the truck is found
		if (truckIdx >= 0)
		{
			// Print the truck color
			const char* colors[] = { "BLUE", "GREEN", "YELLOW" };
			printf("Ship on %s LINE, ", colors[trucks[truckIdx].m_color]);

			// Print the route and the diversion path
			printRoute(&map, &trucks[truckIdx], shipment);
		}
	}

	printf("Thanks for shipping with Seneca Polytechnic!\n");
	return 0;
}
