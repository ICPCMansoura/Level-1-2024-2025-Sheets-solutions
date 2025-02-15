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
string s;

int make_equal(int l, int r, char c){

    int cnt = 0;
    for(int i = l; i <= r; i++){
        cnt += (s[i] != c);
    }

    return cnt;
}

int get_mn(int l, int r, char c){

    if(l == r) return s[l] != c;

    int mid = (l+r) / 2;

    int ch1 = make_equal(l, mid, c) + get_mn(mid+1, r, (char)(c+1));
    int ch2 = make_equal(mid+1, r, c) + get_mn(l, mid, (char)(c+1));

    return min(ch1, ch2);


}




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;

        cout << get_mn(0, n-1, 'a') << endl;
    }
}