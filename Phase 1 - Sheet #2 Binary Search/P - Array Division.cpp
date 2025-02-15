#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);

    ll maxVal = LLONG_MIN, totalSum = 0;

    for (ll &num: nums) {
        cin >> num;
        maxVal = max(maxVal, num);
        totalSum += num;
    }

    ll l = maxVal, r = totalSum, ans = LLONG_MAX;

    while (l <= r) {
        ll mid = (l + r) / 2;

        ll currSum = 0, cnt = 1;
        for (ll num: nums) {
            if (currSum + num > mid) {
                ++cnt;
                currSum = 0;
            }
            currSum += num;
        }

        if (cnt <= k) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
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