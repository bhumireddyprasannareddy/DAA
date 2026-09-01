#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

using namespace std;
using namespace chrono;

long long matrixChainMultiplication(vector<int>& p)
{
    int n = p.size() - 1;

    // DP table
    vector<vector<long long>> m(n + 1,
                                vector<long long>(n + 1, 0));

    // Chain length
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            m[i][j] = LLONG_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                long long cost =
                    m[i][k] +
                    m[k + 1][j] +
                    (long long)p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[1][n];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions:\n";
    cout << "For A1 = p0 x p1, A2 = p1 x p2, ...\n";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // Start timer
    auto start = high_resolution_clock::now();

    long long result = matrixChainMultiplication(p);

    // Stop timer
    auto end = high_resolution_clock::now();

    // Calculate execution time
    auto executionTime =
        duration_cast<microseconds>(end - start);

    cout << "\nMinimum number of scalar multiplications: "
         << result << endl;

    cout << "Execution Time: "
         << executionTime.count()
         << " microseconds" << endl;

    return 0;
}