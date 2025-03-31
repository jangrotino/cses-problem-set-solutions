#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    int tab[n] = {};
    int dp[k+1][n] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }

    for(int i = 0; i < n; ++i)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i < k + 1; i++)
    {
        for(int m = 0; m < n; m++)
        {
            dp[i][m] = dp[i-1][m];
        }

        for(int j = 0; j < n; j++)
        {
            if(tab[j] != -1)
            {
                dp[i][tab[j]] = min(dp[i][tab[j]], dp[i-1][j] + 1);
            }
        }

        for(int l = 1; l < n; l++)
        {
            dp[i][l] = min(dp[i][l-1] + 1, dp[i][l]);
        }
    }
    
    cout << dp[k][n-1] << endl;

    return 0;
}