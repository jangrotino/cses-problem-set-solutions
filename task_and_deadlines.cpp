#include <bits/stdc++.h>

using namespace std;

int main()
{   
    vector<pair<int, int>> tab;
    int n;
    long long curr_time = 0;
    long long answer = 0;

    cin >> n;

    for(int i = 0;i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tab.push_back({a, b});
    }

    sort(tab.begin(), tab.end());

    for(int i = 0; i < n; i++)
    {
        curr_time += tab[i].first;
        answer += tab[i].second - curr_time; 
    }

    cout << answer << endl;

    return 0;
}
