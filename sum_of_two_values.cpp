#include <bits/stdc++.h>

using namespace std;

int main()
{
    int numbers, value;
    vector<int> sort_num;
    vector<int> unsort_num;
    pair<int, int> num_pos(-1, -1);

    cin >> numbers >> value;

    for (int i = 0; i < numbers; i++)
    {
        int pom;
        cin >> pom;

        unsort_num.push_back(pom);
    }

    sort_num = unsort_num;

    sort(sort_num.begin(), sort_num.end());

    vector<int>::iterator beginning = sort_num.begin();
    vector<int>::iterator ending = prev(sort_num.end());

    while (beginning != ending)
    {
        if (*beginning + *ending > value)
        {
            ending = prev(ending);
        }
        else if (*beginning + *ending < value)
        {
            beginning = next(beginning);
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < numbers; i++)
    {
        if (*beginning == unsort_num[i] && num_pos.first == -1)
        {
            num_pos.first = i + 1;
        }

        if (*ending == unsort_num[i])
        {
            num_pos.second = i + 1;
        }
    }

    if (beginning == ending)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << min(num_pos.first, num_pos.second)
             << " " << max(num_pos.first, num_pos.second) << endl;
    }

    return 0;
}