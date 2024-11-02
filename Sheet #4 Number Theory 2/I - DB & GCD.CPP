#include <bits/stdc++.h>
using namespace std;
const int N=262144+5;
#define int long long
int mod=1e9+7;

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
   while(t--){
       int n;cin>>n;
       vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];
           int res=__gcd(a[0],a[1]);
           for (int i = 2; i < n; i++)res=__gcd(res,a[i]);
           if(res>1)cout<<-1;
           else cout<<n;
           cout<<"\n";
   }

 
    return 0;
 
}