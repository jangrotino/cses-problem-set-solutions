#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;

    int weight[n] = {};
    int dp[n + 1] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    
    for(int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for(int j = 1; j <= min(i - 1, k); j++)
        {
            dp[i] = min(dp[i - j] + abs(weight[i - 1] - weight[i - j - 1]), dp[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}