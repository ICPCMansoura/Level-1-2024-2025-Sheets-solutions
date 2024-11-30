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
    int n, x; cin >> n >> x;

    int res = x, tar = n - 1, j = 0;
    for(int b = 0; b < 63; ++b) {
        if(x >> b & 1) continue;
        if(tar >> j & 1) res |= 1ll << b;
        j++;
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) magic();
}
