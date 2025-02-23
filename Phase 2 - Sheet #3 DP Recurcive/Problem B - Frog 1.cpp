#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(s) (int)(s.size())
#define all(s) (s).begin(), (s).end()

constexpr int N = 1e5, oo = 0x3f3f3f3f;

int n;
vector<int> a;
int dp[N];

int rec(int i) {
    if (i >= n - 1) return 0;
    int &ret = dp[i];
    if (~ret) return ret;
    ret = oo;
    for (int j = 1; j <= 2; ++j) {
        if (i + j < n) {
            ret = min(ret, rec(i + j) + abs(a[i] - a[i + j]));
        }
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << rec(0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}
