#include <bits/stdc++.h>
using namespace std;
const int N=262144+5;
#define int long long
int sz=1e9+7;

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1,a,b;cin>>t;
    while(t--){
         int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << "\n";
        } else {
            cout << b - (a % b) << "\n";
        }
        
    }
    return 0;
 
}