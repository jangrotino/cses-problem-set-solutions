#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    int will_get = 0;
    int meters = 0;

    cin >> n >> m >> k;

    vector<int> applicants;
    vector<int> apartments;

    for (int i = 0; i < n; i++)
    {
        cin >> meters;
        applicants.push_back(meters);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> meters;
        apartments.push_back(meters);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int start_appl = 0;
    int start_aprt = 0;

    while(start_appl < n && start_aprt < m)
    {
        if(applicants[start_appl] - k <= apartments[start_aprt] && applicants[start_appl] + k >= apartments[start_aprt])
        {
            will_get++;
            start_appl++;
            start_aprt++;
        }
        else if(applicants[start_appl] + k <= apartments[start_aprt])
        {
            start_appl++;
        }
        else
        {
            start_aprt++;
        }
    }

    cout << will_get << endl;

    return 0;
}