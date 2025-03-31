#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> gaps;
    set<int> traff_light;
    int x, n;
    cin >> x >> n;

    traff_light.insert(0);
    traff_light.insert(x);

    for (int i = 0; i < n; i++)
    {
        int pom = 0;

        cin >> pom;

        traff_light.insert(pom);
        auto where = traff_light.find(pom);
        int begin = *prev(where);
        int end = *next(where);
        auto where2 = gaps.find(end - begin);

        if (where2 != gaps.end())
        {
            gaps.erase(where2);
        }

        gaps.insert(pom - begin);
        gaps.insert(end - pom);
        cout << *gaps.rbegin() << endl;
    }

    return 0;
}