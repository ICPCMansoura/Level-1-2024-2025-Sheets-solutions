#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool can(ll mid, ll a, vector<ll> &personalMoney, vector<ll> &rentalPrices) {
    ll sum = 0;
    for (int i = 0; i < mid; ++i) {
        sum += max(0LL, rentalPrices[i] - personalMoney[mid - 1 - i]);
    }

    return sum <= a;
}


void solve() {
    ll n, m, a;
    cin >> n >> m >> a;

    vector<ll> personalMoney(n), rentalPrices(m);
    for (ll &money: personalMoney) cin >> money;
    for (ll &price: rentalPrices) cin >> price;

    sort(personalMoney.rbegin(), personalMoney.rend());
    sort(rentalPrices.begin(), rentalPrices.end());

    ll l = 0, r = min(n, m), maxRentableBoys = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        if (can(mid, a, personalMoney, rentalPrices)) {
            l = mid + 1;
            maxRentableBoys = mid;
        } else {
            r = mid - 1;
        }
    }

    ll minPersonalMoney = 0;
    for (int i = 0; i < maxRentableBoys; ++i)
        minPersonalMoney += rentalPrices[i];

    cout << maxRentableBoys << " " << max(0LL, minPersonalMoney - a);
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