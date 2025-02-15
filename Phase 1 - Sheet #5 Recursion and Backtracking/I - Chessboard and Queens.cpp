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

vector<string> grid;

bool colVis[9];
bool diag1[17];
bool diag2[17];

int fun(int r)
{
    // base case
    if (r == 8)
        return 1;

    int ans = 0;
    // recursive call
    for (int c = 0; c < 8; c++)
    {
        if (grid[r][c] == '*' || colVis[c] || diag1[r + c] || diag2[r - c + 8])
            continue;

        grid[r][c] = 'Q';

        colVis[c] = diag1[r + c] = diag2[r - c + 8] = 1;

        ans += fun(r + 1);

        grid[r][c] = '.'; // backtrack
        colVis[c] = diag1[r + c] = diag2[r - c + 8] = 0;
    }

    return ans;
}

void solve()
{
    grid.resize(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    cout << fun(0) << endl;
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