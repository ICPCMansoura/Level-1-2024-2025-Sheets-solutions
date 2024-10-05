#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int N , K;
    cin >> N >> K;
    vector<vector<int>>grid(1000 + 5, vector<int>(1000 + 5, 0));
    while (N--)
    {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        X1++;X2++;Y1++;Y2++;
        grid[X1][Y1] += 1;
        grid[X1][Y2] -= 1;
        grid[X2 ][Y1] -= 1;
        grid[X2 ][Y2] += 1;
    }
    for (int i = 1; i <= 1003; ++i) {
        for (int j = 1; j <= 1003; ++j) {
            grid[i][j] += grid[i][j - 1];
        }
    }
    for (int i = 1; i <= 1003; ++i) {
        for (int j = 1; j <= 1003; ++j) {
            grid[i][j] += grid[i - 1][j];
        }
    }
    int coats  = 0;
    for (int i = 0; i <= 1003; ++i) {
        for (int j = 0; j <= 1003; ++j) {
            if(grid[i][j]==K)
                coats++;
        }
    }
    cout << coats;
}
