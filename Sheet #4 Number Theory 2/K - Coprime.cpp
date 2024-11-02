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
   string s1,s2;cin>>s1>>s2;
  if(s1==s2)cout<<s1;
  else cout<<1;

 
    return 0;
 
}