#include<bits/stdc++.h>

using namespace std;

bool bfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &distance, vector<int> &path)
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
            distance[elem] = distance[s] + 1;
            path[elem] = s;
        }
    }

    return visited[visited.size()-1];
}

int main()
{
    int n, m;
    vector<int> road_desc;

    cin >> n >> m;

    vector<vector<int>> ajd_list(n+1);
    vector<bool> visited(n+1, false);
    vector<int> distance(n+1, 0);
    vector<int> path(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        ajd_list[a].push_back(b);
        ajd_list[b].push_back(a);
    }
    
    if(bfs(1, ajd_list, visited, distance, path))
    {
        cout << distance[n] + 1 << endl;
        
        vector<int> ans;
        ans.push_back(n);

        while(ans.back() != 1)
        {
            int pom = path[ans.back()];
            ans.push_back(pom);
        }

        for(int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}