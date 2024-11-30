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
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    map<int, int> mp;
    int tar = (1ll << 31) - 1, res = 0;
    for(int i = 0; i < n; ++i) {
        if(mp[tar ^ v[i]]) mp[tar ^ v[i]]--;
        else mp[v[i]]++, res++;
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}