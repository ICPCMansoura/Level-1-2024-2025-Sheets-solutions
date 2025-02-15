#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool can(ll mid, ll k, string s) {
    ll sum = 0;

    for (int i = 1; i < mid; ++i) {
        if (s[i] >= s[i - 1]) {
            sum += (s[i] - s[i - 1]);
        } else {
            sum += s[i] + (10 - s[i - 1]);
        }
    }

    if (s[mid - 1]) {
        sum += (10 - s[mid - 1]);
    }

    return sum <= k;
}

void solve() {
    ll n, k;
    string s;

    cin >> n >> k >> s;

    for (char &digit: s) digit -= '0';

    ll l = 0, r = n, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        if (can(mid, k, s)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
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