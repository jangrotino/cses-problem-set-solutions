#include <bits/stdc++.h>
   
using namespace std;

   
   vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int> pom;
        vector<long long> ans(arr.size());
        vector<long long> sum(arr.size());
        
        pom = arr;
        sort(pom.begin(), pom.end());
        sum[0] = pom[0];
        
        for(int i = 1; i < n; i++)
        {
            sum[i] += pom[i] + sum[i-1];
        }
        
        for(int i = 0; i < n; i++)
        {
            auto place = upper_bound(pom.begin(), pom.end(), arr[i]);
            int pla = place - pom.begin();
            cout << pla << " " << sum[pla-1] << endl;
            ans[i] = sum[pla-1] - arr[i];
        }
        return ans;
   }
   int main()
   {    
        int n = 0;
        cin >> n;
        vector<int> tab(n);
        vector<long long> ans;
        for(int i = 0; i < n; i++)
        {
            cin >> tab[i];
        }
        ans = smallerSum(n, tab);
         for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
   }