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


const ll N = 1e5 + 5, M = 1 << 10;
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll inf = 1e18;
const double EPS = 1e-4;

vector<vector<int>> adj;
int mem[N];

int dp(int curNode) {
    int &res = mem[curNode];
    if (~res)return res;

    res = 0;
    for (auto i: adj[curNode]) {
        res = max(res, dp(i) + 1);
    }

    return res;
}

void solve() {
    memset(mem , -1 , sizeof mem);
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) { // O(n + n)
        ans = max(ans, dp(i));
    }
    cout << ans;
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