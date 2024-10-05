#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , q;
    cin >> n >> q;
    vector<vector<int>>forest(n+1 , vector<int>(n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char IsTree;
            cin >> IsTree;
            if(IsTree == '*')
                forest[i][j] = 1;
            else
                forest[i][j] = 0;
        }
    }
    //for rows
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            forest[i][j] += forest[i][j-1];
        }
    }
    //for columns
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            forest[i][j] += forest[i-1][j];
        }
    }
    while(q--)
    {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int trees = forest[x2][y2] - forest[x1-1][y2] - forest[x2][y1-1] + forest[x1-1][y1-1];
        cout << trees << endl ;
    }
}