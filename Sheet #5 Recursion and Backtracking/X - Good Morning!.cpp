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

set<int> options;

vector<vector<int>> key;

void get_options(int r, int c, int cur){

    options.insert(cur);
    
    

    if(cur <= 200){

        if(cur || key[r][c]) get_options(r, c, cur*10 + key[r][c]);

        if(c < 2){
            get_options(r,  c+1, cur);
        }

        if(r < 2){
            get_options(r+1, c, cur);
        }

        if(r == 2 && c < 2){
            get_options(3, 0, cur);
        }

    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    key = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {0}
    };

    get_options(0, 0, 0);

    int t, k;
    cin >> t;
    while(t--){
        cin >> k;

        int ans;
        int diff = INT_MAX;
        for(auto op: options){
            if(abs(op - k) < diff){
                diff = abs(op - k);
                ans = op;
            }
        }

        cout << ans << endl;

    }

}