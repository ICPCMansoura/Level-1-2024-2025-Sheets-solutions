// Author: _Sherbiny

#include "bits/stdc++.h"
#include "iostream"
#include "map"
#include "set"
#include "queue"

using namespace std;
typedef long long ll;
#define int ll
#define endl '\n'
void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define Ready ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); fileIO();
//////////////////////////////////////////////////////////////////////////////////////////////

signed main() {
    Ready
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> f(32, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            for(int j = 0; j <= 30; ++j) f[j][i] = f[j][i - 1] + ((x & (1LL << j)) ? 1 : 0);
        }

        int q; cin >> q;
        while(q--) {
            int st, k; cin >> st >> k;

            int l = st, r = n, mid, ans = -1;
            while(l <= r) {
                mid = l + (r - l) / 2;

                ll val = 0;

                for(int j = 0; j <= 30; ++j) {
                    int cnt = f[j][mid] - f[j][st - 1];
                    if(cnt == mid - st + 1) val += (1LL << j);
                }

                if(val >= k) {
                    ans = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }

            cout << ans << ' ';
        }

        cout << endl;
    }
}