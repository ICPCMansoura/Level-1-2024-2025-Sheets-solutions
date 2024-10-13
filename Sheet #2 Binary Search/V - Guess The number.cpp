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
    fastIO(); //fileIO();

    int l = 1, r = 1e6, mid, ans;
    while (l <= r){
        mid = l + (r - l)/2;

        cout << mid << "\n";
        cout.flush();
        string response ; cin >> response;

        if(response == ">="){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }

    cout << "! " << ans << "\n";
    cout.flush();

}

