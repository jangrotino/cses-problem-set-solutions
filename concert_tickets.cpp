#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n_ticket, n_customer;
 
    cin >> n_ticket >> n_customer;
 
    multiset<int> tick;
    int cust[n_customer];
 
    for(int i = 0; i < n_ticket; i++)
    {
        int pom;
        cin >> pom;
        tick.insert(pom);
    }
 
    for(int i = 0; i < n_customer; i++)
    {
        cin >> cust[i];
    }
 
    for(int i = 0; i < n_customer; i++)
    {
        auto position = tick.lower_bound(cust[i]);
 
        if(tick.size() == 0)
        {
            cout << "-1" << endl;
        } 
        else if(*position == cust[i])
        {
            cout << *position << endl;
            tick.erase(position);
        }
        else if(*position > cust[i] && position != tick.begin())
        {
            cout << *(prev(position)) << endl;
            tick.erase(prev(position));
        }
        else if(position == tick.end() && *(prev(position)) < cust[i])
        {
            cout << *(prev(position)) << endl;
            tick.erase(prev(position));
        }
        else if(position == tick.begin())
        {
            cout << "-1" << endl;
        }
    }
 
    return 0;
}