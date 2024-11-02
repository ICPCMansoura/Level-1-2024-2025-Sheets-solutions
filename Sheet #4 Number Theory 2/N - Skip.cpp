#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int testCase) {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    v.push_back(x);
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = gcd(ans, v[i] - v[i - 1]);
    }
    cout << ans << '\n';
}

signed main() {
    fileIO();
    fastIO();
    int numOfTests = 1;
    //cin >> numOfTests;
    for (int testCase = 1; testCase <= numOfTests; testCase++)
        solve(testCase);
    return 0;
}