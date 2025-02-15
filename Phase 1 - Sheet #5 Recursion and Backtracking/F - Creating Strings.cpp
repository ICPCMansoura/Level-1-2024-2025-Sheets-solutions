#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;

string s;
set<string> ans;

void f(int l, int r) {
    if (l == r)
        ans.insert(s);
    else {
        for (int i = l; i <= r; i++) {
            swap(s[i], s[l]);
            f(l + 1, r);
            swap(s[i], s[l]);
        }
    }
}
void palmer() {
    cin >> s;
    f(0, s.size() - 1);
    cout << ans.size() << "\n";
    for (auto it: ans) {
        cout << it << "\n";
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; //cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}