#include <bits/stdc++.h>

using namespace std;

int main()
{
    int coin = 0;
    int n = 0;
    set<int> dice;

    cin >> coin >> n;

    for (int i = 0; i < coin; i++)
    {
        int pom = 0;
        cin >> pom;
        dice.insert(pom);
    }

    int arr[n + 1] = {};
    arr[0] = 1;

    for (auto c : dice)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i - c >= 0)
            {
                arr[i] += arr[i - c];
                arr[i] %= 1000000007;
            }
        }
    }

    cout << arr[n] << endl;

    return 0;
}