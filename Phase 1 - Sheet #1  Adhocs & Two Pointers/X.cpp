#include <bits/stdc++.h>
using namespace std;

#define int long long

bool canFit(int i, int j, int n, int m){
    return (i >= 1 && j >= 1 && i <= n && j <= m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int h, w;
    cin >> h >> w;
    vector<vector<int>>grid(n + 2, vector<int>(m + 2)),check;
    vector<vector<int>>partial(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> grid[i][j];
        }
    }
    check = grid;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            grid[i][j]+=grid[i][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            grid[i][j] += grid[i-1][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x = i + h - 1, y = j + w - 1;
            if (canFit(x, y, n, m))
            {
                if (grid[x][y] - grid[i - 1][y] - grid[x][j - 1] + grid[i - 1][j - 1] == 0)
                {
                    partial[i][j] += 1;
                    partial[x + 1][j] -= 1;
                    partial[i][y + 1] -= 1;
                    partial[x + 1][y + 1] += 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            partial[i][j] += partial[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            partial[i][j] += partial[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!(check[i][j] || partial[i][j]))
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testCases = 1;
 //   cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}
