#include <bits/stdc++.h>

using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int lcm (int a, int b) {
    return a / __gcd(a, b) * b;
}

/*
outside the tests :
sieve_prime_fact()

inside tests :
prime_fact(the number that require prime fac)
*/

const int N = 1000005;
int arr[N];

void sieve_prime_fact() {
    for (int i = 0; i < N; ++i)
        arr[i] = -1;
    for (int i = 2; i < N; ++i) {
        if (arr[i] == -1) {
            for (int j = i; j < N; j += i) {
                if (arr[j] == -1)
                    arr[j] = i;
            }
        }
    }
}
int prime_fact(int n){
    map<int,int> fac;
    while (n != 1) {
        fac[arr[n]]++;
        n/=arr[n];
    }
    int no_div=1;
    for(auto it : fac){
        no_div *= (it.second +1);
    }
    return no_div;
}

#define int long long
typedef long long ll;
#define endl '\n'
#define SetPre(n, x)  cout << fixed << setprecision(n) << x

int m = 1073741824;
signed main() {
    fastIO();
    fileIO();
    sieve_prime_fact();

    int a, b , c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                 ans += prime_fact(i * j * k);
                 ans %= m;
            }
        }
    }
    cout << ans << endl;


}