// Author: _Sherbiny

#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "./debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
#define endl '\n'
#define int ll
//==================//

void magic() {
    int a, b, r; cin >> a >> b >> r;
    if(a < b) swap(a, b);

    int x = 0, big = 0;
    for(int i = 62; i >= 0; --i) {
        if((a >> i & 1) == (b >> i & 1)) continue;

        if(!big) {
            big = 1;
            continue;
        }

        if((x | (1ll << i)) > r) continue;
        if((a >> i & 1)) x |= 1ll << i;
    }

    cout << abs((a ^ x) - (b ^ x)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}