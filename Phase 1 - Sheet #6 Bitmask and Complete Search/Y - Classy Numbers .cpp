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

vector<int> v;

void go(int n = 18, int rem = 3, int curr = 0) {
    if(!n) return v.push_back(curr);

    go(n - 1, rem, curr * 10);

    if(rem) {
        for(int i = 1; i <= 9; ++i)
            go(n - 1, rem - 1, curr * 10 + i);
    }
}

void magic() {
    int l, r; cin >> l >> r;
    cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    go();
    v.push_back(1e18);
    int t = 1;
    cin >> t;
    while (t--) magic();
}
