#include <bits/stdc++.h>

using namespace std;

void is_changed(int *tab, int *visited, int size, int &odp, int first_pos, int *orginal)
{
    if (visited[orginal[first_pos]] == 0 && tab[orginal[max(first_pos - 1, 1)]] > tab[orginal[first_pos]])
    {
        odp++;
        visited[orginal[first_pos]] = 1;
    }
    else if (visited[orginal[first_pos]] == 1 && tab[orginal[max(first_pos - 1, 1)]] < tab[orginal[first_pos]])
    {
        visited[orginal[first_pos]] = 0;
        odp--;
    }

    if (visited[orginal[min(first_pos + 1, size)]] == 0 && tab[orginal[first_pos]] > tab[orginal[min(first_pos + 1, size)]])
    {
        odp++;
        visited[orginal[min(first_pos + 1, size)]] = 1;
    }
    else if (visited[orginal[min(first_pos + 1, size)]] == 1 && tab[orginal[first_pos]] < tab[orginal[min(first_pos + 1, size)]])
    {
        odp--;
        visited[orginal[min(first_pos + 1, size)]] = 0;
    }
}

int main()
{
    int l = 1;
    int odp = 1;
    int n = 0;
    int m = 0;

    cin >> n >> m;

    int tab[n + 1] = {};
    int orginal[n + 1] = {};
    int visited[n + 1] = {};
    visited[1] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        int pom;
        cin >> pom;
        tab[pom] = i;
        orginal[i] = pom;
    }

    for (int i = 1; i <= n; i++)
    {
        if (l > tab[i])
        {
            odp++;
            visited[i] = 1;
        }
        l = tab[i];
    }

    for (int i = 0; i < m; i++)
    {
        int first_pos = 0;
        int second_pos = 0;

        cin >> first_pos >> second_pos;

        swap(orginal[first_pos], orginal[second_pos]);
        swap(tab[orginal[first_pos]], tab[orginal[second_pos]]);
        is_changed(tab, &visited[0], n, odp, first_pos, orginal);
        is_changed(tab, &visited[0], n, odp, second_pos, orginal);
        for (int i = 1; i <= n; i++)
        {
            cout << visited[i] << " ";
        }
        cout << endl;
        cout << odp << endl;
    }

    return 0;
}
