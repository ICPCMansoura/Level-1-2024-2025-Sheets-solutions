#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 10 , M = 2;

vector <bool> is_prime;
void SIEVE() {
    // Make sure to resize the vector to N
    is_prime[0] = is_prime[1] = false;
    for (int i = 1; i <= N; ++i) {
        if (not is_prime[i]) {
            continue;
        }
        for (int j = 2 * i; j <= N; j += i) {
            is_prime[j] = false;
        }
    }
}

void solve()
{
    int n; cin >> n;
    if(is_prime[n]) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    is_prime = vector <bool> (N , 1);
    SIEVE();

    int testCases = 1;
    cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}