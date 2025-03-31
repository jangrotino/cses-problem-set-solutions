#include<iostream>

using namespace std;

int main()
{
    int n = 0;
    int steps = 1;

    cin >> n;

    while(n > 9)
    {
        int max_dig = 0;
        int pom = 10;
        int reserve = n;

        while(reserve > 0)
        {
            max_dig = max(max_dig, (reserve % pom));
            reserve /= pom;
        }

        n -= max_dig;
        steps++;
    }

    cout << steps << endl;

    return 0;
}