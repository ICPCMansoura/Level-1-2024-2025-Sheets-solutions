#include <bits/stdc++.h>
using namespace std;
 
void fastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    // freopen("walong longs.in", "r", stdin);
#endif
}
 
int n, t;
 
bool can(long long time, vector<int> & v){
    long long total = 0;
    for (int i = 0; i < v.size(); ++i) {
        total += time / v[i];
        if(total >= t)
            return 1;
    }
    return total >= t;
}
 
signed main()
{
    fastIO(); fileIO();
 
    cin >> n >> t;
 
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
 
    long long l = 1, r = 1e18, mid, ans;
    while (l <= r){
        mid = l + (r - l)/2;
        if(can(mid, v)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
 
    cout << ans << endl;
 
}