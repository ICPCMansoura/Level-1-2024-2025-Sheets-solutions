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
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(int i =0;i<n;i++)cin>>arr[i];
    int ma = 0;
    for(int i = 1;i<(1<<n);i++){
        int bitmask = i;
        int idx = 0;
        int sum = 0;
        while (bitmask && bit_count(i) == k){
            if(bitmask&1){
                sum ^= arr[idx];
            }
            idx++;
            bitmask >>= 1;
        }
        ma = max(ma,sum);
    }
    cout << ma << '\n';
}


signed main() {
    fastIO();
    fileIO();
    int t;cin>>t;
    while (t--)
    solve();
    return 0;
}
