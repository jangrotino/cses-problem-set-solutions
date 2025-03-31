#include<bits/stdc++.h>

using namespace std;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int max_cnt = 0;
    long long mod = 1000000007;

    cin >> n;

    int query[n] = {};
    int pom = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> pom;
        query[i] = pom;
        max_cnt = max(query[i], max_cnt);
    }

    long long tab[2][max_cnt] = {{}, {}};
    tab[0][0] = 1;
    
    tab[1][0] = 1;

    for(int i = 1; i < max_cnt; i++)
    {
        tab[0][i] = (4 * tab[0][i-1] + tab[1][i-1]) % mod;
        tab[1][i] = (tab[0][i-1] + 2 * tab[1][i-1]) % mod;
    }

    for(int i = 0; i < n; i++)
    {
        cout << (tab[0][query[i]-1] + tab[1][query[i]-1]) % mod << endl;
    }

    return 0;
}