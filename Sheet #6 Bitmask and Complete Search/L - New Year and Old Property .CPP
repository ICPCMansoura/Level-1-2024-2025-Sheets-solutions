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
int a,b,ans=0;
bool f(int val){
    return val >= a && val <= b;
}
void solve() {
    cin>>a>>b;
    for(int i = 1;i<=62;i++){
        // 111
        // 1111
        // 11111
        int bitmask = 0;
        for(int j = 0;j<i;j++)bitmask |= (1ll<<j);
        for(int j = 0;j<i-1;j++){
            ans += f(bitmask & (~(1ll<<j)));
        }
    }
    cout << ans << '\n';
}


signed main() {
    fastIO();
    fileIO();
    solve();
    return 0;
}