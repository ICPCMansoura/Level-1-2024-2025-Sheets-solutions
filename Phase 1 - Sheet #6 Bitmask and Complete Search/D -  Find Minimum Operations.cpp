#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;

vector<int> representation(int n, int base) {
    vector<int> v;
    while (n) {
        v.push_back(n % base);
        n /= base;
    }
    reverse(v.begin(), v.end());
    return v;
}
void palmer() {
    int n, k, ans = 0; cin >> n >> k;
    if (k == 1) {
        cout << n;
        return;
    }
    vector<int> v = representation(n, k);
    for (int i = 0; i < v.size(); i++) {
        ans += v[i];
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