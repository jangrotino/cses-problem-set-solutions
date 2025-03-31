#include <bits/stdc++.h>

using namespace std;

int main()
{
    int customers, arraive, leave;
    int min_room = 0;
    vector<pair<pair<int, int>,int>> tab2;
    multimap<int, int> curr_rooms;

    cin >> customers;

    int tab[customers] = {};
    for(int i = 0; i < customers; i++)
    {
        int a, b;
        cin >> a >> b;
        tab2.push_back({{a, b}, i});
    }
    sort(tab2.begin(), tab2.end());

    for (int i = 0; i < customers; i++)
    {
        arraive = tab2[i].first.first;
        leave = tab2[i].first.second;

        if (curr_rooms.empty())
        {
            curr_rooms.insert({leave, i + 1});
            min_room++;
            tab[tab2[i].second] = 1;
        }
        else
        {
            if(curr_rooms.begin()->first >= arraive)
            {
                min_room++;
                tab[tab2[i].second] = curr_rooms.size() + 1;
                curr_rooms.insert({leave, tab[tab2[i].second]});
            }
            else
            {
                tab[tab2[i].second] = curr_rooms.begin()->second;
                curr_rooms.erase(curr_rooms.begin());
                curr_rooms.insert({leave, tab[tab2[i].second]});
            }
        }
    }

    cout << min_room << endl;

    for (int i = 0; i < customers; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    return 0;
}