#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) {
                break;
            }
            is_prime[i * p] = false;
            if (i % p == 0) {
                break;
            }
        }
    }
    return primes;
}

map <int,bool> T_Primes;

void solve()
{
    auto Primes = sieve(N);
    for (int p : Primes) {
        T_Primes[p * p] = 1;
    }
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(T_Primes[x]) cout << "YES\n";
        else cout << "NO\n";
    }
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