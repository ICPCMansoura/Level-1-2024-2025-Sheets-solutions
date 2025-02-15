#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10 , M = 2;


vector <int> PrimeFact;
void PrimeFactorization(int n) {
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            PrimeFact.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        PrimeFact.push_back(n);
}

void solve()
{
    int n; cin >> n;
    PrimeFactorization(n);
    sort(PrimeFact.begin(), PrimeFact.end());

    for (int p : PrimeFact) cout << p << ' ';
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