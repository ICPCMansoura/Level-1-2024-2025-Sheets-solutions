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
    while (q--){
        int t;cin>>t;
        if(t == 1){
            n |= (1ll << lsb(~n));
            cout << n << '\n';
        }
        else if(t == 2){
            n &= ~(1ll << lsb(n));
            cout << n << '\n';

        }
        else if(t == 3){
            // 0100
            n |= n-1;
            cout << n << '\n';

        }
        else if(t == 4){
            n &= n+1;
            cout << n << '\n';
        }
        else{
            // 8 4 2 1
            // 1 0 0 0
            if(bit_count(n) == 1){
                cout << "is power of two\n";
            }
            else{
                cout << "not power of two\n";
            }
        }
    }
}


signed main() {
    fastIO();
    fileIO();
    solve();
    return 0;
}