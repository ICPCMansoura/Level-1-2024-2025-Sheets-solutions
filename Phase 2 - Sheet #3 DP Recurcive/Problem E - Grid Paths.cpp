#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int mod = 1e9 + 7;
vector<vector<int>> dp;
vector<vector<char>> grid;
int n, m;

int go(int x, int y) {
    if (x == n - 1 && y == m - 1)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    int ways = 0;

    if (x + 1 < n && grid[x + 1][y] != '#') {
        ways = (ways + go(x + 1, y)) % mod;
    }

    if (y + 1 < m && grid[x][y + 1] != '#') {
        ways = (ways + go(x, y + 1)) % mod;
    }

    dp[x][y] = ways;

    return dp[x][y];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    grid.assign(n, vector<char>(m));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << go(0, 0) << endl;

    return 0;
}
