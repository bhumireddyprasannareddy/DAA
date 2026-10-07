#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    // Adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Start measuring execution time
    auto start = high_resolution_clock::now();

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    // Start from vertex 0
    key[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int minKey = INT_MAX;
        int u = -1;

        // Find the vertex with minimum key value
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        // Mark vertex as visited
        visited[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display Minimum Spanning Tree
    cout << "\nMinimum Spanning Tree (MST):\n";
    cout << "Edge\tWeight\n";

    int totalWeight = 0;

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "\nTotal MST Weight = " << totalWeight << endl;

    // Stop measuring execution time
    auto end = high_resolution_clock::now();

    auto executionTime =
        duration_cast<nanoseconds>(end - start);

    cout << "Execution Time = "
         << executionTime.count()
         << " nanoseconds" << endl;

    return 0;
}