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

int k;
vector<int> arr;
vector<int> ans;


bool go(set<int> left, int sum, int pos){
    if(left.empty()){
        return true;
    }

    set<int> temp = left;

    for(auto i: temp){
        if(sum + arr[pos]*i > k) break;

        ans.push_back(i);
        left.erase(i);

        if(go(left, sum + arr[pos]*i, pos+1)) return true;

        left.insert(i);
        ans.pop_back();
    }

    return false;

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t;
    while(t--){
        arr.clear();
        arr.resize(10);

        ans.clear();

        for(int i = 0; i < 10; i++) cin >> arr[i];
        cin >> k;

        set<int> left = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        go(left, 0, 0);

        if(ans.empty()){
            cout << -1 << endl;
            continue;
        }

        for(auto i: ans) cout << i << " ";
        cout << endl;

    }

}