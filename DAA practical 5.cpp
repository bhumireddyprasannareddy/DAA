
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    int n, W;

    // Read number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Read maximum capacity of knapsack
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> wt(n), val(n);

    // Read weights of items
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    // Read profits of items
    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    // Start measuring execution time
    auto start = high_resolution_clock::now();

    // Create DP table with (n+1) rows and (W+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            // If current item's weight is less than or equal to capacity
            if (wt[i - 1] <= w)
            {
                // Choose maximum profit:
                // 1. Include the current item
                // 2. Exclude the current item
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                // Cannot include the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Stop measuring execution time
    auto stop = high_resolution_clock::now();

    // Calculate execution time in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Display maximum profit
    cout << "\nMaximum Profit = " << dp[n][W] << endl;

    // Display execution time
    cout << "Execution Time = " << duration.count()
         << " microseconds" << endl;

    return 0;
}
