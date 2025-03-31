#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    set<int> numbers;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int pom = 0;
        cin >> pom;
        numbers.insert(pom);
    }

    cout << numbers.size() << endl;

    return 0;
}