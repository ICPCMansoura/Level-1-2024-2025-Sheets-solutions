#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e7 + 10 , M = 2;

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


void solve()
{
    auto primes = sieve(2e6);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << primes[x - 1] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);




    int testCases = 1;
    //  cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}