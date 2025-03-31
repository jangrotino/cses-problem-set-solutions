#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int cur_code = 0;

    cin >> n;

    for(int i = 0; i < pow(2, n); i++)
    {
        cur_code = i ^ (i>>1);

        for(int j = n - 1; j>=0; j--)
        {
            if(cur_code&(1<<j))
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        //cout << cur_code <<endl;
        cout << endl;
    }

    return 0;
}
