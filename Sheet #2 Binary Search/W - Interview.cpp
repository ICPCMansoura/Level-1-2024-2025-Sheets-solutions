#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> weights(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    ll l = 1, r = n, ans = 0;
    while (l <= r) {
        ll mid = (r + l) / 2, expectedWeight = 0;

        cout << "? " << (mid - l + 1) << ' ';
        for (int i = l; i <= mid; ++i) {
            cout << i << ' ';
            expectedWeight += weights[i];
        }

        cout << endl;
        cout.flush();

        ll totalWeight;
        cin >> totalWeight;

        if (totalWeight == expectedWeight) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }

    cout << "! " << ans << endl;
    cout.flush();
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}