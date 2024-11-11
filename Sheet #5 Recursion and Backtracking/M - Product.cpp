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

int n, x, cnt;
vector<vector<int>> a;

void fun(int i, int res)
{
    // base case
    if (i == n)
    {
        if (res == x)
        {
            cnt++;
        }

        return;
    }

    // recursive call
    for (int j = 0; j < a[i].size(); j++)
    {
        if (res > (x / a[i][j])) // (res * a > x)
        {
            continue;
        }

        fun(i + 1, res * a[i][j]);
    }
}

void solve()
{
    cin >> n >> x;

    a.resize(n);
    // 3: 1 8 7

    for (int i = 0; i < n; i++)
    {
        int sz;
        cin >> sz;

        while (sz--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    fun(0, 1);

    cout << cnt << endl;
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