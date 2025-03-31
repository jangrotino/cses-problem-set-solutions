#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    long long curr_sum = 0;
    long long ans = 0;
    cin >> n;
    vector<long long> pmod(n);
    pmod[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int a = 0;       
        cin >> a;
        curr_sum += a;
        pmod[(curr_sum % n + n) % n]++;
    }

    for(auto x : pmod)
    {
        ans += x * (x - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}