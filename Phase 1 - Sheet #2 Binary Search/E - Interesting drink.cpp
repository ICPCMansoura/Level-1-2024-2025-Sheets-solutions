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

    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << upper_bound(v.begin(), v.end(), x) - v.begin() << "\n";
    }

}