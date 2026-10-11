# Logistics Simulator

A C console application for assigning shipments to delivery trucks on a fixed city grid. It combines route diversion calculations with truck weight and volume constraints, then prints the selected route for each shipment.

## Features

- Model a 25-by-25 grid with buildings and three predefined delivery routes: BLUE, GREEN, and YELLOW.
- Validate shipment weight (1–2,000 kg), box volume (0.5, 1, or 2 cubic metres), and destination coordinates.
- Track each truck's cumulative load against a 2,000 kg weight limit and a 20 cubic metre volume limit.
- Evaluate diversion paths from points along each eligible truck's route.
- Prefer the truck with the fewest computed diversion points; break ties using the lower projected weight/volume utilization ratio.
- Report invalid shipments and shipments that cannot be assigned to an available truck.
- Include C++ tests and test planning, case descriptions, and traceability documents.

## Technology

C for the simulator and routing logic, C++ with the Microsoft Native Unit Test Framework for tests, and Visual Studio solution/project files. The console application also builds with GCC and the standard C math library.

## Design

| Module | Responsibility |
| --- | --- |
| `mapping.h` / `mapping.c` | Grid representation, predefined routes, point operations, and path search. |
| `shipment.h` / `shipment.c` | Shipment validation, capacity checks, diversion evaluation, and truck selection. |
| `main.c` | Interactive input, fleet initialization, and console output. |
| `SourceCode/Test/` | Validation and routing tests using Microsoft's C++ test framework. |

`Point`, `Map`, and `Route` describe the delivery area. `Shipment` records a package's weight, volume, and destination; `Truck` holds its route and current load.

For each shipment, the selector validates its fields and filters trucks by remaining capacity. It evaluates paths from each truck's route to the destination, compares computed diversion lengths, and uses projected load utilization to resolve equal-length candidates. The selected truck's load is updated before the next shipment is processed.

Path search uses recursive grid traversal and distance-guided route reconstruction. It is a heuristic implementation; the project does not claim a globally optimal vehicle-routing solution. The fleet and map are fixed, and state is held in memory for the current run.

## Build and run

From the repository root, with GCC on your PATH:

```sh
gcc -std=c11 -Wall -Wextra SourceCode/Project/main.c SourceCode/Project/mapping.c SourceCode/Project/shipment.c -lm -o logistics-sim.exe
```

On Windows PowerShell:

```powershell
.\logistics-sim.exe
```

On Linux or macOS, use `./logistics-sim.exe`.

Enter a weight, box volume, and destination. Destinations use a row number from 1 to 25 followed immediately by a column letter from A to Y:

```text
100 0.5 12L
```

For this input, the bundled map produces:

```text
Ship on BLUE LINE, no diversion
```

Enter `0 0 x` to exit. The console currently displays its original Seneca Polytechnic delivery banner.

### Visual Studio

Open `SourceCode/Project.sln` with the Desktop development with C++ workload. The checked-in projects request toolset `v145` and Windows SDK `10.0`; install the requested toolset or retarget both projects to your installed version.

To build and run the console application, select `Project` as the startup project. Build that project directly if the test project is not yet configured.

## Tests and validation

The test sources include boundary-value, invalid-input, capacity, and routing scenarios. To run the configured native tests:

1. Use the Debug/x64 configuration and build the `Project` application first.
2. In the `Test` project's C/C++ include directories, replace the original absolute source path with `$(SolutionDir)Project` and retain the Microsoft UnitTest include directory.
3. In the linker library directories, replace the original absolute object-file path with your application build output directory, and retain the Microsoft UnitTest library directory.
4. Ensure `mapping.obj` and `shipment.obj` are available to the linker, build `Test`, and run it in Visual Studio Test Explorer.

The configured test project compiles `Test.cpp`; `blackboxTest.cpp` is also included in the repository as additional test source. The Microsoft test suite requires Visual Studio and was not executed during this README update.

The GCC console build and the `100 0.5 12L` example followed by `0 0 x` were verified. GCC currently reports existing initializer and const-qualification warnings. This example run is a smoke check, not a claim that all routes or edge cases pass.

## Repository layout

```text
SourceCode/Project/   C simulator, mapping, and shipment modules
SourceCode/Test/      C++ native test sources and project
SourceCode/Project.sln
Documents/Testing/   Test plan, case descriptions, and traceability matrix
Documents/           Original collaboration records and supporting documents
```

## Credits

Team contributors: **Ho Kan Chan, Loun Lee, Shing Suen, and Tianwen Wang**. This repository is maintained by **Tianwen Wang (MaxTianwen)**. The original map/routing scaffold and reference material were provided through Seneca Polytechnic. Existing contributor names and supporting documents are retained; the project is presented as a team implementation.
