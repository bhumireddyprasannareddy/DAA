
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find minimum travelling cost
int tsp(vector<vector<int>>& graph, vector<bool>& visited,
        int current, int count, int cost, int start, int n)
{
    // If all cities are visited
    if (count == n)
    {
        // Return to starting city
        return cost + graph[current][start];
    }

    int minCost = INT_MAX;

    // Visit all unvisited cities
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // Mark the city as visited
            visited[i] = true;

            // Calculate cost recursively
            int newCost = tsp(graph, visited, i,
                              count + 1,
                              cost + graph[current][i],
                              start, n);

            // Find minimum cost
            minCost = min(minCost, newCost);

            // Backtrack: mark city as unvisited
            visited[i] = false;
        }
    }

    return minCost;
}

int main()
{
    int n;

    // Get number of cities
    cout << "Enter number of cities: ";
    cin >> n;

    // Create adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    // Get travelling costs
    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Create visited array
    vector<bool> visited(n, false);

    // Start from city 0
    visited[0] = true;

    // Calculate minimum travelling cost
    int result = tsp(graph, visited, 0, 1, 0, 0, n);

    // Display result
    cout << "\nMinimum travelling cost: " << result << endl;

    return 0;
}
