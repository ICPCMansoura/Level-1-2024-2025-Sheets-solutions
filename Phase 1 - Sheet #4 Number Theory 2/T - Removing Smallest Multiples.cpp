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
    int c; cin >> c;
    while(c--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> frq(n+1);
        int ans = 0;
        s = '2' + s;
        for (int i = 1; i < s.size(); ++i) {
            for (int j = i; j < s.size(); j+=i) {
                if(s[j]=='0'){
                    if(!frq[j]) {
                        ans += i;
                        frq[j]++;
                    }
                }
                else
                    break;
            }
        }
        cout << ans << endl;
    }

}