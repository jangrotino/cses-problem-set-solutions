#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<pair<int, int>> cont;
    int n = 0;

    cin >> n;

    int odp[n] = {};

    for(int i = 0; i < n; i++)
    {
        int pom = 0;
        cin >> pom;

        if(cont.empty())
        {
            cont.push({pom, i + 1});
            odp[i] = 0;
        }
        else if(cont.top().first < pom)
        {
            odp[i] = cont.top().second;
            cont.push({pom, i + 1});
        }
        else
        {
            while(!cont.empty())
            {
                if(cont.top().first >= pom)
                {
                    cont.pop();
                }
                else
                {
                    break;
                }
            }

            if(cont.empty())
            {
                odp[i] = 0;
                cont.push({pom, i + 1});
            }
            else
            {
                odp[i] = cont.top().second;
                cont.push({pom, i + 1});
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << odp[i] << " ";
    }

    return 0;
}