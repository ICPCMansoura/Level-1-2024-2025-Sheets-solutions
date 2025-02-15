#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum(ll n) {
    return n * (n + 1) / 2;
}

ll sum(ll l, ll r) {
    return sum(r) - sum(l - 1);
}

ll BS(ll n, ll k) {

    ll l = 1, r = k;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll s = sum(mid, k);

        if (s == n) {
            return k - mid + 1;
        } else if (s > n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return k - l + 2;
}

void solve() {
    ll n, k;
    cin >> n >> k;


    if (n == 1) {
        cout << 0;
        return;
    }

    if (k >= n) {
        cout << 1;
        return;
    }

    --n, --k;

    if (sum(k) < n) {
        cout << -1;
    } else {
        cout << BS(n, k);
    }
}

signed main() {

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