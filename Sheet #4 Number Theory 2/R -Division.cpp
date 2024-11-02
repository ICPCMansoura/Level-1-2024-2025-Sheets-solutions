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
    string s; cin >> s;
    int x; cin >> x;
    int tenz =1;
    int ans = 0;
    reverse(s.begin(),s.end());
    for (int i = 0; i < s.size(); ++i) {
        ans += ((s[i] - '0')%x * tenz%x) % x;
        ans %= x;
        tenz*=10;
        tenz%=x;
    }
    if(!ans)
        cout << "YES" << endl;
    else cout << "NO" << endl;


}