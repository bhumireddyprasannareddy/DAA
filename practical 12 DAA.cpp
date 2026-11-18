
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> path;

    for(int i = 1; i < n; i++)
    {
        path.push_back(i);
    }

    int minCost = INT_MAX;
    vector<int> bestPath;

    do
    {
        int currentCost = 0;
        int k = 0;

        for(int i = 0; i < path.size(); i++)
        {
            currentCost += cost[k][path[i]];
            k = path[i];
        }

        currentCost += cost[k][0];

        if(currentCost < minCost)
        {
            minCost = currentCost;
            bestPath = path;
        }

    } while(next_permutation(path.begin(), path.end()));

    cout << "\nMinimum travelling cost: "
         << minCost << endl;

    cout << "Best Path: 0 ";

    for(int city : bestPath)
    {
        cout << "-> " << city;
    }

    cout << " -> 0" << endl;

    return 0;
}
