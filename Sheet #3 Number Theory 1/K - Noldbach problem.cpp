#include <bits/stdc++.h>
#define int long long

using namespace std;


vector <int> primes;
vector<bool> IsPrime; // Don't forget to resize it to N
void sieve(int n) {
    IsPrime[0] = IsPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (IsPrime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) {
                break;
            }
            IsPrime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void solve()
{
    IsPrime.resize(3000 , true);
    int n , k; cin >> n >> k;
    sieve(3000);
    int cnt = 0;
    for (int i = 0; i < primes.size() - 1; i++) {
        int val = primes[i] + primes[i + 1] + 1;
        if(val > n) break;
        if(IsPrime[val]) cnt++;
    }
    if(cnt >= k) cout << "YES\n";
    else cout << "NO\n";
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