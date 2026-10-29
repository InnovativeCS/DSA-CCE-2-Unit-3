Water Pipeline Network using Kruskal's Algorithm

Problem Statement

To develop a water pipeline network with installation costs and apply Kruskal's Algorithm to select the minimum-cost pipeline connections required to connect all distribution points.

Objective

To implement Kruskal's Algorithm in C++ to find the minimum-cost connections between water distribution points and reduce the total pipeline installation cost.

Data Structure Used

- Graph
- Edge List
- Disjoint Set (Union-Find)

Operations

- Enter the number of distribution points.
- Enter unique names of the locations.
- Enter possible pipeline connections with their installation costs.
- Sort the connections according to their costs.
- Select minimum-cost connections.
- Display the selected pipeline connections.
- Display the minimum total installation cost.

Concepts Used

- C++
- Graph
- Kruskal's Algorithm
- Minimum Spanning Tree (MST)
- Disjoint Set
- Union-Find
- Vectors
- Classes and Objects
- Pointers
- Greedy Algorithm
- Sorting

Algorithm

1. Start the program.
2. Enter the number of distribution points and their unique names.
3. Enter the number of possible pipeline connections.
4. Enter the two connected locations and the installation cost for each connection.
5. Sort all connections in increasing order of cost.
6. Initialize the Disjoint Set for all locations.
7. Select the lowest-cost connection that does not form a cycle.
8. Repeat until all locations are connected or no more valid connections are available.
9. Display the selected pipeline connections and the total cost.
10. If all locations cannot be connected, display a message that the network is disconnected.
11. Stop the program.

Advantages

- Reduces the total pipeline installation cost.
- Selects connections with minimum cost.
- Avoids cycles in the selected network.
- Works efficiently using the Disjoint Set data structure.
- Helps in planning water distribution networks.

Conclusion

The Water Pipeline Network using Kruskal's Algorithm demonstrates how a minimum spanning tree can be used to connect water distribution points at minimum installation cost. The project uses graphs, sorting, and the Disjoint Set data structure to select suitable pipeline connections and calculate the total cost. It also identifies when all distribution points cannot be connected.
