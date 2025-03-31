#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    int tab[2][size] = {{}};
    set<pair<int,int>> range;

    for(int i = 0; i < size; i++)
    {
        int a, b; 

        cin >> a >> b;

        range.insert(make_pair(a, b));
        auto contains = range.lower_bound(make_pair(a, b));
        auto it_contains = range.upper_bound(make_pair(a, b));

        /*if((*contains).first >= a && (*contains).second >= b && contains != range.end())
        {
            tab[0][i] = 1;
        }*/

        /*if((*it_contains).first <= a && (*it_contains).second <= b && it_contains != range.end())
        {
            tab[1][i] = 1;
        }*/
        //cout << (*contains).first << endl;

    }

    for(int i = 0; i < size; i++)
    {
        cout << tab[0][i] << " ";
    }
    cout << endl;

    for(int i = 0; i < size; i++)
    {
        cout << tab[1][i] << " ";
    }

    cout << endl;

    return 0;
}