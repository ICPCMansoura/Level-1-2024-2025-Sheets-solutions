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

int n, w;
vector<pair<int, int>> items;


int get_mx(int pos, int rem){
    if(pos == n) return 0;

    int ans = get_mx(pos+1, rem);
    if(rem >= items[pos].first){
        ans = max(ans, items[pos].second + get_mx(pos + 1, rem - items[pos].first));
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    items.resize(n);

    for(int i = 0; i < n; i++) cin >> items[i].first >> items[i].second;

    cout << get_mx(0, w);


}