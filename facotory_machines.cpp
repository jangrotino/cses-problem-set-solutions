#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long machines = 0, products = 0;
    vector<long long> tab;
    long long start = 0;
    long long end = 1e18;
    long long sum = 0;
    long long med = 0;
    long long ans = 0;

    cin >> machines >> products;

    for(int i = 0; i < machines; i++)
    {
        int pom;
        cin >> pom;
        tab.push_back(pom);
    }

    sort(tab.begin(), tab.end());

    while(start <= end)
    {
        med = (start + end) / 2;
        sum = 0;
        for(int i = 0; i < machines; i++)
        {
            sum += med / tab[i];
            if(sum >= products)
            {
                break;
            }
        }

        if(sum >= products)
        {
            ans = med;
            end = med - 1;
        }
        else
        {
            start = med + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
