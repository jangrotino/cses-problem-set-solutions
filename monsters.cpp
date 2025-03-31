#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> find_escape(vector<vector<char>> &map)
{
    vector<pair<int, int>> ans;

    for(int i = 0; i < map[0].size(); i++)
    {
        if(map[0][i] == '.' || map[0][i] == 'A')
        {
            ans.push_back({0, i});
        }

        if(map[map.size()-1][i] == '.' || map[map.size()-1][i] == 'A')
        {
            ans.push_back({map.size()-1, i});
        }
    }

    for(int i = 0; i < map.size(); i++)
    {
        if(map[i][0] == '.' || map[i][0] == 'A')
        {
            ans.push_back({i, 0});
        }

        if(map[i][map[0].size()-1] == '.' || map[i][map[0].size()-1] == 'A')
        {
            ans.push_back({i, map[0].size()-1});
        }
    }

    return ans;
}

void re_path(int x, int y, vector<vector<char>> &map, vector<vector<int>> &distances, string ans = "")
{
    while (distances[x][y] != 0)
    {
        if (x - 1 >= 0 && map[x - 1][y] != '#' && distances[x][y] - distances[x - 1][y] == 1)
        {
            ans += "U";
            x--;
        }
        else if (x + 1 < map.size() && map[x + 1][y] != '#' && distances[x][y] - distances[x + 1][y] == 1)
        {
            ans += "D";
            x++;
        }
        else if (y + 1 < map[0].size() && map[x][y + 1] != '#' && distances[x][y] - distances[x][y + 1] == 1)
        {
            ans += "R";
            y++;
        }
        else if (y - 1 >= 0 && map[x][y - 1] != '#' && distances[x][y] - distances[x][y - 1] == 1)
        {
            ans += "L";
            y--;
        }
    }
    
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;

}

bool dfs(int x, int y, vector<vector<char>> &map, pair<int, int> A_pos)
{
    queue<pair<int, int>> que;
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), 0));
    vector<vector<int>> distances(map.size(), vector<int>(map[0].size(), -1));
    visited[x][y] = true;
    distances[x][y] = 0;
    que.push({x, y});
    int close_M = INT_MAX;

    while (!que.empty())
    {
        pair<int, int> pom = que.front();
        x = pom.first;
        y = pom.second;
        que.pop();

        if (map[x][y] == 'M')
        {
            close_M = distances[x][y] + 1;
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

    if(close_M > distances[A_pos.first][A_pos.second])
    {
        re_path(A_pos.first, A_pos.second, map, distances);
        return true;
    }

    return false;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    pair<int, int> A_pos;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'A')
            {
                A_pos = {i, j};
            }
        }
    }

    vector<pair<int, int>> escapes = find_escape(map);
    bool pom = false;

    for(int i = 0; i < escapes.size(); i++)
    {
        pom = dfs(escapes[i].first, escapes[i].second, map, A_pos);
        if(pom)
        {
            break;
        }
    }

    if(!pom)
    {
        cout << "NO" << endl;
    }

    return 0;
}