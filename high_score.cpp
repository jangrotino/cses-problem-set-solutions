#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &ajd_list, int start, int size)
{
    vector<int> visited(size + 1, 0);
    stack<int> s;

    s.push(start);

    while (!s.empty())
    {
        int pom = s.top();
        s.pop();

        if (!visited[pom])
        {
            visited[pom] = true;
        }

        for (auto e : ajd_list[pom])
        {
            if (!visited[e])
            {
                s.push(e);
            }
        }
    }

    return visited[size];
}

int main()
{
    int n, m;
    const long long inf = LLONG_MAX;

    cin >> n >> m;

    vector<tuple<int, int, int>> edge;
    vector<long long> distance(n + 1, -inf);
    vector<vector<int>> ajd_list(n + 1);
    vector<int> in_cycle;
    bool pom = false;

    distance[1] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        edge.push_back(make_tuple(a, b, c));
        ajd_list[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto e : edge)
        {
            int a, b, c;
            tie(a, b, c) = e;

            if (distance[a] > -inf)
            {
                if (distance[b] < distance[a] + c)
                {
                    distance[b] = min(inf, distance[a] + c);
                    if (n == i)
                    {
                        in_cycle.push_back(b);
                    }
                }
            }
        }
    }

    for (int i = 0; i < in_cycle.size(); i++)
    {
        if (dfs(ajd_list, in_cycle[i], n))
        {
            cout << "-1" << endl;
            pom = true;
            break;
        }
    }

    if(!pom)
        cout << distance[n] << endl;

    return 0;
}