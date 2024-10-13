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
    long long n; cin >> n;

    long double l = 0, r = 1e9, mid;
    while ((r - l) > 1e-9){
        mid = l + (r - l)/2;
        if(mid * mid >= n){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << fixed << setprecision(9) << mid;

}
