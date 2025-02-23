#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX
#define eps 1e-6
#define MOD 1073741824
#define int long long

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
int dx[]{-1, 0, 1, 0};
int dy[]{0, 1, 0, -1};
const int oo = 2e18;
int n, w;
vector<pair<int, int>> v;
const int N = 101, W = 1e6;
int dp[N][W];

int solve(int i, int wi) {
    if (wi > w) return -oo;
    if (i == n) return 0;

    if (~dp[i][wi]) return dp[i][wi];

    int ch1 = solve(i + 1, wi);
    int ch2 = solve(i + 1, wi + v[i].first) + v[i].second;
    return dp[i][wi] = max(ch1, ch2);
}

void ayaaa() {
    cin >> n >> w;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    cout << solve(0, 0);
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        ayaaa();
    }

    return 0;
}