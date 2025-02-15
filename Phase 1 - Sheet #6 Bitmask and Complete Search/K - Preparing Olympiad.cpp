#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;

void palmer() {
    int n, l, r, x, ans = 0, sum, mx, mn; cin >> n >> l >> r >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int mask = 0; mask < (1 << n); mask++) {
        sum = 0, mx = 0, mn = LLONG_MAX;
        if (__builtin_popcount(mask) < 2)
            continue;

        for(int i = 0; i < n; i++) {
            if((mask & (1 << i)) == 0)
                continue;

            sum += a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        if (mx - mn >= x && sum >= l && sum <= r)
            ans++;

    }
    cout << ans;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; //cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}
