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

    int n; cin >> n;
    vector<int> v = get_divisors(n);
    int ans = INT64_MAX;
    for (int i = 0; i < v.size(); ++i) {
        int a = v[i];
        int b = n / a;
        if(lcm(a,b)==n)
            ans =  min(ans, max(a,b));
    }
    cout << ans  << ' ' << n/ans << endl;




}