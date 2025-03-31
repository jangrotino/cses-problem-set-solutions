#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n = 0; 
    int odp = 0;
    int curr = 0;
    int last = 0;
    int counter = 0;
    map<int, int> repeat;
    repeat.insert({0, 0});
    cin >> n;
 
    int tab[n] = {};
 
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
 
    while(counter < n)
    {
        auto where = repeat.find(tab[counter]);
 
        if(where == repeat.end())
        {
            repeat.insert({tab[counter], counter});
            curr++;
        }
        else if(where->second < last)
        {
            repeat.erase(where->first);
            repeat.insert({tab[counter], counter});
            curr++;
        }
        else
        {
            last = where->second;
            repeat.erase(where->first);
            repeat.insert({tab[counter], counter});
            odp = max(curr, odp);
            curr = counter - last;
        }
        counter++;
    }
 
    cout << odp << endl;
 
    return 0;
}