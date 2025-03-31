#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int tab[a+1][b+1] = {};
    int last_pos = 0;

    for(int i = 1; i < a + 1; i++)
    {
        tab[i][0] = -1;
        for(int j = 1; j < b + 1; j++)
        {
            if(j == 1)
            {
                tab[i][j] = tab[j][i];
            }
            else if(j % i == 0)
            {
                tab[i][j] = tab[i][j-i] + 1;
                last_pos = j;
            }
            else
            {
                tab[i][j] = tab[i][j - last_pos] + 1;
            }
        }
    }

    for(int i = 1; i < a + 1; i++)
    {
        for(int j = 1; j < b + 1; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << tab[a][b] << endl;

    return 0;
}