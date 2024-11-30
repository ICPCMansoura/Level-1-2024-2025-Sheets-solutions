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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    int minXor = LLONG_MAX, i = 0, j = 0;
    for(int o = 1; o < n; ++o) {
        if((v[o].first ^ v[o - 1].first) < minXor) {
            minXor = v[o].first ^ v[o - 1].first;
            i = o - 1, j = o;
        }
    }

    int x = 0;
    for(int b = 0; b < k; ++b) {
        if(!(v[i].first >> b & 1) && !(v[j].first >> b & 1))
            x |= 1ll << b;
    }

    cout << v[i].second << ' ' << v[j].second << ' ' << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}
