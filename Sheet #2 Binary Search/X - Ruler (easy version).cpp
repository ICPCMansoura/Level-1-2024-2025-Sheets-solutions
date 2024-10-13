#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll l = 2, r = 999, ans;

    while (l <= r) {
        ll mid = (l + r) / 2;

        cout << "? 1 " << mid << endl;
        cout.flush();

        ll measuredArea;
        cin >> measuredArea;

        if (measuredArea == mid) {
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