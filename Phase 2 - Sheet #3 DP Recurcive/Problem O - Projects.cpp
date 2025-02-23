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


const ll N = 4e5 + 5, M = 1 << 10;
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll inf = 1e18;
const double EPS = 1e-4;

int n;
vector<pair<int, int>> Day[N]; //{(R1 , W1) , (R2 ,W2)};

int mem[N];

int dp(int day) {
    if (day >= n)
        return 0;

    int &res = mem[day];
    if (~res)return res;

    res = dp(day + 1);
    for(auto [R , W] : Day[day]){
        res = max(res , dp(R + 1) + W);
    }
    return res;
}

void solve() {
    memset(mem, -1, sizeof mem);
    cin >> n;
    vector<int> L(n), R(n), W(n);
    map<int, int> newVal;
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i] >> W[i];
        newVal[L[i]];
        newVal[R[i]];
    }

    int id = 1;
    for (auto &[_, v]: newVal) {
        v = id++;
    }

    for (int i = 0; i < n; ++i) {
        L[i] = newVal[L[i]];
        R[i] = newVal[R[i]];
    }

    for (int i = 0; i < n; ++i) {
        Day[L[i]].push_back({R[i], W[i]});
    }

    n = id;
    cout << dp(0);
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