#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10 , M = 2;

bool isPrime(int n) {
    if(n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n; cin >> n;

    if(isPrime(n)) cout << "YES\n";
    else cout << "NO\n";
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
        solve();
    }
}
