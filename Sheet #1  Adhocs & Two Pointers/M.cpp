#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("paintbarn.in", "r", stdin);
   // freopen("paintbarn.out", "w", stdout);
   int n , x;
   cin >> n >> x;
   vector<ll>nums(n+1);
    for (int i = 1; i <=n; ++i) {
        cin >>nums[i];
        nums[i]+=nums[i-1];
    }
    map<ll,ll>prefix_freq;
    ll count = 0;
    prefix_freq[0]=1;
    for (int i = 1; i <= n; ++i) {
        count+= prefix_freq[nums[i]-x];
        prefix_freq[nums[i]]++;
    }
    cout << count;
}
