#include <bits/stdc++.h>
 
using namespace std;
using ll = unsigned long long;
ll dp[20] = {};
ll powe[20] = {};
 
int digit(char s)
{
    return s - '0';
}
 
ll corr_digits(string s)
{
    ll ans = (10 - digit(s[0]) - 1) * powe[s.size()-1];
    int curr_dig = 0;
    int prev_dig = 0;
 
    for(int i = 1; i < s.size(); i++)
    {
        curr_dig = digit(s[i]);
        prev_dig = digit(s[i-1]);
 
        if(curr_dig > prev_dig)
        {
            ans += (10 - curr_dig - 1) * powe[s.size()-i-1];
        }
        else if(curr_dig < prev_dig)
        {
            ans += max((10 - curr_dig - 2),0) * powe[s.size()-i-1];
        }
        else
        {
            ans += (10 - curr_dig - 1) * powe[s.size()-i-1];
            return ans;
        }
    }
    
    return ans;
}

bool diff_dig(string s)
{
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i-1] == s[i])
        {
            return false;
        }
    }
    return true;
}
 
int main()
{   
    ll a, b;
    string s1, s2;
 
    cin >> a >> b;
    
    s1 = to_string(a);
    s2 = to_string(b);
    dp[0] = 10;
    powe[0] = 1;

    for(int i = 1; i < 20; i++)
    {
        powe[i] = powe[i-1]*9;
    }
 
    for(int i = 1; i < max(s1.size(), s2.size()); i++)
    {
        dp[i] = dp[i-1] + powe[i+1];
    }

    ll ans1 = (dp[s2.size()-1] - corr_digits(s2));
    ll ans2 = (dp[s1.size()-1] - corr_digits(s1));

    if(diff_dig(s1))
        ans1++;

    cout << ans1 - ans2 << endl;

    return 0;
}