// function : FindlimitingPercentage
EST_CLASS(BBT007)
{
public:
    TEST_METHOD(TruckAtMaxCapacity)
    {
        struct Truck truck = {blue, 500, 20.0, {0, {}}};
        struct Shipment shipment = {500, 20.0, {0, 0}, {0, {}}};
        Assert::AreEqual(100.0, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(TruckWithZeroCapacity)
    {
        struct Truck truck = {green, 0, 0.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        Assert::AreEqual(0.0, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(PartiallyFilledTruck)
    {
        struct Truck truck = {yellow, 250, 10.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        Assert::AreEqual(50.0, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(ExceedingCapacity)
    {
        struct Truck truck = {blue, 300, 15.0, {0, {}}};
        struct Shipment shipment = {400, 20.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1.0, findLimitingPercentage(&truck, &shipment), 0.01);
    }

    TEST_METHOD(NullPointers)
    {
        Assert::AreEqual(-1.0, findLimitingPercentage(nullptr, nullptr), 0.01);
    }
};
// funciton : findTruckForShipment
EST_CLASS(BBT008)
{
public:
    TEST_METHOD(ValidTruckFound)
    {
        struct Map map = {10};
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 500, 30.0, {0, {}}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        Assert::AreEqual(1, findTruckForShipment(&map, trucks, 2, &shipment));
    }

    TEST_METHOD(NoTruckAvailable)
    {
        struct Map map = {10};
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 300, 15.0, {0, {}}}};
        struct Shipment shipment = {400, 20.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1, findTruckForShipment(&map, trucks, 2, &shipment));
    }

    TEST_METHOD(NullMap)
    {
        struct Truck trucks[] = {
            {blue, 300, 20.0, {0, {}}},
            {green, 500, 30.0, {0, {}}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        Assert::AreEqual(-1, findTruckForShipment(nullptr, trucks, 2, &shipment));
    }

    TEST_METHOD(EmptyTruckList)
    {
        struct Map map = {10};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
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
EST_CLASS(BBT009)
{
public:
    TEST_METHOD(ValidAddition)
    {
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        struct Shipment shipment = {100, 5.0, {0, 0}, {0, {}}};
        addShipmentToTruck(&truck, &shipment);
        Assert::AreEqual(400, truck.m_currentWeight);
        Assert::AreEqual(25.0, truck.m_currentVolume, 0.01);
    }

    TEST_METHOD(ExceedingCapacity)
    {
        struct Truck truck = {blue, 300, 20.0, {0, {}}};
        struct Shipment shipment = {500, 10.0, {0, 0}, {0, {}}};
        addShipmentToTruck(&truck, &shipment);
        // Assert unchanged values as no addition should occur
        Assert::AreEqual(300, truck.m_currentWeight);
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

EST_CLASS(BBT010)
{
public:
    TEST_METHOD(ValidInputs)
    {
        struct Map map = {10};
        struct Route route = {0};
        struct Point dest = {5, 5};
        Assert::AreEqual(1, findStartPoint(&map, &route, &dest));
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
EST_CLASS(BBT011)
{
public:
    TEST_METHOD(ValidPathExists)
    {
        struct Map map = {10};
        struct Point start = {0, 0};
        struct Point end = {5, 5};
        struct Route route = {0};
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
EST_CLASS(BBT012)
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
