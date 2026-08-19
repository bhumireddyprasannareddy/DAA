#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    // dp[i] = minimum number of coins needed to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // 0 coins are needed to make amount 0
    dp[0] = 0;

    // Calculate minimum coins for every amount
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If amount cannot be formed
    if (dp[amount] > amount)
        return -1;

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);

    if (result == -1)
        cout << "Amount cannot be formed using the given coins." << endl;
    else
        cout << "Minimum number of coins required: " << result << endl;

    return 0;
}