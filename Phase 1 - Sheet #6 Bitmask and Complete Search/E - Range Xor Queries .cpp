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
    int n,q;cin>>n>>q;
    vector<int>arr(n);
    for(int i =0;i<n;i++)cin>>arr[i];
    for(int i = 1;i<n;i++)arr[i] ^= arr[i-1];
    while (q--){
        int l,r;cin>>l>>r;l--;r--;
        cout << (arr[r] ^ (l-1 >= 0 ?arr[l-1] : 0)) << '\n';
    }
}


signed main() {
    fastIO();
    fileIO();
    solve();
    return 0;
}