#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()


void S() {
    int n; cin >> n;
    vector <int> v(n);
    for (int &i : v) cin >> i;

    vector <int> dif;
    for (int i = 1 ; i < n ; i++) {
        dif.push_back(v[i] - v[i - 1]);
    }
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }



    int ans = n;
    int l = 0 , r = 1;
    while (r < n - 1) {
        if(dif[r] == dif[l]) r++;
        else {
            int len = r - l + 1;
            ans += (len * (len - 1)) / 2;
            while(v[l] != v[r]) l++;
        }
    }
    int len = r - l + 1;
    ans += (len * (len - 1)) / 2;
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif

    int testCases = 1;
   // cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        S();
    }
}