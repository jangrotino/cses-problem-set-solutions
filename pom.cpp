#include <bits/stdc++.h>

using namespace std;

int sum = 0; 

void f(int x, int y, int visited)
{
    if((x < 0 || x > 3) || (y < 0 || y > 3))
    {
        return;
    }
    if((x == 3 && y == 3)){
        sum+=1;
        return;
    }
    //tab[x][y] = 1;
    f(x + 1, y, visited+1);
    //tab[x][y] = 0;
    f(x, y - 1, visited+1);
    //tab[x][y] = 1;
    f(x, y + 1, visited+1);
    //tab[x][y] = 0;
    f(x - 1, y, visited+1);
    //tab[x][y] = 1;
    //tab[x][y] = 0;
}

int main()
{
    //int n = 0;
    //int sum = 0;
    //int tab[3][3] = {};
    //tab[0][0] = 1;
    f(0, 0, 1);
    cout << sum << endl;

    return 0;
}