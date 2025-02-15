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

map <long long,bool> IsPowerOfTwo;
void solve()
{
    int n; cin >> n;
    if(IsPowerOfTwo[n]) cout << "No\n";
    else cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    for (int i = 1; i <= 46; i++) {
        IsPowerOfTwo[pow(2ll , i)] = true;
    }

    int testCases = 1;
    cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}