#include <bits/stdc++.h>

using namespace std;

pair<int, int> bfs(int x, int y, vector<vector<char>> &map, vector<vector<bool>> &visited, vector<vector<int>> &distances)
{
    queue<pair<int, int>> que;
    visited[x][y] = true;
    distances[x][y] = 0;
    que.push({x, y});

    while (!que.empty())
    {
        pair<int, int> pom = que.front();
        x = pom.first;
        y = pom.second;
        que.pop();

        if (map[x][y] == 'B')
        {
            break;
        }

        if (x - 1 >= 0 && map[x - 1][y] != '#' && visited[x - 1][y] == false)
        {
            que.push({x - 1, y});
            visited[x - 1][y] = true;
            distances[x - 1][y] = distances[x][y] + 1;
        }

        if (x + 1 < map.size() && map[x + 1][y] != '#' && visited[x + 1][y] == false)
        {
            que.push({x + 1, y});
            visited[x + 1][y] = true;
            distances[x + 1][y] = distances[x][y] + 1;
        }

        if (y + 1 < map[0].size() && map[x][y + 1] != '#' && visited[x][y + 1] == false)
        {
            que.push({x, y + 1});
            visited[x][y + 1] = true;
            distances[x][y + 1] = distances[x][y] + 1;
        }

        if (y - 1 >= 0 && map[x][y - 1] != '#' && visited[x][y - 1] == false)
        {
            que.push({x, y - 1});
            visited[x][y - 1] = true;
            distances[x][y - 1] = distances[x][y] + 1;
        }
    }

    return make_pair(x, y);
}

string dfs(int x, int y, vector<vector<char>> &map, vector<vector<int>> &distances, string ans = "")
{
    /*if(map[x][y] == 'A')
    {
        reverse(ans.begin(), ans.end());
        return ans;
    }

    if(x - 1 >= 0 && map[x-1][y] != '#' && distances[x][y] - distances[x-1][y] == 1)
    {
        ans += "D";
        return dfs(x-1, y, map, distances, ans);
    }
    else if(x + 1 < map.size() && map[x+1][y] != '#' && distances[x][y] - distances[x+1][y] == 1)
    {
        ans += "U";
        return dfs(x+1, y, map, distances, ans);
    }
    else if(y + 1 < map[0].size() && map[x][y+1] != '#' && distances[x][y] - distances[x][y+1] == 1)
    {
        ans += "L";
        return dfs(x, y+1, map, distances, ans);
    }
    else if(y - 1 >= 0 && map[x][y-1] != '#' && distances[x][y] - distances[x][y-1] == 1)
    {
        ans += "R";
        return dfs(x, y-1, map, distances, ans);
    }
    return ans;
    */
    while (map[x][y] != 'A')
    {
        if (x - 1 >= 0 && map[x - 1][y] != '#' && distances[x][y] - distances[x - 1][y] == 1)
        {
            ans += "D";
            x--;
        }
        else if (x + 1 < map.size() && map[x + 1][y] != '#' && distances[x][y] - distances[x + 1][y] == 1)
        {
            ans += "U";
            x++;
        }
        else if (y + 1 < map[0].size() && map[x][y + 1] != '#' && distances[x][y] - distances[x][y + 1] == 1)
        {
            ans += "L";
            y++;
        }
        else if (y - 1 >= 0 && map[x][y - 1] != '#' && distances[x][y] - distances[x][y - 1] == 1)
        {
            ans += "R";
            y--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    pair<int, int> ans;

    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    vector<vector<int>> distances(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'A')
            {
                ans = bfs(i, j, map, visited, distances);
            }
        }
    }

    if (map[ans.first][ans.second] == 'B')
    {
        cout << "YES" << endl;
        cout << distances[ans.first][ans.second] << endl;
        cout << dfs(ans.first, ans.second, map, distances);
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}