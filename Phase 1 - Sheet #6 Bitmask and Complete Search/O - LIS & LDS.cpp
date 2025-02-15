#include <bits/stdc++.h>
#define int long long
#ifndef ONLINE_JUDGE
#define DBG_MACRO_MINIMAL
#define DBG_MACRO_SINGLE_LINE
#include "dbg.h"
#else
#define dbg(...)
#endif


#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) (__builtin_ctzll(x))
#define bit_count(x) (__builtin_popcountll(x))

using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
#endif
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void f(vector<int>arr){
    int n = arr.size();
    int ans = 0,ansSum=0;
    for(int i =1;i<(1<< n);i++){
        int bitmask = i;
        int idx = 0;
        int sum = 0;
        int taken = 0;
        int lst = -1;
        while (bitmask){
            if(bitmask&1){
                if(arr[idx] > lst) {
                    taken++;
                    lst = arr[idx];
                    sum += lst;
                }
            }
            idx++;
            bitmask >>= 1;
        }
        if(taken >= ans){
            // 1 3 100 4 9  3
            if(taken == ans) {
                ansSum = max(sum,ansSum);
            }
            else
                ansSum = sum;
            ans = taken;
        }
    }
    cout << ans << " " << ansSum << " ";
    // 1 3 10 4 9
}
void solve() {
    int n;cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    f(arr);
    std::reverse(arr.begin(), arr.end());
    f(arr);
}


signed main() {
    fastIO();
    fileIO();
    solve();
    return 0;
}