#include <iostream>

using namespace std;

int coinChange(int coins[], int n, int sum) {
    int dp[sum + 1];
    dp[0] = 1;
    
    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main() {
    int sum;
    cout << "Enter the sum: ";
    cin >> sum;

    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n];
    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int num_ways = coinChange(coins, n, sum);
    cout << "Number of ways to make " << sum << " is " << num_ways << endl;

    return 0;
}
