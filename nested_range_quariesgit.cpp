#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    int tab[2][size] = {};
    map<int, int> ranges;

    for(int i = 0; i < size; i++)
    {
        int a, b;
        cin >> a >> b;
        auto contains = ranges.upper_bound(a);
        /*if(contains->first == a && contains->second < b)
        {
            contains->second = b;
        }*/

        if(contains->first <= a && contains->second >= b)
        {
            tab[0][i] = 1;
        }
        ranges.insert({a, b});
    }

   /*for(auto a: ranges)
    {
        cout << a.first << " " << a.second << endl;
    }*/
    for(int i = 0; i < size; i++)
    {
       cout << tab[0][i] << " ";
    }



    return 0;
}