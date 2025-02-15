#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> dx = {0, 0,  1, -1, -1, 1, 1, 1};
vector<int> dy = {1, -1, 0, 0, -1, 0, 1, -1};
#define int long long


int n, m;
int ans = 0;
vector<vector<int>> grid, vis;

bool is_valid(int x, int y){
    if(x > 0 && x <= n && y > 0 && y <= m && !vis[x][y] && grid[x][y]) return true;
    return false;
}

void go(int x, int y){

    if(!is_valid(x, y)) return;

    vis[x][y] = 1;

    if(x == n && y == m){
        ans++;
        vis[x][y] = 0;
        return;
    }

    for(int i = 0; i < 4; i++){
        int new_x = x + dx[i], new_y = y + dy[i];
        go(new_x, new_y);
    }

    vis[x][y] = 0;
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    grid.resize(n+1, vector<int> (m+1));
    vis.resize(n+1, vector<int> (m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    go(1, 1);

    cout << ans;





}