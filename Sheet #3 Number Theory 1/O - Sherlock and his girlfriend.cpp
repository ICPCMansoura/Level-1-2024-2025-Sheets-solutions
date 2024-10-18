#include <bits/stdc++.h>
#define int long long

using namespace std;


const int N = 1e6 + 10;

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
    int n; cin >> n;
    IsPrime.resize(N + 1 , true);
    sieve(n);

    vector <int> colors(n + 10 , 0); // 2 -> n + 1;

    if(n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
    } else if(n == 2) {
        cout << 1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
    } else {
        for (int i : primes) {
            colors[i] = 1;
        }
        for (int i = 2; i <= n + 1; i++) {
            if(colors[i] == 0) colors[i] = 2;
        }

        cout << 2 << '\n';
        for (int i = 2; i <= n + 1; i++) {
            cout << colors[i] << ' ';
        }
    }


}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int testCases = 1;
 //   cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}