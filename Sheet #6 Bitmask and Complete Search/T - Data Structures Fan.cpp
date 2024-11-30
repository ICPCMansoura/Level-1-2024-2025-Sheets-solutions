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
    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    int ans = 0;
    string s; cin >> s;
    for(int i = 1; i <= n; ++i)
        if(s[i - 1] == '1') ans ^= v[i];

    vector<int> pref(n + 1);
    for(int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] ^ v[i];

    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l, r; cin >> l >> r;
            ans ^= pref[r] ^ pref[l - 1];
        } else {
            int g; cin >> g;
            cout << (g? ans : ans ^ pref[n]) << ' ';
        }
    }

    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}
