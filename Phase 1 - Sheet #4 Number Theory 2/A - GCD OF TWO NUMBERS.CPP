#include <bits/stdc++.h>
using namespace std;
const int N=262144+5;
#define int long long
int mod=1e9+7;
int gcd(int a,int b){
    if(b==0)return a;
    gcd(b,a%b);
}
 
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int a,b;
   cin>>a>>b;
   cout<<__gcd(a,b);
 
    return 0;
 
}