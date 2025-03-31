#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    long long int mod = 1000000007;

    cin >> n;

    long long int sum = n * (n + 1) / 2;
    long long int dp[sum+1] = {};
    dp[0] = 1;

    for(int i = 1; i < n + 1; i++)
    {
        for(int j = sum; j >= 1; j--)
        {     
            if(dp[j-i] > 0 && j - i >= 0)
            {   
                dp[j-i] %= mod;
                dp[j] += dp[j-i];
            }
        }
    }
        
    if(sum % 2 == 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << dp[sum / 2] / 2 << endl;
    }

    return 0;
}