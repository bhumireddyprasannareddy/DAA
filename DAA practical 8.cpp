#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

class Graph {
private:
    int vertices;
    vector<vector<int>> graph;

public:

    // Constructor
    Graph(int v) {
        vertices = v;
        graph.resize(vertices);
    }

    // Add edge
    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Display graph
    void displayGraph() {
        cout << "\nGraph Representation:\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";

            for (int neighbor : graph[i]) {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }

    // DFS Helper Function
    void DFSHelper(int current, vector<bool>& visited) {

        visited[current] = true;

        cout << current << " ";

        for (int neighbor : graph[current]) {

            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }

    // DFS
    void DFS(int start) {

        vector<bool> visited(vertices, false);

        DFSHelper(start, visited);
    }

    // BFS
    void BFS(int start) {

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : graph[current]) {

                if (!visited[neighbor]) {

                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {

    int V, E;

    cout << "===== GRAPH TRAVERSAL =====\n";

    // Number of vertices
    cout << "\nEnter number of vertices: ";
    cin >> V;

    Graph g(V);

    // Number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    // Enter edges
    cout << "\nEnter edges (u v):\n";

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        if (u >= 0 && u < V && v >= 0 && v < V) {
            g.addEdge(u, v);
        }
        else {
            cout << "Invalid edge! Enter vertices between 0 and "
                 << V - 1 << ".\n";

            i--;
        }
    }

    // Display graph
    g.displayGraph();

    // Starting vertex
    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex!";
        return 0;
    }

    // Menu
    int choice;

    cout << "\n===== MENU =====\n";
    cout << "1. DFS\n";
    cout << "2. BFS\n";
    cout << "3. Both DFS and BFS\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // DFS
    if (choice == 1 || choice == 3) {

        auto startTime = high_resolution_clock::now();

        cout << "\nDFS Traversal: ";
        g.DFS(start);

        auto endTime = high_resolution_clock::now();

        auto dfsTime =
            duration_cast<nanoseconds>(endTime - startTime);

        cout << "\nDFS Execution Time: "
             << dfsTime.count() << " ns";
    }

    // BFS
    if (choice == 2 || choice == 3) {

        auto startTime = high_resolution_clock::now();

        cout << "\nBFS Traversal: ";
        g.BFS(start);

        auto endTime = high_resolution_clock::now();

        auto bfsTime =
            duration_cast<nanoseconds>(endTime - startTime);

        cout << "\nBFS Execution Time: "
             << bfsTime.count() << " ns";
    }

    if (choice < 1 || choice > 3) {
        cout << "\nInvalid choice!";
    }

    cout << "\n";

    return 0;
}
