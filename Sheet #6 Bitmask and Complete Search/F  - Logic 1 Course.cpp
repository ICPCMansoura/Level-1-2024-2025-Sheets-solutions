#include <bits/stdc++.h>
#define int long long
#ifndef ONLINE_JUDGE
#define DBG_MACRO_MINIMAL
#define DBG_MACRO_SINGLE_LINE
#include "dbg.h"
#else
#define dbg(...)
#endif


#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) (__builtin_ctzll(x))
#define bit_count(x) (__builtin_popcountll(x))

using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
#endif
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int t,n,x;cin>>t>>n>>x;
    if(t == 1){
        int m = 1;
        int ans = 0;
        while (n){
            ans += (n%10)*m;
            n /= 10;
            m *= x;
        }
        cout << ans << '\n';
    }
    else{
        string ans;
        while (n){
            ans += to_string(n%x);
            n/=x;
        }
        std::reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}


signed main() {
    fastIO();
    fileIO();
    solve();
    return 0;
}