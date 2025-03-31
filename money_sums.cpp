#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int sum = 0;
    int ans = 0;

    cin >> n;

    int tab[n] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
        sum += tab[i];
    }

    int dp[sum+1] = {};
    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= 1; j--)
        {
            if(dp[j-tab[i]] == 1 && j - tab[i] >= 0)
            {
                dp[j] = 1;
            }
        } 
    }

    for(int i = 1; i < sum + 1; i++)
    {
        if(dp[i])
        {
            ans++;
        }
    }

    cout << ans << endl;

    for(int i = 1; i < sum + 1; i++)
    {
        if(dp[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}