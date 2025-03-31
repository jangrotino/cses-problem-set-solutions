#include <bits/stdc++.h>

using namespace std;

vector<long long> dijkstra(int start, vector<vector<pair<int, int>>> &ajd_list, int size)
{
    vector<long long> dis(size + 1, LLONG_MAX);
    vector<bool> vis(size + 1, false);
    priority_queue<pair<long long, int>> q;

    dis[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if(vis[a])
        {
            continue;
        }

        vis[a] = true;

        for (auto elem : ajd_list[a])
        {
            int b, w;

            b = elem.first;
            w = elem.second;

            if (dis[b] > dis[a] + w)
            {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }

    return dis;
}

void answer(int start, vector<vector<pair<int, int>>> &ajd_list, int size)
{ 
    const int mod = 1000000007;
    vector<long long> dis;
    vector<long long> min_dis_num(size + 1, 0);
    vector<int> min_fly_num(size + 1, INT_MAX);
    vector<int> max_fly_num(size + 1, 0);
    //priority_queue<pair<long long, int>> q;


    min_dis_num[start] = 1;
    min_fly_num[start] = 0;
    dis = dijkstra(start, ajd_list, size);

    for(int i = start; i < size + 1; i++)
    {
        for (auto elem : ajd_list[i])
        {
            int b, w;

            b = elem.first;
            w = elem.second;

            if (dis[b] == dis[i] + w)
            {
                min_fly_num[b] = min(min_fly_num[b], min_fly_num[i] + 1);
                max_fly_num[b] = max(max_fly_num[b], max_fly_num[i] + 1);
                min_dis_num[b] += min_dis_num[i];
                min_dis_num[b] %= mod;
            }
        }
    }

    /*q.push({0, start});

    while (!q.empty())
    {
        int i = q.top().second;
        q.pop();

        for (auto elem : ajd_list[i])
        {
            int b, w;

            b = elem.first;
            w = elem.second;

            if (dis[b] == dis[i] + w)
            {
                min_fly_num[b] = min(min_fly_num[b], min_fly_num[i] + 1);
                max_fly_num[b] = max(max_fly_num[b], max_fly_num[i] + 1);
                min_dis_num[b] += min_dis_num[i];
                min_dis_num[b] %= mod;
                q.push({-dis[b], b});
            }
        }
    }*/


    cout << dis[size] << " ";
    cout << min_dis_num[size] << " ";
    cout << min_fly_num[size] << " ";
    cout << max_fly_num[size] << endl;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> ajd_list(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;

        cin >> a >> b >> w;

        ajd_list[a].push_back({b, w});
    }

    answer(1, ajd_list, n);

    return 0;
}