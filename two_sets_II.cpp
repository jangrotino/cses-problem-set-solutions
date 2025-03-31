#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    long long int ans = 0;
    long long int mod = 10e9 + 7;

    cin >> n;

    int sum = n * (1 + n) / 2;

    long long int dp[n+1][sum+1] = {};

    for(int i = 1; i < n + 1; i++)
    {
        dp[i-1][0] = 1;
        for(int j = sum; j >= 1; j--)
        {
            if(dp[i-1][j-i] > 0)
            {
                dp[i][j] += dp[i-1][j-i] + 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    ans = dp[n][sum/2];

    if(sum % 2 == 1)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}