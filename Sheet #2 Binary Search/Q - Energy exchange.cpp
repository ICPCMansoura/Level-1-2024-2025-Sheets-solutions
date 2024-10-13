#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double EPS = 1e-10;

bool can(double mid, double k, vector<ll> &energy) {
    double have = 0, need = 0;
    for (ll &e: energy) {
        if (e > mid) {
            have += (e - mid) * (1 - k / 100.0);
        } else {
            need += mid - e;
        }
    }

    return have >= need;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> energy(n);

    for (ll &e: energy) cin >> e;

    double l = 0, r = 1e3 + 7;
    while (r - l > EPS) {
        double mid = (l + r) / 2.0;

        if (can(mid, k, energy)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(9) << l;
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