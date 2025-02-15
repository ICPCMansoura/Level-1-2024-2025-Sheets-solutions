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

int quick_pow(int a,int b,int p){
    int c=1;
    for(;b;b>>=1){
        if(b&1){c=c*a;if(c>=p)c=c%p+p;}
        a=a*a;if(a>=p)a=a%p+p;
    }
    return c;
}
int m = 1e9 + 7;

signed main() {
    fastIO();
    fileIO();
    int t; cin >> t;
    while(t--) {
        int l, r, k;
        cin >> l >> r >> k;
        int cnt = 9/k + 1;
        cout << (quick_pow(cnt, r, m) -  quick_pow(cnt, l, m) + m )%m << endl;
    }

}