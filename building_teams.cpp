#include <bits/stdc++.h>

using namespace std;

bool bfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &team)
{
    queue<int> q;
    visited[start] = true;
    enum color
    {
        red = 1,
        black = 2
    };
    q.push(start);
    team[start] = red;

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        for (auto elem : adj_list[s])
        {
            if (team[s] == team[elem])
            {
                return false;
            }
            if (visited[elem])
            {
                continue;
            }
            q.push(elem);
            visited[elem] = true;
            if (team[s] == red)
            {
                team[elem] = black;
            }
            else
            {
                team[elem] = red;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    bool ans = true;
    vector<int> road_desc;

    cin >> n >> m;

    vector<vector<int>> ajd_list(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> team(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        ajd_list[a].push_back(b);
        ajd_list[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (!bfs(i, ajd_list, visited, team))
            {
                ans = false;
                break;
            }
        }
    }

    if (ans)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << team[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}