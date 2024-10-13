#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool can(ll k, ll n, ll a, ll mid, vector<ll> &shots) {
    vector<bool> shotPositions(n + 1);

    for (int i = 0; i < mid; ++i)
        shotPositions[shots[i]] = true;

    ll totalShips = 0, emptyCells = 0;

    for (int i = 1; i <= n; ++i) {
        if (!shotPositions[i]) {
            emptyCells++;
        } else {
            emptyCells = 0;
        }

        if (emptyCells == a) {
            totalShips++;
            emptyCells = 0;
            i++;
        }
    }

    return totalShips < k;
}

void solve() {
    ll n, k, a, m;
    cin >> n >> k >> a >> m;

    vector<ll> shots(m);
    for (ll &shot : shots) cin >> shot;

    ll l = 1, r = m, ans = -1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (can(k, n, a, mid, shots)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}