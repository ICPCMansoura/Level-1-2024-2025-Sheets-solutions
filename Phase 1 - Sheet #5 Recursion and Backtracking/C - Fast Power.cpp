#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")

#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define dpp(arr, val) memset(arr, val, sizeof(arr))
#define endl "\n"
#define loop(n) for (ll i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define pb push_back

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int f(int a, int b)
{
    // base case
    if (b <= 0)
        return 1;
    // recursive function
    int x = f(a, b / 2);

    x = (x * x) % mod;

    if (b % 2 == 0)
        return x;
    else
        return (x * a) % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    n %= mod;

    cout << f(n, m) << endl;
}

signed main()
{
    fast;

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}