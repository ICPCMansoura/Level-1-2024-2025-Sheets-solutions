#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;

void palmer() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << arr[0];
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}