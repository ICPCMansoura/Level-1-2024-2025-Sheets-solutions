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

    int ans = 0, curr = 1; // 3 ^ 0

    while(ans < n)
        ans += curr, curr *= 3;

    while(curr) {
        if(ans - curr >= n) ans -= curr;
        curr /= 3;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}
