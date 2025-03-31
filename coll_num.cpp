#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> num;
    int n = 0;
    int odp = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int pom = 0;
        cin >> pom;
        num.insert(pair<int, int>(pom, i + 1));
    }

    for(auto x: num)
    {
        if(num.find(x.first + 1)->second < x.second)
        {
            odp++;
        }
    }

    cout << odp << endl;

    return 0;
}