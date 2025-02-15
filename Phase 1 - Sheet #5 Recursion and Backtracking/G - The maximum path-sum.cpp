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

int n, m;
vector<vector<int>> grid;

int fun(int r, int c, int sum)
{
    // base case
    if (r == n - 1 && c == m - 1)
    {
        return sum + grid[r][c];
    }

    // recursive call
    if (r == n - 1)
    {
        return fun(r, c + 1, sum + grid[r][c]);
    }

    if (c == m - 1)
    {
        return fun(r + 1, c, sum + grid[r][c]);
    }

        int ch1 = fun(r + 1, c, sum + grid[r][c]);
    int ch2 = fun(r, c + 1, sum + grid[r][c]);

    return max(ch1, ch2);
}

void solve()
{
    cin >> n >> m;

    grid.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << fun(0, 0, 0) << endl;
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