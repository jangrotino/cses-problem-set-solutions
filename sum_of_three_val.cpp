#include <bits/stdc++.h>

using namespace std;

int binarysearch(vector<unsigned int> &tab, int l, int r, unsigned int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if(tab[m] == x)
        {
            return m;
        }

        if(tab[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int find_index(vector<unsigned int> &pom, vector<unsigned int> &tab, int num)
{
    for(int i = 0; i < tab.size(); i++)
    {
        if(tab[num] == pom[i])
        {
            pom[i] = 0;
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    unsigned int x;

    cin >> n >> x;

    int start = 0;
    int end = n - 1;
    int num1 = -1;
    int num2 = -1;
    int num3 = -1;
    vector<unsigned int> tab(n);
    vector<unsigned int> pom(n);

    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
    pom = tab;
    sort(tab.begin(), tab.end());

    while(start < end)
    {
        if(tab[start] + tab[end] >= x)
        {
            end--;
        }
        if(tab[start] + tab[end] < x)
        {
            num1 = start;
            num2 = end;
            num3 = binarysearch(tab, 0, n-1, (x-(tab[num1]+tab[num2])));
            if(num3 != -1)
            {
                num1 = find_index(pom, tab, num1) + 1;
                num2 = find_index(pom, tab, num2) + 1;
                num3 = find_index(pom, tab, num3) + 1;
                if(num1 != num2 && num3 != num2 && num3 > 0)
                {
                    cout << num1 << " " << num2 << " " << num3 << endl;
                    return 0;
                }
            }
            start++;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}