#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    set<int> dice = {1, 2, 3, 4, 5, 6};

    cin >> n;

    int arr[n + 1] = {};
    arr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (auto c : dice)
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