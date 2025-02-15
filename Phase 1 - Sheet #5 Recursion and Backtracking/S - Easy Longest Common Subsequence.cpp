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


int ans = 0;
set<vector<char>> subs;
void get_subs(int pos, vector<char> &cur, int sz, string &s, int check){
    if(pos == sz){
        if(!check) subs.insert(cur);
        else if(subs.count(cur)){
            ans = max(ans, (int)cur.size());
        }
        return;
    }

    get_subs(pos+1, cur, sz, s, check);
    cur.push_back(s[pos]);
    get_subs(pos+1, cur, sz, s, check);
    cur.pop_back();
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;

    cin >> a >> b;

    vector<char> init = {};
    get_subs(0, init, a.size(), a, 0);

    init = {};
    get_subs(0, init, b.size(), b, 1);

    cout << ans << endl;



}