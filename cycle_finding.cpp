#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    vector<int> neigbhour(n + 1);
    vector<long long> distance(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;

        cin >> a >> b >> w;

        edges.push_back(tie(a, b, w));
    }

    int pom;

    for (int i = 1; i < n + 1; i++)
    {
        pom = -1;
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e;

            if (distance[b] > distance[a] + w)
            {
                neigbhour[b] = a;
                distance[b] = distance[a] + w;
                pom = b;
            }
        }
    }

    if (pom == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        int y = pom;
        for (int i = 0; i < n; i++)
        {
            y = neigbhour[y];
        }

        vector<int> path;

        for (int cur = y;; cur = neigbhour[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
            {
                break;
            }
        }
        reverse(path.begin(), path.end());

        cout << "YES" << endl;

        for (auto a : path)
        {
            cout << a << " ";
        }
    }

    return 0;
}