#include<iostream>

using namespace std;

int main()
{
    int n = 0;
    
    cin >> n;

    int tab[n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        int max_dig = 0;
        int pom = 10;
        int reserve = i;

        while(reserve > 0)
        {
            max_dig = max(max_dig, (reserve % pom));
            reserve /= pom;
        }
        
        tab[i] += tab[i - max_dig];
        tab[i]++;
    }

    cout << tab[n] << endl;

    return 0;
}