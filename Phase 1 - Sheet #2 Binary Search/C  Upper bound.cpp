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


signed main()
{
    fastIO(); fileIO();

    int n, q; cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    while (q--){
        int x; cin >> x;

        int l = 0, r = n - 1, mid, ans = -1;
        while (l <= r){
            mid = (l + r)/2;
            if(v[mid] > x){
                r = mid - 1;
                ans = mid + 1;
            }
            else{
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }


}
