#include<iostream>

using namespace std;

int main()
{
    int n = 5;

    //cin >> n;

    int weights[n] = {5, 4, 9, 1, 4};
    int dp[n + 1] = {};

    /*for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }*/

    dp[2] = abs(weights[0] - weights[1]);

    for(int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(weights[i - 1] - weights[i - 2]), dp[i - 2] + abs(weights[i - 1] - weights[i - 3]));
    }

    cout << dp[n] << endl;

    return 0;
}