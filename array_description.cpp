#include<iostream>
 
using namespace std;
 
int main()
{
    int n, m;
    int mod = int(10e8) + 7;
 
    cin >> n >> m;
 
    long long tab[n] = {};
    long long dp[n+1][m+1] = {};
    long long ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
 
    for(int i = 1; i < m + 1; i++)
    {
        if(tab[0] == 0)
        {
            dp[1][i] = 1;
        }
        else
        {
            dp[1][tab[0]] = 1;
            break;
        }
    }
 
    for(int i = 2; i < n + 1; i++)
    {
        for(int j = 1; j < m + 1; j++)
        {
            if(tab[i-1] == 0)
            {
                if(j > 1)
                {
                    dp[i][j] += dp[i-1][j-1];
                }
                if(j < m)
                {
                    dp[i][j] += dp[i-1][j+1];
                }
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            else if(tab[i-1] > 0 && tab[i-1] == j)
            {
                if(j > 1)
                {
                    dp[i][tab[i-1]] += dp[i-1][j-1];
                }
                if(j < m)
                {
                    dp[i][tab[i-1]] += dp[i-1][j+1];
                }
                dp[i][tab[i-1]] += dp[i-1][j];
                dp[i][tab[i-1]] %= mod;
            }
        }
    }
 
    for(int i = 1; i < m + 1; i++)
    {
        ans += dp[n][i];
        ans %= mod;
    }
 
    cout << ans << endl;
 
    return 0;
}