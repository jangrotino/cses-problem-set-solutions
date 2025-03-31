#include<iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int values[3][n];
    int dp[3][n];

    for(int i = 0; i < n; i++)
    {
        cin >> values[0][i] >> values[1][i] >> values[2][i];
    }

    dp[0][0] = values[0][0];
    dp[1][0] = values[1][0];
    dp[2][0] = values[2][0];

    for(int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i - 1] + values[0][i], dp[2][i - 1] + values[0][i]);
        dp[1][i] = max(dp[0][i - 1] + values[1][i], dp[2][i - 1] + values[1][i]);
        dp[2][i] = max(dp[1][i - 1] + values[2][i], dp[0][i - 1] + values[2][i]);
    }

    int answer = max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);

    cout << answer << endl;

    return 0;
}