#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;
    int sum=0;
    set<int> coins;
    int inf = INT_MAX - 1;

    cin >> n >> sum;

    int tab[sum + 1];
    tab[0] = 0;
    
    for(int i = 0; i < n; i++)
    {
        int pom;
        cin >> pom;
        coins.insert(pom);
    }

    for(int i = 1; i <= sum; i++)
    {
        tab[i] = inf;
        for(auto c : coins)
        {
            if(i - c >= 0)
            {
                tab[i] = min(tab[i], tab[i - c] + 1);
            }
        }
    }

    if(tab[sum] == inf)
    {
        cout << "-1";
    }
    else
    {
        cout << tab[sum];
    }

    return 0;
}