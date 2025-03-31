#include <bits/stdc++.h>

using namespace std;

vector<int> topological_sort(int start, vector<vector<int>> &ajd_list, vector<int> &v_state)
{
    vector<int> ans;

    for (int i = 1; i < ajd_list.size(); i++)
    {
        if (v_state[i] == 0)
        {
            stack<int> s;
            s.push(i);

            while (!s.empty())
            {
                int pom = s.top();

                if (v_state[pom] == 1)
                {
                    v_state[pom] = 2;
                    ans.push_back(pom);
                    s.pop();
                    continue;
                }
                else if (v_state[pom] == 2)
                {
                    s.pop();
                    continue;
                }

                v_state[pom] = 1;

                for (auto elem : ajd_list[pom])
                {
                    if (v_state[elem] == 0)
                    {
                        s.push(elem);
                    }
                    else if (v_state[elem] == 1)
                    {
                        ans = {};
                        return ans;
                    }
                }
            }
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void max_city_num(vector<vector<int>> &ajd_list, vector<int> &topo_sort, int size)
{
    vector<int> dis(size + 1, -INT_MAX);
    vector<int> path(size + 1);
    vector<int> res_path;
    dis[1] = 1;
    path[1] = 1;

    for (int i = 1; i <= size + 1; i++)
    {
        int cur;
 
        if (i == 1)
            cur = 1;
        else
            cur = topo_sort[i - 1];

        for (auto elem : ajd_list[cur])
        {
            if (dis[elem] < dis[cur] + 1)
            {
                dis[elem] = dis[cur] + 1;
                path[elem] = cur;
            }
        }
    }

    if (dis[size] > 0)
    {
        cout << dis[size] << endl;

        for (int x = size; x != 1; x = path[x])
        {
            res_path.push_back(x);
        }
        res_path.push_back(1);

        for (int i = res_path.size() - 1; i >= 0; i--)
        {
            cout << res_path[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> ajd_list(n + 1);
    vector<int> v_state(n + 1, 0);
    vector<int> topo_sort;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        ajd_list[a].push_back(b);
    }

    topo_sort = topological_sort(1, ajd_list, v_state);
    max_city_num(ajd_list, topo_sort, n);

    return 0;
}