#include<bits/stdc++.h>

using namespace std;

int bfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited)
{   
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int s = q.front();
        q.pop();

        for(auto elem : adj_list[s])
        {
            if(visited[elem])
            {
                continue;
            }
            q.push(elem);
            visited[elem] = true;
        }
    }

    return 1;
}

int main()
{
    int n, m;
    int ans = -1;
    vector<int> road_desc;

    cin >> n >> m;

    vector<vector<int>> ajd_list(n+1);
    vector<bool> visited(n+1, false);

    for(int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        ajd_list[a].push_back(b);
        ajd_list[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            ans += bfs(i, ajd_list, visited);
            road_desc.push_back(i);
        }
    }

    cout << ans << endl;

    for(int i = 1; i < road_desc.size(); i++)
    {
        cout << road_desc[i-1] << " " << road_desc[i] << endl;
    }

    return 0;
}