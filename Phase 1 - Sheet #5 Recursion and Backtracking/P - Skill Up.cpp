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

int n, m, x;
vector<int> prices;
vector<vector<int>> gain;


int get_mn(int book, vector<int> &levels){

    if(book == n){
        bool f = true;
        for(auto level: levels){
            if(level < x){
                f = false;
            }
        }
        if(f) return 0;
        else return 1e9;
    }

    int ch1 = get_mn(book+1, levels);

    for(int i = 0; i < m; i++){
        levels[i] += gain[book][i];
    }

    int ch2 = prices[book] + get_mn(book+1, levels);

    for(int i = 0; i < m; i++){
        levels[i] -= gain[book][i];
    }

    return min(ch1, ch2);
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    prices.resize(n);
    gain.resize(n, vector<int> (m));

    for(int i = 0; i < n; i++){
        cin >> prices[i];
        for(int j = 0; j < m; j++){
            cin >> gain[i][j];
        }
    }

    vector<int> init(m);

    int ans = get_mn(0, init);

    if(ans >= (int)1e9) cout << -1;
    else cout << ans;
    cout << endl;


}