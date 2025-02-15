#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")

#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

using namespace std;

int fun(int i)
{
    // base case
    if (i == 1)
        return 1;
    // recursive call
    if (i % 2 == 0)
        return 1 + fun(i / 2);
    else
        return 1 + fun(3 * i + 1);
}

void solve()
{
    int n;
    cin >> n;

    cout << fun(n) << endl;
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