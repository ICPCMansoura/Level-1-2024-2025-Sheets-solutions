#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
#define ll long long
#define int long long
#define double long double

void UwU() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}


const ll N = 1e5 + 100 + 5, M = 105;
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll inf = 1e18;
const double EPS = 1e-4;

int n, k, H[N];
int mem[N][M];

int dp(int idx, int step) {
    if (step > k)
        return inf;
    if (idx >= n - 1)
        return idx == n - 1 ? 0 : inf;

    int &res = mem[idx][step];
    if (~res)return res;

    res = min(dp(idx, step + 1),
              dp(idx + step, 1) + abs(H[idx] - H[idx + step])
    );


    return res;
}

void solve() {
    memset(mem, -1, sizeof mem);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> H[i];

    cout << dp(0, 1) << '\n';
}


signed main() {
    UwU();
    fileIO();

    int test = 1;
//    cin >> test;

    for (int i = 1; i <= test; ++i) {
        solve();
    }
    return 0;
}