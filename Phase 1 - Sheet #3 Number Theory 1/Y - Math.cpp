#include <bits/stdc++.h>
using namespace std;

#define int long long

int maxFact = 0;
map <int,int> fact;
int PrimeFactorization(int n) {
    vector <int> PrimeFact;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            fact[i]++;
            PrimeFact.push_back(i);
            n /= i;
            maxFact = max(maxFact, fact[i]);
        }
    }
    if (n > 1) {
        fact[n]++;
        PrimeFact.push_back(n);
    }
    return PrimeFact.size();
}

void solve()
{
    int n;
    cin >> n;
    PrimeFactorization(n);

    int po = 1 , TotalOp = 0 , ans = 1;
    while(po < maxFact) {
        po *= 2 , TotalOp++;
    }
    bool f = 0;
    for (auto &[x , rep] : fact) {
        if(rep != po) {
            f = 1;
        }
        ans *= x;
    }
    cout << ans << ' ' << TotalOp + f << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int testCases = 1;
  //  cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}
