# Water Pipeline Network using Kruskal's Algorithm

C++98-compatible Dev-C++ version. Distribution points are vertices, pipeline connections are edges, and edge weights are installation costs.

## Run
Open `main.cpp` in Dev-C++ and select **Execute > Compile & Run**.

## Sample input
```text
6
P1
P2
P3
P4
P5
P6
9
P1 P2 4
P1 P3 3
P2 P3 1
P2 P4 2
P3 P4 4
P3 P5 5
P4 P5 2
P4 P6 7
P5 P6 3
```

Expected minimum total cost: `11` (illustrative cost units).

## Algorithm
Sort connections by cost and use Union-Find to add only edges that do not form a cycle. A minimum spanning tree uses `V-1` edges.

## Complexity
`O(E log E)` time, where `V` is the number of points and `E` is the number of connections.
