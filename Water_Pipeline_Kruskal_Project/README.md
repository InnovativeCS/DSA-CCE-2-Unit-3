# Water Pipeline Network Using Kruskal's Algorithm

## Problem Statement
Develop a water pipeline network with installation costs and apply Kruskal's algorithm to select the minimum-cost pipeline connections required to connect all distribution points.

## Features
- Add distribution points.
- Add pipeline connections and installation costs.
- Display points and available pipelines.
- Find the minimum-cost network using Kruskal's algorithm.
- Display selected connections and total installation cost.
- Detect disconnected networks.

## DSA Concepts
Weighted undirected graph, edge list, sorting, Disjoint Set Union (Union-Find), cycle detection, and Minimum Spanning Tree.

## Dev-C++ Instructions
1. Extract this ZIP file.
2. Open `water_pipeline_kruskal.cpp` in Dev-C++.
3. Select **Execute -> Compile & Run**.
4. Add distribution points first.
5. Add the connections and costs.
6. Select option 5 to run Kruskal's algorithm.

The source avoids C++11 lambda expressions and should work with older Dev-C++ compiler configurations.

## Sample Data
Distribution points:
0 Reservoir
1 North Colony
2 South Colony
3 Hospital Zone
4 Industrial Area

Pipeline connections (first ID, second ID, cost):
0 1 4
0 2 3
1 2 2
1 3 5
2 3 3
2 4 6
3 4 4

Expected minimum-cost network cost: 12
Expected selected connections:
- North Colony -- South Colony: 2
- Reservoir -- South Colony: 3
- South Colony -- Hospital Zone: 3
- Hospital Zone -- Industrial Area: 4

## Complexity
Sorting edges using bubble sort takes O(E^2) time in this beginner-friendly implementation. Union-Find operations are nearly constant amortized time. Space complexity is O(V + E).

## Note
This is an educational simulation. Installation costs are entered by the user and are not live construction estimates.
