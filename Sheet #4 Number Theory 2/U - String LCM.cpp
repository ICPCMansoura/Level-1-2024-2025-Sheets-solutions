#include <bits/stdc++.h>

using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int lcm (int a, int b) {
    return a / __gcd(a, b) * b;
}


#define int long long
typedef long long ll;
#define endl '\n'
#define SetPre(n, x)  cout << fixed << setprecision(n) << x


signed main() {
    fastIO();
    fileIO();
    int t; cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int lc = lcm(s1.size(), s2.size());
        string a = "", b = "";
        for (int i = 0; i < lc / s1.size(); ++i) {
            a += s1;
        }
        for (int i = 0; i < lc / s2.size(); ++i) {
            b += s2;
        }
        if (a == b)
            cout << a << endl;
        else cout << -1 << endl;
    }

}