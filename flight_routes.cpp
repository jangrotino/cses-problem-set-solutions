#include <bits/stdc++.h>

using namespace std;

multiset<unsigned long long> k_shortest_dijkstra(int start, vector<vector<pair<int, int>>> &ajd_list, int size, int k)
{
    vector<int> p_to(size + 1);
    multiset<unsigned long long> ans;
    priority_queue<pair<unsigned long long, int>> q;
    q.push({0, start});

    while(!q.empty() && p_to[size] < k)
    {
        int pom = q.top().second;
        unsigned long long cost_pom = -q.top().first;

        q.pop();
        p_to[pom]++;

        if(pom == size)
        {
            ans.insert(cost_pom);
        }

        if(p_to[pom] <= k)
        {
            for(auto elem : ajd_list[pom])
            {
                unsigned long long cost = cost_pom + elem.second;
                q.push({-cost, elem.first});
            }
        }
    }

    return ans;
}

int main()
{   
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> ajd_list(n + 1);

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        
        cin >> a >> b >> w;

        ajd_list[a].push_back({b, w});
    }

    multiset<unsigned long long> ans = k_shortest_dijkstra(1, ajd_list, n, k);

    for(auto a : ans)
    {
        cout << a << " ";
    }

    return 0;
}