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

int t, n;
vector<int> a;
set<vector<int>> ans;

void get_all(int pos, int sum, vector<int> &sol){
    if(pos == n){
        if(sum == t){
            ans.insert(sol);
        }
        return ;
    }


    get_all(pos+1, sum, sol);
    sol.push_back(a[pos]);
    get_all(pos+1, sum + a[pos], sol);
    sol.pop_back();
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> n;
    while (t || n){
        a.clear();
        a.resize(n);

        ans.clear();

        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> init = {};
        get_all(0, 0, init);

        for(auto i: ans){
            sort(i.begin(), i.end());
            reverse(i.begin(), i.end());
        }

        vector<vector<int>> new_ans;
        for(auto sol: ans) new_ans.push_back(sol);
        reverse(new_ans.begin(), new_ans.end());

        cout << "Sums of " << t << ":\n";
        if(new_ans.empty()){
            cout << "NONE\n";
        } else {
            for(auto sol: new_ans){
                cout << sol[0];
                for(int i = 1; i < sol.size(); i++){
                    cout << "+" << sol[i];
                }
                cout << endl;
            }
        }


        cin >> t >> n;
    }

}