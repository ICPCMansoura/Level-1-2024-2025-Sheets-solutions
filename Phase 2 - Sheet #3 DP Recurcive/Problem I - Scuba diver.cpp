#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX
#define eps 1e-6
#define MOD 1000000007
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
int n, m, o;
int o_needed, n_needed, cylinders;
const int N = 1001, M = 1001;
int ox[N], ni[N], w[N];
int dp[N][22][80];

int solve(int i, int rem_o, int rem_n) {
    rem_o = max(0LL, rem_o);
    rem_n = max(0LL, rem_n);
   if (rem_o == 0 && rem_n == 0) return 0;
    if (i == cylinders) return oo;

    if (~dp[i][rem_o][rem_n]) return dp[i][rem_o][rem_n];

    int ch1 = solve(i + 1, rem_o, rem_n);
    int ch2 = solve(i + 1, rem_o - ox[i], rem_n - ni[i]) + w[i];

    return dp[i][rem_o][rem_n] = min(ch1, ch2);
}


void ayaaa() {
    cin >> o_needed >> n_needed >> cylinders;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < cylinders; i++) {
        cin >> ox[i] >> ni[i] >> w[i];
    }
    cout << solve(0, o_needed, n_needed) << "\n";
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        ayaaa();
    }

    return 0;
}