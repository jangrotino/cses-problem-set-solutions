#include <bits/stdc++.h>

using namespace std;

int main()
{
    int stick_num = 0;
    int median = 0;
    long long int odp = 0;

    cin >> stick_num;

    int tab[stick_num] = {};

    for(int i = 0; i < stick_num; i++)
    {
        cin >> tab[i];
    }

    sort(tab, tab + stick_num);
    median = tab[stick_num / 2];

    for(int i = 0; i < stick_num; i++)
    {
        odp += abs(median - tab[i]);
    }

    cout << odp << endl;

    return 0;
}