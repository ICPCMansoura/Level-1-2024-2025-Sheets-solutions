#include <bits/stdc++.h>
#define int long long

using namespace std;


int PrimeFactorization(int n) {
    set <int> PrimeFact;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            PrimeFact.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        PrimeFact.insert(n);
    return PrimeFact.size();
}

void solve()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(PrimeFactorization(i) == 2) {
            ans++;
        }
    }
    cout << ans << "\n";
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