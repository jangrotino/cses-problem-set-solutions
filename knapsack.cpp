#include<iostream>

using namespace std;

int main()
{
    int n, w;

    cin >> n >> w;

    int weight[n];
    int value[n];
    long long int dp[w + 1] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = w; j >= 0; j--)
        {
            if(weight[i - 1] <= j)
            {
                dp[j] = max(dp[j], dp[j - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[w] << endl;
}