#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1e7
#define MOD 1000000007

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

ll fast_power2(ll base, ll power, ll mod) {
    ll res = 1;
    while (power) {
        if (power & 1) {
            res *= (base % mod);
            res %= mod;
            power--;
        } else {
            base *= (base % mod);
            base %= mod;
            power /= 2;
        }
    }
    return res;
}

int main() {
    fastIO();
    fileIO();
    ll t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        cout << fast_power2(a, b, MOD) << ln;
    }
    return 0;
}