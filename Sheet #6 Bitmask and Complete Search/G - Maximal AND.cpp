#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;
void palmer() {
    int n, k, ans = 0; cin >> n >> k;
    vector<int> bit_count(31, 0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < 31; j++) {
            if (!(num & (1 << j)))
                bit_count[j]++;
        }
    }
    for (int i = 30, j = 0; i >= 0; i--) {
        if (bit_count[i] <= k) {
            ans += (1LL << i);
            k -= bit_count[i];
        }
    }

    cout << ans;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}