#include<bits/stdc++.h>

using namespace std;

int main()
{
    int cusotmers;
    int max_at_time = 0;

    cin >> cusotmers;

    vector<pair<int, int>> arr_and_leav;
    vector<int> arr(cusotmers);
    vector<int> leav(cusotmers);

    for(int i = 0; i < cusotmers; i++)
    {
        cin >> arr[i] >> leav[i];
        arr_and_leav.push_back(make_pair(arr[i], leav[i]));
    }

    sort(arr.begin(), arr.end());
    sort(leav.begin(), leav.end());

    for(int i = 0; i < cusotmers; i++)
    {
        int at_time = 0;

        auto at_arv = lower_bound(arr.begin(), arr.end(), arr_and_leav[i].first);
        auto at_leav = upper_bound(leav.begin(), leav.end(), arr_and_leav[i].first);
        at_time = (at_arv - arr.begin() + 1) - (at_leav - leav.begin() + 1) + 1;
        max_at_time = max(max_at_time, at_time);

        at_arv = lower_bound(arr.begin(), arr.end(), arr_and_leav[i].second);
        at_leav = upper_bound(leav.begin(), leav.end(), arr_and_leav[i].second);
        at_time = (at_arv - arr.begin() + 1) - (at_leav - leav.begin() + 1) + 1;
        max_at_time = max(max_at_time, at_time);
    }

    cout << max_at_time << endl;
}