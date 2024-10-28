#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10 , M = 2;


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

vector<int> prime_factorization(int n, vector<int>& primes) {
    vector<int> ret;
    for (int i = 0; i < (int)primes.size(); ++i) {
        if (primes[i] * primes[i] > n) {
            break;
        }
        while (n % primes[i] == 0) {
            n /= primes[i];
            ret.push_back(primes[i]);
        }
    }
    if (n != 1) {
        ret.push_back(n);
    }
    return ret;
}

void solve()
{

    vector <int> primes = sieve(1e6 + 1);
    int q; cin >> q;

    while (q--) {
        int n; cin >> n;
        auto ans = prime_factorization(n , primes);
        sort(ans.begin(), ans.end());

        for (int i : ans) cout << i << ' ';
        cout << '\n';
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
