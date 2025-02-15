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

    int n; cin >> n;
    map<int,int> v;
    int ans = 1;
    for (int i = 1; i <= n-1; ++i) {
        if(__gcd(n, i)==1){
            v[i]++;
            ans *= i;
            ans%=n;
        }
    }
    int c = v.size();
    if(ans != 1){
        v[ans]=0;
        c--;
    }
    cout << c << endl;
    for(auto it : v){
        if(it.second){
            cout << it.first << ' ';
        }
    }

}