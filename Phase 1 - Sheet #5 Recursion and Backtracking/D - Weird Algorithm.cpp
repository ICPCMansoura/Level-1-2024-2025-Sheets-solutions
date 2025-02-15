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

vector<int> ans;

void f(int k)
{
    // base case
    if (k <= 1)
    {
        ans.pb(1);
        return;
    }

    // recursive function
    ans.pb(k);
    if (k % 2)
    {
        f(3 * k + 1);
    }
    else
    {
        f(k / 2);
    }
}

void solve()
{
    int n;
    cin >> n;

    f(n);
    
    for (auto x : ans)
    {
        cout << x << " ";
    }
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