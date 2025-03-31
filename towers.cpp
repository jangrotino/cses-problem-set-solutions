#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tow_num = 0;
    int tower = 0;
    multiset<int> towers;

    cin >> tower;

    for (int i = 0; i < tower; i++)
    {
        int number = 0;

        cin >> number;

        auto where = towers.upper_bound(number);

        if (where == towers.end())
        {
            tow_num++;
            towers.insert(number);
        }
        else
        {
            towers.erase(towers.find(*where));
            towers.insert(number);
        }
    }

    cout << tow_num << endl;

    return 0;
}
