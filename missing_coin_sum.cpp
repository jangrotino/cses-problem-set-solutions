#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size = 0;
    long long int curr_sum = 0;
    cin >> size;
    int tab[size] = {};

    for(int i = 0; i < size; i++)
    {
        cin >> tab[i];
    }

    sort(tab, tab + size);

    for(int i = 0; i < size; i++)
    {
        if(tab[i] > curr_sum + 1)
        {
            break;
        }
        curr_sum += tab[i];
    }

    cout << curr_sum + 1 << endl;

    return 0;
}