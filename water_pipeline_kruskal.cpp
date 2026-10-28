#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAXV 50
#define MAXE 500

struct Edge
{
    int u, v, cost;
};

class PipelineNetwork
{
    string point[MAXV];
    Edge edges[MAXE];
    int vertices, edgeCount;

    int findParent(int parent[], int x)
    {
        if (parent[x] == x)
            return x;
        return findParent(parent, parent[x]);
    }

    bool unionSets(int parent[], int rankSet[], int a, int b)
    {
        a = findParent(parent, a);
        b = findParent(parent, b);

        if (a == b)
            return false;

        if (rankSet[a] < rankSet[b])
            parent[a] = b;
        else if (rankSet[a] > rankSet[b])
            parent[b] = a;
        else
        {
            parent[b] = a;
            rankSet[a]++;
        }
        return true;
    }

public:
    PipelineNetwork()
    {
        vertices = 0;
        edgeCount = 0;
    }

    void addPoint()
    {
        if (vertices >= MAXV)
        {
            cout << "Distribution point limit reached!\n";
            return;
        }

        cin.ignore(1000, '\n');
        cout << "Enter distribution point name: ";
        getline(cin, point[vertices]);

        if (point[vertices].empty())
        {
            cout << "Name cannot be empty!\n";
            return;
        }

        cout << "Point added with ID: " << vertices << endl;
        vertices++;
    }

    void displayPoints()
    {
        if (vertices == 0)
        {
            cout << "No distribution points added!\n";
            return;
        }

        cout << "\n--- Distribution Points ---\n";
        for (int i = 0; i < vertices; i++)
            cout << i << " : " << point[i] << endl;
    }

    void addPipeline()
    {
        if (vertices < 2)
        {
            cout << "Add at least two distribution points first!\n";
            return;
        }

        if (edgeCount >= MAXE)
        {
            cout << "Pipeline connection limit reached!\n";
            return;
        }

        int a, b, cost;
        displayPoints();

        cout << "Enter first point ID: ";
        cin >> a;
        cout << "Enter second point ID: ";
        cin >> b;

        if (a < 0 || a >= vertices || b < 0 || b >= vertices || a == b)
        {
            cout << "Invalid point IDs!\n";
            return;
        }

        cout << "Enter installation cost: ";
        cin >> cost;

        if (cost < 0)
        {
            cout << "Cost cannot be negative!\n";
            return;
        }

        for (int i = 0; i < edgeCount; i++)
        {
            if ((edges[i].u == a && edges[i].v == b) ||
                (edges[i].u == b && edges[i].v == a))
            {
                cout << "Pipeline connection already exists!\n";
                return;
            }
        }

        edges[edgeCount].u = a;
        edges[edgeCount].v = b;
        edges[edgeCount].cost = cost;
        edgeCount++;

        cout << "Pipeline connection added successfully!\n";
    }

    void displayPipelines()
    {
        if (edgeCount == 0)
        {
            cout << "No pipeline connections added!\n";
            return;
        }

        cout << "\n--- Available Pipeline Connections ---\n";
        cout << left << setw(22) << "From"
             << setw(22) << "To" << "Cost\n";

        for (int i = 0; i < edgeCount; i++)
        {
            cout << left << setw(22) << point[edges[i].u]
                 << setw(22) << point[edges[i].v]
                 << edges[i].cost << endl;
        }
    }

    void kruskal()
    {
        if (vertices == 0)
        {
            cout << "Add distribution points first!\n";
            return;
        }

        if (vertices == 1)
        {
            cout << "Only one point exists. No pipeline is needed.\n";
            return;
        }

        if (edgeCount == 0)
        {
            cout << "No pipeline connections available!\n";
            return;
        }

        Edge sorted[MAXE];
        for (int i = 0; i < edgeCount; i++)
            sorted[i] = edges[i];

        // Bubble sort keeps the program compatible with older Dev-C++ compilers.
        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (sorted[j].cost > sorted[j + 1].cost)
                {
                    Edge temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        int parent[MAXV], rankSet[MAXV];
        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
            rankSet[i] = 0;
        }

        int selected = 0;
        long long totalCost = 0;

        cout << "\n--- Minimum-Cost Pipeline Network (Kruskal) ---\n";
        cout << left << setw(22) << "From"
             << setw(22) << "To" << "Cost\n";

        for (int i = 0; i < edgeCount && selected < vertices - 1; i++)
        {
            if (unionSets(parent, rankSet, sorted[i].u, sorted[i].v))
            {
                cout << left << setw(22) << point[sorted[i].u]
                     << setw(22) << point[sorted[i].v]
                     << sorted[i].cost << endl;

                totalCost += sorted[i].cost;
                selected++;
            }
        }

        if (selected != vertices - 1)
        {
            cout << "\nNetwork is disconnected. All points cannot be connected.\n";
            cout << "The selected connections form a minimum spanning forest.\n";
        }
        else
        {
            cout << "\nAll distribution points are connected.\n";
        }

        cout << "Total minimum installation cost: " << totalCost << endl;
        cout << "Pipeline connections selected: " << selected << endl;
    }
};

int main()
{
    PipelineNetwork network;
    int choice;

    do
    {
        cout << "\n===== WATER PIPELINE NETWORK =====\n";
        cout << "1. Add Distribution Point\n";
        cout << "2. Add Pipeline Connection\n";
        cout << "3. Display Distribution Points\n";
        cout << "4. Display Available Pipelines\n";
        cout << "5. Find Minimum-Cost Network (Kruskal)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: network.addPoint(); break;
            case 2: network.addPipeline(); break;
            case 3: network.displayPoints(); break;
            case 4: network.displayPipelines(); break;
            case 5: network.kruskal(); break;
            case 6: cout << "Program terminated.\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
