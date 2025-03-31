#include<bits/stdc++.h>
 
using namespace std;
 
int dfs(int start, vector<vector<int>> &ajd_list, vector<bool> &visited, vector<int> &cycle)
{
    stack<int> s;
    s.push(start);
 
    while(!s.empty())
    {
        int pom = s.top();
        s.pop();
 
        if(!visited[pom])
        {
            visited[pom] = true;
        }
 
        for(auto elem : ajd_list[pom])
        {
            if(!visited[elem])
            {
                cycle[elem] = pom;
                s.push(elem);
            }
            else if(cycle[pom] == elem || elem == start)
            {
                cycle[elem] = pom;
                return elem;
            }
        }
    }
 
    return 0;
}
 
int main()
{
    int n, m;
    int ans = 0;
    int start = 0;
 
    cin >> n >> m;
 
    vector<vector<int>> ajd_list(n+1);
    vector<bool> visited(n+1, 0);
    vector<int> cycle(n+1, 0);
 
    for(int i = 0; i < m; i++)
    {
        int a, b;
 
        cin >> a >> b;
 
        ajd_list[a].push_back(b);
    }
 
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            start = dfs(i, ajd_list, visited, cycle);
        }
 
        if(start)
        {
            break;
        }
    }
 
    if(start)
    {
        vector<int> ans;
        int pom = start;
 
        ans.push_back(start);
        while(cycle[pom] != start)
        {
            pom = cycle[pom];
            ans.push_back(pom);
        }
        ans.push_back(start);
 
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
 
        for(int i = 0; i < ans.size(); i++)
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