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
   int n,k;cin>>n>>k;
   vector<int>a(n);
   for(int i=0;i<n;i++){
       cin>>a[i];}
    sort(a.begin(),a.end());
    bool f=true,f1=true;
   for(int i=1;i<n;i++){
       if((a[i]-a[0])%k!=0)f=false;
   }
   if(!f)cout<<-1;
   else{
       int res=0;
       for(int i=1;i<n;i++){
           res+=((a[i]-a[0])/k);
       }
       cout<<res;
   }

 
    return 0;
 
}