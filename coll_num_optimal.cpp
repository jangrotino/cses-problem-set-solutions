#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int l = 1;
    int odp = 1;
    cin >> n;
    int tab[n + 1] = {0};

    for(int i = 1; i < n + 1; i++)
    {
        int pom;
        cin >> pom;
        tab[pom] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        if(l > tab[i])
            odp++;
        l = tab[i];
    }

    cout << odp << endl;

    return 0;
}
