#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> dijkstra(int start, vector<vector<pair<int, int>>> &ajd_list, int size)
{
    vector<bool> processed(ajd_list.size() + 1, 0);
    vector<unsigned long long> distance(ajd_list.size() + 1, ULLONG_MAX);
    priority_queue<pair<long long, int>> q;

    distance[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if (processed[a])
        {
            continue;
        }
        processed[a] = true;

        for (auto u : ajd_list[a])
        {
            int b = u.first;
            int w = u.second;

            if (distance[b] > distance[a] + w)
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }

    return distance;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> ajd_list(n + 1);
    vector<vector<pair<int, int>>> rev_ajd_list(n + 1);
    vector<unsigned long long> from_1;
    vector<unsigned long long> from_n;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;

        cin >> a >> b >> w;

        ajd_list[a].push_back({b, w});
        rev_ajd_list[b].push_back({a, w});
    }

    from_1 = dijkstra(1, ajd_list, n);
    from_n = dijkstra(n, rev_ajd_list, n);
    unsigned long long ans = ULLONG_MAX;

    for(int i = 1; i < n + 1; i++)
    {
        for(auto elem : ajd_list[i])
        {
            if(from_1[i] == ULLONG_MAX || from_n[elem.first] == ULLONG_MAX)
            {
                continue;
            }
            else
            {
                ans = min(ans, from_1[i] + from_n[elem.first] + elem.second / 2);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
