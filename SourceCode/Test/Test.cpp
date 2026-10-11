#include "pch.h"
#include "project_r.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BlackBoxTest
{
    /* Function : isValidWeight */
    TEST_CLASS(BBT001)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            int weight = 50;
            Assert::AreEqual(1, isValidWeight(weight));
        };
        // Case 2: Lower Bound
        TEST_METHOD(LowerBound)
        {
            int weight = 1;
            Assert::AreEqual(1, isValidWeight(weight));
        };
        // Case 3: Upper Bound
        TEST_METHOD(UpperBound)
        {
            int weight = 2000;
            Assert::AreEqual(1, isValidWeight(weight));
        };
        // Case 4: Minimum Value - 1
        TEST_METHOD(MinValue)
        {
            int weight = 0;
            Assert::AreEqual(0, isValidWeight(weight));
        };
        // Case 5: Maximum Value + 1
        TEST_METHOD(MaxValue)
        {
            int weight = 2001;
            Assert::AreEqual(0, isValidWeight(weight));
        };
        // Case 6: Negative Value
        TEST_METHOD(NegativeValue)
        {
            int weight = -1;
            Assert::AreEqual(0, isValidWeight(weight));
        };
    };

    /* Function : isValidSize */
    TEST_CLASS(BBT002)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            double size = 1;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 2: Lower Bound
        TEST_METHOD(LowerBound)
        {
            double size = 0.5;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 3: Upper Bound
        TEST_METHOD(UpperBound)
        {
            double size = 2;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 4: <0.5
        TEST_METHOD(MinValue)
        {
            double size = 0;
            Assert::AreEqual(0, isValidSize(size));
        };
        // Case 5: Maximum Value + 1
        TEST_METHOD(MaxValue)
        {
            double size = 3;
            Assert::AreEqual(0, isValidSize(size));
        };
        // Case 6: Negative Value
        TEST_METHOD(NegativeValue)
        {
            double size = -1;
            Assert::AreEqual(0, isValidSize(size));
        };
    };

    /* Function : isValidDestination */
TEST_CLASS(BBT003)
    {
    public:
        TEST_METHOD(NormalSpace)
        {
            struct Point dest = { 11, 11 };  // row 12, column 'L'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(MinRowAndCol)
        {
            struct Point dest = { 0, 0 };  // row 1, column 'A'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(MaxRowAndCol)
        {
            struct Point dest = { 24, 24 };  // row 25, column 'Y'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(MinRowMaxCol)
        {
            struct Point dest = { 0, 24 };  // row 1, column 'Y'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(MaxRowMinCol)
        {
            struct Point dest = { 24, 0 };  // row 25, column 'A'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(BuildingLocation)
        {
            struct Point dest = { 1, 1 };  // row 2, column 'B'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

        TEST_METHOD(RowExceedsMax)
        {
            struct Point dest = { 25, 12 };  // row 26, column 'M'
            Assert::AreEqual(0, isValidDestination(&dest));
        }

        TEST_METHOD(ColExceedsMax)
        {
            struct Point dest = { 11, 25 };  // row 12, column 'Z'
            Assert::AreEqual(0, isValidDestination(&dest));
        }

        TEST_METHOD(RowZero)
        {
            struct Point dest = { -1, 12 };  // row 0, column 'M'
            Assert::AreEqual(0, isValidDestination(&dest));
        }

        TEST_METHOD(ColBeforeA)
        {
            struct Point dest = { 11, -1 };  // row 12, column '@'
            Assert::AreEqual(0, isValidDestination(&dest));
        }

        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, isValidDestination(nullptr));
        }
    };

    /* Function : checkCurrentWeight */
    TEST_CLASS(BBT004)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            struct Truck truck = { blue,1000,10,{{},0,'\0'} };
            int weight = 200;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 2: Empty truck, max shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue,0,10,{{},0,'\0'} };
            int weight = 2000;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 3: Empty truck, minimum shipment
        TEST_METHOD(EmptyTruckMinShipment)
        {
            struct Truck truck = { blue,0,10,{{},0,'\0'} };
            int weight = 1;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 4: Half full truck, max/2 shipment
        TEST_METHOD(HalfTruckHalfMaxShipment)
        {
            struct Truck truck = { blue,988,10,{{},0,'\0'} };
            int weight = 1012;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 5: Full Truck Minimum Shipment
        TEST_METHOD(FullTruckMinShipment)
        {
            struct Truck truck = { blue,2000,10,{{},0,'\0'} };
            int weight = 1;
            Assert::AreEqual(0, checkCurrentWeight(&truck, weight));
        };
        // Case 6: Min Truck, max shipment
        TEST_METHOD(MinTruckMaxShipment)
        {
            struct Truck truck = { blue,1,10,{{},0,'\0'} };
            int weight = 2000;
            Assert::AreEqual(0, checkCurrentWeight(&truck, weight));
        };
        // Case 7: Max-1 Truck, minimum shipment
        TEST_METHOD(MaxMinus1TruckMinShipment)
        {
            struct Truck truck = { blue,1999,10,{{},0,'\0'} };
            int weight = 1;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
    };

    /* Function : checkCurrentVolume */
     TEST_CLASS(BBT005)
    {
    public:
        // Case 1: Empty Truck
        TEST_METHOD(EmptyTruck)
        {
            struct Truck truck = { blue, 0, 0.0, {{}, 0, '\0'} };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1));  // boxSize = 1 (0.5 cubic meters)
        }

        // Case 2: Partially Filled
        TEST_METHOD(PartiallyFilled)
        {
            struct Truck truck = { blue, 0, 10.0, {{}, 0, '\0'} };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1));  // boxSize = 1 (0.5 cubic meters)
        }

        // Case 3: Exact Capacity
        TEST_METHOD(ExactCapacity)
        {
            struct Truck truck = { blue, 0, 19, {{}, 0, '\0'} };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1));  // boxSize = 1 (0.5 cubic meters)
        }

        // Case 4: Exceeds Capacity
        TEST_METHOD(ExceedsCapacity)
        {
            struct Truck truck = { blue, 0, 19.5, {{}, 0, '\0'} };
            Assert::AreEqual(0, checkCurrentVolume(&truck, 2));  // boxSize = 2 (1.0 cubic meters)
        }

        // Case 5: NULL Pointer
        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, checkCurrentVolume(nullptr, 1));
        }

        // Case 6: Invalid Box Size
        TEST_METHOD(InvalidBoxSize)
        {
            struct Truck truck = { blue, 0, 10.0, {{}, 0, '\0'} };
            Assert::AreEqual(0, checkCurrentVolume(&truck, 4));  // invalid box size
        }
    };
    /* Function : isTruckAvailable */
    TEST_CLASS(BBT006)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            struct Truck truck = { blue,70,10,{{},0,'\0'} };
            struct Shipment shipment = { 20,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 2: Exceed Space Limit
        TEST_METHOD(ExceedSpaceLimit)
        {
            struct Truck truck = { blue,70,18.5,{{},0,'\0'} };
            struct Shipment shipment = { 20,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 3: Exceed Weight Limit
        TEST_METHOD(ExceedWeightLimit)
        {
            struct Truck truck = { blue,700,10,{{},0,'\0'} };
            struct Shipment shipment = { 1500,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 4: Exceed both limits
        TEST_METHOD(ExceedBothLimits)
        {
            struct Truck truck = { blue,700,19,{{},0,'\0'} };
            struct Shipment shipment = { 1500,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 5: Empty Truck Minimum Shipment
        TEST_METHOD(EmptyTruckMinShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 6: Empty truck, max shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 2000,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 7: Truck has the Exact Space And Weight
        TEST_METHOD(ExactSpaceAndWeight)
        {
            struct Truck truck = { blue,1800,18,{{},0,'\0'} };
            struct Shipment shipment = { 200,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 8: Truck has the Exact Space Needed
        TEST_METHOD(ExactSpaceNeeded)
        {
            struct Truck truck = { blue,1100,18,{{},0,'\0'} };
            struct Shipment shipment = { 200,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 9: Truck has the Exact Weight Needed
        TEST_METHOD(ExactWeightNeeded)
        {
            struct Truck truck = { blue,1500,11,{{},0,'\0'} };
            struct Shipment shipment = { 500,1,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 10: Feeding null pointer
        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, isTruckAvailable(nullptr, nullptr));
        };
    };
// function : FindlimitingPercentage
TEST_CLASS(BBT007)
{
public:
    TEST_METHOD(TruckAtMaxCapacity)
    {
        struct Truck truck = {blue, 500, 0.0, {0, {}}};
        struct Shipment shipment = {500, 1.0, {0, 0}, {0, {}}};
        Assert::AreEqual(0.5, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(TruckWithZeroCapacity)
    {
        struct Truck truck = {green, 0, 0.0, {0, {}}};
        struct Shipment shipment = {100, 2.0, {0, 0}, {0, {}}};
        Assert::AreEqual(0.1, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(PartiallyFilledTruck)
    {
        struct Truck truck = {yellow, 250, 10.0, {0, {}}};
        struct Shipment shipment = {100, 1.0, {0, 0}, {0, {}}};
        Assert::AreEqual(0.55, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(ExceedingCapacity)
    {
        struct Truck truck = {blue, 300, 19.0, {0, {}}};
        struct Shipment shipment = {400, 2.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1.0, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(NullPointers)
    {
        Assert::AreEqual(-1.0, findLimitingPercentage(nullptr, nullptr), 0.01);
    }
};
// funciton : findTruckForShipment
TEST_CLASS(BBT008)
{
public:
    TEST_METHOD(ValidTruckFound)
    {
        struct Map map = populateMap();
        struct Route bRoute = getBlueRoute();
        struct Route gRoute = getGreenRoute();
        struct Truck trucks[] = {
            {blue, 300, 10.0, bRoute},
            {green, 500, 20.0, gRoute}
        };
        struct Shipment shipment = {100, 2.0, {4, 4}, {0, {}}};
        Assert::AreEqual(0, findTruckForShipment(&map, trucks, 2, &shipment));
    }

    TEST_METHOD(NoTruckAvailable)
    {
        struct Map map = {10};
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 300, 15.0, {0, {}}}};
        struct Shipment shipment = {400, 2.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1, findTruckForShipment(&map, trucks, 2, &shipment));
    }

    TEST_METHOD(NullMap)
    {
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 500, 30.0, {0, {}}}};
        struct Shipment shipment = {100, 1.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1, findTruckForShipment(nullptr, trucks, 2, &shipment));
    }

    TEST_METHOD(EmptyTruckList)
    {
        struct Map map = {10};
        struct Shipment shipment = {100, 1.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1, findTruckForShipment(&map, nullptr, 0, &shipment));
    }

    TEST_METHOD(NullShipment)
    {
        struct Map map = {10};
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 500, 30.0, {0, {}}}};
        Assert::AreEqual(-1, findTruckForShipment(&map, trucks, 2, nullptr));
    }
};
// function : addShipmentToTruck
TEST_CLASS(BBT009)
{
public:
    TEST_METHOD(ValidAddition)
    {
        struct Truck truck = {blue, 300, 10.0, {0, {}}};
        struct Shipment shipment = {100, 1.0, {0, 0}, {0, {}}};
        addShipmentToTruck(&truck, &shipment);
        Assert::AreEqual(400, truck.m_currentWeight);
        Assert::AreEqual(11.0, truck.m_currentVolume, 0.01);
    }

    TEST_METHOD(ExceedingCapacity)
    {
        struct Truck truck = {blue, 1800, 20.0, {0, {}}};
        struct Shipment shipment = {500, 5.0, {0, 0}, {0, {}}};
        addShipmentToTruck(&truck, &shipment);
        // Assert unchanged values as no addition should occur
        Assert::AreEqual(1800, truck.m_currentWeight);
        Assert::AreEqual(20.0, truck.m_currentVolume, 0.01);
    }

    TEST_METHOD(NullTruck)
    {
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        addShipmentToTruck(nullptr, &shipment);
        // Expect no crash
    }

    TEST_METHOD(NullShipment)
    {
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        addShipmentToTruck(&truck, nullptr);
        // Expect no crash
    }
};

//function :findStartPoint

TEST_CLASS(BBT010)
{
public:
    TEST_METHOD(ValidInputs)
    {
        struct Map map = populateMap();
        struct Route route = getBlueRoute();
        struct Point dest = {4, 4};
        Assert::AreEqual(8, findStartPoint(&map, &route, &dest));
    }

    TEST_METHOD(DestinationOutOfBounds)
    {
        struct Map map = {10};
        struct Route route = {0};
        struct Point dest = {25, 5}; // Row out of bounds
        Assert::AreEqual(-1, findStartPoint(&map, &route, &dest));
    }

    TEST_METHOD(NullMap)
    {
        struct Route route = {0};
        struct Point dest = {5, 5};
        Assert::AreEqual(-1, findStartPoint(nullptr, &route, &dest));
    }

    TEST_METHOD(NullRoute)
    {
        struct Map map = {10};
        struct Point dest = {5, 5};
        Assert::AreEqual(-1, findStartPoint(&map, nullptr, &dest));
    }

    TEST_METHOD(NullDestination)
    {
        struct Map map = {10};
        struct Route route = {0};
        Assert::AreEqual(-1, findStartPoint(&map, &route, nullptr));
    }
};

//funciton :getFinalPath
TEST_CLASS(BBT011)
{
public:
    TEST_METHOD(ValidPathExists)
    {
        struct Map map = populateMap();
        struct Point start = {4, 3};
        struct Point end = {4, 4};
        struct Route route = getBlueRoute();
        Assert::AreEqual(1, getFinalPath(&map, &start, &end, &route));
    }

    TEST_METHOD(NoValidPath)
    {
        struct Map map = {10};
        struct Point start = {0, 0};
        struct Point end = {25, 25}; // Out of bounds
        struct Route route = {0};
        Assert::AreEqual(0, getFinalPath(&map, &start, &end, &route));
    }

    TEST_METHOD(NullMap)
    {
        struct Point start = {0, 0};
        struct Point end = {5, 5};
        struct Route route = {0};
        Assert::AreEqual(0, getFinalPath(nullptr, &start, &end, &route));
    }

    TEST_METHOD(NullStart)
    {
        struct Map map = {10};
        struct Point end = {5, 5};
        struct Route route = {0};
        Assert::AreEqual(0, getFinalPath(&map, nullptr, &end, &route));
    }

    TEST_METHOD(NullEnd)
    {
        struct Map map = {10};
        struct Point start = {0, 0};
        struct Route route = {0};
        Assert::AreEqual(0, getFinalPath(&map, &start, nullptr, &route));
    }

    TEST_METHOD(NullRoute)
    {
        struct Map map = {10};
        struct Point start = {0, 0};
        struct Point end = {5, 5};
        Assert::AreEqual(0, getFinalPath(&map, &start, &end, nullptr));
    }
};

// function : printRoute
TEST_CLASS(BBT012)
{
public:
    TEST_METHOD(ValidInputs)
    {
        struct Map map = {10};
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, &truck, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(EmptyRoute)
    {
        struct Map map = {10};
        struct Truck truck = {green, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, &truck, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(NullMap)
    {
        struct Truck truck = {yellow, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(nullptr, &truck, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(NullTruck)
    {
        struct Map map = {10};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, nullptr, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(NullShipment)
    {
        struct Map map = {10};
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        printRoute(&map, &truck, {0, 0, {0, 0}, {0, {}}});
        // Expect no crash; manual verification required for output
    }
};
}

namespace WhiteBoxTest
{
    /* Function : isValidWeight */
    TEST_CLASS(WBT001)
    {
    public:
        // Case 1: weight < 1
        TEST_METHOD(WeightLessThanOne)
        {
            int weight = 0;
            Assert::AreEqual(0, isValidWeight(weight));
        }

        // Case 2: weight > MAX_WEIGHT
        TEST_METHOD(WeightGreaterThanMax)
        {
            int weight = 2001;
            Assert::AreEqual(0, isValidWeight(weight));
        };

        // Case 3: weight == 1 (minimum)
        TEST_METHOD(WeightEqualsOne)
        {
            int weight = 1;
            Assert::AreEqual(1, isValidWeight(weight));
        };

        // Case 4: weight == MAX_WEIGHT
        TEST_METHOD(WeightEqualsMax)
        {
            int weight = 2000;
            Assert::AreEqual(1, isValidWeight(weight));
        };

        // Case 5: 1 < weight < MAX_WEIGHT
        TEST_METHOD(WeightInValidRange)
        {
            int weight = 1000;
            Assert::AreEqual(1, isValidWeight(weight));
        };
    };

    /* Function : isValidSize */
    TEST_CLASS(WBT002)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            double size = 1;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 2: Lower Bound
        TEST_METHOD(LowerBound)
        {
            double size = 0.5;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 3: Upper Bound
        TEST_METHOD(UpperBound)
        {
            int size = 2;
            Assert::AreEqual(1, isValidSize(size));
        };
        // Case 4: <0.5
        TEST_METHOD(MinValue)
        {
            int size = 0;
            Assert::AreEqual(0, isValidSize(size));
        };

        // Case 5: Middle Value
        TEST_METHOD(MiddleValue)
        {
            double size = 1.5;
            Assert::AreEqual(0, isValidSize(size));
        };
        // Case 6: Maximum Value + 0.1
        TEST_METHOD(MaxValue)
        {
            double size = 2.1;
            Assert::AreEqual(0, isValidSize(size));
        };
        // Case 7: Minimum Value - 0.1
        TEST_METHOD(MinimumMinus)
        {
            double size = 0.4;
            Assert::AreEqual(0, isValidSize(size));
        };
    };
    /* Function : checkCurrentWeight */
    TEST_CLASS(WBT004)
    {
    public:
        // Case 1: Almost full truck
        TEST_METHOD(FromAlmostFullToFull)
        {
            struct Truck truck = { blue,1980,10,{{},0,'\0'} };
            int weight = 20;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 2: Empty truck, max shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue,0,10,{{},0,'\0'} };
            int weight = 2000;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 3: Half full truck, heavy shipment
        TEST_METHOD(HalfFullTruckHeavyShipment)
        {
            struct Truck truck = { blue,990,10,{{},0,'\0'} };
            int weight = 1010;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 4: Empty truck, light shipment
        TEST_METHOD(EmptyTruckLightShipment)
        {
            struct Truck truck = { blue,0,10,{{},0,'\0'} };
            int weight = 2;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
        // Case 5: Full Truck Minimum Shipment
        TEST_METHOD(FullTruckMinShipment)
        {
            struct Truck truck = { blue,2000,10,{{},0,'\0'} };
            int weight = 2;
            Assert::AreEqual(0, checkCurrentWeight(&truck, weight));
        };
        // Case 6: Almost full Truck, light shipment
        TEST_METHOD(MinTruckMaxShipment)
        {
            struct Truck truck = { blue,1990,10,{{},0,'\0'} };
            int weight = 11;
            Assert::AreEqual(0, checkCurrentWeight(&truck, weight));
        };
    };
    /* Function : isTruckAvailable */
    TEST_CLASS(WBT006)
    {
    public:
        // Case 1: Empty Truck, Minimum Shipment
        TEST_METHOD(EmptyTruckMinimumShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 2: Almost Full Truck, Minimum Shipment
        TEST_METHOD(AlmostFullTruckMinimumShipment)
        {
            struct Truck truck = { blue,1999,19.5,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 3: Empty Truck Maximum Shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 2000,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 4: Exceed weight limit
        TEST_METHOD(ExceedWeightLimits)
        {
            struct Truck truck = { blue,2000,11.5,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 5: Exceed Volume Limit
        TEST_METHOD(ExceedVolumeLimit)
        {
            struct Truck truck = { blue,1000,20,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 6: Exceed Volume and Weight Limits
        TEST_METHOD(ExceedAllLimits)
        {
            struct Truck truck = { blue,2000,20,{{},0,'\0'} };
            struct Shipment shipment = {1,0.5,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };

    };
        // funciton : findTruckForShipment
    TEST_CLASS(WBT008)
    {
    public:
        TEST_METHOD(TypicalCase)
        {
        struct Map map = populateMap();
        struct Route bRoute = getBlueRoute();
        struct Route gRoute = getGreenRoute();
            struct Truck trucks[] = {
                {blue, 500, 10.0, bRoute},
                {green, 800, 5.0, gRoute}
            };
            struct Shipment shipment = {100, 1.0, {0, 0}, {0, {}}};
            Assert::AreEqual(1, findTruckForShipment(&map, trucks, 2, &shipment));
        }

        TEST_METHOD(NoTruckAvailable)
        {
            struct Map map = {10};
            struct Truck trucks[] = {
                {blue, 1900, 20.0, {0, {}}},
                {green, 900, 15.0, {0, {}}}};
            struct Shipment shipment = {200, 2.0, {0, 0}, {0, {}}};
            Assert::AreEqual(-1, findTruckForShipment(&map, trucks, 2, &shipment));
        }


        TEST_METHOD(LowerPercentage)
        {
        struct Map map = populateMap();
        struct Route bRoute = getBlueRoute();
        struct Route gRoute = getGreenRoute();
            struct Truck trucks[] = {
                {blue, 500, 10.0, bRoute},
                {green, 200, 11.0, gRoute}
            };
            struct Shipment shipment = {60, 1.0, {0, 0}, {0, {}}};
            Assert::AreEqual(0, findTruckForShipment(&map, trucks, 2, &shipment));
        }

        TEST_METHOD(OverLimit)
        {
            struct Map map = {10};
            struct Truck trucks[] = {
                {blue, 500, 10.0, {0, {}}},
                {green, 600, 11.0, {0, {}}}};
            struct Shipment shipment = {2001, 1.0, {0, 0}, {0, {}}};
            Assert::AreEqual(-4, findTruckForShipment(&map, trucks, 2, &shipment));
        }
    };

        /* Function : isValidDestination */
    TEST_CLASS(WBT003)
    {
    public:
        // Case 1: NULL pointer
        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, isValidDestination(nullptr));
        };

        // Case 2: row < 0
        TEST_METHOD(RowLessThanZero)
        {
            struct Point dest = { -1, 1 };
            Assert::AreEqual(0, isValidDestination(&dest));
        };

        // Case 3: row >= MAP_ROWS
        TEST_METHOD(RowExceedsMapRows)
        {
            struct Point dest = { 25, 1 };
            Assert::AreEqual(0, isValidDestination(&dest));
        };

        // Case 4: col < 'A'
        TEST_METHOD(ColBeforeA)
        {
            struct Point dest = { 5, -1 };
            Assert::AreEqual(0, isValidDestination(&dest));
        };

        // Case 5: col > 'Y'
        TEST_METHOD(ColAfterY)
        {
            struct Point dest = { 5, 25 };
            Assert::AreEqual(0, isValidDestination(&dest));
        };

        // Case 6: All conditions are valid
        TEST_METHOD(AllConditionsValid)
        {
            struct Point dest = { 5, 1 };
            Assert::AreEqual(1, isValidDestination(&dest));
        };
    };

    /* Function: checkCurrentVolume */
    TEST_CLASS(WBT005)
    {
    public:
        // Case 1: Test NULL pointer
        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, checkCurrentVolume(nullptr, 1.0));
        }

        // Case 2: Test sum > MAX_VOLUME
        TEST_METHOD(ExceedsMaxVolume)
        {
            struct Truck truck = { blue, 500, 19.5, getBlueRoute() };
            Assert::AreEqual(0, checkCurrentVolume(&truck, 1.0));
        }

        // Case 3: Test sum = MAX_VOLUME
        TEST_METHOD(EqualsMaxVolume)
        {
            struct Truck truck = { blue, 500, 19.0, getBlueRoute() };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1.0));
        }

        // Case 4: Test sum < MAX_VOLUME
        TEST_METHOD(UnderMaxVolume)
        {
            struct Truck truck = { blue, 500, 10.0, getBlueRoute() };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1.0));
        }

        // Case 5: Test empty truck
        TEST_METHOD(EmptyTruck)
        {
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1.0));
        }
    };

    /* Function: findLimitingPercentage */
    TEST_CLASS(WBT007)
    {
    public:
        // Case 1: Test typical case
        TEST_METHOD(TypicalCase)
        {
            struct Truck truck = { blue, 500, 10.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {1, 7}, {{}, 0, DIVERSION} };
            double expected = 0.55; // (600/2000) = 0.3 vs (11/20) = 0.55
            double actual = findLimitingPercentage(&truck, &shipment);
            Assert::AreEqual(expected, actual, 0.01);
        }

        // Case 2: Test heavy truck and light shipment
        TEST_METHOD(HeavyTruckCase)
        {
            struct Truck truck = { blue, 1999, 10.5, getBlueRoute() };
            struct Shipment shipment = { 1, 0.5, {1, 7}, {{}, 0, DIVERSION} };
            double expected = 1.0;
            double actual = findLimitingPercentage(&truck, &shipment);
            Assert::AreEqual(expected, actual, 0.01);
        }

        // Case 3: Test volume big truck and light shipment
        TEST_METHOD(VolumeLimitedCase)
        {
            struct Truck truck = { blue, 600, 18.0, getBlueRoute() };
            struct Shipment shipment = { 20, 2.0, {1, 7}, {{}, 0, DIVERSION} };
            double expected = 1.0;
            double actual = findLimitingPercentage(&truck, &shipment);
            Assert::AreEqual(expected, actual, 0.01);
        }

        // Case 4: Test half-full truck
        TEST_METHOD(HalfFullCase)
        {
            struct Truck truck = { blue, 900, 11.5, getBlueRoute() };
            struct Shipment shipment = { 600, 2.0, {1, 7}, {{}, 0, DIVERSION} };
            double expected = 0.75;
            double actual = findLimitingPercentage(&truck, &shipment);
            Assert::AreEqual(expected, actual, 0.01);
        }
    };

    /* Function: addShipmentToTruck */
    TEST_CLASS(WBT009)
    {
    public:
        // Case 1: Test typical case
        TEST_METHOD(TypicalCase)
        {
            struct Truck truck = { blue, 500, 10.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {1, 7}, {{}, 0, DIVERSION} };
            addShipmentToTruck(&truck, &shipment);
            Assert::AreEqual(600, truck.m_currentWeight);
            Assert::AreEqual(11.0, truck.m_currentVolume);
        }

        // Case 2: Test almost full weight
        TEST_METHOD(AlmostFullWeight)
        {
            struct Truck truck = { blue, 1700, 10.0, getBlueRoute() };
            struct Shipment shipment = { 300, 1.0, {1, 7}, {{}, 0, DIVERSION} };
            addShipmentToTruck(&truck, &shipment);
            Assert::AreEqual(2000, truck.m_currentWeight);
            Assert::AreEqual(11.0, truck.m_currentVolume);
        }

        // Case 3: Test almost full volume
        TEST_METHOD(AlmostFullVolume)
        {
            struct Truck truck = { blue, 100, 18.0, getBlueRoute() };
            struct Shipment shipment = { 300, 2.0, {1, 7}, {{}, 0, DIVERSION} };
            addShipmentToTruck(&truck, &shipment);
            Assert::AreEqual(400, truck.m_currentWeight);
            Assert::AreEqual(20.0, truck.m_currentVolume);
        }

        // Case 4: Test empty truck with max size shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            struct Shipment shipment = { 2000, 2.0, {1, 7}, {{}, 0, DIVERSION} };
            addShipmentToTruck(&truck, &shipment);
            Assert::AreEqual(2000, truck.m_currentWeight);
            Assert::AreEqual(2.0, truck.m_currentVolume);
        }
    };
 
    /* Function: getFinalPath */
    TEST_CLASS(WBT011)
    {
    public:
        // Case 1: Test no diversion needed
        TEST_METHOD(NoDiversion)
        {
            struct Map map = populateMap();
            struct Point start = { 4, 9 };
            struct Point dest = { 4, 9 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(1, result);
            Assert::AreEqual(0, route.numPoints);
        }

        // Case 2: Test simple diversion
        TEST_METHOD(SimpleDiversion)
        {
            struct Map map = populateMap();
            struct Point start = { 4, 9 };
            struct Point dest = { 4, 10 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(1, result);
            Assert::AreEqual(1, route.numPoints);
            Assert::AreEqual(4, route.points[0].row);
            Assert::AreEqual(10, route.points[0].col);
        }

        // Case 3: Test multiple steps diversion
        TEST_METHOD(MultipleStepsDiversion)
        {
            struct Map map = populateMap();
            struct Point start = { 4, 9 };
            struct Point dest = { 6, 10 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(1, result);
            Assert::AreEqual(3, route.numPoints);
            Assert::AreEqual(5, route.points[0].row);
            Assert::AreEqual(9, route.points[0].col);
            Assert::AreEqual(6, route.points[1].row);
            Assert::AreEqual(9, route.points[1].col);
            Assert::AreEqual(6, route.points[2].row);
            Assert::AreEqual(10, route.points[2].col);
        }

        // Case 4: Test building avoidance
        TEST_METHOD(BuildingAvoidance)
        {
            struct Map map = populateMap();
            struct Point start = { 5, 9 };
            struct Point dest = { 7, 8 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(1, result);
            Assert::AreEqual(3, route.numPoints);
            // Verify path avoids buildings
            Assert::AreEqual(6, route.points[0].row);
            Assert::AreEqual(9, route.points[0].col);
            Assert::AreEqual(7, route.points[1].row);
            Assert::AreEqual(9, route.points[1].col);
            Assert::AreEqual(7, route.points[2].row);
            Assert::AreEqual(8, route.points[2].col);
        }

        // Case 5: Test invalid destination
        TEST_METHOD(InvalidDestination)
        {
            struct Map map = populateMap();
            struct Point start = { 4, 9 };
            struct Point dest = { 1, 1 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(0, result);
            Assert::AreEqual(0, route.numPoints);
        }

        // Case 6: Test multiple possible paths
        TEST_METHOD(MultiplePossiblePaths)
        {
            struct Map map = populateMap();
            struct Point start = { 8, 3 };
            struct Point dest = { 8, 5 };
            struct Route route = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &route);

            Assert::AreEqual(1, result);
            Assert::AreEqual(2, route.numPoints);

            Assert::AreEqual(8, route.points[0].row);
            Assert::AreEqual(4, route.points[0].col);
            Assert::AreEqual(8, route.points[1].row);
            Assert::AreEqual(5, route.points[1].col);
        }
    };
    TEST_CLASS(WBT012)
{
public:
    TEST_METHOD(ValidInputs)
    {
        struct Map map = populateMap();
        struct Route route=getBlueRoute();
        struct Truck truck = {blue, 300, 20.0, route};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, &truck, shipment);
    }

    TEST_METHOD(EmptyRoute)
    {
        struct Map map = {10};
        struct Truck truck = {green, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, &truck, shipment);
    }

    TEST_METHOD(NullMap)
    {
        struct Truck truck = {yellow, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(nullptr, &truck, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(NullTruck)
    {
        struct Map map = {10};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        printRoute(&map, nullptr, shipment);
        // Expect no crash; manual verification required for output
    }

    TEST_METHOD(NullShipment)
    {
        struct Map map = {10};
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        printRoute(&map, &truck, {0, 0, {0, 0}, {0, {}}});
        // Expect no crash; manual verification required for output
    }
};
}
namespace IntegrationTest
{
    /* Function: checkCurrentVolume */
    TEST_CLASS(IT001)
    {
    public:
        // Test Data 1: Volume check with shipment addition
        TEST_METHOD(VolumeCheckWithAddShipment)
        {
            struct Map map = populateMap();
            struct Truck truck = { blue, 0, 15.0, getBlueRoute() };
            struct Shipment shipment = { 100, 2.0, {4, 9} };

            bool volumeOK = checkCurrentVolume(&truck, shipment.m_size); //interaction
            Assert::IsTrue(volumeOK);
            addShipmentToTruck(&truck, &shipment); //interaction
            Assert::AreEqual(17.0, truck.m_currentVolume);
        }

        // Test Data 2: Volume limits and truck selection
        TEST_METHOD(VolumeLimitsWithTruckSelection)
        {
            struct Map map = populateMap();
            struct Truck trucks[NUM_TRUCKS] = {
                {blue, 0, 18.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()}
            };
            struct Shipment shipment = { 100, 2.0, {4, 9} };

            bool volumeOK = checkCurrentVolume(&trucks[0], shipment.m_size); //interaction
            Assert::IsFalse(volumeOK);
            int truckIdx = findTruckForShipment(&map, trucks, 2, &shipment); //interaction
            Assert::AreEqual(1, truckIdx);
        }

        // Test Data 3: Empty truck volume check
        TEST_METHOD(EmptyTruckVolumeCheck)
        {
            struct Map map = populateMap();
            struct Truck truck = { yellow, 0, 0.0, getYellowRoute() };
            struct Shipment shipment = { 100, 1.0, {4, 9} };

            bool volumeOK = checkCurrentVolume(&truck, shipment.m_size);
            Assert::IsTrue(volumeOK);
            addShipmentToTruck(&truck, &shipment); //interaction
            Assert::AreEqual(1.0, truck.m_currentVolume);
        }

        // Test Data 4: Max volume check
        TEST_METHOD(MaxVolumeCheck)
        {
            struct Map map = populateMap();
            struct Truck trucks[NUM_TRUCKS] = {
                {blue, 0, 17.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()}
            };
            struct Shipment shipment = { 100, 3.0, {4, 9} };

            bool volumeOK = checkCurrentVolume(&trucks[0], shipment.m_size);
            Assert::IsFalse(volumeOK);
            int truckIdx = findTruckForShipment(&map, trucks, 2, &shipment); //interaction
            Assert::AreEqual(1, truckIdx);
            addShipmentToTruck(&trucks[truckIdx], &shipment); //interaction
            Assert::AreEqual(3.0, trucks[truckIdx].m_currentVolume);
        }
    };

    /* Function: printRoute */
    TEST_CLASS(IT002)
    {
    public:
        // Test Data 1: Direct Route
        TEST_METHOD(DirectRoutePrinting)
        {
            struct Map map = populateMap();
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {4, 9} };

            int startPointIdx = findStartPoint(&map, &truck.m_route, &shipment.m_dest); //interaction
            Assert::IsTrue(startPointIdx >= 0);
            if (startPointIdx >= 0) {
                Assert::AreEqual(4, truck.m_route.points[startPointIdx].row);
                Assert::AreEqual(9, truck.m_route.points[startPointIdx].col);
            }
        }

        // Test Data 2: Building Avoidance
        TEST_METHOD(BuildingAvoidanceRoute)
        {
            struct Map map = populateMap();
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {7, 7} };

            int startPointIdx = findStartPoint(&map, &truck.m_route, &shipment.m_dest); //interaction
            Assert::IsTrue(startPointIdx >= 0);
            if (startPointIdx >= 0) {
                struct Route diversionPath = { {0}, 0, DIVERSION };
                int result = getFinalPath(&map, &truck.m_route.points[startPointIdx], &shipment.m_dest, &diversionPath); //interaction

                Assert::IsTrue(result == 1);
                Assert::IsTrue(diversionPath.numPoints >= 2);
            }
        }

        // Test Data 3: Cross-Route Path
        TEST_METHOD(CrossRoutePath)
        {
            struct Map map = populateMap();
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {0, 15} };

            int startPointIdx = findStartPoint(&map, &truck.m_route, &shipment.m_dest); //interaction
            Assert::IsTrue(startPointIdx >= 0);
            if (startPointIdx >= 0) {
                struct Route diversionPath = { {0}, 0, DIVERSION };
                int result = getFinalPath(&map, &truck.m_route.points[startPointIdx], &shipment.m_dest, &diversionPath); //interaction

                Assert::IsTrue(result == 1);
                Assert::IsTrue(diversionPath.numPoints >= 4);
            }
        }

        // Test Data 4: Long Diversion Path
        TEST_METHOD(LongDiversionPath)
        {
            struct Map map = populateMap();
            struct Truck truck = { blue, 0, 0.0, getBlueRoute() };
            struct Shipment shipment = { 100, 1.0, {8, 15} };

            int startPointIdx = findStartPoint(&map, &truck.m_route, &shipment.m_dest);
            Assert::IsTrue(startPointIdx >= 0);
            if (startPointIdx >= 0) {
                struct Route diversionPath = { {0}, 0, DIVERSION };
                int result = getFinalPath(&map, &truck.m_route.points[startPointIdx], &shipment.m_dest, &diversionPath);

                Assert::IsTrue(result == 1);
                Assert::IsTrue(diversionPath.numPoints >= 3);

            }
        }
    };
       /* Function : isTruckAvailable */
    TEST_CLASS(IT003)
    {
    public:
        // Case 1: Typical
        TEST_METHOD(Typical)
        {
            struct Truck truck = { blue,600,5.0,{{},0,'\0'} };
            struct Shipment shipment = { 100,1.0,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 2: Exceed weight limit
        TEST_METHOD(ExceedWeightLimits)
        {
            struct Truck truck = { blue,1900,11.5,{{},0,'\0'} };
            struct Shipment shipment = { 150,0.5,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 3: Exceed Volume Limit
        TEST_METHOD(ExceedVolumeLimit)
        {
            struct Truck truck = { blue,1500,19.0,{{},0,'\0'} };
            struct Shipment shipment = { 200,2.0,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 4: Null Input
        TEST_METHOD(NullInput)
        {
            Assert::AreEqual(0, isTruckAvailable(NULL, NULL));
        };

    };
    TEST_CLASS(IT004)
{
public:
    TEST_METHOD(ValidInputs)
    {
        struct Map map = populateMap();
        struct Route route = getBlueRoute();
        struct Point dest = {4, 4};
        Assert::AreEqual(8, findStartPoint(&map, &route, &dest));
    }

    TEST_METHOD(DestinationOutOfBounds)
    {
        struct Map map = {10};
        struct Route route = {0};
        struct Point dest = {25, 5}; // Row out of bounds
        Assert::AreEqual(-1, findStartPoint(&map, &route, &dest));
    }

    TEST_METHOD(NullMap)
    {
        struct Route route = {0};
        struct Point dest = {5, 5};
        Assert::AreEqual(-1, findStartPoint(nullptr, &route, &dest));
    }


    TEST_METHOD(NullDestination)
    {
        struct Map map = {10};
        struct Route route = {0};
        Assert::AreEqual(-1, findStartPoint(&map, &route, nullptr));
    }
};

}

namespace AcceptanceTest
{

    /* Function : isValidWeight */
    TEST_CLASS(AT001)
    {
    public:
        TEST_METHOD(NormalValue)
        {
            int weight = 50;
            Assert::AreEqual(1, isValidWeight(weight));
        };
    };

    /* Function : isValidSize */
    TEST_CLASS(AT002)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            double size = 1;
            Assert::AreEqual(1, isValidSize(size));
        };
    };

    /* Function : isValidDestination */
TEST_CLASS(AT003)
    {
    public:
        TEST_METHOD(NormalSpace)
        {
            struct Point dest = { 11, 11 };  // row 12, column 'L'
            Assert::AreEqual(1, isValidDestination(&dest));
        }

    };

    /* Function : checkCurrentWeight */
    TEST_CLASS(AT004)
    {
    public:
        TEST_METHOD(NormalValue)
        {
            struct Truck truck = { blue,1000,10,{{},0,'\0'} };
            int weight = 200;
            Assert::AreEqual(1, checkCurrentWeight(&truck, weight));
        };
    };

    /* Function : checkCurrentVolume */
     TEST_CLASS(AT005)
    {
    public:
        TEST_METHOD(PartiallyFilled)
        {
            struct Truck truck = { blue, 0, 10.0, {{}, 0, '\0'} };
            Assert::AreEqual(1, checkCurrentVolume(&truck, 1));  // boxSize = 1 (0.5 cubic meters)
        }

    };
    /* Function : isTruckAvailable */
    TEST_CLASS(BBT006)
    {
    public:
        // Case 1: Normal Value
        TEST_METHOD(NormalValue)
        {
            struct Truck truck = { blue,70,10,{{},0,'\0'} };
            struct Shipment shipment = { 20,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 2: Exceed Space Limit
        TEST_METHOD(ExceedSpaceLimit)
        {
            struct Truck truck = { blue,70,18.5,{{},0,'\0'} };
            struct Shipment shipment = { 20,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 3: Exceed Weight Limit
        TEST_METHOD(ExceedWeightLimit)
        {
            struct Truck truck = { blue,700,10,{{},0,'\0'} };
            struct Shipment shipment = { 1500,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 4: Exceed both limits
        TEST_METHOD(ExceedBothLimits)
        {
            struct Truck truck = { blue,700,19,{{},0,'\0'} };
            struct Shipment shipment = { 1500,2,{1,7} };
            Assert::AreEqual(0, isTruckAvailable(&truck, &shipment));
        };
        // Case 5: Empty Truck Minimum Shipment
        TEST_METHOD(EmptyTruckMinShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 1,0.5,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 6: Empty truck, max shipment
        TEST_METHOD(EmptyTruckMaxShipment)
        {
            struct Truck truck = { blue,0,0,{{},0,'\0'} };
            struct Shipment shipment = { 2000,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 7: Truck has the Exact Space And Weight
        TEST_METHOD(ExactSpaceAndWeight)
        {
            struct Truck truck = { blue,1800,18,{{},0,'\0'} };
            struct Shipment shipment = { 200,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 8: Truck has the Exact Space Needed
        TEST_METHOD(ExactSpaceNeeded)
        {
            struct Truck truck = { blue,1100,18,{{},0,'\0'} };
            struct Shipment shipment = { 200,2,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 9: Truck has the Exact Weight Needed
        TEST_METHOD(ExactWeightNeeded)
        {
            struct Truck truck = { blue,1500,11,{{},0,'\0'} };
            struct Shipment shipment = { 500,1,{1,7} };
            Assert::AreEqual(1, isTruckAvailable(&truck, &shipment));
        };
        // Case 10: Feeding null pointer
        TEST_METHOD(NullPointer)
        {
            Assert::AreEqual(0, isTruckAvailable(nullptr, nullptr));
        };
    };    
    /* User story: As a user, I want to ensure the trucks follow thier assigned routes*/
    TEST_CLASS(AT007) {
    public:
        TEST_METHOD(TestTruckFollowsDefaultRoute) {
            Map map = populateMap();
            Truck trucks[NUM_TRUCKS] = {
                {blue, 0, 0.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()},
                {yellow, 0, 0.0, getYellowRoute()}
            };

            Shipment package = { 100, 1.0, {4, 9} }; // Location on blue route
            int selectedTruck = findTruckForShipment(&map, trucks, NUM_TRUCKS, &package);

            Assert::AreEqual(0, selectedTruck);
        }
    };

    /* User story: As a user, I want to accurately calculate the distance */
    TEST_CLASS(AT008) {
    public:
        TEST_METHOD(TestDeliveryDistanceCalculation) {
            Point truckLocation = { 0, 0 };
            Point deliveryLocation = { 3, 4 };// Delivery 5 units away

            double deliveryDistance = distance(&truckLocation, &deliveryLocation);

            Assert::AreEqual(5.0, deliveryDistance, 0.01);
        }
    };

    /* User story: As a user, I want to use the shortest available route */
    TEST_CLASS(AT009) {
    public:
        TEST_METHOD(TestSelectsShortestDeliveryPath) {
            Map map = populateMap();
            Truck trucks[NUM_TRUCKS] = {
                {blue, 0, 0.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()},
                {yellow, 0, 0.0, getYellowRoute()}
            };
            Shipment delivery = { 100, 1.0, {7, 'F' - 'A'} }; // Location near multiple routes

            int selectedTruck = findTruckForShipment(&map, trucks, NUM_TRUCKS, &delivery);
            Assert::IsTrue(selectedTruck >= 0);
        }
    };

    /* User story: As a user, I want clear notification when delivery isn't possible */
    TEST_CLASS(AT010) {
    public:
        TEST_METHOD(TestUnreachableLocationHandling) {
            Map map = populateMap();
            Truck trucks[1] = { {blue, 0, 0.0, getBlueRoute()} };
            Shipment delivery = { 100, 1.0, {1, 1} }; // Location inside building

            int result = findTruckForShipment(&map, trucks, NUM_TRUCKS, &delivery);
            Assert::AreEqual(-1, result);
        }
    };

    /* User story: As a user, I want to correctly select the path when there are multiple equal paths */
    TEST_CLASS(AT011) {
    public:
        TEST_METHOD(TestEqualPathSelection) {
            Map map = populateMap();
            Truck trucks[2] = {
                {blue, 0, 0.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()}
            };
            Shipment delivery = { 100, 1.0, {4, 9} }; // Point are equal from both routes

            int selectedTruck = findTruckForShipment(&map, trucks, 2, &delivery);

            Assert::IsTrue(selectedTruck >= 0);
        }
    };

    /* User story: As a user, I want to avoid the buildings */
    TEST_CLASS(AT012) {
    public:
        TEST_METHOD(TestBuildingAvoidance) {
            Map map = populateMap();
            Point start = { 0, 0 };
            Point dest = { 2, 2 }; // Behind a building
            Route path = { {0}, 0, DIVERSION };

            int result = getFinalPath(&map, &start, &dest, &path);

            Assert::IsTrue(result >= 0);
        }
    };

    /* User story: As a user, I want the system to select trucks with shortest diversion paths */
    TEST_CLASS(AT013) {
    public:
        TEST_METHOD(TestShortestDiversionSelection) {
            Map map = populateMap();
            Truck trucks[NUM_TRUCKS] = {
                {blue, 0, 0.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()},
                {yellow, 0, 0.0, getYellowRoute()}
            };
            Shipment delivery = { 100, 1.0, {8, 15} }; // Point requiring diversion

            int selectedTruck = findTruckForShipment(&map, trucks, NUM_TRUCKS, &delivery);

            Assert::IsTrue(selectedTruck >= 0);
        }
    };

    /* User story: As a user, I want alternative trucks if first choice is full */
    TEST_CLASS(AT014) {
    public:
        TEST_METHOD(TestAlternativeTruckSelection) {
            Map map = populateMap();
            Truck trucks[2] = {
                {blue, MAX_WEIGHT, MAX_VOLUME, getBlueRoute()}, // First truck full
                {green, 0, 0.0, getGreenRoute()}  // Second truck empty
            };
            Shipment delivery = { 100, 1.0, {4, 9} };

            int selectedTruck = findTruckForShipment(&map, trucks, 2, &delivery);

            Assert::AreEqual(1, selectedTruck);
        }
    };

    /* User story: As a customer, I want to know if my package must wait until tomorrow if all trucks are full */
    TEST_CLASS(AT015) {
    public:
        TEST_METHOD(TestShipsTomorrowNotification) {
            Map map = populateMap();
            Truck trucks[NUM_TRUCKS] = {
                {blue, MAX_WEIGHT, MAX_VOLUME, getBlueRoute()},
                {green, MAX_WEIGHT, MAX_VOLUME, getGreenRoute()},
                {yellow, MAX_WEIGHT, MAX_VOLUME, getYellowRoute()}
            };
            Shipment delivery = { 100, 1.0, {4, 9} };

            int result = findTruckForShipment(&map, trucks, NUM_TRUCKS, &delivery);

            Assert::AreEqual(-1, result);
        }
    };

    /* User story: As a user, I want to clear truck assignment */
    TEST_CLASS(AT016) {
    public:
        TEST_METHOD(TestClearTruckAssignment) {
            Map map = populateMap();
            Truck trucks[2] = {
                {blue, 0, 0.0, getBlueRoute()},
                {green, 0, 0.0, getGreenRoute()}
            };
            Shipment delivery = { 100, 1.0, {4, 9} };

            int assignedTruck = findTruckForShipment(&map, trucks, 2, &delivery);

            Assert::IsTrue(assignedTruck >= 0 && assignedTruck < 2);
        }
    };

    /* User story: As a user, I want to clear delivery location information */
    TEST_CLASS(AT017) {
    public:
        TEST_METHOD(TestDeliveryLocation) {
            Shipment delivery = { 100, 1.0, {4, 9} };

            bool isValid = isValidDestination(&delivery.m_dest);

            Assert::IsTrue(isValid);
        }
    };

    /* User story: As a user, I want to clear diversion instruction */
    TEST_CLASS(AT018) {
    public:
        TEST_METHOD(TestDiversionInstructions) {
            Map map = populateMap();
            Truck truck = { blue, 0, 0.0, getBlueRoute() };
            Shipment delivery = { 100, 1.0, {8, 15} }; // Requires diversion
            Route diversionPath = { {0}, 0, DIVERSION };

            int startPoint = findStartPoint(&map, &truck.m_route, &delivery.m_dest);
            int result = getFinalPath(&map, &truck.m_route.points[startPoint], &delivery.m_dest, &diversionPath);

            Assert::IsTrue(result >= 0);
        }
    };
}