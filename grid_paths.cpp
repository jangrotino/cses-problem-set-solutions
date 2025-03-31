#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int size;
    long long int mod = 1000000007;
    cin >> size;
    long long int tab[size][size] = {};
    char grid[size][size] = {};

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '*')
    {
        tab[0][0] = 0;
    }
    else
    {
        tab[0][0] = 1;
    }

    for(int i = 1; i < size; i++)
    {
        if(grid[0][i] == '.')
        {
            tab[0][i] = tab[0][i - 1];
        }
        else
        {
            tab[0][i] = 0;
        }

        if(grid[i][0] == '.')
        {
            tab[i][0] = tab[i - 1][0];
        }
        else
        {
            tab[i][0] = 0;
        }
    }


    for(int i = 1; i < size; i++)
    {
        for(int j = 1; j < size; j++)
        {
            if(grid[i][j] == '.')
            {
                tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
                tab[i][j] %= mod;
            }
            else
            {
                tab[i][j] = 0;
            }
        }
    }
 
    cout << tab[size - 1][size - 1] << endl;
 
    return 0;
}