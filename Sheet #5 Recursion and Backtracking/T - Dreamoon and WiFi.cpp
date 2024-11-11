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

int sz;
string s1, s2;
int req;
int total;

int cnt(int pos, int cur){
    if(pos == sz){
        total++;
        return (cur == req);
    }

    if(s2[pos] == '?'){
        return cnt(pos+1, cur+1) + cnt(pos+1, cur - 1);
    } else if(s2[pos] == '+'){
        return cnt(pos+1, cur+1);
    } else {
        return cnt(pos+1, cur - 1);
    }
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;
    sz = (int)s1.size();

    for(auto c: s1){
        if(c == '+') req++;
        else req--;
    }

    cout << fixed << setprecision(11) << cnt(0, 0)*1.0 / total << endl;
}