#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<double> prob;
    int size = 0;
    double dp[size+1][size+1] = {};
    double ans = 0;

    prob.push_back(0);

    cin >> size;

    for(int i = 0; i < size; i++)
    {
        double pom = 0;
        cin >> pom;
        prob.push_back(pom);
    }

    dp[0][0] = 1.0;

    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j <= size; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i - 1][j] * (1.0 - prob[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = (size+1) / 2; i <= size; i++)
    {
        ans += dp[size][i];
    }

    cout << ans << endl;

    return 0;
}