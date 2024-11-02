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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int g = 0;
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, v[i] - v[0]);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cout << __gcd(g, x + v[0]) << ' ';
    }
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