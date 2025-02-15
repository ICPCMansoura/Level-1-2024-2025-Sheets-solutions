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
    int a,b;cin>>a>>b;
    int ans = 0;
    for(int i =0;i<=32;i++){
        if((bool)(a&(1ll << i)) + (bool)(b&(1ll << i)) == 1)ans |= (1ll<<i);
    }
    cout << ans << '\n';
}


signed main() {
    fastIO();
    fileIO();
    int t;cin>>t;
    while (t--)
    solve();
    return 0;
}