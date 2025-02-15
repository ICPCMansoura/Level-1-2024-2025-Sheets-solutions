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

int is_sorted(int l, int r){

    for(int i = l+1; i <= r; i++){
        if(a[i] < a[i-1]) return false;
    }
    return true;
}

int snap(int l, int r){

    if(is_sorted(l, r)){
        return r - l + 1;
    }

    int mid = (l+r) / 2;
    return max(snap(l, mid), snap(mid+1, r));

}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << snap(0, n-1);
}