#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, q;

    int max_tab = 0;

    cin >> n >> k >> q;

    int tab[n] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
        max_tab = max(tab[i], max_tab);
    } 

    int dp[max_tab+1][k+1] = {};
    int ans[n] = {};

    for(int i = 0; i <= k; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i < max_tab + 1; i++)
    {
        for(int j = 0; j < k + 1; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if(j > 0)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            if(j < k)
            {
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= q;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k + 1; j++)
        {
            ans[i] += dp[tab[i]][j];
            ans[i] %= q;
        }
        cout << ans[i] << " ";
    }

    return 0;
}