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


vector<int> get_divisors(int num) {
    vector<int> divisors;
    ll i;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }
    if((i * i) == num) divisors.push_back(i);
    return divisors;
}

signed main() {
    fastIO();
    fileIO();
    while(true){
        int x; cin >> x;
        if(!x)
            break;
        vector<int> d = get_divisors(x);
        int ans = 0;
        for (int i = 0; i < d.size(); ++i) {
            for (int j = i; j < d.size(); ++j) {
                if(lcm(d[i],d[j]) == x)
                    ans++;
            }
        }
        cout << x << ' ' << ans << endl;
    }


}