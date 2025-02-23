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


const ll N = 2005, M = 1 << 10;
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll inf = 1e18;
const double EPS = 1e-4;

int n, h, l, r, a[N];
int mem[N][N];

bool valid(int x) {
    return x >= l and x <= r;
}

int dp(int idx, int curHour) {
    if (idx == n)
        return 0;

    int &res = mem[idx][curHour];
    if (~res)return res;

    res = max(dp(idx + 1, (curHour + a[idx]) % h) + valid((curHour + a[idx]) % h),
              dp(idx + 1, (curHour + a[idx] - 1) % h) + valid((curHour + a[idx] - 1) % h) 
    );
    return res;
}

void solve() {
    memset(mem, -1, sizeof mem);
    cin >> n >> h >> l >> r;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << dp(0, 0);
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