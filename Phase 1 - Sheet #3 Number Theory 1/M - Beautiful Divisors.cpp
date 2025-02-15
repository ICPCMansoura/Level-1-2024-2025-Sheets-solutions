#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<long long> divisors;
void getDivisors(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
}




void solve()
{
    set <int> BeautfulNumbers {1 , 6 , 28 , 120 , 496 , 2016 , 8128 , 32640}; // All Beautiful numbers less than 1e5

    int n; cin >> n;
    getDivisors(n);
    sort(divisors.rbegin(), divisors.rend());

    for (int i : divisors) {
        if(BeautfulNumbers.find(i) != BeautfulNumbers.end()) {
            cout << i << '\n';
            return;
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
   // cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}