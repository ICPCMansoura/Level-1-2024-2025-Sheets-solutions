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

int n;
vector<int> a;

priority_queue<pair<int, pair<int, int>>> pq;

void edit(int cur){

    if(pq.empty()) return;

    pair<int, pair<int, int>> top = pq.top();
    pq.pop();
    int l = -top.second.first, r = top.second.second;

    if(l > r) return;


    int target = (l+r) / 2;
    a[target] = cur;

    pq.push({target - l, {-l, target - 1}});
    pq.push({r - target, {- target - 1, r}});

    edit(cur+1);

}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.clear();
        a.resize(n, 0);

        pq.push({n, {0, n-1}});

        edit(1);

        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

}