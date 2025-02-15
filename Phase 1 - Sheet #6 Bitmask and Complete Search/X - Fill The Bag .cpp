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
    int n, m; cin >> n >> m;
    vector<int> f(65);

    int sum = 0;
    for(int i = 0; i < m; ++i) {
        int x; cin >> x;
        sum += x;
        f[__lg(x)]++;
    }

    if(sum < n) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for(int i = 0; i < 63; ++i) {
        if(!(n >> i & 1)) {
            f[i + 1] += f[i] / 2;
            continue;
        }

        int x = i;
        while (!f[x]) ++x;

        while(x > i) {
            --f[x];
            f[x - 1] += 2;
            x--;
            ans++;
        }

        f[i]--;
        f[i + 1] += f[i] / 2;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) magic();
}