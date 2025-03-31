#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    int mod = 1000000007;
    
    cin >> n >> m;

    swap(n, m);

    long long dp[n + 1] = {};
    dp[1] = n % 2;

    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            
        }
    }

    return 0;
}