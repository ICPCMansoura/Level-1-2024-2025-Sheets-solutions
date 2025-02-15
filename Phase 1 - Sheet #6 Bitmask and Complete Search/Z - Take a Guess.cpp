// Author: _Sherbiny

#include "bits/stdc++.h"
using namespace std;

#ifdef DBG
#include "./debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
#define int ll
//==================//

int ask(int i, int j, int type) {
    cout << (type? "and" : "or") << ' ' << i << ' ' << j << endl;
    int res; cin >> res;
    return res;
}

bool has(int x, int b) {
    return x >> b & 1;
}

void magic() {
    int n, k; cin >> n >> k;
    vector<int> v(n);

    int and12 = ask(1, 2, 1);
    int and13 = ask(1, 3, 1);
    int and23 = ask(2, 3, 1);
    int or12 = ask(1, 2, 0);
    int or13 = ask(1, 3, 0);
    int or23 = ask(2, 3, 0);

    v[0] = and12 | and13;
    v[1] = and12 | and23;
    v[2] = and13 | and23;

    for(int b = 0; b < 63; ++b) {
        if(!has(v[0], b) && has(or12, b) && has(or13, b) && !has(and23, b))
            v[0] |= 1ll << b;

        if(!has(v[1], b) && has(or12, b) && has(or23, b) && !has(and13, b))
            v[1] |= 1ll << b;

        if(!has(v[2], b) && has(or13, b) && has(or23, b) && !has(and12, b))
            v[2] |= 1ll << b;
    }

    for(int i = 3; i < n; ++i) {
        int x = ask(1, i + 1, 1), y = ask(1, i + 1, 0);
        v[i] = x;
        for(int b = 0; b < 63; ++b)
            if(has(y, b) && !has(v[0], b))
                v[i] |= 1ll << b;
    }

    sort(v.begin(), v.end());
    cout << "finish " << v[k - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) magic();
}
